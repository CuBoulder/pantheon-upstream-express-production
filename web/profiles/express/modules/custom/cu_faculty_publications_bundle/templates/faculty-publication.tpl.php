<div class="padding-bottom margin-bottom">
  <h3 class="h5">
    <?php
      if ($doi) {
        print l($name, 'https://dx.doi.org/' . $doi, array('html' => TRUE));
      }
      else {
        print $name;
      }
    ?>
  </h3>
  <strong>Authors:</strong>
  <?php
    $names = array();
    foreach ($authors as $author) {
      $names[] = l($author['name'], $author['uri']);
    }
    print implode($names, '; ');
  ?><br />
  <?php if (!empty($publishedIn)): ?>
    <strong>Published in:</strong> <?php print l($publishedIn['name'], $publishedIn['uri']); ?><br />
  <?php endif; ?>
  <strong>Publication Date:</strong> <?php print $publicationDate; ?><br />
  <strong>Type:</strong> <?php print $mostSpecificType; ?>
</div>
