<div id="video-hero-<?php print $bid; ?>" class="fitvidsignore video-hero-unit <?php print $hero_classes; ?>" data-video-hero="video-hero-<?php print $bid; ?>" data-video-hero-iframe="video-hero-iframe-<?php print $bid; ?>" data-video-hero-id="<?php print $bid; ?>">
  <script src="https://player.vimeo.com/api/player.js"></script>


  <?php if ($content['field_hero_video_overlay'][0]['#markup']): ?>
    <div class="video-hero-overlay"></div>
  <?php endif; ?>
  <div class="video-hero-poster-frame"></div>
  <div class="video-hero-content-wrapper">
    <div class="video-hero-content">
      <h2><?php print render($content['field_hero_unit_headline']); ?></h2>
      <?php if(!empty($content['field_hero_unit_text'])): ?>
        <p class="video-hero-text"><?php print render($content['field_hero_unit_text']); ?></p>
      <?php endif; ?>
      <?php if(!empty($content['field_hero_unit_link'])): ?>
        <div class="hero-unit-links clearfix"><?php print render($content['field_hero_unit_link']); ?></div>
      <?php endif; ?>
    </div>
  </div>

  <iframe id="video-hero-iframe-<?php print $bid; ?>" class="video-hero-iframe"  frameborder="0" src="<?php print $video_url; ?>?background=1&loop=1" width="" height="" data-fullscreeneo="true"></iframe>

  <div class="video-hero-controls-wrapper">
  	<div class="video-hero-controls">
  		<div class="button-play" title="Play/Pause video"><i class="fa fa-pause"></i></div>
  	</div>
  </div>
</div>

<?php if(!empty($content['field_hero_unit_image'])): ?>
  <style>
    #video-hero-<?php print $bid; ?> .video-hero-poster-frame {
      background-image:url(<?php print $image_small; ?>);
    }
    @media all and (min-width: 768px) and (max-width: 959px) {
      #video-hero-<?php print $bid; ?> .video-hero-poster-frame {
        background-image:url(<?php print $image_medium; ?>);
      }
    }
    @media all and (min-width: 960px) {
      #video-hero-<?php print $bid; ?> .video-hero-poster-frame {
        background-image:url(<?php print $image_large; ?>);
      }
    }
  </style>
<?php endif; ?>
