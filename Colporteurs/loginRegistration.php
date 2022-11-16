 
<?php
ob_start();
session_start();

error_reporting (E_ALL ^ E_NOTICE); 
include 'header1.php';
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
<body style="background-color:#39005d">

 <link href="css/bootstrap.min.css" rel="stylesheet" >
 


 <div class="container" >
  <div class="row" style="padding: 100px" >
    <div class="col-md-7"style="background-image: url('images/bgg.jpg')" >
       
      <form action="" method="post" enctype="multipart/form-data">
       <div class="form-group mb-5 mt-5"> <input type="text" name="name" value="" placeholder="Username" class="form-control" required /> </div>
       <div class="form-group mb-5 mt-5"> <input type="email" name="email" value="" placeholder="email address" class="form-control" required /> </div>
       <div class="form-group mb-5 mt-5"><input type="text" name="phone" value="" placeholder="phone number" class="form-control" /></div>
       <div class="form-group mb-5 mt-5"><input type="text" name="password" value="" placeholder="enter password" class="form-control" /></div>
       <div class="form-group mb-5 mt-5"><input type="text" name="retype" value="" placeholder="re-type password" class="form-control" /></div>


       <div class="form-group mb-5 mt-5">
        <input type="submit"  value="Sign Up"  class="btn btn-outline-info" />
        <?php 
        if(isset($_POST['name']) && isset($_POST['email']) && isset($_POST['phone']) && isset($_POST['password']) && isset($_POST['retype']) ){
        $name=$_POST['name'];
        $email=$_POST['email'];
        $phone=$_POST['phone'];
        $pass=md5($_POST['password']);
        $repass=md5($_POST['retype']);
        $created_date= date("Y-m-d H:i:s");
        $sqlCheck="select * from user where user_email='".$email."'";
        $resultCheck=mysqli_query($link,$sqlCheck);
        $noOfRow=mysqli_num_rows($resultCheck);
        date_default_timezone_set("ASIA/DHAKA");
        $currentDate=date('Y-m-d H:i:s');
        if(!$noOfRow && $pass==$repass){

          $sqlInsert="INSERT INTO user(user_name,user_email,user_phone,user_password,status,created_date,updated_date) VALUES('".$name."','".$email."','".$phone."','".$pass."',2,'".$currentDate."','".$currentDate."')";

           $resultInsert=mysqli_query($link,$sqlInsert);
       
        
           header( "refresh:5; url=home.php" );   

        }
        else {
          echo 'already register';
        }

        $insertId=mysqli_insert_id($link); }?>
      </div>
    </form>

  </div>

  <!--LOG IN-->
  <div class="col-md-5 " style="background-image: url('images/bgg.jpg')" ><form action="" method="post" enctype="multipart/form-data">


    <div class="form-group mb-5 mt-5" style="padding-top: 100px">
     <input type="email" name="lemail" value="" placeholder="email" class="form-control" required />
   </div>
   <div class="form-group mb-5 mt-5">
     <input type="password" name="lpassword" value="" placeholder=" password" class="form-control" required />
   </div>
   <div class="form-group mb-5 mt-5 "> <input type="submit"  value="Log In"  class="btn btn-outline-warning" style="height: 50px; width: 150px; left: 250; top: 250;" />
    <?php 
	if(isset($_POST['lemail']) && isset($_POST['lpassword'])){
		$lemail=$_POST['lemail'];
		$lpass=md5($_POST['lpassword']);
		$sql="select * from user where user_email='".$lemail."'";

		$result=mysqli_query($link,$sql) or die(mysqli_error($link));
		$noOfRows=mysqli_num_rows($result);
		if($noOfRows){
			while($row= mysqli_fetch_assoc($result)){
	   
				if($row['status']==1 &&  $row['user_password']==$lpass){

		 
				  $userData= array('id' =>$row['user_id'] ,
					'name' =>$row['user_name'] ,
					'email' =>$row['user_email'],
        
				  );
				  echo "<pre>";
				  echo "login success!!";
          $_SESSION['user_data']=$userData;
				  header( "refresh:5; url=home.php" ); 	   
				}
				else if($row['status']==1 && $row['user_password']!=$pass)
				{ echo "<pre>"; echo "login fail!!";}
				else if($row['status']!=1)
					echo"something wrong!";
			}
		}else
		echo "registration first";
	}
?>
</div>
</form>
</div>
</div>
</div>

<script src="js/bootstrap.bundle.min.js" ></script>
</body>
</html>
<?php 
ob_end_flush();
include 'connection_close.php';