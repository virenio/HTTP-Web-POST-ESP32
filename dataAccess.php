
 <?php
 //  Create database and datatable on local servar or website.   
 // accordingle edit following data 
    $serverName = "localhost";
    $userName = "root";
    $passWord = "";
    $dbName = "xx_db";
 
 //--------------------------------------------------
 function getReading(){
   global $serverName, $userName, $passWord, $dbName ;
   // Create connection
 $vCon = new mysqli($serverName, $userName, $passWord, $dbName );
 // Check connection
 if ($vCon->connect_error) {
   die("Connection failed: " . $vCon->connect_error);
 }
 
 $sql = "SELECT id, val1,val2 FROM  xx_tbl order by id DESC limit 1" ;
 if ($result = $vCon->query($sql)) {
   return $result->fetch_assoc();
 }
 else {
   return false;
 }
  
 
 $vCon->close();
 }
 
 //----------------------------------------------------------
 ?>
