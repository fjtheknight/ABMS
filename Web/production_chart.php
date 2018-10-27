<?php

$username = "2269611_arduino"; 
$password = "2269611_arduino";  
$servername = "fdb5.your-hosting.net";
$database = "2269611_arduino";

// Create connection
$conn = mysqli_connect($servername, $username, $password);
mysqli_select_db($conn,$database);
// Check connection
if (!$conn) {
	die("Connection failed: " . mysqli_connect_error());
}

$parameter=$_GET["parameter"];
$date1=$_GET["date1"];
$date2=$_GET["date2"];
$param=0;
$label;
switch ($parameter) {

                case 'mortalite':
		$param=2;
                $label='Mortalité';
		break;
		case 'cons_aliment':
		$param=3;
                $label='Consommation d aliment';
                break;
		case 'cons_eau':
		$param=4;
                $label='Consommation d eau';
		break;
                case 'poids':
		$param=5;
                $label='Poids';
		break;
		
}

if ($param == 5 ){$Search="SELECT * from poidsnew"; 
}
else{$Search="SELECT * from production"; 
}

$Exec=mysqli_query($conn,$Search);


        
echo "
<!DOCTYPE html>
<html>
<head>
<!-- jQuery -->
  <script src='js/jquery.js'></script>
  <!-- Bootstrap Core JavaScript -->
  <script src='js/bootstrap.min.js'></script>
      <script src='js/html2canvas.js'></script>

 
  <!-- Flot Charts JavaScript -->
  <!--[if lte IE 8]><script src='js/excanvas.min.js'></script><![endif]-->
  <script src='js/plugins/flot/jquery.flot.js'></script>
  
    <script type='text/javascript' src='http://www.pureexample.com/js/flot/jquery.flot.min.js'></script>

	<title></title>
	<style type='text/css'>
#line-chart{
  min-height: 250px;
}
	</style>
</head>
<body>
 <h3 class='text-primary text-center'>
    
  </h3>
  <div id='saveme' style='background:white;width:100%'>
          <div class'row'>
    
            <div class='col-sm-6 text-center'>
               <label class='label label-success'>".$label."</label>
               <div id='line-chart' style='background:white'></div>
            </div>
    
    
          </div>


  <script type='text/javascript'>
 var options = {
            series: {
                lines: { show: true },
                points: {
                    radius: 2,
                    show: true
                }
                }
                ,
                 xaxis: {
                mode: 'time',
                timeformat: ' %0m/%0d'
            },
             grid: { 
      hoverable: true, 
      clickable: true 
    }
            ,colors: ['rgb(50,50,50)']
        };
        
  var data = [
";

$min = 5000;
      $max=-5000;
while($row=mysqli_fetch_array($Exec)){
	if ($param == 5){      $rowparam=$row[2];
      }else{      $rowparam=$row[$param];
      }
	$timestampcompare = strtotime($row[1]);
	$datecompare = date('Y-m-d', $timestampcompare);
        $timecompare = date('Hi', $timestampcompare);
        $id = $row[0];
      
	if($datecompare>=$date1 && $datecompare<=$date2){
        if ($rowparam<$min){$min=$rowparam;}
        if ($rowparam>$max){$max=$rowparam;}
      
      if (($param == 4)||($param == 3)){  echo "[".(1000*$timestampcompare).",".($rowparam/5000)."],";
      }else{     echo "[".(1000*$timestampcompare).",".$rowparam."],";
      }



        }
        }
echo "
   
    ]
    var dataset = [{label: '".$label."',data: data}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart'), dataset, options);
        });
    
   
</script>

  <script>
function doFunction () { 
 html2canvas($('#line-chart'), {
                onrendered: function (canvas) {
        var a = document.createElement('a');
        // toDataURL defaults to png, so we need to request a jpeg, then convert for file download.
        a.href = canvas.toDataURL('image/jpeg').replace('image/jpeg', 'image/octet-stream');
        a.download = '".$parameter.":".$date1."/".$date2.".jpg';
        a.click();
      }
            });
};
</script>
  </div>
    </br>
  <input id='clickMe' type='button' value='Créer une sauvegarde' onclick='doFunction();' />

  
</body>
</html>
";

	?>