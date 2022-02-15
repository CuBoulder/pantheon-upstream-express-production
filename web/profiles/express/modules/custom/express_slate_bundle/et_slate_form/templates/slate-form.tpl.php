<div id="form_<?php print check_plain($variables['account_id']); ?>">Loading...</div>
<script>/*<![CDATA[*/
  var script = document.createElement('script');
  var div = jQuery('.field-item'),
    comment = div.contents().filter(function() {
      return this.nodeType === 8;
    }).get(0);

  if (typeof comment !== "undefined") {
    var options = comment.nodeValue.split(":");
    var optionsquery = '&sys:field:' + options[0] + '=' + options[1];
  } else {
    var optionsquery = '';
  }
  script.async = 1; script.src = 'https://<?php print check_plain($variables['slate_domain']); ?>/register/?id=<?php print check_plain($variables['account_id']); ?>&output=embed' + optionsquery + '&div=form_<?php print check_plain($variables['account_id']); ?>' + ((location.search.length > 1) ? '&' + location.search.substring(1) : ''); var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(script, s);
  /*]]>*/</script>
