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
$temperature = $_GET["Temperature"];
$humidity= $_GET["Humidity"];
$pressure= $_GET["Pressure"];
$airspeed= $_GET["AirSpeed"];
$coolinglevel= $_GET["CoolingLevel"];
$heatinglevel= $_GET["HeatingLevel"];

    $sqli = "INSERT INTO ABMS (Temperature,Humidity,Pressure,AirSpeed,CoolingLevel,HeatingLevel)  VALUES  ($temperature,$humidity,$pressure,$airspeed,$coolinglevel,$heatinglevel)"   ; 

mysqli_query($conn,$sqli) or die ('Error SQL ! '.$sqli.'<br/>'.mysqli_error());
mysqli_close();

?>