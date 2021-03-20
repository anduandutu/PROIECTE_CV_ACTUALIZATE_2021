<?php
// Initialize the session
session_start();
if(isset($_GET['varname'])) {
 	$prod_name=$_GET['varname'];
}
// Include config file
$liked = false;
require_once "generate_xml.php";
?>


<!-- HTML begin -->
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" href="style_product.css?version=17">
<link rel="stylesheet" href="node_modules/bootstrap/dist/css/bootstrap.min.css">
<link rel="stylesheet" href="node_modules/font-awesome/css/font-awesome.min.css">
<link rel="stylesheet" href="node_modules/bootstrap-social/bootstrap-social.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<script
    type="text/javascript"
    async defer
    src="//assets.pinterest.com/js/pinit.js"
></script>
<script src="https://apis.google.com/js/plusone.js"></script>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.css" />
</head>
<body>

<!-- PHP functions -->
<?php
  $comanda_initiata = false;

  function logout() {
    $_SESSION["loggedin"] = false;
  }

  if (isset($_GET['logout'])) {
    logout();
  }

  if(isset($_POST['read_article'])) { 
    echo "This is read article that is selected"; 
  }

  if(isset($_POST["buy_product"])){
  	if($_SESSION["loggedin"] == true){
  		echo "<h2 style='color:white;'>PRODUCT BOUGHT! </h2>";

  		 //ADUGAREA IN COS
	  	 $cantitate = $_POST["quantity"];
	  	 $sql_insert_comanda = "INSERT INTO comenzi(ID_Utilizator,ID_Produs,Pret_cumparare,Cantitate,ID_Lista) VALUES((SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION["username"]."'), (SELECT P_ID FROM products WHERE P_name = '".$prod_name."'),(SELECT P_Price - P_Price *(Reducere/100) AS Pret_cumparare FROM products WHERE P_name = '".$prod_name."'),$cantitate,(SELECT ID_Inregistrare FROM liste_comenzi WHERE ID_Utilizator = (SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION["username"]."') ORDER BY Data_comenzii DESC LIMIT 1))";
	  	 $mysqli->query($sql_insert_comanda);

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
<div class="modal fade" id="modalLoginForm" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
						  aria-hidden="true">
						      <!-- DE TESTAT DUPA PUBLISHMENT OF WEBSITE -->
							  <div class="modal-dialog" role="document">
							    <div class="modal-content">
									<a href="http://www.facebook.com/sharer.php?u=<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>">
								        <span id="facebook" class="fa-stack fa-lg">
								            <i class="fa fa-facebook fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="http://twitter.com/share?text=<?php echo $prod_name; ?>&url=<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>&hashtags=#silentKnightGames">
								        <span id="twitter" class="fa-stack fa-lg">
								            <i class="fa fa-twitter fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="http://pinterest.com/pin/create/button/?url=<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>&description=<?php echo $row_on_page['Event_Description'] ?>" class="pin-it-button" count-layout="horizontal">
								        <span id="pinterest" class="fa-stack fa-lg">
								            <i class="fa fa-pinterest-p fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="https://plus.google.com/share?url=<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>">
								        <span id="googleplus" class="fa-stack fa-lg">
								            <i class="fa fa-google-plus fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="https://www.linkedin.com/shareArticle?mini=true&url=<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>&title=<?php echo $prod_name; ?>&source=SILENT KNIGHT GAMES">
								        <span id="linkedin" class="fa-stack fa-lg">
								            <i class="fa fa-linkedin fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="whatsapp://send?&text=<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>" data-action="share/whatsapp/share">
								        <span id="whatsapp" class="fa-stack fa-lg">
								            <i class="fa fa-whatsapp fa-stack-1x"></i>
								        </span>
								    </a>
							    </div>
							  </div>
							  <!--- --->
					</div>
	<!-- main page start -->

