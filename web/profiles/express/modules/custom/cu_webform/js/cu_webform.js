(function ($) {
  $(document).ready(function(){
    $('form.webform-client-form').submit(function( event ) {
      $('input.webform-submit', this).prop("disabled",true);
    });
  });
}(jQuery));
