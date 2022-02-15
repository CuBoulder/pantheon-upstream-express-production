<div class="collection-item-view-mode-sidebar clearfix node-view-mode-sidebar">
  <?php if(!empty($content['field_collection_thumbnail'][0])): ?>
    <?php print render($content['field_collection_thumbnail'][0]); ?>
  <?php endif; ?>
  <div class="collection-item-view-mode-sidebar-content node-view-mode-sidebar-content">
    <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
  </div>
</div>
