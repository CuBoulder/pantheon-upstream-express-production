<div id="collection-<?php print $collection['collection_id']; ?>" class="collection-grid collection-filter-effect-<?php print $collection['filter_effect']; ?>">
  <div class="collection-grid-filters">
    <?php print render($content['filters']); ;?>
  </div>
  <div class="results element-invisible"></div>
  <div class="collection-grid-items">
    <?php print render($content['items']); ;?>
  </div>
</div>
