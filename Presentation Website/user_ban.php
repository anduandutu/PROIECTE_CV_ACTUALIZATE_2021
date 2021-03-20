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
	<form style="background-color: white;" action = "user_ban.php" method="POST">
		<label>Enter the username of the user you want to ban</label>
		<input type="text" name="username_ban" style="width: 65%; height: 50px;">
	</form>
 <div class="table-responsive">        
  <table class="table table-bordered">
    <thead>
      <tr>
		<th>ID_Cos</th>
		<th>Data_Comanda</th>
		<th>Total_comanda</th>
		<th>Username comandant</th>
      </tr>
    </thead>
    <tbody>
    	<?php
			if(isset($_POST["username_ban"])){

				$username = $_POST["username_ban"];

				$sql_delete_entry = "UPDATE users SET Blocked = 'yes' WHERE username = '".$username."';";
				$mysqli->query($sql_delete_entry);
				$sql_select_all = "SELECT Nume,Prenume,username AS UN,Email FROM users WHERE username!='admin' AND Blocked!='yes';";
				if ($results = $mysqli->query($sql_select_all)){
					while($rows = mysqli_fetch_array($results)) {
		?>
		<tr>
			<td><?php echo $rows['Nume'] ?></td>
			<td><?php echo $rows['Prenume'] ?></td>
			<td><?php echo $rows['UN'] ?></td>
			<td><?php echo $rows['Email'] ?></td>
		</tr>
		<?php
					}
				}	
			}
			else{
				$sql_select_all = "SELECT Nume,Prenume,username AS UN,Email FROM users WHERE username!='admin'AND Blocked!='yes'";
				if ($results = $mysqli->query($sql_select_all)){
					while($rows = mysqli_fetch_array($results)) {
		?>
		<tr>
			<td><?php echo $rows['Nume'] ?></td>
			<td><?php echo $rows['Prenume'] ?></td>
			<td><?php echo $rows['UN'] ?></td>
			<td><?php echo $rows['Email'] ?></td>
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