<?php
  $custom_logo = array();
  // Load logo files
  if (variable_get('cu_custom_white_logo', NULL) && variable_get('cu_custom_black_logo', NULL)) {
    $custom_logo = array(
      'white' => file_load(variable_get('cu_custom_white_logo')),
      'black' => file_load(variable_get('cu_custom_black_logo')),
    );
    // Create img markup
    $custom_logo['white']->markup = '<img class="cu-custom-logo custom-logo-white" src="' . file_create_url($custom_logo['white']->uri) . '" alt="' . check_plain($site_name) . ' logo" />';
    $custom_logo['black']->markup = '<img class="cu-custom-logo custom-logo-black" src="' . file_create_url($custom_logo['black']->uri) . '" alt="' . check_plain($site_name) . ' logo" />';
  }
?>
<?php if (!empty($custom_logo)):?>
  <<?php print $site_name_tag; ?> class="site-name">
    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="custom-logo-black" rel="home"><span><?php print $custom_logo['black']->markup; ?></span></a>
    <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="custom-logo-white" rel="home"><span><?php print $custom_logo['white']->markup; ?></span></a>
  </<?php print $site_name_tag; ?>>
<?php else: ?>

  <?php if ($site_name): ?>
    <<?php print $site_name_tag; ?> class="site-name">
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="header__site-link" rel="home"><span><?php print $site_name; ?></span></a>
    </<?php print $site_name_tag; ?>>
  <?php endif; ?>
<?php endif; ?>
<?php
  // Get affilation saved settings.
  // Get site_type - we have some specific affilation rules based on this value.
  $site_type = variable_get('express_site_type', NULL);
  // Check to see if affiliations are enabled. If not this won't display.
  $affilation_enable = variable_get('cu_affiliation_enable', 0);
  // Get the site affiliation setting from cu_core.module.
  $affiliation = variable_get('cu_site_affiliation_options', NULL);
  // Null title and url.
  $affiliation_title = NULL;
  $affilation_url = NULL;

  // Set the $affiliation_title and $affilation_url vars so we can make text/link.

  // Check to see if we have affiation rules for site type.
  if ($site_type && ucb_affiliation($site_type)) {
    $affiliation = ucb_affiliation($site_type);
    $affiliation_title = $affiliation['label'];
    $affiliation_url = $affiliation['url'];
  }
  // Some sites may use the custom setting.
  elseif ($affiliation == 'custom') {
    $affiliation_title = variable_get('express_site_affiliation_title', NULL);
    $affiliation_url = variable_get('express_site_affiliation_url', NULL);
  }
  // If a site still has an affiliation set we will pass that value to the cu_core
  // function to get the set label and url.
  elseif (!empty($affiliation)) {
    $affiliation = cu_core_site_affiliation_options($affiliation);
    $affiliation_title = $affiliation['label'];
    $affiliation_url = $affiliation['url'];
  }
?>

<?php
  // If affiliations are enabled and the affiliation is set, create element and
  // add text and link if necessary.
  if ($affilation_enable && $affiliation):
?>
  <div class="affiliation">
    <?php
      // If there's only a label we just output the text.
      if ($affiliation_title && !$affiliation_url) {
        print $affiliation_title;
      }
      // If there is also a url, we will link the label to that url.
      elseif ($affiliation_title && $affiliation_url) {
        print l($affiliation_title, $affiliation_url, array('html' => TRUE));
      }
    ?>
  </div>
<?php endif; ?>
<div id="print-site-name"><?php print check_plain($site_name); ?></div>
