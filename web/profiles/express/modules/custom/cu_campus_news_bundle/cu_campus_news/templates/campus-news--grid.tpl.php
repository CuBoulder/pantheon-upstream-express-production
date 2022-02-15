<div class="article-view-mode-grid col-lg-4 col-md-4 col-sm-6 col-xs-12">
  <?php if(!empty($thumbnail)): ?>
    <?php print $thumbnail; ?>
  <?php else: ?>
    <a href="<?php print variable_get('cu_campus_news_url', 'http://www.colorado.edu/today'); ?>/node/<?php print $nid; ?>"><img src="<?php print cu_campus_news_placeholder_img('600'); ?>" alt /></a>
  <?php endif; ?>
  <h3><?php print $title; ?></h3>
  <div class="article-grid-summary"><?php print $body; ?></div>
</div>
