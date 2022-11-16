<?php

session_start();
if(isset($_SESSION['user_data']))
 
  {include 'header2.php' ;
  
}
else{
 include 'header1.php' ;
}
  if(isset($_POST["submit1"]))
  {
	  header ('Location:magazine.php');
  }
  if(isset($_POST["submit2"]))
  {
	  header ('Location:study.php');
  }
   if(isset($_POST["submit3"]))
  {
	  header ('Location:textbook.php');
  }
   if(isset($_POST["submitl"]))
  {
	  header ('Location:loginRegistration.php');
  }

?>

<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- Bootstrap CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link  rel ="stylesheet" href = "css/product.css"/>
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Dancing+Script:wght@400;500;600;700&display=swap" rel="stylesheet">
     <link rel="preconnect" href="https://fonts.gstatic.com">
     <link href="https://fonts.googleapis.com/css2?family=Arvo:ital,wght@0,400;0,700;1,400;1,700&family=Dancing+Script:wght@400;500;600;700&display=swap" rel="stylesheet">
     <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Akaya+Telivigala&family=Arvo:ital,wght@0,400;0,700;1,400;1,700&family=Dancing+Script:wght@400;500;600;700&display=swap" rel="stylesheet">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Akaya+Telivigala&family=Arvo:ital,wght@0,400;0,700;1,400;1,700&family=Dancing+Script:wght@400;500;600;700&family=EB+Garamond:ital,wght@0,400;0,500;0,600;0,700;0,800;1,400;1,500;1,600;1,700;1,800&display=swap" rel="stylesheet">
    <link rel="preconnect" href="https://fonts.gstatic.com">
    <link href="https://fonts.googleapis.com/css2?family=Kiwi+Maru:wght@300;400;500&display=swap" rel="stylesheet">
	<title>Service Page</title>
	<!-- Latest compiled and minified CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css" integrity="sha384-BVYiiSIFeK1dGmJRAkycuHAHRg32OmUcww7on3RYdg4Va+PmSTsz/K68vbdEjh4u" crossorigin="anonymous">

     <!-- Optional theme -->
   <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap-theme.min.css" integrity="sha384-rHyoN1iRsVXV4nD0JutlnGaslCJuC7uwjduW9SVrLvRYooPp2bWYgmgJQIXwl/Sp" crossorigin="anonymous">
     <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
	
    <!-- Latest compiled and minified JavaScript -->
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
	
	
  </head>
  <body>
    
	<div class = "imagecontainer">
	  <div class = "row">	 
	      <div class ="col-md-12">
	
	   <div class= "header">
	     <h1>Welcome to Colporteur...</h1>
	   </div>
        <div class="menuconyainer">
		
		<div id="carousel-example-generic" class="carousel slide" data-ride="carousel">
  <!-- Indicators -->
  <ol class="carousel-indicators">
    <li data-target="#carousel-example-generic" data-slide-to="0" class="active"></li>
    <li data-target="#carousel-example-generic" data-slide-to="1"></li>
    <li data-target="#carousel-example-generic" data-slide-to="2"></li>
	<li data-target="#carousel-example-generic" data-slide-to="3"></li>
	<li data-target="#carousel-example-generic" data-slide-to="4"></li>
  </ol>

  <!-- Wrapper for slides -->
  <div class="carousel-inner" role="listbox">
    <div class="item active">
      <img src="images/slidera.jpg" alt="book">
      <div class="carousel-caption">
       
      </div>
    </div>
    <div class="item">
      <img src="images/slideb.jpg" alt="book">
      <div class="carousel-caption">
       
      </div>
    </div>
	
	 <div class="item">
      <img src="images/slidec.jpg" alt="book">
      <div class="carousel-caption">
       
      </div>
    </div>
    <div class="item">
      <img src="images/slided.jpg" alt="book">
      <div class="carousel-caption">
       
      </div>
    </div>
	  <div class="item">
      <img src="images/slidee.jpg" alt="book">
      <div class="carousel-caption">
       
      </div>
    </div>
	
    
  </div>

  <!-- Controls -->
  <a class="left carousel-control" href="#carousel-example-generic" role="button" data-slide="prev">
    <span class="glyphicon glyphicon-chevron-left" aria-hidden="true"></span>
    <span class="sr-only">Previous</span>
  </a>
  <a class="right carousel-control" href="#carousel-example-generic" role="button" data-slide="next">
    <span class="glyphicon glyphicon-chevron-right" aria-hidden="true"></span>
    <span class="sr-only">Next</span>
  </a>
</div>
		  
	       
	    </div>	

</div>
</div>
</div>	  
	<div class="item-header">
	  <h2>Our Products and Services</h2>
	
	</div>
	
	<div class="item-container">
	  
	  <div class="row">
	  
	  <div class="item">
	  <div class ="col-md-4">
		  
			 <div class ="block_images">
		       <img src="images/magazine.jpg" class="img-fluid" alt="blog1">
		     </div>
		
		     <div class = "blog_title">
		       <h4>News and Magazins<br></h4>
			   <p class="text-center">This Section contains news and different magazines<br></p>
		     </div>			 
			
		     <div class = "text-center">
                <form name="form1" action ="" method="post">
                  <input type ="submit" name="submit1" value="show Details">
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
                  <input type ="submit" name="submit2" value="show Details">
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
                  <input type ="submit" name="submit3" value="show Details">
				</form>  				   
		     </div>
			 
			 
	   </div>
	
	 </div>

	  </div>
	</div>





	
	
	
	<div class="login-container">
	  
	  <div class="row">
	  
	  <div class="item">
	   
	   <div class ="col-lg-4 col-lg-offset-4">
		    
			<div class ="block_images">
		       <img src="images/login.jpg" class="img-fluid" alt="login.jpg">
		     </div>
		     <div class = "blog_title">
		      
			   <h4 class="text-center">To see more ....<br>please log in <br></h4>
		     </div>
		     <div class = "text-center">
                <form name="form1" action ="" method="post">
                  <input type ="submit" name="submitl" value="Log in here">
				</form>  				   
		     </div>
			
			 
	   </div>
	
	
	 </div>

	  </div>
	</div>
	
	
	
	
	
	
	
	

    <div id="end-container">
		<p>&copy;Copyright 2021.All Rights Reserved</p>	
    </div>	


	 
	 
	 
	
	
	
	
	
	

    <script src="js/bootstrap.bundle.min.js">
</script>
    
  </body>
</html>