<div class="container" style="background-color: gray;">
	<div class="row row-header">
	     <div class="col-sm-12 col-xl-9">
			<h2 class = "path"> PRODUCT DETAILS </h2>
			<?php 
			$sql_query_post_details = "SELECT P.P_ID , P.P_name, P.P_description, P.P_price - P.P_Price * (P.Reducere/100) AS Price, P.P_unit, P.ID_Imagine AS main_image, P.Key_Features AS features FROM `products` P WHERE P.P_name = '$prod_name'";
			if ($result = $mysqli->query($sql_query_post_details)) {

    		/* fetch associative array */
	    		while ($rows = $result->fetch_assoc()) {

			?>
				<div class = "post d-none d-xl-block">
					<div class = "post_image">
						<?php 
						
			    			//select the relevant image associated with the post
			    			$post_id = $rows['P_ID'];
			    			$sql_imagine = "SELECT DISTINCT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'da' AND Tip_asociere = 'produs'";
			    			$result_imag= $mysqli->query($sql_imagine);
			    			$row_imag = $result_imag->fetch_assoc();

							if(mysqli_num_rows($result_imag) > 0){

						?>
						<?php echo "<img src='data:image/jpeg;base64," . base64_encode( $row_imag['Imagine'] ) . "' class = 'post_dummy'/>"; ?>
						<?php 
							}
							else{
						?>
							<?php echo "<img src='./placeholder.jpg' class = 'post_dummy'/>"; ?>
						<?php
							}
						?>
					</div>
					
					<div class = "post_content">
						<!-- AICI -->
						<form method="POST" action="<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>">
							<div class="form-group row">
						            <h3 class="col-md-12">Quantity</h3>
						            <div class="col-md-12">
						                <input type="text" class="form-control" id="quantity" name="quantity" placeholder="Enter quantity here ...">
						            </div>
						    </div>
							<div class="form-group row">
								<input type="submit" class="btn btn-success btn-lg col-md-12" name="buy_product" value="BUY ITEM">  
							</div>
							<div class="form-group row">
								<a href="" class="btn btn-info btn-lg col-md-12" data-toggle="modal" data-target="#modalLoginForm">
						    	Share Product</a>  
							</div>
						</form>
						<!-- buton like -->
						<?php
							$prod_id = $rows['P_ID'];
							$sql_verif_like = "SELECT COUNT(*) AS likes FROM likes WHERE ID_user = (SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION['username']."') AND ID_liked = $prod_id AND Tip_like = 'produs'";
							$like_count= $mysqli->query($sql_verif_like);
			    			$likes = $like_count->fetch_assoc();
			    			if($likes['likes'] == 0){
			    				if(isset($_GET['liked'])){
			    					//INSERT LIKE
			    					$insert_like = "INSERT INTO likes(ID_User,Tip_like,ID_liked) VALUES((SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION['username']."'),'produs',$prod_id)";
			    					$mysqli->query($insert_like);
			    					//UPDATE total number of likes
			    					$update_total_likes_product = "UPDATE products SET Likes_no = Likes_no + 1 WHERE P_ID = $prod_id";
			    					$mysqli->query($update_total_likes_product);
			    					//refresh page
			    					$URL="view_product.php?varname=$prod_name";
									echo '<META HTTP-EQUIV="refresh" content="0;URL=' . $URL . '">';
			    				}
						?>
						<h3 class = "prod_title"><?php echo $rows['P_name'] ?><button style = "font-size: 20px; margin-left: 20px;">LIKE : <a style="color: black;" href = "view_product.php?liked=true&varname=<?php echo $prod_name ?>"><img alt="Home" style = "width: 25px; height: 25px;" src="./like.jpg"></a></button></h3>
						<?php
							}
							else{
						?>
						<h3 class = "prod_title"><?php echo $rows['P_name']." --- LIKED" ?></h3>
						<?php
							}
						?>
						<?php
							$sql_likes_count = "SELECT COUNT(*) AS likes FROM likes WHERE ID_liked = $prod_id AND Tip_like = 'produs'";
							if($result_count = $mysqli->query($sql_likes_count)){
								$likes_count = $result_count->fetch_assoc();
							}
						?>
						<h3 class = "prod_price"><?php echo "Number of likes:"." ".$likes_count['likes'] ?></h3>
						<div class="row">
							<h4 class = "prod_price"><?php echo "Pret cumparare:"." ".$rows['Price']." ".$rows['P_unit'] ?></h4>
						</div>
						<br>
						<h5 class = "prod_description"><?php echo $rows['P_description'] ?></h5>
						<div class = "Photo_Gallery">
							<h2>PHOTO GALLERY</h2>
							<?php
								$post_id = $rows['P_ID'];
				    			$sql_gallery = "SELECT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'nu' AND Tip_asociere = 'produs' LIMIT 3";
								if ($result_gallery = $mysqli->query($sql_gallery)) {

						    		/* fetch associative array */
							    	while ($rows_gallery = $result_gallery->fetch_assoc()) {
							?>
								<div class="gallery">
								    <?php echo "<img src='data:image/jpeg;base64," . base64_encode( $rows_gallery['Imagine'] ) . "' class = 'gallery_image_item'/>"; ?>
								</div>
							<?php
									}
								}
							?>
						</div>
					</div>
				</div>

				<div class = "card d-block d-sm-block d-xl-none" style = "width:100%;margin-top:2%;border-radius:20px;">
						<?php 
			    			//select the relevant image associated with the post
			    			$post_id = $rows['P_ID'];
			    			$sql_imagine = "SELECT DISTINCT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'da' AND Tip_asociere = 'produs'";
			    			$result_imag= $mysqli->query($sql_imagine);
			    			$row_imag = $result_imag->fetch_assoc();

							if(mysqli_num_rows($result_imag) > 0){

						?>
						<?php echo "<img src='data:image/jpeg;base64," . base64_encode( $row_imag['Imagine'] ) . "' class = 'post_dummy_sm'/>"; ?>
						<?php 
							}
							else{
						?>
							<?php echo "<img src='./placeholder.jpg' class = 'post_dummy_sm'/>"; ?>
						<?php
							}
						?>

						<div class = "card-body">
							<!-- AICI -->
							<form method="POST" action="<?php echo $_SERVER['PHP_SELF']."?varname=".$prod_name; ?>">
								<div class="form-group row">
							            <h3 class="col-md-12">Quantity</h3>
							            <div class="col-md-12">
							                <input type="text" class="form-control" id="quantity" name="quantity" placeholder="Enter quantity here ...">
							            </div>
							    </div>
								<div class="form-group row">
									<input type="submit" class="btn btn-success btn-lg col-md-12" name="buy_product" value="BUY ITEM">  
								</div>
								<div class="form-group row">
									<a href="" class="btn btn-info btn-lg col-md-12" data-toggle="modal" data-target="#modalLoginForm">
						    	Share Product</a>  
								</div>
							</form>
							<?php
								$prod_id = $rows['P_ID'];
								$sql_verif_like = "SELECT COUNT(*) AS likes FROM likes WHERE ID_user = (SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION['username']."') AND ID_liked = $prod_id AND Tip_like = 'produs'";
								$like_count= $mysqli->query($sql_verif_like);
				    			$likes = $like_count->fetch_assoc();
				    			if($likes['likes'] == 0){
				    				if(isset($_GET['liked'])){
				    					//INSERT LIKE
				    					$insert_like = "INSERT INTO likes(ID_User,Tip_like,ID_liked) VALUES((SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION['username']."'),'produs',$prod_id)";
				    					$mysqli->query($insert_like);
				    					//UPDATE total number of likes
				    					$update_total_likes_product = "UPDATE products SET Likes_no = Likes_no + 1 WHERE P_ID = $prod_id";
				    					$mysqli->query($update_total_likes_product);
				    					//refresh page
				    					$URL="view_product.php?varname=$prod_name";
										echo '<META HTTP-EQUIV="refresh" content="0;URL=' . $URL . '">';
				    				}
							?>
							<h3 class = "card-title"><?php echo $rows['P_name'] ?><button style = "font-size: 20px; margin-left: 20px;">LIKE : <a style="color: black;" href = "view_product.php?liked=true&varname=<?php echo $prod_name ?>"><img alt="Home" style = "width: 25px; height: 25px;" src="./like.jpg"></a></button></h3>
							<?php
								}
								else{
							?>
							<h3 class = "card-text"><?php echo $rows['P_name']." --- LIKED" ?></h3>
							<?php
								}
							?>
							<?php
								$sql_likes_count = "SELECT COUNT(*) AS likes FROM likes WHERE ID_liked = $prod_id AND Tip_like = 'produs'";
								if($result_count = $mysqli->query($sql_likes_count)){
									$likes_count = $result_count->fetch_assoc();
								}
							?>
							<h3 class = "card-text"><?php echo "Number of likes:"." ".$likes_count['likes'] ?></h3>
							<div class="row">
								<h4 class = "card-text"><?php echo "Pret cumparare:"." ".$rows['Price']." ".$rows['P_unit'] ?></h4>
							</div>
							<h5 class = "card-text"><?php echo $rows['P_description'] ?></h5>
							<h5 class = "card-title">PHOTO GALLERY</h5>
								<?php
									$post_id = $rows['P_ID'];
					    			$sql_gallery = "SELECT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'nu' AND Tip_asociere = 'produs' LIMIT 3";
									if ($result_gallery = $mysqli->query($sql_gallery)) {

							    		/* fetch associative array */
								    	while ($rows_gallery = $result_gallery->fetch_assoc()) {
								?>
									    <?php echo "<img src='data:image/jpeg;base64," . base64_encode( $rows_gallery['Imagine'] ) . "' class = 'card-img'/>"; ?>
								<?php
									}
								}
							?>
						</div>
					</div>
			<?php
				}
			}
			?>
		</div>

		<!-- side page - some products -->
		<div class = "col-sm-12 col-xl-3">
			<h3 class = "path row" style="text-align: center;"> PRODUCT KEY FEATURES </h3>
			<div class = "features_all">
				<?php
				$sql_query_features = "SELECT P.Key_Features AS features FROM `products` P WHERE P.P_name = '$prod_name'";
				if ($result_features = $mysqli->query($sql_query_features)) {
	    			$text_features = $result_features->fetch_assoc();
				?>
					<div class="feature_list">
						<ul class = "features">
							<?php
								//IN ADMIN FEATURES SE SCRIU CU - 
								$new_array = explode("-",$text_features['features']);
								unset($new_array[0]);
								foreach($new_array as $feature) {
    								$feature = trim($feature);
							?>
								<li><h4><?php echo $feature ?></h4></li>
							<?php
							}
							?>
						</ul>
					</div>
				<?php
				}
				?>
			</div>

		</div>
	</div>
	<!-- footer start -->
