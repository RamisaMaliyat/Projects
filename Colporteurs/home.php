 <?php 
session_start();
if(isset($_SESSION['user_data']))
 
	{include 'header2.php' ;
	
}
else{
 include 'header1.php' ;
}

$con= mysqli_connect("localhost","root","","product_details");
if(isset($_POST["add"])){
	if(isset($_SESSION["cart"])){
		$item_array_id=array_column($_SESSION["cart"],"product_id");
		if(!in_array($_GET["id"],$item_array_id)){
			$count =count($_SESSION["cart"]);
			$item_array = array(
			'product_id'=>$_GET["id"],
			'item_name'=>$_POST["hidden_name"],
			'product_price'=>$_POST["hidden_price"],
			'item_quantity'=>$_POST["quantity"],	
			);
			$_SESSION["cart"]["$count"]=$item_array;
			echo'<script>window.location="magazine.php"</script>';
	   }else{
			echo '<script>alert("product is alrady Add to cart")</script>';
			echo'<script>window.location="magazine.php"</script>';
		}
	   }else{
			$item_array=array(
			 'product_id'=>$_GET["id"],
			 'item_name'=>$_POST["hiddden_name"],
			 'product_price'=>$_POST["hiddden_price"],
			 'item_quantity'=>$_POST["quantity"],
			
			);
			$_SESSION["cart"][0]=$item_array;
		}
		}
		
		if(isset($_GET["action"])){
			if($_GET["action"]=="delete"){
				foreach($_SESSION["cart"]as $keys=>$value){
					if($value["product_id"]==$_GET["id"]){
						unset($_SESSION["cart"][$keys]);
						echo'<script>alert("product has been Removed...!")</script>';
						echo'<script>window.location="magazine.php"</script>';
		            }
	        	}
		    }
		}
		 if(isset($_POST["submit3"]))
  {
	  header ('Location:AllProduct.php');
  }
?>

 <!doctype html>
<html lang="en">
<head>
  <!-- Required meta tags -->
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <!-- Bootstrap CSS -->
  <link href="css/bootstrap.min.css" rel="stylesheet" >
  <link rel="preconnect" href="https://fonts.gstatic.com">
<link href="https://fonts.googleapis.com/css2?family=Lobster&display=swap" rel="stylesheet">
  <link href="css/style.css" rel="stylesheet">
  <title>COLPORTEUR</title>
 <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

     <!-- Optional theme -->
   <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
     <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
	
    <!-- Latest compiled and minified JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
</head>
<body >
	<<?php include "connection_open.php"; ?>
