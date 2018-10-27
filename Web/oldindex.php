



<!DOCTYPE html>
<html>
    <head>
        <title>Automatic Broiler Monitoring System Online</title>
        
    </head>
    <style>
        .txt_block {
            border: 5px solid black;
            width: 270px;
            height: 150px;
            padding: 5px 3px 7px 10px;
            margin: 20px 20px 27px 20px;
            text-align: center
           // background-color: grey;
            float: left;
            
        }
    </style>
    <body>
       
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
    

$Search="SELECT * from ABMS ORDER BY Identifier DESC LIMIT 1"; 
$Exec=mysqli_query($conn,$Search);

     
   
while($row=mysqli_fetch_array($Exec)){
$a1 = $row[2];
$a2 = $row[3];
$a3 = $row[4];
$a4 = $row[5];
$a5 = $row[6];
$a6 = $row[7];
}



?>

        <h1 style="text-align:center">Automatic Broiler Monitoring System Online</h1>
       
        
      
        <div class="txt_block">
        <p style="text-align:center">
        <img src="http://i.imgur.com/x2TPiiu.jpg" >
        <br/>
        CURRENT TEMPERATURE : 
        <br/>
      <?php echo $a1; ?>
        </p>
        </div>
        
        <div class="txt_block">
        <p style="text-align:center">
        <img src="http://i.imgur.com/x5Y9csK.jpg" >
        <br/>
        CURRENT HUMIDITY :
        <br/>
         <?php echo $a2; ?>
         </p>
        </div>
        
         <div class="txt_block">
         <p style="text-align:center">
         <img src="http://i.imgur.com/A52r6DD.png" style="width:64;height:64px;" >
        <br/>
        CURRENT PRESSURE : 
        <br/>
        <?php echo $a3; ?>
        </p>
        </div>
       
        <div class="txt_block">
        <p style="text-align:center">
         <img src="http://i.imgur.com/ZVaQa5G.jpg" >
        <br/>
        APPROXIMATIVE AIR SPEED :
        <br/>
         <?php echo $a4*0.5; ?>
         </p>
        </div>
        
        <div class="txt_block">
        <p style="text-align:center">
        <img src="http://i.imgur.com/agLqOGM.png" style="width:64;height:64px;" >
        <br/>
        COOLING SYSTEM LEVEL :
        <br/>
         <?php echo $a5; ?>
         </p>
        </div>
        
        <div class="txt_block">
        <p style="text-align:center">
        <img src="http://i.imgur.com/vzFam5H.png" style="width:64;height:64px;">
        <br/>
        HEATING SYSTEM LEVEL :
        <br/>
         <?php echo $a6; ?>
         </p>
        </div>
       
        <div class="txt_block">
       <p style="text-align:center">
        <img src="http://i.imgur.com/acJLJh1.png" style="width:64;height:64px;" >
        <br/>
        ACTIVE FANS :
        <br/>
        <?php echo $a4; ?>
         </p>
         </div>

         <div class="txt_block">
       <p style="text-align:center">
       <br/><br/>
        <a href="http://mmppmmll.getenjoyment.net/write_data.php"><font size="5" color="black"><STRONG>SEE FULL DATA</STRONG></font></a>
         </p>
         </div>
        



    </body>
</html>