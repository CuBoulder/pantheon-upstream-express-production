<?php

/**
 * @file
 * Code needed to work with Json Web Tokens.
 */

require_once drupal_get_path('module', 'express_site_metrics') . '/classes/JWT.php';
/**
 * Class for working with Json Web Tokens.
 *
 * The JWT class is taken from
 * https://github.com/crmcmullen/jwtphpjquery/blob/master/jwt.php.
 * See class comments for this class lower in this file.
 */
class TokenHandler extends JWT {
  /**
   * Wrapper class for variable_set() and variable_get() Drupal functions.
   *
   * @var object
   */
  private $variableDb;

  /**
   * A copy of the super global $_SERVER variable.
   *
   * @var array
   */
  private $server;

  /**
   * Build the class. Takes a wrapper class for needed functions.
   */
  public function __construct($variableDb, $server = []) {
    $this->variableDb = $variableDb;
    $this->server = $server;
  }

  /**
   * Generates a new Json Web Token and can save $userId to datbase.
   *
   * @param string $newUserId
   *   A unique string describing the bearer of this token.
   * @param bool $saveToDb
   *   Save or not save $userId to database, defaults to TRUE.
   *
   * @return string
   *   Returns Json Web Token.
   */
  public function generateToken($newUserId, $saveToDb = TRUE) {
    // Create a token.
    $payloadArray = array();
    $payloadArray['userId'] = $newUserId;
    $token = JWT::encode($payloadArray, $this->variableDb->getSecret());

    // Save new userId to tokensDb.
    if ($saveToDb) {
      $this->saveUser($newUserId);
    }

    // Return to caller.
    return $token;
  }

  /**
   * Takes a token and checks if the userId in its payload is in the tokensDb.
   *
   * @return bool
   *   If token can be validated return TRUE, else FALSE.
   */
  public function validateToken() {
    $token = $this->getTokenFromHeader();
    if ($token == "no token found") {
      return FALSE;
    }

    $decodedToken = parent::decode($token, $this->variableDb->getSecret(), array('HS256'));

    return $this->validateUserId($decodedToken->userId);
  }

  /**
   * Returns $tokensDb.
   */
  private function saveUser($userId) {
    $this->variableDb->addUser($userId);
  }

  /**
   * Checks if a userId is already in the tokensDb.
   *
   * @param string $userId
   *   The name of service using this endpoint. One token per userId is allowed.
   *
   * @return bool
   *   TRUE if UserId is in tokensDb, FALSE if it is not.
   */
  private function validateUserId($userId) {
    foreach ($this->variableDb->getUsers() as $userIdInDb) {
      if ($userIdInDb === $userId) {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Grabs token from $server['HTTP_AUTHORIZATION'] if present.
   *
   * @return string
   *   Json Web Token if present or 'no token found' message.
   */
  private function getTokenFromHeader() {
    if (!empty($this->server['HTTP_AUTHORIZATION'])) {
      $token = explode(' ', $_SERVER['HTTP_AUTHORIZATION'])[1];
      return $token;
    }
    return 'no token found';
  }

}
