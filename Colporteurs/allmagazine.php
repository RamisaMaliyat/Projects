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
			echo'<script>window.location="allmagazine.php"</script>';
	   }else{
			echo '<script>alert("product is alrady Add to cart")</script>';
			echo'<script>window.location="allmagazine.php"</script>';
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
						echo'<script>window.location="allmagazine.php"</script>';
		            }
	        	}
		    }
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
	<link  rel ="stylesheet" href = "css/shop.css"/>
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/5.15.3/css/all.min.css" integrity="sha512-iBBXm8fW90+nuLcSKlbmrPcLa0OT92xO1BIsZ+ywDWZCvqsWgccV3gFoRBv0z+8dLJgyAHIhR35VZc2oM/gI1w==" crossorigin="anonymous" />
     <link rel="preconnect" href="https://fonts.gstatic.com">
     <link href="https://fonts.googleapis.com/css2?family=Titillium+Web:ital,wght@0,200;0,300;0,400;0,600;0,700;0,900;1,200;1,300;1,400;1,600;1,700&display=swap" rel="stylesheet">
	<title>Shopping Cart</title>
  </head>
  <body>
    <div class="abc"></div>
  	<div class = "container">
	  <div class = "row">
	    <div class = "text-left">
                <form name="form1" action ="" method="post">
                  <input type ="submit" class="btn btn-outline-secondary" name= "submit3" value="Back...">
				</form>  				   
	</div>
	   <h2>Some Magazines</h2>
        <?php
            $query = "SELECT * FROM magazined ORDER BY id ASC ";
            $result = mysqli_query($con,$query);
            if(mysqli_num_rows($result) > 0) {

                while ($row = mysqli_fetch_array($result)) {

                    ?>
                    <div class="col-md-4">

                        <form method="post" action="allmagazine.php?action=add&id=<?php echo $row["id"]; ?>">

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
                }
            }
        ?>

        <div style="clear: both"></div>
        <h3 class="title2">Shopping Cart Details</h3>
        <div class="table-responsive">
            <table class="table table-bordered">
            <tr>
                <th width="30%">Product Name</th>
                <th width="10%">Quantity</th>
                <th width="13%">Price Details</th>
                <th width="10%">Total Price</th>
                <th width="17%">Remove Item</th>
            </tr>

            <?php
                if(!empty($_SESSION["cart"])){
                    $total = 0;
                    foreach ($_SESSION["cart"] as $key => $value) {
                        ?>
                        <tr>
                            <td><?php echo $value["item_name"]; ?></td>
                            <td><?php echo $value["item_quantity"]; ?></td>
                            <td>$ <?php echo $value["product_price"]; ?></td>
                            <td>
                                $ <?php echo number_format($value["item_quantity"] * $value["product_price"], 2); ?></td>
                            <td><a href="allmagazine.php?action=delete&id=<?php echo $value["product_id"]; ?>"><span
                                        class="text-danger">Remove Item</span></a></td>

                        </tr>
                        <?php
                        $total = $total + ($value["item_quantity"] * $value["product_price"]);
                    }
                        ?>
                        <tr>
                            <td colspan="3" align="right">Total</td>
                            <th align="right">$ <?php echo number_format($total, 2); ?></th>
                            <td></td>
                        </tr>
                        <?php
                    }
                ?>
            </table>
        </div>


	  </div>
	</div>
 
    <script src="js/bootstrap.bundle.min.js">
    </script>
    
  </body>
</html>