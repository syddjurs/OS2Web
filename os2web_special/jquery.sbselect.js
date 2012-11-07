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
(function($) {
  jQuery('#edit-committee').yaselect();
  jQuery('.sb-select').yaselect();
})(jQuery);


