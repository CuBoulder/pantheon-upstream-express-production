<?php if ($multiple): ?>
  <div class="collection-filter-links-wrapper collection-filter-links-multiple collection-filter-links-multi-select">
    <div class="collection-filter-links-inner">
    <h3 class="collection-filter-label" aria-controls="collection-<?php print $collection_id; ?>-filter-links">
      <span><?php print $label; ?></span>
    </h3>

    <div class="collection-filter-links-form collection-filter-links" id="collection-<?php print $collection_id; ?>-filter-links">
        <?php foreach ($collection_filter_terms as $term): ?>
          <div class="filter">
            <input type="checkbox" id="<?php print _express_collections_bundle_clean_string($term->name); ?>" name="collection-<?php print $collection_id; ?>" value="<?php print _express_collections_bundle_clean_string($term->name); ?>" data-collection="collection-<?php print $collection_id; ?>">
            <label for="<?php print _express_collections_bundle_clean_string($term->name); ?>"><?php print $term->name; ?></label>
          </div>
        <?php endforeach; ?>
    </div>

</div>
  </div>
<?php else: ?>

<div class="collection-filter-links-wrapper collection-filter-links-multiple collection-filter-links-single-select <?php if (isset($image)) {print 'collection-filter-links-bg';} ?>" <?php
  if (isset($image)) {
    print "style=background-image:url('$image');";
  }
?>>
  <div class="collection-filter-links-inner">
    <h3 class="collection-filter-label" aria-controls="collection-<?php print $collection_id; ?>-filter-links">
      <a href="#collection-<?php print $collection_id; ?>-filter-links" aria-expanded="false">
        <span><?php print $label; ?></span>
      </a>
    </h3>
    <div class="collection-filter-links" id="collection-<?php print $collection_id; ?>-filter-links">
      <div class="collection-links-buttons">
        <button data-collection="collection-<?php print $collection_id; ?>" class="collection-filter-clear">All</button>
        <?php foreach ($collection_filter_terms as $term): ?>
          <button data-collection="collection-<?php print $collection_id; ?>" data-collection-category="<?php print _express_collections_bundle_clean_string($term->name); ?>" data-collection-category-hash="#<?php print _express_collections_bundle_clean_string($term->name); ?>"><?php print $term->name; ?></button>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
</div>

<?php endif; ?>
