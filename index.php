<?php
// 
include_once('dataAccess.php');
 
$reading_Id   = "";

if (isset($_POST['getData'])) {
		
	$reading = getReading();
	$reading_Id   = $reading["id"];

	$reading_Id= test_input($reading_Id);
	echo $reading_Id;
}
else {
	echo "No data posted with HTTP xxx POST.";
}
function test_input($data) {
$data = trim($data);
$data = stripslashes($data);
$data = htmlspecialchars($data);
return $data;
}

?>

  <html>
      <head><meta http-equiv="Content-Type" content="text/html; charset=utf-8">
          
       <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
      </head>
      <header class="header">
          <h1> Data Display</h1>           
      </header>
  <body>
             <p> Value 1 :<?php echo $reading_Id?></p>             
  </body>
  </html>
 