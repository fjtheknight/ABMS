<?php
echo "
       <!DOCTYPE html>
<html>
<head>
<script type='text/javascript' src='/js/lib/jquery-1.8.3.min.js'></script>
<!--[if lte IE 8]><script language='javascript' type='text/javascript' src='/js/flot/excanvas.min.js'></script><![endif]-->
  <script src='https://cdnjs.cloudflare.com/ajax/libs/jquery/2.1.3/jquery.js'></script>
    <script src='https://cdnjs.cloudflare.com/ajax/libs/flot/0.8.3/jquery.flot.js'></script>
    <script src='https://cdnjs.cloudflare.com/ajax/libs/flot/0.8.3/jquery.flot.pie.js'></script>
    <script src='https://cdnjs.cloudflare.com/ajax/libs/flot/0.8.3/jquery.flot.resize.js'></script>
        <script src='https://cdnjs.cloudflare.com/ajax/libs/flot/0.8.3/jquery.flot.stack.js'></script>

    <script src=' http://www.benjaminbuffet.com/public/js/jquery.flot.orderBars.js'></script>
    <script src='https://cdnjs.cloudflare.com/ajax/libs/flot/0.8.3/jquery.flot.categories.js'></script>
    <script src='https://raw.githubusercontent.com/winne27/flot-valuelabels/master/jquery.flot.valuelabels.js'></script>
<script>
//******* 2012 Average Temperature - BAR CHART
var data = [    
    [0, 1.47], //London, UK
    [1, 0.49], //New York, USA
    [2, 0.98], //New Delhi, India
    [3, 2.94], //Taipei, Taiwan
    [4, 1.06], //Beijing, China
    [5, 1.55],  //Sydney, AU
    [6, 0.98],
    [7, 3.18],
    [8, 0.73],
    [9, 0.49],
    [10, 1.71],
    [11, 9.71],
    [12, 57.91],
    [13, 22.51],
    [14, 80.42],
    [15, 6.93],
    [16, 93.07]
];

var dataset = [
    { label: '% coût de production', data: data, color: '#5482FF' }
];

var ticks = [
    [0, 'Dotation aux amortissement'], [1, 'Frais Financiers'], [2, 'Autres charges de structure'], [3, 'Total charges de structure'],
    [4, 'Chauffage'], [5, 'Frais vétérinaires'], [6, 'Désinfection'], [7, 'Eau Electricité'], [8, 'Cotisation Taxes'], [9, 'Enlèvement animaux'],
    [10, 'Litière Enlèvement fumier'], [11, 'Total charges variables'], [12, 'Aliment'], [13, 'Poussins'], [14, 'Total Aliment Poussin']
    , [15, 'Rém. travail'], [16, 'Coût de production (hors rémunération)']
];


var options = {
    series: {
        bars: {
            show: true
        }
    },
    bars: {
        align: 'center',
        barWidth: 0.5
    },
    xaxis: {
        axisLabel: 'World Cities',
        axisLabelUseCanvas: true,
        axisLabelFontSizePixels: 12,
        axisLabelFontFamily: 'Verdana, Arial',
        axisLabelPadding: 10,
        ticks: ticks
        
    },
    yaxis: {
        axisLabel: 'Average Temperature',
        axisLabelUseCanvas: true,
        axisLabelFontSizePixels: 12,
        axisLabelFontFamily: 'Verdana, Arial',
        axisLabelPadding: 3,
        tickFormatter: function (v, axis) {
            return v + ' %';
        }   },
    legend: {
        noColumns: 0,
        labelBoxBorderColor: '#000000',
        position: 'nw'
    },
    grid: {
        hoverable: true,
        borderWidth: 2,        
        backgroundColor: { colors: ['#ffffff', '#EDF5FF'] }
    }
};

$(document).ready(function () {
    $.plot($('#flot-placeholder'), dataset, options);    
    $('#flot-placeholder').UseTooltip();
});


</script>
<!-- HTML -->
</head>
<body>
<div id='flot-placeholder' style='width:1100px;height:500px;margin:20 auto'></div>

</body>
         </html>
 "


?>