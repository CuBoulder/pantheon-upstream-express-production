<?php

/**
 * @file
 * Code needed to work with Drupal's variable database table.
 */

/**
 * Wrapper class for Drupal's variable_*() functions.
 */
class VariableController {
  /**
   * Name of users key in variable database table.
   *
   * @var string
   */
  private $metricsUsersDb = 'express_site_metrics_users';

  /**
   * Name of secret key in variable database table.
   *
   * @var string
   */
  private $secretDb = 'express_site_metrics_secret';

  /**
   * Get user id's from variable database table.
   *
   * @return array
   *   Returns string[] of user ids.
   */
  public function getUsers() {
    return variable_get($this->metricsUsersDb, []);
  }

  /**
   * Save a new userId to users variable database table.
   *
   * @param string $newUserId
   *   New user id to be saved.
   */
  public function addUser(string $newUserId) {
    $users = $this->getUsers();
    array_push($users, $newUserId);
    $this->setUsers($users);
  }

  /**
   * Saves users to users variable database table.
   *
   * @param array $users
   *   All of the user ids to be saved.
   */
  private function setUsers(array $users) {
    variable_set($this->metricsUsersDb, array_unique($users));
  }

  /**
   * Gets secret from variable database table.
   *
   * @return string
   *   The secret used for creating tokens.
   */
  public function getSecret() {
    return variable_get($this->secretDb, NULL);
  }

}
