<?php 
	session_start();

	// variable declaration
	$name = "";
	$surname = "";
	$email    = "";
	$errors = array(); 
	$_SESSION['success'] = "";

	// connect to database
	$db = mysqli_connect('localhost', 'root', '', 'proiect_php');

	// REGISTER USER
	if (isset($_POST['reg_user'])) {
		// receive all input values from the form
		$name = mysqli_real_escape_string($db, $_POST['name']);
		$surname = mysqli_real_escape_string($db,$_POST['surname']);
		$email = mysqli_real_escape_string($db, $_POST['email']);
		$password_1 = mysqli_real_escape_string($db, $_POST['password_1']);
		$password_2 = mysqli_real_escape_string($db, $_POST['password_2']);

		// form validation: ensure that the form is correctly filled
		if (empty($name)) { array_push($errors, "Name is required"); }
		if (empty($surname)) { array_push($errors, "Surname is required"); }
		if (empty($email)) { array_push($errors, "Email is required"); }
		if (empty($password_1)) { array_push($errors, "Password is required"); }

		if ($password_1 != $password_2) {
			array_push($errors, "The two passwords do not match");
		}

		// register user if there are no errors in the form
		if (count($errors) == 0) {
			//$password = md5($password_1);//encrypt the password before saving in the database
			$query = "INSERT INTO clienti (Nume, Prenume,Email, Parola) 
					  VALUES('$name', '$surname','$email', '$password_1')";
			mysqli_query($db, $query);
			$_SESSION['email'] = $email;
			$_SESSION['success'] = "You are now registered. Please log in! ";
			header('location: login.php');
		}

	}
    
	// ... 
	if(isset($_POST["VIEW_DETAILS"])){
			//CODE FOR VIEW DETAILS
				$dbHost     = 'localhost';
				$dbUsername = 'root';
				$dbPassword = '';
				$dbName     = 'proiect_php';
				$email = $_SESSION["email"];
				$parola = $_SESSION["parola"];
				//Create connection and select DB
				$db = new mysqli($dbHost, $dbUsername, $dbPassword, $dbName);
				
				// Check connection
				if($db->connect_error){
					die("Connection failed: " . $db->connect_error);
				}
				header('location: view_detailed_product.php');
	}
	// LOGIN USER
	if (isset($_POST['login_user'])) {
		$email = mysqli_real_escape_string($db, $_POST['email']);
		$password = mysqli_real_escape_string($db, $_POST['password']);

		if (empty($email)) {
			array_push($errors, "Email is required");
		}
		if (empty($password)) {
			array_push($errors, "Password is required");
		
		}

		if (count($errors) == 0) {
			$query = "SELECT ID_Client FROM clienti WHERE Email = '$email' AND Parola='$password'";
			$results = mysqli_query($db, $query);

			if (mysqli_num_rows($results) == 1) {
				$_SESSION['email'] = $email;
				$_SESSION['parola'] = $password;
				$_SESSION['success'] = "You are now logged in";
				$_SESSION['id_client'] = mysqli_fetch_array($results);
				$query_generate_new_factura = "SELECT MAX(ID_Factura) + 1 AS ID_Factura  FROM detalii_factura";
				$id =  mysqli_query($db,$query_generate_new_factura);
				$id = mysqli_fetch_array($id);
				$_SESSION['id_factura'] = $id;
				header('location: index.php');
			}else {
				array_push($errors, "Wrong username/password combination");
			}
		}
	}

?>