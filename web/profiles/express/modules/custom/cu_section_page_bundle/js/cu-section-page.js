(function( $ ){
  $(document).ready(function(){
    var sections = $('.section-page-sections .block-section').length;

    var section_nav;
    // Add section navigation.
    $('.section-page-navigation-active .section-page-sections').prepend('<div class="section-page-nav"><ul></ul</div>');

    // Add animation class.
    // $('.section-page-sections .block-section:not(:first) .block-section-content').addClass('animated');

    // Build section navigation.
    $('.section-page-sections .block-section').each(function(i){
      var item = i +1;
      var target = $(this).attr('id');
      var link = '<li><a href="#' + target + '" id="section-nav-id-' + target +'"><i class="fa fa-circle"></i><span class="element-invisible">' + item + '</span></li>';
      $('.section-page-navigation-active .section-page-nav ul').append(link);

      // Add anchors for each section
      $('<a name="' + i + '" name="' + i + '" id="section-anchor-' + target +'">').insertBefore(this);

      // Add a tabindex so we can focus user to sections
      $(this).attr('tabindex','-1');
      // Add waypoints for highlighting what section is currently in view.
      $(this).waypoint(function(direction) {
         // Highlight element when related content
         // is 100px from the bottom...
         // remove if below
         var id = $(this).attr('id');
         //sectionPageActive(id);
         $(this).toggleClass('active', direction === 'down');
         var id = $(this).attr('id');
         sectionPageActive(id);
         // $('.block-section-content', this).addClass('fadeIn');
       }, {
         offset: 80 //
       })
       .waypoint(function(direction) {
         var id = $(this).attr('id');
         // Highlight element when bottom of related content
         // is 100px from the top - remove if less
         // TODO - make function for this
         $(this).toggleClass('active', direction === 'up');
         var id = $(this).attr('id');
         sectionPageActive(id);
       }, {
         offset: function() {  return -$(this).height() + 80; }
       });
       // $('.section-page-sections .block-section-content:first').addClass('fadeIn');
    });
    $('.section-page-navigation-active .section-page-sections .block-section:not(:last)').each(function(i){
      // Next.
      var next = '<div class="section-next-wrapper"><div class="section-next"><i class="fa fa-angle-down"></i></div></div>';
      $(this).append(next);
    });
    $('.section-next').click(function(event){
      event.preventDefault();

      var nextSection = $(this).parents('.contextual-links-region').next();
      var target = $('.block-section:first', nextSection).attr('id');
      // Scroll to section.
      $('html, body').animate({
        scrollTop: $('#' + target).offset().top
      }, 1000, function() {
        $(target).focus();
      });

    });

    // Sticky navigation
    $('.layout-wide .section-page-navigation-wrapper').waypoint({
      handler: function(e, d) {
        $('.section-page-section-navigation').toggleClass('sticky').css('top', $('#sticky-menu').outerHeight());
      },
      offset: function() {
        var sticky = $('#sticky-menu');
        return ($('#sticky-menu').outerHeight());
      }
    });

    $('.layout-boxed .section-page-navigation-wrapper').waypoint({
      handler: function(e, d) {
        $('.section-page-navigation-wrapper').toggleClass('sticky').css('top', $('#sticky-menu').outerHeight());;
      },
      offset: function() {
        var sticky = $('#sticky-menu');
        return ($('#sticky-menu').outerHeight());
      }
    });

    // Add click events to section navigation.
    $('.section-page-nav a, .section-page-section-navigation ul  a').click(function(event){
      event.preventDefault();
      var target = $(this).attr('href');
      // Scroll to section.
      $('html, body').animate({
        scrollTop: $(target).offset().top
      }, 2000, function() {
        $(target).focus();
      });
    });


    $('#section-page-section-navigation-expand').click(function(event){
      event.preventDefault();
      $('.section-page-section-navigation ul').slideToggle();
      $('i.fa', this).toggleClass('fa-reorder').toggleClass('fa-times');
      if ($(this).attr('aria-expanded') == 'true') {
        $(this).attr('aria-expanded', 'false');
      } else {
        $(this).attr('aria-expanded', 'true');
      }
    });

    // Set active section for section navigation

    function sectionPageActive(id) {
      $('.section-page-nav i.fa').removeClass('fa-circle-o').addClass('fa-circle');
      $('i.fa', '#section-nav-id-' + id).removeClass('fa-circle').addClass('fa-circle-o');

      $('.section-page-section-navigation a').removeClass('active-section');
      $('a#top-section-nav-' + id).addClass('active-section');

      // Update url to add which section is being viewed.
      var section = $('#section-anchor-' + id).attr('name');
      var url = [location.protocol, '//', location.host, location.pathname].join('')

      // Removing push state because of tracking pixel issues.
      //history.pushState('', document.title, url + '#' + section);
    }

  });
})( jQuery );
