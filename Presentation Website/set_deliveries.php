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
<style>
tr:nth-child(even) {
  background-color: #dddddd;
  border: 5px solid black;
}
tr:nth-child(odd) {
  background-color: #dddddd;
  border: 5px solid black;
}
</style>
</head>
<body>
	<a href="index.php" class = "logo" title = "home" alt = "home" style="float: left;">
		<img alt="Home" src="./home.jpg" style="width: 100px; height: 50px;">
	</a>
	<form style="background-color: white;" action = "set_deliveries.php" method="POST">
		<label>Enter the ID_COS you want to mark as delievered</label>
		<input type="text" name="cart" style="width: 65%; height: 50px;">
	</form>
 <div class="table-responsive">        
  <table class="table table-bordered">
    <thead>
      <tr>
      	<th>ID_COS</th>
		<th>Client Email</th>
		<th>Total Comanda</th>
		<th>Status Comanda</th>
		<th>Data Comanda</th>
      </tr>
    </thead>
    <tbody>
    	<?php
			if(isset($_POST["cart"])){

				$cart = $_POST["cart"];

				$sql_delete_entry = "UPDATE liste_comenzi SET Status_Comanda = 'DELIVERED' WHERE ID_Inregistrare = '".$cart."';";
				$mysqli->query($sql_delete_entry);

				$sql_select_all = "SELECT ID_Inregistrare , (SELECT Email FROM users WHERE ID_Utilizator = 12) AS Email_Client, Data_comenzii, Total_comanda,Status_Comanda FROM liste_comenzi;";
				if ($results = $mysqli->query($sql_select_all)){
					while($rows = mysqli_fetch_array($results)) {
		?>
		<tr>
			<td><?php echo $rows['ID_Inregistrare'] ?></td>
			<td><?php echo $rows['Email_Client'] ?></td>
			<td><?php echo $rows['Total_comanda'] ?></td>
			<td><?php echo $rows['Status_Comanda'] ?></td>
			<td><?php echo $rows['Data_comenzii'] ?></td>
		</tr>
		<?php
					}
				}	
			}
			else{
				$sql_select_all = "SELECT ID_Inregistrare , (SELECT Email FROM users WHERE ID_Utilizator = 12) AS Email_Client, Data_comenzii, Total_comanda,Status_Comanda FROM liste_comenzi;";
				if ($results = $mysqli->query($sql_select_all)){
					while($rows = mysqli_fetch_array($results)) {
		?>
		<tr>
			<td><?php echo $rows['ID_Inregistrare'] ?></td>
			<td><?php echo $rows['Email_Client'] ?></td>
			<td><?php echo $rows['Total_comanda'] ?></td>
			<td><?php echo $rows['Status_Comanda'] ?></td>
			<td><?php echo $rows['Data_comenzii'] ?></td>
		</tr>
		<?php
					}
				}
			}

		?>
    </tbody>
  </table>
</div>
</body>
</html>
<script src="node_modules/jquery/dist/jquery.slim.min.js"></script>
<script src="node_modules/popper.js/dist/umd/popper.min.js"></script>
<script src="node_modules/bootstrap/dist/js/bootstrap.min.js"></script>