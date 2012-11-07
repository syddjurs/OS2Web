/**
 * @author Thomas Thune Hansen <tth@bellcom.dk>
 * Bellcom Udvikling ApS
 **/


/**
 * function used to create a <select> element from an <ul>
 * <option> are populated with values corresponding to <li><a href />
 **/
(function($) {
  $('ul.sb-list').each(function(){
  var list=$(this),
  select=$(document.createElement('select')).addClass('sb-select').insertBefore($(this).hide());
  $('>li a', this).each(function(){
        var target=$(this).attr('target'),
        option=$(document.createElement('option'))
          .appendTo(select)
          .val(this.href)
          .html($(this).html())
    });
    list.remove();
  });
})(jQuery);

/**
 * function redirects the user to the url specified in <option> value
 * triggers on 
 *    keydown - 'enter'
 *    option.click
 **/
(function($) {
  $('.sb-select').keydown(function(e) {
    if (e.keyCode == 13) {
      window.location.href = $(this).val();
    }
  });

  $('.sb-select option').click(function(e) {
    window.location.href = $(this).val();
  });

})(jQuery);

/**
 * add yaselect stuff to <selects>
 * */
(function($) {
  jQuery('#edit-committee').yaselect();
  jQuery('.sb-select').yaselect();
})(jQuery);