</div>
<div class = "container" style="background-color: gray;">
	<div class="row">
		<h2 class="title_reviews">Reviews <button style = "font-size: 20px;" class = "btn btn-info"><a style="color: black;" href = "view_product.php?new_review=true&varname=<?php echo $prod_name ?>">Add review</a></button> </h2>
		
	</div>
		<?php 
			if(isset($_GET['new_review'])){
		?>
			<form action="view_product.php?submitted=true&varname=<?php echo $prod_name ?>" method="post">
				<div class="form-group row">
					<div class="col-12">
						<textarea id = "recenzie" name = "recenzie" class="form-control" rows="4">
						</textarea>
					</div>
				</div>
				<input type="submit">
			</form>
		<?php
		}
		?>
	<?php
		//if a new review has been submitted
		if(isset($_GET['submitted'])){
			$review = $_POST["recenzie"];
			$sql_insert_review = "INSERT INTO recenzii_produse(P_ID,Text_recenzie,ID_Utilizator) VALUES((SELECT P.P_ID FROM products P WHERE P.P_name = '$prod_name'),'$review',(SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION['username']."'))";
			$mysqli->query($sql_insert_review);
			$URL="view_product.php?varname=$prod_name";
			echo '<META HTTP-EQUIV="refresh" content="0;URL=' . $URL . '">';
		}
		$sql_recenzii = "SELECT Text_recenzie,ID_Utilizator FROM recenzii_produse WHERE P_ID = $post_id";
		if($result_reviews = $mysqli->query($sql_recenzii)){
			while($reviews = $result_reviews->fetch_assoc()){
	?>
		<div class = "review row">
			<?php
				$sql_user = "SELECT Nume,Prenume FROM users WHERE ID_Utilizator = '".$reviews['ID_Utilizator']."'";
				if($result_user = $mysqli->query($sql_user)){
					while($user_post = $result_user->fetch_assoc()){
			?>
			<h4 class = "user_name"><?php echo $user_post['Nume'] . " " . $user_post['Prenume']?></h4>
			<?php
				}
			}
			?>
			<textarea class = "recenzie" rows="4" cols="50" readonly>
				<?php echo $reviews['Text_recenzie']?>
			</textarea>
		</div>
	<?php
		}
	}
	?>
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