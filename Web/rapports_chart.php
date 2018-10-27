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


$date1=$_GET["date1"];
$date2=$_GET["date2"];
$nbdays=(strtotime($date2)-strtotime($date1))/86400;


$Search="SELECT * from elevage ORDER BY id DESC LIMIT 1"; 
$Exec=mysqli_query($conn,$Search);
$cdate=date("Y-m-d");
while($row=mysqli_fetch_array($Exec)){
$startingnumber=$row[2];
$startingdate=$row[1];
}



$Search="SELECT * from production"; 


$Exec=mysqli_query($conn,$Search);

$arraymortality=array();
$arrayfoodcons=array();
$arraywatercons=array();


        
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
.line-chart{
  min-height: 250px;
}
	</style>
</head>
<body>
 <h3 class='text-primary text-center'>
    
  </h3> 
  <div id='saveme' style='background:white; width:100%'>
    <fieldset>
    <legend>Rapport ".$date1." ".$date2."</legend>
  
  <div class'row'>
   
    



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
            </script>
        ";
        
        
        
        for ($i = 2; $i<=4; $i++){
        mysqli_data_seek($Exec, 0);

        switch($i){
        
        case 2:
        $label='Mortalité';
        break;
        case 3:
        $label='Consommation d aliment';
        break;
        case 4:
        $label='Consommation d eau';
        break;
        
        
        }
          
        echo"
        
         <div class='col-sm-6 text-center'>
       <label class='label label-success'> ".$label." </label>
      <div class='line-chart' id='line-chart".$i."' style='background:white'></div>
    </div>
    <script>
  var data".$i." = [
";

$min = 5000;
      $max=-5000;
while($row=mysqli_fetch_array($Exec)){
	   $rowparam=$row[$i];
     
	$timestampcompare = strtotime($row[1]);
	$datecompare = date('Y-m-d', $timestampcompare);
        $timecompare = date('Hi', $timestampcompare);
        $id = $row[0];
      
	if($datecompare>=$date1 && $datecompare<=$date2){
        if ($rowparam<$min){$min=$rowparam;}
        if ($rowparam>$max){$max=$rowparam;}
      

        echo "[".(1000*$timestampcompare).",".$rowparam."],";
                switch($i){
                
                case 2: array_push($arraymortality,$rowparam); break;
                case 3: array_push($arrayfoodcons,$rowparam); break;  
                case 4: array_push($arraywatercons,$rowparam); break;                
                }    
        }
        }
echo "];

    var dataset".$i." = [{label: '".$label."',data: data".$i."}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart".$i."'), dataset".$i.", options);
        });
    
</script>
  "; 
}
        
      
  //********************Poids
  $Search="SELECT * from poidsnew"; 


$Exec=mysqli_query($conn,$Search);
$label='Poids';

  echo"
       
         <div class='col-sm-6 text-center'>
       <label class='label label-success'> ".$label." </label>
      <div class='line-chart' id='line-chart5' style='background:white'></div>
    </div>
    <script>
  var data5 = [
";

$min = 5000;
      $max=-5000;
while($row=mysqli_fetch_array($Exec)){
	   $rowparam=$row[2];
     
	$timestampcompare = strtotime($row[1]);
        
	$datecompare = date('Y-m-d', $timestampcompare);

        $timecompare = date('Hi', $timestampcompare);
        $id = $row[0];
      
	if($datecompare>=$date1 && $datecompare<=$date2){
      
        echo "[".(1000*$timestampcompare).",".$rowparam."],";

        }
        }
echo "];

    var dataset5 = [{label: '".$label."',data: data5}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart5'), dataset5, options);
        });
    
</script>
  
  ";
  //****************************************Poids moyen
          mysqli_data_seek($Exec, 0);
          $label='Poids moyen';
          
          echo"
       
         <div class='col-sm-6 text-center'>
       <label class='label label-success'> ".$label." </label>
      <div class='line-chart' id='line-chart6' style='background:white'></div>
    </div>
    <script>
  var data6 = [
";

$min = 5000;
      $max=-5000;
      $counter=0;
      $poids=0;
      $j=0;  
      $l=0;
      $m=0;
      $n=0;
$cond=false;
$arr=array();  
$arr2=array();
$arrd=array();
$arrvar=array();
$arrforvar=array();
while($row=mysqli_fetch_array($Exec)){
	   $rowparam=$row[2];

	$timestampcompare = strtotime($row[1]);
	$datecompare = date('Y-m-d', $timestampcompare);
        $timecompare = date('Hi', $timestampcompare);
        $id = $row[0];


                      
	if($datecompare>=$date1 && $datecompare<=$date2){
     $arr[$j]=$rowparam;
     $arrd[$j]=$datecompare;
        $j+=1;

        }
        }
        $datek=$arrd[0];
$vals = array_count_values($arrd);


      for($k=0;$k<count($vals);$k++){

       while($arrd[$m]==$datek){
       $poids+=$arr[$m]; 
       array_push($arrforvar,$arr[$m]);
       $l+=1; 
       $m+=1;
       }
    
       $arr2[$k]=($poids/$l);
      
       $poids=0; $l=0;
echo "[".(1000*(strtotime($datek))).",".$arr2[$k]."],";

        $datek=$arrd[$m];
     array_push($arrvar,variance($arrforvar));$arrforvar=array();
        }
        
          

       // 
echo "];

    var dataset6 = [{label: '".$label."',data: data6}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart6'), dataset6, options);
        });
    
