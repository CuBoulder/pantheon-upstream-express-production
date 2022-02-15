<?php if (express_localist_bundle_api_disable()): ?>
  Localist events are unavailable.
<?php else: ?>
  <div class="localist-events <?php print $localist_classes; ?>">
    <script type="text/javascript"
  src="<?php print $widget_url; ?>"></script>
  </div>
  <?php
    if (!empty($content['field_localist_link'])):
  ?>
    <div class="localist-link more-link">
      <?php print render($content['field_localist_link']); ?>
    </div>
  <?php endif; ?>
<?php endif; ?>
