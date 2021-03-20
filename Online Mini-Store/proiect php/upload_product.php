<HTML>
<HEAD>
<TITLE>Upload Products</TITLE>
<link href="style_product.css" type="text/css" rel="stylesheet" />
</HEAD>
<BODY>
	<form method = "post" enctype="multipart/form-data">
				<label>Selectati imaginea produsului </label>
				<input type="file" value="Choose file" class = "button" name = "UPLOAD_IMAGE" />
				<div class = "input-group">
					<label>Introduceti Numele produsului: </label>
					<input type="text" class="product-quantity" name="nume" value="" size="10" />
				</div>
				<div class = "input-group">
					<label>Introduceti Categoria produsului: </label>
					<input type="text" class="product-quantity" name="categorie" value="" size="10" />
				</div>
				<div class = "input-group">
					<label>Introduceti Pretul produsului: </label>
					<input type="text" class="product-quantity" name="pret" value="0.00" size="10" />
				</div>
				<div class = "input-group">
					<label>Descriere produs: </label>
				</div>
				<textarea name = "Descriere" rows = "10" cols = "100"> </textarea>
				<div class = "input-group">
					<label>Detalii de livrare produs: </label>
				</div>
				<textarea name = "Detalii_livrare" rows = "20" cols = "100"> </textarea>
				<div class = "post">
					<input type="submit" value="Posteaza anunt" class = "button" name = "SUBMIT_POST" />
				</div>
	</form>
	<?php
		if(isset($_POST["SUBMIT_POST"])){
			// Database configuration
			$check = getimagesize($_FILES["UPLOAD_IMAGE"]["tmp_name"]);
			if($check !== false){
				$image = $_FILES["UPLOAD_IMAGE"]["tmp_name"];
				$imgContent = addslashes(file_get_contents($image));
				//DB details
				$dbHost     = 'localhost';
				$dbUsername = 'root';
				$dbPassword = '';
				$dbName     = 'proiect_php';
				
				//Create connection and select DB
				$db = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);
				
				// Check connection
				if($db->connect_error){
					die("Connection failed: " . $db->connect_error);
				}
				//VERIFIC DACA EXITA PRODUSUL CU DATELE SI IMAGINILE SPECIFICATE
				$categorie = mysqli_real_escape_string($db,$_POST["categorie"]);
				$nume = mysqli_real_escape_string($db,$_POST["nume"]);
				$pret = mysqli_real_escape_string($db,$_POST["pret"]);
				$descriere = mysqli_real_escape_string($db,$_POST["Descriere"]);
				$detalii_livrare = mysqli_real_escape_string($db,$_POST["Detalii_livrare"]);
				//VERIFICAM DACA ANUNTUL EXISTA DEJA 
				$check_exists_id_prod = "SELECT ID_Produs FROM produse 
											WHERE Nume_Produs = '$nume' AND Descriere = '$descriere' 
											AND Pret = '$pret' AND Detalii_Livrare = '$detalii_livrare'
										    AND Nume_Categorie = '$categorie'";
				$results = mysqli_query($db, $check_exists_id_prod);
				if (mysqli_num_rows($results) == 1) {
					//DACA EXISTA NU IL MAI POSTAM
					echo "Deja exista o inregistrare cu acest anunt";
				}
				else{
					//DACA NU EXISTA 
					//INSERAM NOUL ANUNT IN BAZA DE DATE 
					$insert = $db->query("INSERT into produse ( Nume_Produs, Descriere,Pret,Detalii_Livrare,Imagine_Produs,Nume_Categorie) 
										 VALUES ('$nume', '$descriere','$pret','$detalii_livrare','$imgContent','$categorie')");
					if($insert){
						echo "File uploaded successfully.";
						
					}else{
						echo "File upload failed, please try again.";
					}
				} 			
			}
			else{
				echo "Please select an image file to upload.";
			}

		}
	?>
</BODY>
</HTML>