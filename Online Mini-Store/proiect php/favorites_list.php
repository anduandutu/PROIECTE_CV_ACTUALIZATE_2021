<?php include('server.php') ?>
<?php
require_once("dbcontroller.php");
$db_handle = new DBController();
?>

<HTML>
<HEAD>
<TITLE>Main Page - Products</TITLE>
<link href="style_cart.css" type="text/css" rel="stylesheet" />
</HEAD>
<BODY>

<div id="product-grid">
	<div class="txt-heading">List of favorite products</div>
	<?php
	$id_client = $_SESSION["id_client"][0];
	$product_array = $db_handle->runQuery("SELECT * FROM favorite F JOIN produse P ON F.ID_Produs = P.ID_Produs WHERE ID_Client = '$id_client';");
	if (!empty($product_array)) { 
		foreach($product_array as $key=>$value){
	?>
		<div class="product-item">
			<form method="post" action="index.php?action=add&code=<?php echo $product_array[$key]["ID_Produs"]; ?>" name = "code" >
				<div class="product-image" name = "image">
					<img src="source.php?ID_Produs=<?php echo $product_array[$key]["ID_Produs"]; ?>" width="270" height="150" />
				</div>
				<div class="product-tile-footer">
				<div class="product-title" name = "name"><?php echo $product_array[$key]["Nume_Produs"]; ?></div>
				<div class="product-price" name = "price"><?php echo "RON ".$product_array[$key]["Pret"]; ?></div>
				
			    </div>
			    <div class="cart-action">
					<input type="text" class="product-quantity" name="quantity" value="0" size="2" />
				</div>
				<div class="cart-action">
					<input type="submit" value="Add to Cart" class = "btnAddAction" name = "ADD_PRODUCT" />
				</div>
				
			</form>
			<form method="post" action="index.php?action=details&code=<?php echo $product_array[$key]["ID_Produs"]; ?>">
				<input type="submit" value="View details" class = "btnAddAction" name = "VIEW_DETAILS"/>
			</form>
		</div>
	<?php
		}			
	?>
	<?php
	}
	?>
	
	<?php
		if(isset($_POST["VIEW_DETAILS"])){
			//CODE FOR VIEW DETAILS
			$_SESSION["id_prod"] = $_GET["code"];
			header('location: view_detailed_product.php');
		}
	?>
</div>
</BODY>
</HTML>