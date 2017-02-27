'use strict';

/*
 * A Design by GraphBerry
 * Author: GraphBerry
 * Author URL: http://graphberry.com
 * License: http://graphberry.com/pages/license
 */

// Open offsite navigation.
$('#nav-expander').on('click', function (e) {
    e.preventDefault();
    $('nav').toggleClass('nav-expanded');
});

// Close offsite navigation.
$('.menu .close').on('click', function (e) {
    e.preventDefault();
    $('nav').toggleClass('nav-expanded');
});

// Close offsite navigation after user click on an link in navigation.
$('.menu  a').on('click', function (e) {
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
            url: '/' + itemId + '/ShortDetails/',
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

function DecodeBtn_Click(type) {
    var textArea = $("#TextAreaCoded")[0].value;
    var plainText = $("#TextAreaPlain")[0].value;
    var key = $("#InputKey")[0].value;
    var dataToSend = {
        text: textArea, plainText: plainText, key: key
    };

    var url = '/' + type + '/Decode/';
    var resultElement = $('#TextAreaDecoded')[0];
    getCode(url, dataToSend, resultElement);
};

function EncodeBtn_Click(type) {
    var textArea = $("#TextAreaPlain")[0].value;
    var dataToSend = { value: textArea };

    var url = "/" + type + "/Encode/";
    var resultElement = $('#TextAreaEncodec')[0];

    var success = function (content) {
        var arr = content.split("$");
        if (arr.length > 1) {
            resultElement.value = arr[0];
            $("#Key")[0].value = arr[1];
        }
        else {
            resultElement.value = content;
        }
    };

    getCode(url, dataToSend, resultElement, success);
};

function getCode(url, data, resultElement, success) {
    success = success || function (content) {
        resultElement.value = content;
    };

    $.ajax({
        url: url,
        type: 'POST',
        contentType: 'application/json',
        data: JSON.stringify(data),
        //data: JSON.stringify(model),
        success: success,
        error: function (e) {
        }
    });
}

function convertTableToArray() {
    var matrix = [];

    $("table#matrix tr").each(function () {
        var arrayOfThisRow = [];
        var tableData = $(this).find('td');
        if (tableData.length > 0) {
            tableData.each(function () {
                var val = $(this).find('input').val();
                arrayOfThisRow.push(val);
            });
            matrix.push(arrayOfThisRow);
        }
    });

    return matrix;
};

function hammingDecode() {
    var r = $('#inputR').val();
    var y = $('#Yinput').val();
    var resultElement = $('#YResult')[0];

    var success = function (content) {
        resultElement.value = content.split(";");
    };

    var url = "/Hemming/Decode/";
    var dataToSend = { r: r, y: y };
    getCode(url, dataToSend, resultElement, success);
}

function meggitDecode() {
    var length = $('#length').val();
    var vector = $('#vector').val();
    var yInput = $('#yInput').val();
    var resultElement = $('#YResult')[0];

    var success = function (content) {
        resultElement.value = content.split(";");
    };

    var url = "/Meggitt/Decode/";
    var dataToSend = { n: length, data: vector, yInput: yInput };
    getCode(url, dataToSend, resultElement, success);
}

function reedMuller(method, r, m, y, success, resultElement) {
    var url = "/ReedMuller/" + method + "/";
    var dataToSend = { r: r, m: m, input: y };
    getCode(url, dataToSend, resultElement, success);
}

function reedMullerEncode() {
    var r = $('#R').val();
    var m = $('#M').val();
    var y = $('#Y').val();

    var resultElement = $('#Youtput')[0];

    var success = function (content) {
        resultElement.value = content.split(";");
    };

    reedMuller('Encode', r, m, y, success, resultElement);
}

function reedMullerDecode() {
    var r = $('#R1').val();
    var m = $('#M1').val();
    var y = $('#Y1').val();

    var resultElement = $('#Youtput1')[0];

    var success = function (content) {
        resultElement.value = content.split(";");
    };

    reedMuller('Decode', r, m, y, success, resultElement);
}

function syndromDecode() {
    var h = convertTableToArray();
    var n = $('#cols').val();
    var m = $('#rows').val();
    var d = $('#minimalLength').val();
    var y = $('#Yinput').val();

    var resultElement = $('#Youtput')[0];

    var success = function (content) {
        resultElement.value = content.split(";");
    };

    var url = "/SystematicallyDecoding/Decode/";
    var dataToSend = { n: n, m: m, minimalLength: d, yInput: y, matrix: h };
    getCode(url, dataToSend, resultElement, success);
}

function matrixCode(type) {
    debugger;

    var matrix = convertTableToArray();

    var n = $('#cols').val();
    var m = $('#rows').val();

    var success = {};

    var url = "/" + type + '/Encode/';
    var resultElement = $('#LinearResult')[0];
    var resultSystematicForm = $("#SystematicForm")[0];

    if (type == "LinearCodes") {
        success = function (content) {
            resultElement.value = content.split(";");
        };
    }

    if (type == "SystematicForm") {
        success = function (content) {
            resultSystematicForm.value = content;
        };
    }

    var dataToSend = { n: n, m: m, matrix: matrix };

    getCode(url, dataToSend, resultElement, success);
}
