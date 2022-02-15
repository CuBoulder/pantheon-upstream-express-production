<?php

/**
 * @file
 * Functions to help display nested taxanomy terms in the filter forms on .
 */

/**
 * Build a nested array from a taxonomy tree.
 */
function &people_content_type_taxonomy_treedata(&$nvocs) {
  // This function will take a flat vocabulary tree and turn it into a multi-tiered array.
  // The return array will simply contain an array of pointers rather then physical objects.

  $map = array();

  // Go through the tree and find the lowest depth aswell as all available depth levels to scan.
  $startdepth = FALSE;
  $depthlist = array();
  foreach ($nvocs as &$vocitem) {
    if ($startdepth === FALSE || $startdepth > $vocitem->depth) {
      // New start depth found.
      $startdepth = $vocitem->depth;
    }

    // Add this item to the speciffic depth level.
    $depthlist[$vocitem->depth][$vocitem->tid] = &$vocitem;
  }

  // Sort the depthlist so lowest is first.
  ksort($depthlist);

  // Scan all depth levels found.
  foreach ($depthlist as $depthlevel => &$depths) {
    // Check for first depth (root) level.
    $currentdepthdata = array();

    if ($depthlevel == $startdepth) {
      // Add root items to the map.
      foreach ($depths as $itemindex => &$item) {
        $mapindex = count($map);
        $map[$mapindex] = array("data" => &$item, "children" => array());
        $currentdepthdata[$itemindex] = &$map[$mapindex];
      }
    }
    else {
      // Scan through all items within this depth.
      foreach ($depths as $itemindex => &$item) {
        // Find a matching "map" in the last depth to assign the item too.
        foreach ($item->parents as $parentindex) {
          $mapindex = count($lastdepthdata[$parentindex]["children"]);
          $lastdepthdata[$parentindex]["children"][$mapindex] = array(
            "data" => &$item,
            "children" => array()
          );
          $currentdepthdata[$itemindex] = &$lastdepthdata[$parentindex]["children"][$mapindex];
        }
      }
    }

    $lastdepthdata = $currentdepthdata;
  }

  return $map;
}

/**
 * Build a nested select options list.
 */
function people_content_type_nested_options($terms) {
  $options = array();
  uasort($terms, 'people_content_type_sort');
  foreach ($terms as $term) {
    // Use depth to add - to denote children terms.
    $indent = people_content_type_term_depth($term['data']->depth);
    // Load full term so we can tell if term should be hidden or not.
    $term_full = taxonomy_term_load($term['data']->tid);
    // Term display field is different in catagory and tag.
    if (!empty($term_full->field_tag_display)) {
      if ($term_full->field_tag_display[LANGUAGE_NONE][0]['value'] == 'show') {
        $options[$term['data']->tid] = $indent . ' ' . $term['data']->name;
        if (!empty($term['children'])) {
          $nested = people_content_type_nested_options($term['children']);
          $options = $options + $nested;
        }
      }
    }
    elseif (!empty($term_full->field_category_display)) {
      if ($term_full->field_category_display[LANGUAGE_NONE][0]['value'] == 'show') {
        $options[$term['data']->tid] = $indent . ' ' . $term['data']->name;
        if (!empty($term['children'])) {
          $nested = people_content_type_nested_options($term['children']);
          $options = $options + $nested;
        }
      }
    }
    else {
      $options[$term['data']->tid] = $indent . ' ' . $term['data']->name;
      if (!empty($term['children'])) {
        $nested = people_content_type_nested_options($term['children']);
        $options = $options + $nested;
      }
    }
  }
  return $options;
}

/**
 * Returns - to denote children.
 */
function people_content_type_term_depth($depth = 0) {
  $indent = '';
  for ($i = 0; $i < $depth; $i++) {
    $indent = $indent . '-';
  }
  return $indent;
}

/**
 * Sort function for terms array.
 */
function people_content_type_sort($comparisonA, $comparisonB) {
  $termA = $comparisonA['data']->name;
  $termB = $comparisonB['data']->name;
  if ($termA == $termB) {
    return 0;
  }
  return ($termA < $termB) ? -1 : 1;
}
