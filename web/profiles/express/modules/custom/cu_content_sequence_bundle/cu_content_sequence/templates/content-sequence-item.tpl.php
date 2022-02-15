<div class="adv-timeline-item timeline-item timeline-item-wrapper">
  <div class="timeline-content">


  <?php
    $date1 = NULL;
    if (isset($vars['start_date']['display_date'])) {
      $date1 = $vars['start_date']['display_date'];
    }
    elseif (!empty($vars['start_date']['month']) && !empty($vars['start_date']['day']) && !empty($vars['start_date']['year'])){
      $date1 = $vars['start_date']['month'] . '/' . $vars['start_date']['day'] . '/' . $vars['start_date']['year'];
    }

    $date2 = NULL;
    if (isset($vars['end_date']['display_date'])) {
      $date2 = $vars['end_date']['display_date'];
    }
    elseif (!empty($vars['end_date']['month']) && !empty($vars['end_date']['day']) && !empty($vars['end_date']['year'])){
      $date2 = $vars['end_date']['month'] . '/' . $vars['end_date']['day'] . '/' . $vars['end_date']['year'];
    }
    $dates = array();
    if ($date1) {
      $dates[] = $date1;
    }
    if ($date2) {
      $dates[] = $date2;
    }
  ?>

  <div class="timeline-item-top">
    <div class="timeline-item-header">
      <?php
        if (!empty($dates)) {
          print '<h3 class="timeline-item-date">' . join(' - ', $dates) . '</h3>';
          print '<h4 class="timeline-item-title">' . $vars['text']['headline'] . '</h4>';
        }
        else {
          print '<h3 class="timeline-item-title">' . $vars['text']['headline'] . '</h3>';
        }
      ?>
    </div>
    <div class="timeline-item-media">
      <?php if (!empty($vars['media']['url']) && $vars['media']['type'] == 'image'): ?>
        <img src="<?php print $vars['media']['url']; ?>" alt="<?php print $vars['media']['alt']; ?>"/>
      <?php endif; ?>
      <?php if (!empty($vars['media']['url']) && $vars['media']['type'] == 'video') {
        print $vars['media']['rendered'];
      }
      ?>
    </div>
  </div>




  <div class="timeline-item-body">
    <?php print $vars['text']['text']; ?>
  </div>
  </div>
</div>
