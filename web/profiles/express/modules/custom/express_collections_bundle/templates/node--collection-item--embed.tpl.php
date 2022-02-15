<div class="collection-item-view-mode-embed node-view-mode-embed clearfix">
  <?php if(!empty($content['field_collection_thumbnail'][0])): ?>
    <?php print render($content['field_collection_thumbnail'][0]); ?>
  <?php endif; ?>
  <div class="collection-item-view-mode-embed-content node-view-mode-embed-content">
    <h3<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
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
