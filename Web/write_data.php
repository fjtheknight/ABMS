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
    

$Search="SELECT * from ABMS"; 
$Exec=mysqli_query($conn,$Search);

     
   echo "<table border='1'>
<tr>
<th>Identifier</th>
<th>Time</th>
<th>Temperature</th>
<th>Humidity</th>
<th>Pressure</th>
<th>Active Fans</th>
<th>Cooling System Level</th>
<th>Heating System Level</th>
</tr>";

while($row=mysqli_fetch_array($Exec)){
echo "<tr>";
echo "<td>" .$row[0]. "</td>";
echo "<td>" .$row[1]. "</td>";
echo "<td>" .$row[2]. "</td>";
echo "<td>" .$row[3]. "</td>";
echo "<td>" .$row[4]. "</td>";
echo "<td>" .$row[5]. "</td>";
echo "<td>" .$row[6]. "</td>";
echo "<td>" .$row[7]. "</td>";


echo "</tr>";}



echo "</table>";


?>