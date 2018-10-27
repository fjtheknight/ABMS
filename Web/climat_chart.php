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
$date=$_GET["date"];
$param=0;
$label;
switch ($parameter) {
	case 'temperature':
		$param=2;
                $label='Température';
		break;
		case 'humidite':
		$param=3;
                $label='Humidité';
				break;
				case 'pression':
		$param=4;
                $label='Pression';
		break;
		case 'vitessedair':
		$param=5;
                $label='Vitesse d air';
		break;
                case 'intensitelumineuse':
		$param=6;
                $label='Intensité lumineuse';
		break;
                case 'niveauderefroidissement':
		$param=7;
                $label='Système de refroidissement';
		break;
                case 'niveaudechauffage':
		$param=8;
                $label='Système de chauffage';
		break;
	
	default:
$param=0;
		break;
}
$Search="SELECT * from climat2"; 
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
  <!-- Morris Charts JavaScript -->
  <script src='js/plugins/morris/raphael.min.js'></script>
  <script src='js/plugins/morris/morris.min.js'></script>
  <script src='js/plugins/morris/morris-data.js'></script>
  <!-- Flot Charts JavaScript -->
  <!--[if lte IE 8]><script src='js/excanvas.min.js'></script><![endif]-->
   <script type='text/javascript' src='http://www.pureexample.com/js/lib/jquery-1.8.3.min.js'></script>
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
  
  <div class'row' id='saveme' style='background:white;width:100%'>
    
    

";

$min = 5000;
      $max=-5000;
      $counter=0;
      
while($row=mysqli_fetch_array($Exec)){
	
	$timestampcompare = strtotime($row[1]);
	$datecompare = date('Y-m-d', $timestampcompare);
        $timecompare = date('Hi', $timestampcompare);
        $id = $row[0];
        

      
	if($datecompare==$date){
     $w=(floor($counter/360));  
        if ($row[$param]<$min){$min=$row[$param];}
        if ($row[$param]>$max){$max=$row[$param];}
       
        
  if ($counter%360==0){
  
echo "

<div class='col-sm-6 text-center'>
       <label class='label label-success'> ".$label." </label>

      <div id='line-chart".$w."' style='width:100%;height:400px;background:white'></div>
</div>
  
</br>


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
                timeformat: ' %0H:%0M'
            },
             grid: { 
      hoverable: true, 
      clickable: true 
    }
            ,colors: ['rgb(50,50,50)']
        };
        
  var data".$w." = [";}
         
         echo "[".(1000*$timestampcompare).",".$row[$param]."],";

        
        if ($counter%360==359){
          

          echo "   
    ];
    
    var dataset".$w." = [{label: '".$label."',data: data".$w."}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart".$w."'), dataset".$w.", options);
        });
    
   
</script>

";
}
                
       
       
          $counter = $counter+1;     }
         
                         

	}
        
        
        if (($counter%360)<>0){
        
          
          
          echo " ];
    
    var dataset".$w." = [{label: '".$label."',data: data".$w."}];
    
   
        
         $(document).ready(function () {
            $.plot($('#line-chart".$w."'), dataset".$w.", options);
        });
        </script>

";
}
     
     $cdate=date("Y-m-d H:i:s",$date);
 echo "</br>
   

  min: ".$min." </br>max: ".$max."

  
<script>
function doFunction () { 
 html2canvas($('#saveme'), {
                onrendered: function (canvas) {
        var a = document.createElement('a');
        // toDataURL defaults to png, so we need to request a jpeg, then convert for file download.
        a.href = canvas.toDataURL('image/jpeg').replace('image/jpeg', 'image/octet-stream');
        a.download = '".$label.":".$date.".jpg';
        a.click();
      }
            });
};
</script>
  </div>
    </br>
  <input id='clickMe' type='button' value='Créer une sauvegarde' onclick='doFunction();' />

  </br>

</body>
</html>
";


	
        


	?>