<div class="adv-timeline-wrapper">
  <div class="timeline-list-link">
    <a href="#timeline-list-<?php print $uid; ?>" data-timeline-uid="<?php print $uid; ?>" class="button button-blue button-small">View as List</a>
  </div>
  <div id='timeline-embed-<?php print $uid; ?>' style="width: 100%; height: 600px" aria-hidden="true" role="presentation" tabindex="-1"></div>
</div>


<script type="text/javascript">
 var timeline_json = <?php print $json; ?>; // you write this part
 // two arguments: the id of the Timeline container (no '#')
 // and the JSON object or an instance of TL.TimelineConfig created from
 // a suitable JSON object

 var options = {
   hash_bookmark: true,
   scale_factor: <?php print $scale; ?>,
 }
 window.timeline = new TL.Timeline('timeline-embed-<?php print $uid; ?>', timeline_json, options);

// Link toggle between advanced timeline and list view.
 jQuery('.timeline-list-link a').toggle(function(){
    var t = jQuery(this).attr('data-timeline-uid');
    jQuery('#timeline-embed-' + t).hide();
    jQuery('#timeline-list-' + t).fadeIn();
    jQuery(this).text('View as Timeline');
    return false;
  }, function() {
    var t = jQuery(this).attr('data-timeline-uid');
    jQuery('#timeline-list-' + t).hide();
    jQuery('#timeline-embed-' + t).fadeIn();
    jQuery(this).text('View as List');
    return false;
  });

</script>

<div id="timeline-list-<?php print $uid; ?>" class="adv-timeline-list">
  <ol class="timeline-event-list">
    <?php
      foreach ($event_list as $event) {
        print '<li>' . $event . '</li>';
      }
    ?>
  </ol>
</div>
