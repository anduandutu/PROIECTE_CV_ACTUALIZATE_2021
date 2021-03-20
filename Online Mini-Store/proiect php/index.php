<?php
session_start();
require_once("dbcontroller.php");
$db_handle = new DBController();
$id_client_curent = $_SESSION["id_client"][0];
$id_nou = $_SESSION["id_factura"][0];
if(!empty($_GET["action"])) {
switch($_GET["action"]) {
	case "add": 
		if(!empty($_POST["quantity"])) {
			$productByCode = $db_handle->runQuery("SELECT * FROM produse WHERE ID_Produs='" . $_GET["code"] . "'");
			$itemArray = array($productByCode[0]["ID_Produs"]=>array('name'=>$productByCode[0]["Nume_Produs"], 'code'=>$productByCode[0]["ID_Produs"], 'quantity'=>$_POST["quantity"], 'price'=>$productByCode[0]["Pret"], 'image'=>$productByCode[0]["Imagine_Produs"]));
			//partea de inserare in BD
			$db = mysqli_connect('localhost', 'root', '', 'proiect_php');
			$product = $_GET["code"];
			$quantity = $_POST["quantity"];
			
			$query_insert_detali_factura = "INSERT INTO detalii_factura(ID_Factura,ID_Produs,Cantitate) VALUES ('$id_nou','$product','$quantity');";
			mysqli_query($db, $query_insert_detali_factura);
			
			if(!empty($_SESSION["cart_item"])) {
				if(in_array($productByCode[0]["ID_Produs"],array_keys($_SESSION["cart_item"]))) {
					foreach($_SESSION["cart_item"] as $k => $v) {
							if($productByCode[0]["ID_Produs"] == $k) {
								if(empty($_SESSION["cart_item"][$k]["quantity"])) {
									$_SESSION["cart_item"][$k]["quantity"] = 0;
								}
								$_SESSION["cart_item"][$k]["quantity"] += $_POST["quantity"];
							}
					}
				} else {
					$_SESSION["cart_item"] = array_merge($_SESSION["cart_item"],$itemArray);
				}
			} else {
				$_SESSION["cart_item"] = $itemArray;
			}
		}
	break;
	case "add_to_favorites": 
		$db = mysqli_connect('localhost', 'root', '', 'proiect_php');
		$product = $_GET["code"];
		$query_insert_favorit = "INSERT INTO favorite(ID_Client,ID_Produs) VALUES('$id_client_curent','$product')";
		mysqli_query($db, $query_insert_favorit);	
	break;
	case "add_recenzie":
		$product = $_GET["code"];
		$recenzie = $_POST["Recenzie"];
		$db = mysqli_connect('localhost', 'root', '', 'proiect_php');
		$query_insert_favorit = "INSERT INTO recenzii(DetaliiRecenzie,ID_Produs,ID_Client) VALUES('$recenzie','$product','$id_client_curent')";
		mysqli_query($db, $query_insert_favorit);
	break;
	case "details": 
		$_SESSION["id_prod"] = $_GET["code"];
		header('location: view_detailed_product.php');
	break;
	case "remove":
		//DE REVAZUT PENTRU CA NU FUNCTIONEAZA CUM TREBUIE -- dintr-un motiv functioneaza doar pentru cand am 1 singur element in cosul de cumparaturi
		//ASTA ESTE CIUDATEL
		if(!empty($_SESSION["cart_item"])) {
			foreach($_SESSION["cart_item"] as $k => $v) {
					if($_GET["code"] == $k)
						unset($_SESSION["cart_item"][$k]);				
					if(empty($_SESSION["cart_item"]))
						unset($_SESSION["cart_item"]);
			}
		}
	break;
	case "empty":
	
		unset($_SESSION["cart_item"]);
		$db = mysqli_connect('localhost', 'root', '', 'proiect_php');
		$delete_factura_query = "DELETE FROM detalii_factura WHERE ID_Factura = '$id_nou'";
		mysqli_query($db, $delete_factura_query);
		
	break;	
	case "finalize":
		echo "Transaction done";
		////INSERT PE TABELA Facturi Cu nr de factura , id_client_curent si suma_totala -- problema e cum iau eu suma totala tho :)))
		unset($_SESSION["cart_item"]);
		
		
	break;
}
}
?>
<HTML>
<HEAD>
<TITLE>Simple PHP Shopping Cart</TITLE>
<link href="style_product.css" type="text/css" rel="stylesheet" />
</HEAD>
<BODY>
<div id="shopping-cart">
<div class="txt-heading">Shopping Cart</div>

