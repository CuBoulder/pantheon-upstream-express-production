<?php $tag = isset($heading_tag['#tag']) ? $heading_tag['#tag'] : 'h3'; ?>
<div class="article-view-mode-feature node-view-mode-feature clearfix">
  <?php if(!empty($thumbnail)): ?>
    <?php print $thumbnail; ?>
  <?php else: ?>
    <a href="<?php print variable_get('cu_campus_news_url', 'http://www.colorado.edu/today'); ?>/node/<?php print $nid; ?>"><img src="<?php print cu_campus_news_placeholder_img('800'); ?>" alt /></a>
  <?php endif; ?>
  <div class="article-view-mode-feature-content node-view-mode-feature-content">
    <<?php print $tag; ?>><?php print $title; ?></<?php print $tag; ?>>
    <div class="article-summary"><?php print $body; ?></div>

  </div>
</div>
