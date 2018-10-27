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


$Search="SELECT * from activite ORDER BY id DESC LIMIT 10"; 
$Exec=mysqli_query($conn,$Search);

    
echo "
<!DOCTYPE html>
<html>
<head>
<!-- jQuery -->
  <script src='js/jquery.js'></script>
  <!-- Bootstrap Core JavaScript -->
  <script src='js/bootstrap.min.js'></script>
  <!-- Morris Charts JavaScript -->
  <script src='js/plugins/morris/raphael.min.js'></script>
  <script src='js/plugins/morris/morris.min.js'></script>
  <script src='js/plugins/morris/morris-data.js'></script>
  <!-- Flot Charts JavaScript -->
  <!--[if lte IE 8]><script src='js/excanvas.min.js'></script><![endif]-->
  <script src='js/plugins/flot/jquery.flot.js'></script>
  <script src='js/plugins/flot/jquery.flot.tooltip.min.js'></script>
  <script src='js/plugins/flot/jquery.flot.resize.js'></script>
  <script src='js/plugins/flot/jquery.flot.pie.js'></script>
  <script src='js/plugins/flot/flot-data.js'></script>
	<title></title>
	<style type='text/css'>
        table {
    font-family: arial, sans-serif;
    border-collapse: collapse;
    width: 100%;
}

td, th {
    border: 1px solid rgb(180,180,180);
    text-align: left;
    padding: 5px;
}

        tr:nth-child(even) {
            background-color: rgb(180,180,180);
        }
}
	</style>
</head>
<body>
 <h3 class='text-primary text-center'>
    
  </h3>
  <div class'row'>
    
    <div class='col-sm-6 text-center'>
      <div>
      
      <table>
  <tr>
    <th>Temps</th>
    <th>Alerte</th>
  </tr>

      ";
      while($row=mysqli_fetch_array($Exec)){
$act_time = $row[1];
$act = $row[2];
echo "<tr><td>".$act_time."</td><td>  ".$act."</td></tr>";
}
echo"

      <table>
</div>
    </div>
    
    
  </div>
</body>
</html>
";

	?>