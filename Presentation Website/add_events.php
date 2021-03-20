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
	if(isset($_POST["submit_event"])){
		$event_name = $event_description = $event_start_date = $event_end_date = "";
		if(isset($_POST["date_start"])){
			$start = strtotime($_POST["date_start"]);
			$event_start_date = date('Y-m-d',$start);
		}
		if(isset($_POST["date_end"])){
			$end = strtotime($_POST["date_end"]);
			$event_end_date = date('Y-m-d',$end);
		}
		if(isset($_POST["event_name"])){
			$event_name = $_POST["event_name"];
		}
		if(isset($_POST["event_description"])){
			$event_description = $_POST["event_description"];
		}
		if (count($_FILES) > 0) {
		    if (is_uploaded_file($_FILES['image']['tmp_name'])) {
		        $image = addslashes(file_get_contents($_FILES['image']['tmp_name']));
		    }
		}

		$sql_select_unicity_event = "SELECT COUNT(*) AS uncicity FROM events WHERE Event_name = '".$event_name."'";
		$result_u= $mysqli->query($sql_select_unicity_event);
		$get_u = mysqli_fetch_array($result_u);
		if($get_u["uncicity"] == 1){
			echo "<h2>Please choose another event name</h2>";
		}
		if($get_u["uncicity"] == 0){
			$sql_insert_event = "INSERT INTO events(Event_name,Start_Date,End_Date,Event_Description) VALUES('".$event_name."',CAST('". $event_start_date ."' AS DATE),CAST('". $event_end_date ."' AS DATE),'".$event_description."')";
			$mysqli->query($sql_insert_event);

			//then get the new P_ID
			$select_id_prod = "SELECT ID_Event FROM events WHERE Event_name = '".$event_name."';";
			$result_id = $mysqli->query($select_id_prod);
			$get_id = mysqli_fetch_array($result_id);
			$id = $get_id["ID_Event"];
			//insert the image
			$sql_insert_main_image = "INSERT INTO imagini_website (Imagine, ID_Postare, Main, Tip_Asociere) VALUES('".$image."',$id,'Da','eveniment');";
			$mysqli->query($sql_insert_main_image);
			echo "<h2>Event inserted successfully</h2>";
		}
	}
?>
<form style="background-color: white;" method="POST" action="add_events.php" enctype="multipart/form-data">
	<a href="index.php" class = "logo" title = "home" alt = "home" style="float: left;">
		<img alt="Home" src="./home.jpg" style="width: 100px; height: 50px;">
	</a>
	<div class = "form-group row" >
		<label for="event_name" class="col-md-2 col-form-label">Event Name</label>
        <div class="col-md-10">
            <input type="text" class="form-control" id="event_name" name="event_name" placeholder="Event Name">
        </div>
	</div>
	<div class = "form-group row">
		<label for="event_description" class="col-md-2 col-form-label">Event Description</label>
        <div class="col-md-10">
            <textarea class="form-control" id="event_description" name="event_description" rows="12"></textarea>
        </div>
	</div>
	<div class = "form-group row">
			<label for="main_prod_image" class="col-md-2 col-form-label">Event Image: </label>
			<input type="file" name="image">
	</div>
	<div class = "form-group row">
		<label for="date_start" class="col-md-2 col-form-label">Event Start Date</label>
        <div class="col-md-10">
            <input type="date" class="form-control" id="date_start" name="date_start" placeholder="Event Start Date">
        </div>
	</div>
	<div class = "form-group row">
		<label for="date_end" class="col-md-2 col-form-label">Event End Date</label>
        <div class="col-md-10">
            <input type="date" class="form-control" id="date_end" name="date_end" placeholder="Event End Date">
        </div>
	</div>
	<div class="form-group row">
		<input type="submit" name="submit_event" style="width: 700px;height: 50px;">
	</div>
</form>
</body>
</html>
<script src="node_modules/jquery/dist/jquery.slim.min.js"></script>
<script src="node_modules/popper.js/dist/umd/popper.min.js"></script>
<script src="node_modules/bootstrap/dist/js/bootstrap.min.js"></script>