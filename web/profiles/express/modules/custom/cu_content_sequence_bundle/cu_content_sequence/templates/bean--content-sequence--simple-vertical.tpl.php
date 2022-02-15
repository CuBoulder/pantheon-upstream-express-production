<section class="cd-vertical-timeline">
  <?php if (isset($timeline_title)): ?>
    <h2><?php print $timeline_title; ?></h2>
  <?php endif; ?>
	<div class="events-content">
		<ol class="vertical-timeline-items clearfix">
			<?php foreach ($event_list as $item): ?>

				<li class="timeline-single-item">
					<?php print render($item); ?>
				</li>
			<?php endforeach; ?>
		</ol>
	</div> <!-- .events-content -->
</section>
