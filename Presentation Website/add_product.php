<?php
// Initialize the session
session_start();
// Include config file
require_once "generate_xml.php";
?>


<!-- HTML begin -->
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" href="style_home_page.css">
<link rel="stylesheet" href="node_modules/bootstrap/dist/css/bootstrap.min.css">
<link rel="stylesheet" href="node_modules/font-awesome/css/font-awesome.min.css">
<link rel="stylesheet" href="node_modules/bootstrap-social/bootstrap-social.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.css" />
</head>
<body>
<?php
	if(isset($_POST["submit_prod"])){

		$prod_name = $prod_description = $prod_key_char = $prod_price = $prod_unit = $prod_categ = "";
		if(isset($_POST["productName"])){
			$prod_name = $_POST["productName"];
		}  
		if(isset($_POST["productPrice"])){
			$prod_price = floatval($_POST["productPrice"]);
		}
		if(isset($_POST["prod_unit"])){
			$prod_unit = $_POST["prod_unit"];
		}
		if(isset($_POST["prod_description"])){
			$prod_description = $_POST["prod_description"];
		}   
		if(isset($_POST["prod_key_char"])){
			$prod_key_char = $_POST["prod_key_char"];
		}  
		if(isset($_POST["prod_categ"])){
			$prod_categ = $_POST["prod_categ"];
		}  
		if (count($_FILES) > 0) {
		    if (is_uploaded_file($_FILES['image']['tmp_name'])) {
		        $image = addslashes(file_get_contents($_FILES['image']['tmp_name']));
		    }
		}

		//first insert the new product
		$sql_insert_new_prod = "INSERT INTO products(P_name,P_description,P_price,P_unit,ID_Imagine,Key_Features,categ,Likes_no) VALUES('".$prod_name."','".$prod_description."',$prod_price,'".$prod_unit."',0,'".$prod_key_char."','".$prod_categ."',0)";
		$mysqli->query($sql_insert_new_prod);
		//then get the new P_ID
		$select_id_prod = "SELECT P_ID FROM products WHERE P_name = '".$prod_name."';";
		$result_id = $mysqli->query($select_id_prod);
		$get_id = mysqli_fetch_array($result_id);
		$id = $get_id["P_ID"];
		//insert the image
		$sql_insert_main_image = "INSERT INTO imagini_website (Imagine, ID_Postare, Main, Tip_Asociere) VALUES('".$image."',$id,'Da','produs');";
		$mysqli->query($sql_insert_main_image);
		//get the entry id
		$sql_select_id_main_image = "SELECT ID_Imagine FROM imagini_website WHERE ID_Postare = $id";
		$result_id_imag = $mysqli->query($sql_select_id_main_image);
		$get_id_imag = mysqli_fetch_array($result_id_imag);
		$id_imag = $get_id_imag["ID_Imagine"];
		//update the image_id:))
		$sql_update_imag = "UPDATE products SET ID_Imagine = $id_imag WHERE P_ID = $id";
		$mysqli->query($sql_update_imag);
		echo "<h2>Product insertion was succesful</h2>";
	}   
	
	//pentru image gallery -- TO_DO
	if(isset($_POST["submit_other_images"])){
		
		if (count($_FILES > 0)){
			if(is_uploaded_file($_FILES['image']['tmp_name'])){
				$image = addslashes(file_get_contents($_FILES['image']['tmp_name']));
			}
		}

		$sql_id_post = "SELECT P_ID AS ID_Produs FROM products ORDER BY P_ID DESC LIMIT 1";
		$result_id = $mysqli->query($sql_id_post);
		$id_post = mysqli_fetch_array($result_id);
		$id = $id_post["ID_Produs"];


		if(empty($image)){
			echo "<h2>There is no image selected</h2>";
		}
		else{
			$sql_select_not_main_images = "SELECT COUNT(*) AS no_gallery FROM imagini_website WHERE ID_Postare = $id AND Main = 'Nu';";
			$result_entries = $mysqli->query($sql_select_not_main_images);
			$entries = mysqli_fetch_array($result_entries);	
			$no_entries = $entries["no_gallery"];
			if($no_entries == 3){
				echo "<h2>You cannot upload more than 3 images</h2>";
			}
			else if($no_entries < 3){
				$sql_insert_main_image = "INSERT INTO imagini_website (Imagine, ID_Postare, Main, Tip_Asociere) VALUES('".$image."',$id,'Nu','produs');";
				$mysqli->query($sql_insert_main_image);
				echo "<h2>Post Image Updated successfull</h2>";
			}
		}
	}     
?>
<!--<a href="index.php" class = "logo" title = "home" alt = "home" style="float: left;">
		<img alt="Home" src="./home.jpg" style="width: 100px; height: 50px;">
	</a>-->
	<form style="background-color: gray; height: auto;" method="POST" action="add_product.php" enctype="multipart/form-data">
		<a href="index.php" class = "logo" title = "home" alt = "home" style="float: left;">
			<img alt="Home" src="./home.jpg" style="width: 100px; height: 50px;">
		</a>
        <div class="form-group row">
            <label for="productName" class="col-md-2 col-form-label">Product Name</label>
            <div class="col-md-10">
                <input type="text" class="form-control" id="productName" name="productName" placeholder="Product Name">
            </div>
        </div>
        <div class="form-group row">
            <label for="productPrice" class="col-md-2 col-form-label">Product Price</label>
            <div class="col-6 col-sm-6 col-md-6">
                <input type="text" class="form-control" id="productPrice" name="productPrice" placeholder="Product Price">
            </div>
            <div class="col-6 col-sm-6 col-md-4">
					<select name = "prod_unit">
						<option>euro</option>
						<option>dolari</option>
						<option>lei</option>
					</select>            	
            </div>
        </div>
		<div class = "form-group row" >
			<label for="prod_description" class="col-md-2 col-form-label">Product Description</label>
            <div class="col-md-10">
                <textarea class="form-control" id="prod_description" name="prod_description" rows="12"></textarea>
            </div>
		</div>
		<div class = "form-group row" >
			<label for="prod_key_char" class="col-md-2 col-form-label">Key Characteristics (se vor introduce cu liniuta)</label>
            <div class="col-md-10">
                <textarea class="form-control" id="prod_key_char" name="prod_key_char" rows="12"></textarea>
            </div>
		</div>
		<div class="form-group row">
            <label for="prod_categ" class="col-6 col-sm-6 col-md-2 col-form-label">Product Category</label>
            <div class="col-2 col-sm-2 col-md-1">
					<select name = "prod_categ">
						<option>cards</option>
						<option>sleeves</option>
					</select>            	
            </div>
        </div>
		<div class = "form-group row">
			<label for="main_prod_image" class="col-md-2 col-form-label">Main Product Image: </label>
			<input type="file" name="image">
		</div>
		<div class="form-group row">
			<input type="submit" name="submit_prod" style="width: 700px;height: 50px;">
		</div>
	</form>
	<form style="background-color: gray; height: auto;" method="POST" action="add_product.php" enctype="multipart/form-data">
		<div class = "form-group row">
			<label for="other_prod_image" class="col-md-2 col-form-label">Gallery Product Images: </label>
			<input type="file" name="image">
		</div>
		<div class="form-group row">
			<input type="submit" name="submit_other_images" style="width: 700px;height: 50px;">
		</div>
		
	</form>
</body>
</html>
<script src="node_modules/jquery/dist/jquery.slim.min.js"></script>
<script src="node_modules/popper.js/dist/umd/popper.min.js"></script>
<script src="node_modules/bootstrap/dist/js/bootstrap.min.js"></script>