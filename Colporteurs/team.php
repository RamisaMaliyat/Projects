<?php
include 'connection_open.php';

session_start();
if(isset($_SESSION['user_data']))
 
  {include 'header2.php' ;
  
}
else{
 include 'header1.php' ;
}
$sql="select * from teami ";

$result=mysqli_query($link,$sql) or die(mysqli_error($link));
$noOfRows=mysqli_num_rows($result);
?>
<!doctype html>
<html >
<head>
  <!-- Required meta tags -->
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <!-- Bootstrap CSS -->
 
   <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <!-- Bootstrap CSS -->
  <link href="css/bootstrap.min.css" rel="stylesheet" >
  <link href="css/style.css" rel="stylesheet">
  
</head>
<body style="background-image: url('images/bgg.jpg')">
 <link href="css/bootstrap.min.css" rel="stylesheet" >
<div><?php include 'header1.php' ?></div>
  <div class="container bg-white mt-5 mb-5">
    <div class="row ml-5" style="padding-left: 100px" >
      <?php while($rw= mysqli_fetch_assoc($result)){
      ?>
        
           <div class="col-md-6 ml-5 pt-5 "  >  <div class="wl">
            <img src="<?php echo $rw['Image'] ?>" alt="Responsive image"  >
             <h1 >Name : <?php echo $rw['Name'] ?></h1>
        <h2>ID: <?php echo $rw['Id'] ?></h2>
         <h2 >email: <?php echo $rw['Email'] ?></h2>

          </div></div>

    
      
          

        <?php } ?>
      
     
        
      </div>
           
   

    </div>
   

  </div>

<script src="js/bootstrap.bundle.min.js" ></script>
</body>
</html>
<?php
include 'connection_close.php';