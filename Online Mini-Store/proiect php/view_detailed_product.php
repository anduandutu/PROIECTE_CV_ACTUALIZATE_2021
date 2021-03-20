<?php
	session_start();
	$cod_produs = $_SESSION["id_prod"];
	$id_client_curent =$_SESSION["id_client"][0];
	require_once("dbcontroller.php");
	$db_handle = new DBController();
?>	
	
	
<HTML>
<HEAD>
<TITLE>Detalii Produs</TITLE>
<link href="style_product.css" type="text/css" rel="stylesheet" />
</HEAD>
<BODY>	
	<form>
	<div id="product-grid">
		<div class="txt-heading">Detalii produs</div>
	<?php
	$product_array = $db_handle->runQuery("SELECT * FROM produse WHERE ID_Produs = '$cod_produs';");
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
			<?php echo nl2br("\r\n"); ?>
			<?php echo nl2br("\r\n"); ?>
			<form method = "post" action="index.php?action=add_recenzie&code=<?php echo $cod_produs ?>">
				<textarea name = "Recenzie" rows = "10" cols = "50"> </textarea>
				<input type="submit" value="Adaugare recenzie" class="btnAddAction" name = "Recenzie_ADD"/>
			</form>
		</div>
	</div>
	<?php
		}
	}
	//De afisat toate recenziile de la produsul cu id-ul respectiv 
	?>
	<div>
		<label> Detalii despre produs : </label>
		<?php echo nl2br("\r\n"); ?>
		<?php echo nl2br("\r\n"); ?>
		<?php echo $product_array[$key]["Descriere"]; ?>
		
		<?php echo nl2br("\r\n"); ?>
		<?php echo nl2br("\r\n"); ?>
	
		<label> Detalii despre livrarea produsului : </label>
		<?php echo nl2br("\r\n"); ?>
		<?php echo nl2br("\r\n"); ?>

		<?php echo $product_array[$key]["Detalii_Livrare"]; ?>
	</div>
	<?php echo nl2br("\r\n"); ?>
	</form>
		<label>Recenziile utilizatorilor sunt : </label>
		<?php
		echo nl2br("\r\n");
		$recenziile = $db_handle->runQuery("SELECT * FROM recenzii R
										JOIN clienti C ON R.ID_Client = C.ID_Client
										WHERE ID_Produs = '$cod_produs';");
		if(!empty($recenziile)){
			foreach($recenziile as $key1=>$value){
					$nume_complet = $recenziile[$key1]["Nume"] . " " . $recenziile[$key1]["Prenume"];
					echo $nume_complet;
					echo nl2br("\r\n");
					echo $recenziile[$key1]["DetaliiRecenzie"];
					echo nl2br("\r\n");
			}
		}
		?>
	<form>
	<?php
		echo nl2br("\r\n");
	?>
	</form>
</BODY>
</HTML>