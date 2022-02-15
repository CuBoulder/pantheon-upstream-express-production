<?php
  if (!empty($content['body']) || !empty($content_bottom)):
?>
<div class="section-page-body">
  <?php
    print render($content['body']);
  ?>
  <?php print render($content_bottom); ?>
</div>
<?php endif; ?>

<?php
  // Check to see if the section navigation has items and has the same number
  // of items as sections.
  //$var['field_section_page_navigation']['#items'][0]['value']
  if ($content['field_section_page_navigation']['#items'][0]['value'] && !empty($section_page_labels)):
?>
  <div class="section-page-navigation-wrapper">
    <div class="section-page-section-navigation">
      <a href="#" id="section-page-section-navigation-expand" aria-expanded="false">
        <i class="fa fa-reorder"></i>
      </a>
      <ul class="element-max-width-padding">

        <?php
          foreach ($section_page_labels as $key => $label) {
            print '<li><a href="#block-section-' . $key . '" id="top-section-nav-block-section-' . $key . '">' . $label . '</a></li>';
          }
        ?>
      </ul>
    </div>
  </div>
<?php endif; ?>
<div class="section-page-sections">
  <?php

    foreach ($content['field_section_page_sections']['#items'] as $key => $item): ?>
    <div class="contextual-links-region">

      <?php
        $delta = $content['field_section_page_sections']['#items'][$key]['entity']->delta;
        $path = "block/$delta/edit";

      ?>
      <?php
        if (drupal_valid_path($path)):
      ?>
        <div class="contextual-links-wrapper">
          <ul class="contextual-links">
            <li>
              <?php print l('Edit Section', $path, array('query' => array('destination' => current_path()))); ?>
            </li>
          </ul>
        </div>
      <?php endif; ?>
      <?php print render($content['field_section_page_sections'][$key]); ?>
      </div>
  <?php endforeach; ?>
  <?php //print render($content['field_section_page_sections']); ?>
</div>
