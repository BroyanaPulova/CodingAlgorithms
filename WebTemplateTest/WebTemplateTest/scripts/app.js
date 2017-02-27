'use strict';

/*
 * A Design by GraphBerry
 * Author: GraphBerry
 * Author URL: http://graphberry.com
 * License: http://graphberry.com/pages/license
 */

// Open offsite navigation.
$('#nav-expander').on('click', function(e) {
    e.preventDefault();
    $('nav').toggleClass('nav-expanded');
});

// Close offsite navigation.
$('.menu .close').on('click', function(e) {
    e.preventDefault();
    $('nav').toggleClass('nav-expanded');
});

// Close offsite navigation after user click on an link in navigation.
$('.menu  a').on('click', function(e) {
    e.preventDefault();
    $('nav').removeClass('nav-expanded');
});


//Calculate full with of jumbotron.
function homeFullScreen() {

    var homeSection = $('.home');
    var windowHeight = $(window).outerHeight();

    if (homeSection.hasClass('home-fullscreen')) {

        $('.home-fullscreen').css('height', windowHeight);
    }
}

//Load details of single project from portfolio.
function openProject() {

    var portfolioItem = $('.portfolio-item  i');
    var singleProject = $('#single-project');
    
    portfolioItem.click(function () {
        debugger;
        var itemId = this.id;
        $('html, body').animate({
            scrollTop: singleProject.offset().top - 70
        }, 500);

        singleProject.empty();
        $.ajax({
            url: '/Index/' + itemId + '/',
            type: 'GET',
            contentType: 'application/html',
            //data: JSON.stringify(model),
            success: function (content) {
                $('#single-project').html(content);
            },
            error: function (e) {
                var t = e;
            }
        });

        
        //setTimeout(function () {
        //    debugger;
        //    var t = $(singleProject).load('@Url.ActionLink("Project","Controller")');
        //    singleProject.slideDown(500);

        //    var closeProject = $('#close-project');
        //    closeProject.on('click', function () {
        //        singleProject.slideUp(500);
        //        setTimeout(function () {

        //            singleProject.empty();
        //        }, 500);
        //    });

            //    singleProject.load(link, function (response, status) {
            //        if (status === "error") {
            //            alert("An error");
            //        } else {
            //            singleProject.slideDown(500);

            //            var closeProject = $('#close-project');
            //            closeProject.on('click', function () {
            //                singleProject.slideUp(500);
            //                setTimeout(function () {

            //                    singleProject.empty();
            //                }, 500);
            //            });
            //        }
            //    });
            //}, 500);
            return false;
        });
    }
//Initialization
$(window).load(function () {
    openProject();
    homeFullScreen();

    smoothScroll.init();
});


    //What happen on window resize
    $(window).resize(function () {
        homeFullScreen();
    });