<a id="btnEmpty" href="index.php?action=empty">Empty Cart</a>
<?php
if(isset($_SESSION["cart_item"])){
    $total_quantity = 0;
    $total_price = 0;
?>	
<table class="tbl-cart" cellpadding="10" cellspacing="1">
<tbody>
<tr>
<th style="text-align:left;">Name</th>
<th style="text-align:left;">Code</th>
<th style="text-align:right;" width="5%">Quantity</th>
<th style="text-align:right;" width="10%">Unit Price</th>
<th style="text-align:right;" width="10%">Price</th>
<th style="text-align:center;" width="5%">Remove</th>
</tr>	
<?php		
    foreach ($_SESSION["cart_item"] as $item){
        $item_price = $item["quantity"]*$item["price"];
		?>
				<tr>
				<td><img src="source.php?ID_Produs=<?php echo $item["code"] ?>" width="50" height="50" /></td>
				<td><?php echo $item["code"]; ?></td>
				<td style="text-align:right;"><?php echo $item["quantity"]; ?></td>
				<td  style="text-align:right;"><?php echo "RON ".$item["price"]; ?></td>
				<td  style="text-align:right;"><?php echo "RON ". number_format($item_price,2); ?></td>
				<td style="text-align:center;"><a href="index.php?action=remove&code=<?php echo $item["code"]; ?>" class="btnRemoveAction"><img src="icon-delete.png" alt="Remove Item" /></a></td>
				</tr>
				<?php
				$total_quantity += $item["quantity"];
				$total_price += ($item["price"]*$item["quantity"]);
		}
		?>

<tr>
<td colspan="2" align="right">Total:</td>
<td align="right"><?php echo $total_quantity; ?></td>
<td align="right" colspan="2"><strong><?php echo "RON ".number_format($total_price, 2); ?></strong></td>
<td>
	<form method="post" action="index.php?action=finalize&pret_total = <?php echo $total_price ?>">
			<input type="submit" value="Finalize transaction" class="btnAddAction" />
	</form>
</td>
</tr>
</tbody>
</table>		
  <?php
} else {
?>
<div class="no-records">Your Cart is Empty</div>
<?php 
}
?>
</div>
<div class ="upload-a-product">
	<input type="submit" value="Incarcare anunt nou " class = "button" name = "ANUNT_NOU" onClick = "window.location = 'upload_product.php'"/>
	<input type="submit" value="Vizualizare favorite " class = "button" name = "FAVORITES" onClick = "window.location = 'favorites_list.php'"/>
	<input type="submit" value="Log out " class = "button" name = "LOGOUT" onClick = "window.location = 'login.php'"/>
</div>
<?php
	if(isset($_POST["FINALIZARE_CUMPARATURI"])){
		echo "Bine, tatii";
	}
?>
<?php	
	if(isset($_POST['formSubmit'])) 
	{
		//acel undefined index care ma deranjeaza un pic dar nu prea tare
		$aCountries = $_POST['formCountries'];
	}
	if(isset($_POST['formSubmitPret_maxim'])){
		$pret_maxim_nou = $_POST['formPreturi_maxime'];
	}
	if(isset($_POST['formSubmitPret_minim'])){
		$pret_minim_nou = $_POST['formPreturi_minime'];
	}
?>
<?php
	$query_pret_max_posibil = "SELECT CEIL(Pret) AS Pret FROM produse WHERE Pret = (SELECT MAX(Pret) FROM produse )";
	$array_max = $db_handle->runQuery($query_pret_max_posibil);
	$pret_max = $array_max[0]["Pret"];
	//PRET MAXIM
	$query_pret_min_posibil = "SELECT FLOOR(Pret) AS Pret FROM produse WHERE Pret = (SELECT MIN(Pret) FROM produse )";
	$array_min = $db_handle->runQuery($query_pret_min_posibil);
	$pret_min = $array_min[0]["Pret"];
	//iau minimul si maximul de preturi 
	//si creez limitele intervalului de selectare pret
	if($pret_min % 100 == 0){
		$pret_minim = $pret_min;
	}
	else if($pret_min < 100 && $pret_min % 100 != 0)
	{ 
		$pret_minim = floor($pret_min/100);
	}
	else if($pret_min > 100 && $pret_min %100 !=0)
	{

		$pret_minim  = (floor($pret_min/100) + 1)*100;
	}
	
	if($pret_max % 100 == 0){
		$pret_maxim = $pret_max;
	}
	else if($pret_max < 100 && $pret_max % 100 != 0)
	{
		$pret_maxim = floor($pret_max/100);
	}
	else if($pret_min > 100 && $pret_max %100 !=0)
	{

		$pret_maxim  = (floor($pret_max/100) + 1)*100;
	}
	//0  400
	//0 100 200 300 400 
	$prices = array();
	for ($i = $pret_minim ; $i<=$pret_maxim; $i = $i + 100){
		array_push($prices,$i);
	}
