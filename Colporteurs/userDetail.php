
<?php

session_start();
if(isset($_SESSION['user_data']))
 
  {include 'header2.php' ;
  
}
else{
 include 'header1.php' ;
}
include 'connection_open.php';
if(isset($_SESSION['user_data']))
{
  $user_id=$_SESSION['user_data']['id'];
  $sql='select * from user where user_id='.$user_id;
  $result=mysqli_query($link,$sql);
  $row=mysqli_fetch_assoc($result);
  $id=$row['user_id'];
  $name=$row['user_name'];
  $email=$row['user_email'];
  $phone=$row['user_phone'];
  $pass=$row['user_password'];
  $address=$row['user_address'];
  
}
else{
  header("Location:home.php");
}
error_reporting (E_ALL ^ E_NOTICE); 
include 'connection_open.php';
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
 
 


 <div class="container" >
  <div class="row" >
    <div class="col-md-8" style="background-image: url('images/bgg.jpg')">
      <form action="" method="post" enctype="multipart/form-data">

       <div class="form-group mb-5 mt-5 text-white"><label>Username</label> <input type="text" name="name" value="<?php echo "$name"?>"  class="form-control" required /> </div>
       <div class="form-group mb-5 mt-5 text-white"> <label>Email</label><input type="email" name="email" value="<?php echo "$email"?> "  class="form-control" required /></div>
       <div class="form-group mb-5 mt-5 text-white"><label>Phone Number</label><input type="text" name="phone" value="<?php echo "$phone"?>"  class="form-control" required /> </div>
        <div class="form-group mb-5 mt-5 text-white"><label>Address</label><input type="text" name="address" value="<?php echo "$address"?>"  class="form-control" required/> </div>
      <div class="form-group mb-5 mt-5"><input type="submit"  value="Save Changes" class="btn btn-outline-warning" />
  
  <?php 
  if(count($_POST)>0){
      $name=$_POST['name'];
      $email=$_POST['email'];
      $phone=$_POST['phone'];
      $address=$_POST['address'] ;
      $sqlInsert="UPDATE user SET user_name='".$name."',user_email='".$email."',user_phone='".$phone."',user_address='".$address."' where user_id='".$user_id."'";
        
      if (mysqli_query($link,$sqlInsert)) {
      echo "Record updated successfully";
   } else {
      echo "Error updating record: " . mysqli_error($link);
   }
  
}
       ?>
      </div>

       </div>
    </form>
  </div>

<script src="js/bootstrap.bundle.min.js" ></script>
</body>
</html>
<?php
include 'connection_close.php';