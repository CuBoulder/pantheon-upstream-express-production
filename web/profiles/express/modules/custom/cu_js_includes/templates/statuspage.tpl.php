<?php

/**
 * @file
 * Template for StatusPage include.
 */
?>
<!-- Required for IE11 Only -->
<script src="https://cdn.polyfill.io/v2/polyfill.min.js"></script>
<!-- Standard dependencies -->
<script src="https://unpkg.com/@webcomponents/webcomponentsjs@2.1.3/webcomponents-bundle.js"></script>
<script src="https://unpkg.com/@statuspage/status-widget/dist/index.js"></script>
<statuspage-widget src="<?php print check_plain($statuspage_url); ?>"></statuspage-widget>
