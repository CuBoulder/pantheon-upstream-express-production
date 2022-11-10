<?php

/**
 * @file
 * Template for Mainstat chatbot include.
 */
?>
<script>
    window.admitHubBot = {
        botToken: "<?php print check_plain($account_id); ?>",
        collegeId: "<?php print check_plain($college_id); ?>"
    };
</script>
<script async src="https://webbot.mainstay.com/static/js/webchat.js"></script>
<link rel="stylesheet" type="text/css" href="https://webbot.mainstay.com/static/css/webchat.css">
