<?php
// Initialize the session
session_start();
// Include config file
require_once "generate_xml.php";
$cart = $_SESSION["shopping_cart_no"];
use PHPMailer\PHPMailer\PHPMailer;
  use PHPMailer\PHPMailer\Exception;
  use PHPMailer\PHPMailer\SMTP;
  require 'PHPMailer-master/src/Exception.php';
  require 'PHPMailer-master/src/PHPMailer.php';
  require 'PHPMailer-master/src/SMTP.php';
?>


<!-- HTML begin -->
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
<meta name="viewport" content="width=device-width, initial-scale=1, ">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" href="style_home_page.css?version=11">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<link rel="stylesheet" href="node_modules/bootstrap/dist/css/bootstrap.min.css">
<link rel="stylesheet" href="node_modules/font-awesome/css/font-awesome.min.css">
<link rel="stylesheet" href="node_modules/bootstrap-social/bootstrap-social.css">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.css" />
</head>
<body>

<!-- PHP functions -->
<?php
    function logout() {
        $_SESSION["loggedin"] = false;
    }

    if (isset($_GET['logout'])) {
        logout();
    }
  
    if(isset($_POST["remove_product"])){
        if(isset($_GET["prod_del"])){
            $nume_prod_to_remove = $_GET["prod_del"];
            echo "<h2 style = 'color:white'>DELETED $nume_prod_to_remove</h2>";
            $sql_remove_element = "DELETE FROM comenzi WHERE ID_Produs = (SELECT P_ID FROM products WHERE P_name = '".$nume_prod_to_remove."') AND ID_Lista = $cart";
            $mysqli->query($sql_remove_element);
        }    
    }
    if(isset($_POST["submit_order"])){
        if(isset($_GET["order"])){
            $order = $_GET["order"];
            echo "<h2 style = 'color:white'>ORDER SUBMITTED FOR CART  $order</h2>";
            $sql_update_status = "UPDATE liste_comenzi SET Status_Comanda = 'SENT' WHERE ID_Inregistrare = $order";
            $mysqli->query($sql_update_status);
            $_SESSION["STATUS_COMANDA"] = 'SENT';
        }
    }
    if(isset($_POST["submit_user_data"])){
        if(isset($_POST["TelNum"])){
            $phone = $_POST["TelNum"];
        }
        if(isset($_POST["fullName"])){
            $full_name = $_POST["fullName"];
        }
        if(isset($_POST["CNP"])){
            $cnp = $_POST["CNP"];
        }

        $sql_get_credentials = "SELECT Email,Parola FROM users WHERE username = '".$_SESSION["username"]."'";
        $credentials = $mysqli->query($sql_get_credentials);
        $data_credentials = mysqli_fetch_array($credentials);

        //SMTP needs accurate times, and the PHP time zone MUST be set
        //This should be done in your php.ini, but this is how to do it if you don't have access to that
        date_default_timezone_set('Etc/UTC');

        //Create a new PHPMailer instance
        $mail = new PHPMailer;
        //Tell PHPMailer to use SMTP
        $mail->isSMTP();
        //Enable SMTP debugging
        // SMTP::DEBUG_OFF = off (for production use)
        // SMTP::DEBUG_CLIENT = client messages
        // SMTP::DEBUG_SERVER = client and server messages
        $mail->SMTPDebug = SMTP::DEBUG_OFF;
        //Set the hostname of the mail server
        $mail->Host = 'smtp.gmail.com';
        //Set the SMTP port number - likely to be 25, 465 or 587
        $mail->Port = 587;
        //Whether to use SMTP authentication
        $mail->SMTPAuth = true;
        //Username to use for SMTP authentication
        $mail->Username = $data_credentials["Email"];
        //Password to use for SMTP authentication
        $mail->Password = $data_credentials["Parola"];
        //Set who the message is to be sent from
        $mail->setFrom($data_credentials["Email"], 'Client');
        //Set an alternative reply-to address
        $mail->addReplyTo($data_credentials["Email"], 'Client');
        //Set who the message is to be sent to
        $success = true;
        $sql_admin="SELECT Email FROM users WHERE username = 'admin'";
        if ($result_admin = $mysqli->query($sql_admin)){
            while($row_admin = mysqli_fetch_array($result_admin)) {
                    $mail->addAddress($row_admin['Email']);
            }
        }
        //Set the subject line
        $mail->Subject = 'New Order!';
        $sql_select_all = "SELECT C.Pret_cumparare,C.ID_Lista,C.Cantitate,P.P_name,P.P_unit,P.Reducere,L.Status_Comanda FROM comenzi C , products P,liste_comenzi L WHERE C.ID_Produs = P.P_ID AND C.ID_Lista = $cart AND L.Status_Comanda='SENT' AND L.ID_Inregistrare = C.ID_Lista";

        $body="";
        if ($results = $mysqli->query($sql_select_all)){
            while($rows = mysqli_fetch_array($results)) {
                        $body = $body."<tr>";
                        $body = $body."<td>".$rows["P_name"]."</td>";
                        $body = $body."<td>".$rows["P_unit"]."</td>";
                        $body = $body."<td>".$rows["Cantitate"]."</td>";
                        $body = $body."<td>".$rows["Pret_cumparare"]."</td>";
                        $body = $body."<td>".$rows["Reducere"]."</td>";
                        $body = $body."</tr>";
            }
        }
        $total = 0.00;
        //EURO
        $sql_total_plata_euro = "SELECT SUM(C.Cantitate * C.Pret_cumparare) AS Total_comanda FROM comenzi C , products P,liste_comenzi L WHERE C.ID_Lista = $cart AND L.Status_Comanda='SENT' AND L.ID_Inregistrare = C.ID_Lista AND P.P_unit = 'euro' AND C.ID_Produs = P.P_ID";
        $result_plata_euro = $mysqli->query($sql_total_plata_euro);
        $row_plata_euro = mysqli_fetch_array($result_plata_euro);
        $total_euro = $row_plata_euro["Total_comanda"];
        //LEU
        $sql_total_plata_lei = "SELECT SUM(C.Cantitate * C.Pret_cumparare) AS Total_comanda FROM comenzi C , products P,liste_comenzi L WHERE C.ID_Lista = $cart AND L.Status_Comanda='SENT' AND L.ID_Inregistrare = C.ID_Lista AND P.P_unit = 'lei' AND C.ID_Produs = P.P_ID";
        $result_plata_lei = $mysqli->query($sql_total_plata_lei);
        $row_plata_lei = mysqli_fetch_array($result_plata_lei);
        $total_lei = $row_plata_lei["Total_comanda"];
        //DOLAR
        $sql_total_plata_dolar = "SELECT SUM(C.Cantitate * C.Pret_cumparare) AS Total_comanda FROM comenzi C , products P,liste_comenzi L WHERE C.ID_Lista = $cart AND L.Status_Comanda='SENT' AND L.ID_Inregistrare = C.ID_Lista AND P.P_unit = 'dolar' AND C.ID_Produs = P.P_ID";
        $result_plata_dolar = $mysqli->query($sql_total_plata_dolar);
        $row_plata_dolar = mysqli_fetch_array($result_plata_dolar);
        $total_dolar = $row_plata_dolar["Total_comanda"];

        $total = $total + $total_lei + 4.07 * $total_dolar + 4.83*$total_euro;
        //Read an HTML message body from an external file, convert referenced images to embedded,
        //convert HTML into a basic plain-text alternative body
        $mail->msgHTML("HELLO, a new order has been placed by ".$full_name."<br>CNP :".$cnp."<br> Phone Number: ".$phone."
                        <br>
                      <table class='table table-bordered'>
                      <thead>
                      <tr>
                        <th>Nume Produs</th>
                        <th>Unitate Produs</th>
                        <th>Cantitatea</th>
                        <th>Pret cumparare</th>
                        <th>Reducere aplicata</th>
                      </tr>
                    </thead>
                    <tbody>
                        ".$body."
                    </tbody>
                    </table>
                    <br>
                    TOTAL COMANDA : ".$total." RON
                    ");
        //Replace the plain text body with one created manually
        $mail->AltBody = 'This is a plain-text message body';
        //send the message, check for errors
        if (!$mail->send()) {
            $success = false;

        } else {
            $success = true;
        }

        if($success == true){
            echo "<h2 style = 'color:white;'>Order has been placed!</h2>";

            //update total
            $sql_update_total = "UPDATE liste_comenzi SET Total_comanda = $total WHERE ID_Inregistrare = $cart";
            $mysqli->query($sql_update_total);      
            //initializare cos de cumparaturi gol          
            $sql_insert_comanda = "INSERT INTO liste_comenzi(ID_Utilizator,Data_comenzii,Total_comanda) VALUES((SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION["username"]."'),CURRENT_TIMESTAMP,0)";
            $mysqli->query($sql_insert_comanda);
            //vatriabila de sesiune este id-ul cosului nou creat
            $sql_id_cos = "SELECT ID_Inregistrare FROM liste_comenzi WHERE ID_Utilizator =  (SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION["username"]."') ORDER BY Data_comenzii DESC LIMIT 1";
            $results = $mysqli->query($sql_id_cos);
            $id_cos = $results->fetch_assoc();
            $_SESSION["shopping_cart_no"] = $id_cos["ID_Inregistrare"];
            $_SESSION["STATUS_COMANDA"] = 'NOT SENT';
        }
        else{
             echo "<h2 style = 'color:white;'>Something went wrong!</h2>";
        }
    }
?>


<div id = "main">
	<header class="jumbotron"> <!-- separates the jumbotron from the rest of the page-->
        <div class="container">
            <div class="row row-header">
                <div class="col-12 col-sm-6">
				    <a href="index.php" class = "logo" title = "home" alt = "home">
				        <img alt="Home" src="./placeholder.jpg" class="col col-md-7" style="border-radius: 50px;">
				    </a>
                </div>
                <div class="col-12 col-sm-6">
                			<div class="row">

                				<!-- aici vin link-uri catre conturi -->
	                			<a href = ""><input type="image" src="facebook.png" name="saveForm" class="new_buttons" id="saveForm" /></a>
								<a href = ""><input type="image" src="instagram.jpg" name="saveForm" class="new_buttons" id="saveForm" /></a>
								<a href = ""><input type="image" src="youtube.jpg" name="saveForm" class="new_buttons" id="saveForm" /></a>
								<a href = ""><input type="image" src="pinterest.jpg" name="saveForm" class="new_buttons" id="saveForm" /></a>
								<a href = ""><input type="image" src="twitter.png" name="saveForm" class="new_buttons" id="saveForm" /></a>
                    		</div>
                        	<div class="row">
                        		<input type="text" onkeyup="showResult(this.value)">
                        	</div>
                        	<div class="row">
								<div class = "scroll col-12" id="livesearch" style = "  padding:4px 4px 4px 0px; background-color: black; 
			  						width: 250px; height: 150px; overflow-x: hidden; overflow-y: auto; text-align:justify;">
			  					</div>
		  					</div>	
                </div>
            </div>
        </div>
    </header>
	<!-- Bootstrapp added -->
	<nav class="navbar navbar-dark navbar-expand-sm fixed"> 
        <div class="container">
            <!--responsive navigation bar-->
            <button class="navbar-toggler" type = "button" data-toggle = "collapse" data-target = '#Navbar'>
                <!--data-toggle -- kinda JS related -->
                <!-- data-target is another div which has an id of Navbar and will be rendered when collapsing -->
                <span class="navbar-toggler-icon"> </span>
            </button>
            <div class="collapse navbar-collapse" id = "Navbar">
                <ul class="navbar-nav mr-auto"><!-- mr-auto is used to specify the right margin for the right margin (content is pushed as left as possible)-->
                    <!-- we use fa-lg in order to have bigger icons--->
                    <!-- we use either span or i in order to specify font-awesome icons--->
                    <li class="nav-item active"><a class="nav-link" href="index.php"><span class="fa fa-home fa-lg"></span> Home</a></li>
                    <li class="nav-item dropdown">
                    	<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown">News</a>
	                    <div class="dropdown-menu">
	                       	<a href="all_blog_posts.php" class="dropdown-item">Blog</a>
	      					<a href="all_article_posts.php" class="dropdown-item">Articles</a>
	                    </div>
                	</li>
                	<li class="nav-item dropdown">
                    	<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown">Products</a>
	                    <div class="dropdown-menu">
	                       	<a href="view_list_products.php?category=cards" class="dropdown-item">Yu-Gi-Oh! cards</a>
	      					<a href="view_list_products.php?category=sleeves" class="dropdown-item">Sleeves</a>
	                    </div>
                	</li>
                	<li class="nav-item">
               			<span class="navbar-text" style="padding-right: 8px;">
                			<a href="all_events.php">Events</a>
                		</span>
                	</li>
                	<li class="nav-item">
                		<span class="navbar-text" style="padding-right: 8px;">
                			<a href="forums_list.php">Forums</a>
                		</span>
                	</li>
                	<?php
					  	if($_SESSION["loggedin"] == true){
						  	if($_SESSION['username'] == 'admin'){
						  ?>
							<li class="nav-item dropdown">
		                    	<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown">Admin options</a>
			                    <div class="dropdown-menu">
				                 	<a href="article_writer.php?post_type=blog" class="dropdown-item">Write a blog</a>
							        <a href="article_writer.php?post_type=article" class="dropdown-item">Write an article</a>
							        <a href="add_product.php" class="dropdown-item">Add a new product</a>
							        <a href="user_ban.php" class="dropdown-item">Ban a certain user</a>
							        <a href="add_events.php" class="dropdown-item">Initiate a new event</a>
                                    <a href="set_deliveries.php" class="dropdown-item">Finish a certain delivery</a>
			                    </div>
	                		</li>
						  <?php
							}
						}
					?>
					<li class="nav-item dropdown">
		                    	<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown">User settings </a>
			                    <div class="dropdown-menu">
									<?php
								    	if(!isset($_SESSION["loggedin"]) || $_SESSION["loggedin"] !== true){
								    		echo "<a href='login.php' class = 'dropdown-item'>Login</a>";
								    	}
								    	else{
								    		echo "<a href='#username'> Logged as ".$_SESSION["username"]."</a>";
								    		echo "<a href='password_reset.php' class='dropdown-item'>Reset Your Password</a>";
								    		echo "<a href='index.php?logout=true' class='dropdown-item'>Logout</a>";
								    		echo "<a href='shopping_cart.php' class='dropdown-item'>My Shopping Cart</a>";
								    	}
							    	?>   
			                    </div>
	                </li>
                </ul>
            </div>
        </div>
    </nav>
    <!--presentation clip -->
    <!---<div class="container">-->
        <!--<div class="row row-content">-->
           <div class="col">
                <div id="mycarousel" class="carousel slide" data-ride="carousel">
                    <div class="carousel-inner" role="listbox">
                        <div class="carousel-item active">
                            <img class="d-block img-fluid" src="background.jpg">
                        </div>
                        <div class="carousel-item">
                             <img class="d-block img-fluid" src="pinterest.jpg">
                        </div>
                        <div class="carousel-item">
                            <img class="d-block img-fluid" src="placeholder.jpg">
                        </div>
                    </div>
                    <ol class="carousel-indicators">
                        <li data-target="#mycarousel" data-slide-to="0" class="active"></li>
                        <li data-target="#mycarousel" data-slide-to="1"></li>
                        <li data-target="#mycarousel" data-slide-to="2"></li>
                    </ol>
                    <a class="carousel-control-prev" href="#mycarousel" role="button" data-slide="prev">
                        <span class="carousel-control-prev-icon"></span>
                    </a>
                    <a class="carousel-control-next" href="#mycarousel" role="button" data-slide="next">
                        <span class="carousel-control-next-icon"></span>
                    </a>
                    <button class="btn btn-danger btn-sm" id="carouselButton">
                        <span class="fa fa-pause"></span>
                    </button>
                </div>
           </div>
        <!--</div>-->
    <!--</div>-->
	<div class="container" style="background-color: gray;">
        <?php 
            if($_SESSION["STATUS_COMANDA"]==='NOT SENT'){
        ?>
    	    <div class="table-responsive">        
                  <table class="table table-bordered">
                    <thead>
                      <tr>
                        <th>Nume Produs</th>
                        <th>Unitate Produs</th>
                        <th>Cantitatea</th>
                        <th>Pret cumparare Produs</th>
                        <th>Reducere aplicata</th>
                        <th>Anulare</th>
                      </tr>
                    </thead>
                    <tbody>
                        <?php
                            $sql_select_all = "SELECT C.Pret_cumparare,C.ID_Lista,C.Cantitate,P.P_name,P.P_unit,P.Reducere,L.Status_Comanda FROM comenzi C , products P,liste_comenzi L WHERE C.ID_Produs = P.P_ID AND C.ID_Lista = $cart AND L.Status_Comanda='NOT SENT' AND L.ID_Inregistrare = C.ID_Lista";
                            if ($results = $mysqli->query($sql_select_all)){
                                 while($rows = mysqli_fetch_array($results)) {
                        ?>
                        <tr>
                            <td><?php echo $rows["P_name"] ?></td>
                            <td><?php echo $rows["P_unit"] ?></td>
                            <td><?php echo $rows["Cantitate"] ?></td>
                            <td><?php echo $rows["Pret_cumparare"] ?></td>
                            <td><?php echo $rows["Reducere"]." %" ?></td>
                            <td>
                                <form method="POST" action="<?php echo $_SERVER['PHP_SELF']."?prod_del=".$rows["P_name"]; ?>">
                                    <div class="form-group row">
                                        <input type="submit" class="btn btn-sm btn-block btn-danger col-12" name="remove_product" value="DELETE ITEM">
                                    </div>
                                </form>
                            </td>
                        </tr>
                        <?php
                                }
                            }
                        ?>
                    </tbody>
                  </table>
            </div>
            <form method="POST" action="<?php echo $_SERVER['PHP_SELF']."?order=".$cart; ?>">
                <div class="form-group row">
                    <input type="submit" class="btn btn-lg btn-block btn-success col-12" name="submit_order" value="SUBMIT ORDER">
                </div>
            </form>
        <?php
            }
            else if($_SESSION["STATUS_COMANDA"] === 'SENT'){
        ?>
            <form method="POST" action="<?php echo $_SERVER['PHP_SELF']."?order=".$cart; ?>">
                <div class="form-group row">
                    <label for="fullName" class="col-md-2 col-form-label">Full Name</label>
                    <div class="col-md-10">
                        <input type="text" class="form-control" id="fullName" name="fullName" placeholder="Full Name">
                    </div>
                </div>
                <div class="form-group row">
                    <label for="CNP" class="col-md-2 col-form-label">CNP</label>
                    <div class="col-md-10">
                        <input type="text" class="form-control" id="CNP" name="CNP" placeholder="CNP">
                    </div>
                </div>
                <div class="form-group row">
                    <label for="TelNum" class="col-md-2 col-form-label">PHONE NUMBER</label>
                    <div class="col-md-10">
                        <input type="text" class="form-control" id="TelNum" name="TelNum" placeholder="TelNum">
                    </div>
                </div>
                <div class="form-group row">
                    <input type="submit" class="btn btn-lg btn-block btn-success col-12" name="submit_user_data" value="FINISH ORDER">
                </div>
            </form>
        <?php
            }
        ?>
	</div>
	<!-- footer start -->

</div>
</body>
</html>
<script src="node_modules/jquery/dist/jquery.slim.min.js"></script>
<script src="node_modules/popper.js/dist/umd/popper.min.js"></script>
<script src="node_modules/bootstrap/dist/js/bootstrap.min.js"></script>
<script>
  $(document).ready(function(){
            $("#mycarousel").carousel( { interval: 2000 } );
            $("#carouselButton").click(function(){
                if($('#carouselButton').children('span').hasClass('fa fa-pause')){
                    $("#mycarousel").carousel('pause');
                    $('#carouselButton').children('span').removeClass('fa fa-pause'); //remove class
                    $('#carouselButton').children('span').addClass('fa fa-play'); //change from pause to play
                }
                else if($('#carouselButton').children('span').hasClass('fa fa-play')){
                    $("#mycarousel").carousel('cycle');
                    $('#carouselButton').children('span').removeClass('fa fa-play'); //remove class
                    $('#carouselButton').children('span').addClass('fa fa-pause'); // change from play to pause
                }
            });
        });
  function showResult(str) {
	  if (str.length==0) {
	    document.getElementById("livesearch").innerHTML="";
	    document.getElementById("livesearch").style.border="0px";
	    return;
	  }
	  var xmlhttp=new XMLHttpRequest();
	  xmlhttp.onreadystatechange=function() {
	    if (this.readyState==4 && this.status==200) {
	      document.getElementById("livesearch").innerHTML=this.responseText;
	      document.getElementById("livesearch").style.border="1px solid #A5ACB2";
	    }
	  }
	  xmlhttp.open("GET","livesearch.php?q="+str,true);
	  xmlhttp.send();
 }
</script>