?>
<div>
<form action="<?php echo htmlentities($_SERVER['PHP_SELF']); ?>" method="post">
	<label for='formPreturi_minime[]'>Alegeti pretul minim dorit : </label><br>
	<select multiple="multiple" name="formPreturi_minime[]">
	<?php
		$product_array = $prices; 
		if (!empty($product_array)) { 
		foreach($product_array as $key=>$value){
	?>
		<option value="<?php echo $product_array[$key]?>"><?php echo $product_array[$key]?></option>
	<?php
		}
	}
	?>
	</select><br>
	<input type="submit" name="formSubmitPret_minim" value="Filtrare Pret Minim" >
</form>
<form action="<?php echo htmlentities($_SERVER['PHP_SELF']); ?>" method="post">
	<label for='formPreturi_maxime[]'>Alegeti pretul maxim dorit : </label><br>
	<select multiple="multiple" name="formPreturi_maxime[]">
	<?php
		$product_array = $prices;  
		if (!empty($product_array)) { 
		foreach($product_array as $key=>$value){
	?>
		<option value="<?php echo $product_array[$key]?>"><?php echo $product_array[$key]?></option>
	<?php
		}
	}
	?>
	</select><br>
	<input type="submit" name="formSubmitPret_maxim" value="Filtrare Pret Maxim" >
</form>
<form action="<?php echo htmlentities($_SERVER['PHP_SELF']); ?>" method="post">
	<label for='formCountries[]'>Alegeti categoria de produs dorita : </label><br>
	<select multiple="multiple" name="formCountries[]">
	<?php
		//ca aici :))
		$product_array = $db_handle->runQuery("SELECT DISTINCT Nume_Categorie FROM produse ORDER BY ID_Produs ASC");  
		if (!empty($product_array)) { 
		foreach($product_array as $key=>$value){
	?>
		<option value="<?php echo $product_array[$key]["Nume_Categorie"]?>"><?php echo $product_array[$key]["Nume_Categorie"]?></option>
	<?php
		}
	}
	?>
	</select><br>
	<input type="submit" name="formSubmit" value="Filtrare" >
</form>
</div>
<div id="product-grid">
	<div class="txt-heading">Products</div>
	<?php
  
	$product_array = $db_handle->runQuery("SELECT * FROM produse ORDER BY ID_Produs ASC");
	//AICI M-AM OCUPAT DE CRITERIILE DE FILTRARE 
	if(!empty($aCountries)){
		$categ = $aCountries[0];
		foreach($product_array as $key=>$value){
			if($product_array[$key]["Nume_Categorie"] !== $categ){
				unset($product_array[$key]);
			}
		}
	}
	if(!empty($pret_minim_nou)){
		$pret = $pret_minim_nou[0];
		foreach($product_array as $key=>$value){
			if($product_array[$key]["Pret"] < $pret){
				unset($product_array[$key]);
			}
		}
	}
	if(!empty($pret_maxim_nou)){
		$pret = $pret_maxim_nou[0];
		foreach($product_array as $key=>$value){
			if($product_array[$key]["Pret"] > $pret){
				unset($product_array[$key]);
			}
		}
	}
	if (!empty($product_array)) { 
		foreach($product_array as $key=>$value){
	?>
		<div class="product-item">
			<form method="post" action="index.php?action=add&code=<?php echo $product_array[$key]["ID_Produs"]; ?>">
			<div class="product-image" >
				<img src="source.php?ID_Produs=<?php echo $product_array[$key]["ID_Produs"]; ?>" width="250" height="150" />
			</div>
			<div class="product-tile-footer">
			<div class="product-title"><?php echo $product_array[$key]["Nume_Produs"]; ?></div>
			<div class="product-price"><?php echo "RON ".$product_array[$key]["Pret"]; ?></div>
			<div class="cart-action">
				<input type="text" class="product-quantity" name="quantity" value="1" size="2" />
				<input type="submit" value="Add to Cart" class="btnAddAction" action="index.php?action=add&code=<?php echo $product_array[$key]["ID_Produs"]; ?>"/></div>
			</div>
			</form>
			<form method="post" action="index.php?action=add_to_favorites&code=<?php echo $product_array[$key]["ID_Produs"]; ?>">
				<input type="submit" value="Add to Favorites" class="btnAddAction" />
			</form>
			<form method="post" action="index.php?action=details&code=<?php echo $product_array[$key]["ID_Produs"]; ?>">
				<input type="submit" value="View Details" class="btnAddAction" />
			</form>
			</div>
		</div>
	<?php
		}
	}
	?>
</BODY>
</HTML>