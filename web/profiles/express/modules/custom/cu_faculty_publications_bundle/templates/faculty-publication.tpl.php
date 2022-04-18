<div class="faculty-publication padding-bottom margin-bottom">
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
  <div class="cu-authors">
    <strong>CU Boulder Authors:</strong>
    <?php
      $names = array();
      foreach ($authors as $author) {
        $names[] = l($author['name'], $author['uri']);
      }
      print implode('; ', $names);
    ?>
  </div>
  <div class="all-authors-container" style="display: flex">
    <strong style="margin-right:.5rem; width: 85px;">All Authors:</strong>
    <?php if (strlen($citedAuthors) < 100): ?>
      <?php print $citedAuthors; ?>

    <?php else: ?>
      <?php $allAuthorArray = explode("; ", $citedAuthors); ?>
      <details style="margin-left: .5rem" class="all-authors">
        <summary>
          <span class=all-authors-truncated><?php print substr($citedAuthors, 0, 120) . "..."; ?></span>
        </summary>

        <ul class="all-authors-list">

          <?php foreach($allAuthorArray as $author): ?>
            <li><?php print $author; ?></li>
          <?php endforeach; ?>

        </ul>
      </details>
    <?php endif; ?>
  </div>
  <?php if (!empty($publishedIn)): ?>
    <strong>Published in:</strong> <?php print l($publishedIn['name'], $publishedIn['uri']); ?><br />
  <?php endif; ?>
  <strong>Publication Date:</strong> <?php print $publicationDate; ?><br />
  <strong>Type:</strong> <?php print $mostSpecificType; ?>
</div>

