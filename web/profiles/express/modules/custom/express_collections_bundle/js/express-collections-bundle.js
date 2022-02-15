(function ($) {
  $(document).ready(function(){
    $(".bean-collection-grid .expand-trigger").each(function(i){
      var trigger = $(this).attr('href');
      var trigger2 = trigger + '-' + i;
      var target = trigger2.substring(1);
      $(this).attr('href', trigger2);
      $(this).next('.expand-content').attr('id', target);
    });
    $(".collection-items-categories").hide();

    $(".collection-filter-links button").click(function(){
      // Get the collection to operate on
      var collectionTarget = $(this).attr("data-collection");
      // Remove disabled class, aria from all items in collection
      $("#" + collectionTarget + " .collection-item").removeClass('collection-item-disabled').removeAttr('aria-hidden').removeAttr('role').removeClass('collection-item-active');
      // Get the collection category
      var target = $(this).attr("data-collection-category");
      history.pushState(null,null,'#' + target);
      // Apply disabled class, aria to all items not in category
      $('#' + collectionTarget + ' .collection-item').not('.collection-category-' + target).addClass('collection-item-disabled').attr('aria-hidden', 'true').attr('role', 'presentation');
      $('#' + collectionTarget + ' .collection-item.collection-category-' + target).addClass('collection-item-active');
      // Remove active class from category links
      $('#' + collectionTarget + ' .collection-filter-links button').removeClass('active');
      // Apply active class to the clicked link
      $(this).addClass('active');
      updateCollectionResults(collectionTarget);
      return false;
    });


    $('.collection-filter-links-multi-select input').change(function(){
      var collectionTarget = $(this).attr("data-collection");
      var filters = [];
      var breadcrumbs = [];
      var filterClasses;
      var type;
      // When a filter is changed, get all checked filters.
      $('#' + collectionTarget + ' .collection-filter-links-single.collection-filter-links-multi-select input:checkbox:checked').each(function () {
        filters.push('.collection-category-' + $(this).val());
        var label = $(this).next().text();
        breadcrumbs.push(label);
        type = 'multiple';
      });
      // When a filter is changed, display a breadcrumb of what was selected.
      $('#' + collectionTarget + ' .collection-filter-links-multi-select.collection-filter-links-multiple').each(function () {
        var $groups = $(this);
        $('input:checkbox:checked', $groups).each(function(){
          filters.push('.collection-category-' + $(this).val());
          var label = $(this).next().text();
          breadcrumbs.push(label);
          type = 'multiple';
        });
      });
      if (type == 'single') {
        filterClasses = filters.join(', ');
      }
      else if (type == 'multiple') {
        filterClasses = filters.join(', ');
        filterBreadcrumbs = breadcrumbs.join(', ');
      }
      if (filters.length == 0) {
        $('#' + collectionTarget + ' .collection-item').fadeIn();
        $('#' + collectionTarget + ' .collection-breadcrumbs').html('');
        $('.collection-breadcrumbs-wrapper .collection-reset').hide();
      }
      else {
        $('#' + collectionTarget + ' .collection-item').hide();
        //$(filterClasses).fadeIn();
        $('#' + collectionTarget + ' .collection-item' + filterClasses).fadeIn();
        $('#' + collectionTarget + ' .collection-breadcrumbs').html('<strong>Selected filters:</strong> ' + filterBreadcrumbs);
        $('.collection-breadcrumbs-wrapper .collection-reset').show();
      }
      $(this).parent().toggleClass('active');
      updateCollectionResults(collectionTarget, 'multiple');
    });
    $('.collection-reset').click(function(){
      var collectionTarget = $(this).attr("data-collection");
      $('#' + collectionTarget + ' .collection-item').fadeIn();
      $('#' + collectionTarget + ' .collection-breadcrumbs').html('');
      $('#' + collectionTarget + ' input:checkbox').prop( "checked", false );
      $('.collection-breadcrumbs-wrapper .collection-reset').hide();
      updateCollectionResults(collectionTarget, 'multiple');
      return false;
    });
    // Collection ALL link
    $("button.collection-filter-clear").click(function(){
      // Get the collection to operate on
      var collectionTarget = $(this).attr("data-collection");
      // Remove disabled class, aria from all items in collection
      $("#" + collectionTarget + " .collection-item").removeClass('collection-item-disabled').removeAttr('aria-hidden').removeAttr('role').addClass('collection-item-active');
      // Remove active class from category links
      $("ul.collection-items-navigation a").removeClass('active');
      // Apply active class to the clicked link
      $(this).addClass('active');
      updateCollectionResults(collectionTarget);
      return false;
    });

    $('.collection-filter-links-multiple h3.collection-filter-label a').click(function(event){
      event.preventDefault();
      var link = $(this);
      if ($(this).attr('aria-expanded') == 'true') {
        $('.collection-filter-links').slideUp().parent().removeClass('expanded');
        $('h3.collection-filter-label a').attr('aria-expanded', 'false');
      }
      else {
        $('.collection-filter-links').slideUp().parent().removeClass('expanded');
        $('h3.collection-filter-label a').attr('aria-expanded', 'false');
        $(this).parent().next().slideDown().parent().addClass('expanded');
        $(this).attr('aria-expanded', 'true');

        setTimeout(function(){
            $('html, body').animate({
              scrollTop: $(link).offset().top - 100
            }, 500);
          }, 600);
      }
    });
    $('.collection-grid').each(function(){
      $('.collection-item', this).addClass('collection-item-active');
      var items = $('.collection-item-active', this).length;
      $('.collection-grid .results').text(items + ' items found.');
      $('.collection-filter-clear').addClass('active');

      // Check for hash
      if(window.location.hash) {
        var $hash = window.location.hash;
        if ( $("button[data-collection-category-hash='" + $hash + "']", this).length ) {
          $("button[data-collection-category-hash='" + $hash + "']").click();
        }
      }

    });



    // UPdate the items found in a collection grid.
    function updateCollectionResults(collectionId, type) {

      $('#' + collectionId + ' .collection-item').removeAttr('tabindex');
      var items = $('#' + collectionId + ' .collection-item-active').length;
      if (type == 'multiple') {
        $('#' + collectionId + ' .results').text(items + ' items found.');
      }
      else {
        $('#' + collectionId + ' .results').text(items + ' items found.').attr('tabindex','-1').focus();
      }
      $('.element-item').removeAttr('tabindex');
      $('#' + collectionId + ' .collection-item-active').attr('tabindex',0);

    }
  });
})(jQuery);
