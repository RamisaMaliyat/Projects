<?php
session_start();
if(isset($_SESSION['user_data']))
 
	{include 'header2.php' ;
	
}
else{
 include 'header1.php' ;
}
?>
<?php
  if(isset($_POST["submit1"]))
  {
	  header ('Location:allmagazine.php');
  }
  if(isset($_POST["submit2"]))
  {
	  header ('Location:allstudy.php');
  }
   if(isset($_POST["submit3"]))
  {
	  header ('Location:allbook.php');
  }
   if(isset($_POST["submit4"]))
  {
	  header ('Location:AllProduct.php');
  }

?>


<!DOCTYPE html>
<html>
<head>
	<title>Registration system PHP and MySQL</title>
	<link rel="stylesheet" href="css/private.css">
</head>
<body>

  	<div class="item-container">
	  
	  <div class="row">
	  
	  <div class="item">
	  <div class ="col-md-4">
		  
			 <div class ="block_images">
		       <img src="images/magazine.jpg" class="img-fluid" alt="blog1">
		     </div>
		     <div class = "blog_title">
		       <h4>Magazins<br></h4>
			   <p class="text-center">This Section contains news and different magazines<br></p>
		     </div>			 
			
		      <div class = "text-center">
                <form name="form1" action ="" method="post">
                  <input type ="submit" class="btn btn-outline-secondary" name="submit1" value="show Details">
				</form>  				   
		     </div>
			 
			 
			 
			 
	   </div>
	   <div class ="col-md-4">
		  
			 <div class ="block_images">
		       <img src="images/study.jpg" class="img-fluid" alt="blog1">
		     </div>
		     <div class = "blog_title">
		       <h4>Study Related Materials<br></h4>
			   <p class="text-center">This Section contains different different study<br>related materials and devices<br></p>
		     </div>			 
			
		     <div class = "text-center">
                <form name="form1" action ="" method="post">
                  <input type ="submit" class="btn btn-outline-secondary"  name= "submit2" value="show All">
				</form>  				   
		     </div>
			 
			
			 
	   </div>
	   <div class ="col-md-4">
		  
			 <div class ="block_images">
		       <img src="images/book.jpg" class="img-fluid" alt="blog1">
		     </div>
		     <div class = "blog_title">
		       <h4>Books<br></h4>
			   <p class="text-center">This Section contains different books for students<br>and other kind of books.<br></p>
		     </div>
		     <div class = "text-center">
                <form name="form1" action ="" method="post">
                  <input type ="submit" class="btn btn-outline-secondary" name=" submit3" value="show All">
				</form>  				   
		     </div>
			 
			 
	   </div>
	
	
	 </div>

	  </div>
	</div>


	
 

</body>
</html>
























