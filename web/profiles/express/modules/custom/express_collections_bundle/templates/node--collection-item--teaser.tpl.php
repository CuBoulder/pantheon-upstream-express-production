<div class="collection-item-view-mode-teaser node-view-mode-teaser clearfix">
  <?php if(!empty($content['field_collection_thumbnail'][0])): ?>
    <?php print render($content['field_collection_thumbnail'][0]); ?>
  <?php endif; ?>
  <div class="collection-item-view-mode-teaser-content node-view-mode-teaser-content">
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <div class="collection-item-summary">
      <?php

        if (!empty($content['field_collection_preview'])) {
          print render($content['field_collection_preview']);
        }
        else {
          print render($content['field_collection_body']);
        }
      ?>
    </div>
  </div>
</div>
