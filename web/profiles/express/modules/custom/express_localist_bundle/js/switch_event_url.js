/**
 * @file
 * Replace the event URL links if they match certain patterns.
 */

(function ($) {
  Drupal.behaviors.swapLocalistURLs = {
    attach: function (context) {



      // Wait for Localist HTML to render.
      var tries = 0;
      var elementLoaded = setInterval(function() {
        tries++;
        if($(".localist-events").length > 0){
          clearInterval(elementLoaded);
          // Swap links.
          localistLinkSwapper();
        }
        else if (tries == 5) {
          clearInterval(elementLoaded);
        }
      },1000);

      function localistLinkSwapper() {
        // Get urls to match for swapping
        var bypassURLs = Drupal.settings.localist_bypass_urls;
        // Grab all event IDs from rendered output.
        $('li.le-event').each(function() {
          var eventItem = $(this);
          var eventUrl = $(this).data('website-url');
          // Find and replace all event links.
          // Step through bypass options
          $(bypassURLs).each(function(key, value){
            if (eventUrl.includes(value)) {
              // Image URL.
              $('.le-photo a, a.le-photo', eventItem).attr('href', eventUrl);
              // Details URL.
              $('a.view-event-details', eventItem).attr('href', eventUrl);
              // Title URL.
              $('.le-event-title a, a.le-event-title', eventItem).attr('href', eventUrl);
            }
          });

        });
      }
    }
  };

})(jQuery);
