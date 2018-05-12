$("[data-code]").each(function(i){
	var source = $(this).attr('data-code');
	$(this).text("Loading code from "+source);
	var target = $(this);
	$.get( source, function( data ) {
		data = data.replace(/[\u00A0-\u9999<>\&]/gim, function(i) {
   			return '&#'+i.charCodeAt(0)+';';
		});
		target.html(prettyPrintOne(data.replace(/\t/g, "    ")));
	});

});