</script>
  
  ";
  
  //***********************************Param Zoo
  
  $label="Indice de conversion";
  $arrayfcr=array();
  for($i=0;$i<=$nbdays;$i++){
  $cumulcons+=$arrayfoodcons[$i]*1000;
  array_push($arrayfcr, (($cumulcons/($startingnumber-$arraymortality[$i]))/$arr2[$i]));
  }

  echo"
       
         <div class='col-sm-6 text-center'>
       <label class='label label-success'> ".$label." </label>
      <div class='line-chart' id='line-chart7' style='background:white'></div>
    </div>
    <script>
  var data7 = [
";


      for($i=0;$i<count($arrayfcr);$i++){
        echo "[".(1000*(strtotime($date1)+86400*$i)).",".$arrayfcr[$i]."],";

        }
echo "];

    var dataset7 = [{label: '".$label."',data: data7}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart7'), dataset7, options);
        });
    
</script>
  
  ";
  //********************
  
  $label="Facteur d efficacite de production";
  $arraypef=array();
  for($i=0;$i<=$nbdays;$i++){
  $cumulmortality+=$arraymortality[$i];
$livability=(($startingnumber-$cumulmortality)/$startingnumber)*100;
$liveweight=$arr2[$i]/1000;
$age = 1+((strtotime($date1)+86400*$i)-(strtotime($startingdate)))/86400;
$fcr=$arrayfcr[$i];
$pef=(($livability*$liveweight)/($age*$fcr))*100;

  array_push($arraypef, $pef);
  }





  echo"
       
         <div class='col-sm-6 text-center'>
       <label class='label label-success'> ".$label." </label>
      <div class='line-chart' id='line-chart8' style='background:white'></div>
    </div>
    <script>
  var data8 = [
";


      for($i=0;$i<count($arraypef);$i++){
        echo "[".(1000*(strtotime($date1)+86400*$i)).",".$arraypef[$i]."],";

        }
echo "];

    var dataset8 = [{label: '".$label."',data: data8}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart8'), dataset8, options);
        });
    
</script>
  
  "; 
  
  //********************
  
    $label="Coefficient de variation";


  echo"
       
         <div class='col-sm-6 text-center'>
       <label class='label label-success'> ".$label." </label>
      <div class='line-chart' id='line-chart9' style='background:white'></div>
    </div>
    <script>
  var data9 = [
";


      for($i=0;$i<count($arrvar);$i++){
        echo "[".(1000*(strtotime($date1)+86400*$i)).",".$arrvar[$i]."],";

        }
echo "];

    var dataset9 = [{label: '".$label."',data: data9}];
    
   
        
         $(document).ready(function (){
            $.plot($('#line-chart9'), dataset9, options);
        });
    
</script>
  
  ";
  //*****************************************variance???
  
  function average($arr)
{
    if (!count($arr)) return 0;

    $sum = 0;
    for ($i = 0; $i < count($arr); $i++)
    {
        $sum += $arr[$i];
    }

    return $sum / count($arr);
}

function variance($arr)
{
    if (!count($arr)) return 0;

    $mean = average($arr);

    $sos = 0;    // Sum of squares
    for ($i = 0; $i < count($arr); $i++)
    {
        $sos += ($arr[$i] - $mean) * ($arr[$i] - $mean);
    }

    return $sos / (count($arr)-1);  // denominator = n-1; i.e. estimating based on sample 
                                    // n-1 is also what MS Excel takes by default in the
                                    // VAR function
}

//echo variance(array(4,6,23,15,18)); // echoes 64.7...correct value :)


  
  

   echo"

  <script>
function doFunction () { 
 html2canvas($('#saveme'), {
                onrendered: function (canvas) {
        var a = document.createElement('a');
        // toDataURL defaults to png, so we need to request a jpeg, then convert for file download.
        a.href = canvas.toDataURL('image/jpeg').replace('image/jpeg', 'image/octet-stream');
        a.download = 'Rapport ".$date1."/".$date2.".jpg';
        a.click();
      }
            });
};
</script>
  </div>
      </fieldset>
  </div>
    </br>
  <input id='clickMe' type='button' value='Créer une sauvegarde' onclick='doFunction();' />

  
</body>
</html>
";

	?>