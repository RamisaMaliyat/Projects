<?php
session_start();
include 'connection_open.php';
if(isset($_SESSION['user_data']))
 
  {include 'header2.php' ;
   $user_id=$_SESSION['user_data']['id'];
  $sql='select * from user where user_id='.$user_id;
  $result=mysqli_query($link,$sql);
  $row=mysqli_fetch_assoc($result);
  
  $name=$row['user_name'];
  $email=$row['user_email'];
}
else{
 include 'header1.php' ;
}
 error_reporting (E_ALL ^ E_NOTICE); 

$no_of_row=0;


$resOrder = array(
"1"=>  $_POST['name'],
"2"=>  $_POST['email'],
"3"=>  $_POST['phone'],
"4"=>  $_POST['message'],
"5"=> date("Y-m-d H:i:s")
);

?>

<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">

    
  <title>html | form</title> 
</head>
<body>
  <div class="container">
    <div class="row">
      <div class="col-md-12">
    <form action="" method="post" enctype="multipart/form-data">
      <div class="form-group mb-3 mt-5">
        <label>Name</label>
        <input type="text" name="name" value="<?php echo "$name"?>" placeholder="" class="form-control" />
      </div>
      

            <div class="form-group mb-5 mt-5">
                <label>Email</label>
                <input type="email" name="email" value="<?php echo "$email"?>" placeholder="" class="form-control" required />
            </div>

          

            <div class="form-group mb-5 mt-5">
                <label>Your message</label>
                <textarea name="message" value="" class="form-control"></textarea>
            </div>

            <div class="form-group mb-5 mt-5">
                <input type="submit"  value="SEND" name="subm" class="btn btn-success" />
                 <?php 
        if(isset($_POST['email']) && ($_POST['message'])){

        $name=$_POST['name'];
        $email=$_POST['email'];
        $message=$_POST['message'];
        $sqlInsert="INSERT INTO contactus(Name,Email,Message) VALUES('".$name."','".$email."','".$message."')";
        $resultInsert=mysqli_query($link,$sqlInsert);
        $insertId=mysqli_insert_id($link);
        echo "your response have been recorded";
         header( "refresh:5; url=home.php" ); 
      } ?>
            </div>
    </form>
       
  </div>
    </div>
  </div>
      <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>

</body>
</html>

<?php
include 'connection_close.php';?>