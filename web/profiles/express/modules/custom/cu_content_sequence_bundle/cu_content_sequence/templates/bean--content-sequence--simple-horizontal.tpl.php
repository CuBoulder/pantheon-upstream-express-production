<?php if (isset($timeline_title)): ?>
  <h2><?php print $timeline_title; ?></h2>
<?php endif; ?>
<div class="simple-horizontal-timeline-wrapper">
  <div class="timeline-list-link">
    <a href="#" data-timeline-uid="<?php print $uid; ?>">View As List</a>
  </div>
  <div class="cd-horizontal-timeline" id="timeline-embed-<?php print $uid; ?>">
  	<div class="timeline">
  		<div class="events-wrapper">
  			<div class="events">
  				<ol>
            <?php
              foreach ($events_data['events'] as $key => $event) {
                print '<li><a href="#' . $event['data_index'] . '" data-date="' . $event['data_index'] . '">' . $event['label'] . '</a></li>';
              }
            ?>
  				</ol>
  				<span class="filling-line" aria-hidden="true"></span>
  			</div> <!-- .events -->
  		</div> <!-- .events-wrapper -->

  		<ul class="cd-timeline-navigation">
  			<li><a href="#" class="prev inactive"><i class="fa fa-chevron-circle-left"></i><span class="element-invisible">Previous</span></a></li>
  			<li><a href="#" class="next"><i class="fa fa-chevron-circle-right"></i><span class="element-invisible">Next</span></a></li>
  		</ul> <!-- .cd-timeline-navigation -->
  	</div> <!-- .timeline -->

  	<div class="events-content">
  		<ol>
        <?php $count=0; foreach ($event_list as $item): ?>
          <?php
          $count++;
            $index = str_pad($count, 4, "0", STR_PAD_LEFT);
            $data_date = $index;
          ?>
  				<li class="timeline-single-item" data-date="<?php print $data_date; ?>">
  					<div class="timeline-item-wrapper">
              <?php print render($item); ?>
            </div>
  				</li>
  			<?php endforeach; ?>
  		</ol>
  	</div> <!-- .events-content -->
    <div class="cd-timeline-item-navigation-wrapper">
      <ul class="cd-timeline-item-navigation">
        <li><a href="#0" class="prev inactive"><i class="fa fa-chevron-left"></i><span class="element-invisible">Previous</span></a></li>
        <li><a href="#0" class="next"><i class="fa fa-chevron-right"></i><span class="element-invisible">Next</span></a></li>
      </ul>
    </div>
  </div>
</div>




<div id="timeline-list-<?php print $uid; ?>" class="adv-timeline-list">
  <ol class="timeline-event-list">
    <?php
      foreach ($event_list as $event) {
        print '<li>' . $event . '</li>';
      }
    ?>
  </ol>
</div>

<script type="text/javascript">
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
