<?php

/**
 * @file
 * Template for allowing multiple filters to be selected.
 */
?>
<div id="collection-<?php print $collection['collection_id']; ?>" class="collection-grid collection-filter-effect-<?php print $collection['filter_effect']; ?>">
  <div class="row">
    <div class="col-lg-3 col-md-12 col-sm-12 col-xs-12">
      <div class="collection-grid-filters">
        <form>
          <?php print render($content['filters']); ;?>
          <input type="reset" value="Reset Filters" class="button button-gray-light collection-reset" data-collection="collection-<?php print $collection['collection_id']; ?>"/>
        </form>
      </div>
    </div>
    <div class="col-lg-9 col-md-12 col-sm-12 col-xs-12">
      <div class="results element-invisible"></div>
      <div class="collection-breadcrumbs-wrapper"><span class="collection-breadcrumbs"></span> <a href="#" data-collection="collection-<?php print $collection['collection_id']; ?>" class="collection-reset"><i class="fa fa-times" aria-hidden="true"></i> Reset Filters</a></div>
      <div class="collection-grid-items">
        <?php print render($content['items']); ;?>
      </div>
    </div>
  </div>

</div>
