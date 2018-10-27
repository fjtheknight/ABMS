<?php

$Error = $_GET["Error"];

$text ="Error: Your {$Error} system is unable to provide acceptable breeding conditions!!!";

$admin_email 	= "fj.the.knight@gmail.com";
$email 	= "automaticbroilermonitoringsys@gmail.com";
$subject ="System Error";


//send email
mail($admin_email,"$subject",$text,"From:" .$email);

?>