<link href="css/bootstrap.min.css" rel="stylesheet" >


   <div class="container">

   
   	<div class="row">
   		<h3 style="padding-top: 50px" class="ctg">Products</h3>
	<?php 
	
            $query = "SELECT * FROM magazine ORDER BY id ASC ";
            $result = mysqli_query($con,$query);
            if(mysqli_num_rows($result) > 0) {

                while ($row = mysqli_fetch_array($result) and ($row["id"]==1 or $row["id"]==2  ) ) {

                    ?>
                    <div class="col-md-4" style="margin-top: 50px">

                        <form method="post" action="magazine.php?action=add&id=<?php echo $row["id"]; ?>">

                            <div class="product">
                                <img src="<?php echo $row["images"]; ?>" class="img-responsive">
                                <h5 class="text-info"><?php echo $row["pname"]; ?></h5>
                                <h5 class="text-danger"><?php echo $row["price"]; ?></h5>
                                <input type="text" name="quantity" class="form-control" value="1">
                                <input type="hidden" name="hidden_name" value="<?php echo $row["pname"]; ?>">
                                <input type="hidden" name="hidden_price" value="<?php echo $row["price"]; ?>">
                                <input type="submit" name="add" style="margin-top: 5px;" class="btn btn-success"
                                       value="Add to Cart">
                            </div>
                        </form>
                    </div>
                    <?php
                     if(isset($_POST["submit3"]))
  {
	  header ('Location:magazine.php');
  }
                }
            }
        ?>
  <?php
            $query = "SELECT * FROM product ORDER BY id ASC ";
            $result = mysqli_query($con,$query);
            if(mysqli_num_rows($result) > 0) {

                while ($row = mysqli_fetch_array($result) and ($row["id"]==1 or $row["id"]==2  or $row["id"]==3  )) {

                    ?>
                    <div class="col-md-4" style="margin-top: 50px">

                        <form method="post" action="study.php?action=add&id=<?php echo $row["id"]; ?>">

                            <div class="product">
                                <img src="<?php echo $row["image"]; ?>" class="img-responsive">
                                <h5 class="text-info"><?php echo $row["pname"]; ?></h5>
                                <h5 class="text-danger"><?php echo $row["price"]; ?></h5>
                                <input type="text" name="quantity" class="form-control" value="1">
                                <input type="hidden" name="hidden_name" value="<?php echo $row["pname"]; ?>">
                                <input type="hidden" name="hidden_price" value="<?php echo $row["price"]; ?>">
                                <input type="submit" name="add" style="margin-top: 5px;" class="btn btn-success"
                                       value="Add to Cart">
                            </div>
                        </form>
                    </div>
                    <?php
                }
            }
        ?>
         <?php
            $query = "SELECT * FROM book ORDER BY id ASC ";
            $result = mysqli_query($con,$query);
            if(mysqli_num_rows($result) > 0) {

                while ($row = mysqli_fetch_array($result)and ($row["id"]==11 or $row["id"]==12  or $row["id"]==13  or $row["id"]==14 or $row["id"]==15 )) {

                    ?>
                    <div class="col-md-4" style="margin-top: 50px">

                        <form method="post" action="textbook.php?action=add&id=<?php echo $row["id"]; ?>">

                            <div class="product">
                                <img src="<?php echo $row["image"]; ?>" class="img-responsive">
                                <h5 class="text-info"><?php echo $row["pname"]; ?></h5>
                                <h5 class="text-danger"><?php echo $row["price"]; ?></h5>
                                <input type="text" name="quantity" class="form-control" value="1">
                                <input type="hidden" name="hidden_name" value="<?php echo $row["pname"]; ?>">
                                <input type="hidden" name="hidden_price" value="<?php echo $row["price"]; ?>">
                                <input type="submit" name="add" style="margin-top: 5px;" class="btn btn-success"
                                       value="Add to Cart">
                            </div>
                        </form>
                    </div>
                    <?php
                }
            }
        ?>
         <div class="col-md-4 fs-40" style="margin-top: 100px">

                       
                            <div class="seeall">
                               
                                 <a href="AllProduct.php"><h3>see all</h3></a>
                               
                            </div>
                        </form>
                    </div>
                    	<h3 style="padding-top: 50px" class="ctg">Categories</h3>
   		<div class="col-md-4">
   			 <div class = "blog_title"><a href="magazine.php"><h3><b>News and Magazins</b><br></h3></a> </div>
   		     <div class ="block_images"> <img src="images/slide1.png" class="img-fluid" alt="blog1"> </div>
		</div>

   		 <div class ="col-md-4">
		  	  <div class = "blog_title"> <a href="study.php"><h3><b>Stationary</b><br></h3></a></div>
			 <div class ="block_images"><img src="images/hb2.jpg" class="img-fluid" alt="blog1"></div>
		       
	    </div>
	    <div class ="col-md-4">
		  	 <div class = "blog_title"><a href="textbook.php"><h3><b>Books</b><br></h3></a></div>
			 <div class ="block_images"> <img src="images/section.jpg" class="img-fluid" alt="blog1"></div>
		    
   	</div>
</div>
<h3 style="padding-top: 50px" class="ctg">About Us</h3>
<div class="row">
	<div class="col-md-12">
		 <h3>We give peole the opportunity to buy different books,magazines, and related study materials at low  price so that they can read for themselves and inspire others to read  <a href="about.php"> More</a></h3>
	</div>
	

<div class="col-md-6" style="margin-top: 50px;">
	<div id="carouselExampleIndicators" class="carousel slide" data-bs-ride="carousel">
  <div class="carousel-indicators">
    <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="0" class="active" aria-current="true" aria-label="Slide 1"></button>
    <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="1" aria-label="Slide 2"></button>
    <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="2" aria-label="Slide 3"></button>
  </div>
  <div class="carousel-inner">
    <div class="carousel-item active">
      <img src="images/bag.jpg" class="d-block w-100" alt="...">
    </div>
    <div class="carousel-item">
      <img src="images/study1.jpg" class="d-block w-100" alt="...">
    </div>
    <div class="carousel-item">
      <img src="images/book2.jpg" class="d-block w-100" alt="...">
    </div>
  </div>
  <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="prev">
    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
    <span class="visually-hidden">Previous</span>
  </button>
  <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="next">
    <span class="carousel-control-next-icon" aria-hidden="true"></span>
    <span class="visually-hidden">Next</span>
  </button>
</div>
</div></div>

<?php include 'footer.php' ?>
<script src="js/bootstrap.bundle.min.js" ></script>
</body>
</html>
