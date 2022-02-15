(function( $ ){
  $(document).ready(function(){
    $('.video-hero-unit').each(function(){

      var vars = {};
      var iframe = $('#' + $(this).data('video-hero-iframe'));
      var iframeID = '#' + $(this).data('video-hero-iframe');
      var id = $(this).data('video-hero-id');
      console.log(id);
      vars['player' + id] = new Vimeo.Player(iframe);

      // Play the video.
      vars['player' + id].play();
      // Wait for their to be progress and then fade out poster frame
      vars['player' + id].on('progress', function(data) {
        var videoheroID = $(this).data('video-hero-id');
        $('#video-hero-' + id + ' .video-hero-poster-frame').fadeOut();
        $('#video-hero-' + id).addClass('video-hero-playing');
      });
      $('#video-hero-' + id + ' .button-play').on('click', function() { videoHeroPlayPause(vars['player' + id], id); } );
    });
    // Size video on load
    fullscreenVideoHero();
    videoSize();
  });

  // Play/Pause controls
  function videoHeroPlayPause(player, id) {
    player.getPaused().then(function(paused) {
      if (paused) {
        player.play();
        $('#video-hero-' + id + ' .button-play').addClass('paused');
        $('#video-hero-' + id + ' .button-play').find('.fa-play').addClass('fa-pause').removeClass('fa-play');

      } else {
        player.pause();
        $('#video-hero-' + id + ' .button-play').removeClass('paused');
        $('#video-hero-' + id + ' .button-play').find('.fa-pause').removeClass('fa-pause').addClass('fa-play');
      }
    });
  }

  // Full Screen Video Hero
  function fullscreenVideoHero() {
    $('.video-hero-unit-size-full').each(function(){
      // Determine header size by calculating site of header + navigation
      var header = $('#header-wrapper').outerHeight() + $('#navigation-wrapper').outerHeight();
      $(this).css('min-height', 'calc(100vh - ' + header + 'px)');
    });
  }

  // Resize video hero units
  function videoSize() {
    $('.video-hero-unit').each(function(){
      var $wrapper = $(this);
      var $h = $wrapper.height();
      var $w = $wrapper.width();
      // console.log($w);
      // console.log($h);

      var dimensions = calculateAspectRatioFit(800, 450, $w, $h);
      //console.log(dimensions);
      $('iframe', $wrapper).css('width', dimensions['width']).css('height', dimensions['height']);

      var l = ($w - dimensions['width'])/2;
      var t = ($h - dimensions['height'])/2;
      //console.log(l);
      $('iframe', $wrapper).css('top', t).css('left', l);
    });
  }


  // Calculate aspect ratio/dimensions
  function calculateAspectRatioFit(srcWidth, srcHeight, maxWidth, maxHeight) {
    var ratio = Math.max(maxWidth / srcWidth, maxHeight / srcHeight);
    return { width: srcWidth*ratio, height: srcHeight*ratio };
 }

  // Size video on window resize
  $( window ).resize(function() {
    fullscreenVideoHero();
    videoSize();
  });
})( jQuery );
