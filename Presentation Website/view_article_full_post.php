<?php
// Initialize the session
session_start();
if(isset($_GET['post_no'])) {
 	$post_no=$_GET['post_no'];
 }
// Include config file
require_once "generate_xml.php";
?>


<!-- HTML begin -->
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
<link rel="stylesheet" href="style_article.css?version=6">
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
  function logout() {
    $_SESSION["loggedin"] = false;
  }

  if (isset($_GET['logout'])) {
    logout();
  }

  if(isset($_POST['read_article'])) { 
    echo "This is read article that is selected"; 
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
	<!-- main page start -->
    <div class="modal fade" id="modalLoginForm" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
						  aria-hidden="true">
						      <!-- DE TESTAT DUPA PUBLISHMENT OF WEBSITE -->
							  <div class="modal-dialog" role="document">
							    <div class="modal-content">
									<a href="http://www.facebook.com/sharer.php?u=<?php echo $_SERVER['PHP_SELF']."?post_no=".$post_no; ?>">
								        <span id="facebook" class="fa-stack fa-lg">
								            <i class="fa fa-facebook fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="http://twitter.com/share?text=<?php echo $prod_name; ?>&url=<?php echo $_SERVER['PHP_SELF']."?post_no=".$post_no; ?>&hashtags=#silentKnightGames">
								        <span id="twitter" class="fa-stack fa-lg">
								            <i class="fa fa-twitter fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="http://pinterest.com/pin/create/button/?<?php echo $_SERVER['PHP_SELF']."?post_no=".$post_no; ?>&description=<?php echo $rows['Post_Description'] ?>" class="pin-it-button" count-layout="horizontal">
								        <span id="pinterest" class="fa-stack fa-lg">
								            <i class="fa fa-pinterest-p fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="https://plus.google.com/share?url=<?php echo $_SERVER['PHP_SELF']."?post_no=".$post_no; ?>">
								        <span id="googleplus" class="fa-stack fa-lg">
								            <i class="fa fa-google-plus fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="https://www.linkedin.com/shareArticle?mini=true&<?php echo $_SERVER['PHP_SELF']."?post_no=".$post_no; ?>&title=<?php echo $rows['Post_Title'] ?>&source=SILENT KNIGHT GAMES">
								        <span id="linkedin" class="fa-stack fa-lg">
								            <i class="fa fa-linkedin fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="whatsapp://send?&text=<?php echo $_SERVER['PHP_SELF']."?post_no=".$post_no; ?>" data-action="share/whatsapp/share">
								        <span id="whatsapp" class="fa-stack fa-lg">
								            <i class="fa fa-whatsapp fa-stack-1x"></i>
								        </span>
								    </a>
							    </div>
							  </div>
							  <!--- --->
				</div>
	<div class="container" style="background-color: gray;">
	    <div class="row row-header">
	        <div class="col-sm-12 col-xl-9">
				<h2 class = "path"> POST DETAILS </h2>
				<?php
				//TO_DO de vazut ce e cu undefined 
				$sql_query_posts = "SELECT Post_TEXT, Post_Description , Posting_date, Post_Title,Post_ID FROM posts WHERE Post_ID = $post_no";
				if ($result = $mysqli->query($sql_query_posts)) {

	    		/* fetch associative array */
		    		while ($rows = $result->fetch_assoc()) {
			    		$string = $rows['Post_TEXT'];
			    		$text_string = $string;

				?>
					<div class = "post d-none d-xl-block">
							<a href="" class="btn btn-info btn-lg col-md-3" data-toggle="modal" data-target="#modalLoginForm">Share Post</a>
							<?php 
							
				    			//select the relevant image associated with the post
				    			$post_id = $rows['Post_ID'];
				    			$sql_imagine = "SELECT DISTINCT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'da' AND Tip_asociere = 'postare'";
				    			$result_imag= $mysqli->query($sql_imagine);
				    			$row_imag = $result_imag->fetch_assoc();

				    			if(mysqli_num_rows($result_imag) > 0){

							?>
									<?php echo "<img src='data:image/jpeg;base64," . base64_encode( $row_imag['Imagine'] ) . "' class = 'post_dummy'/>"; ?>
									<!--<a href="" class="btn btn-info btn-lg col-md-3" data-toggle="modal" data-target="#modalLoginForm">Share Post</a>-->
									<h3 class = "p_title"><?php echo $rows['Post_Title'] ?></h1>
									<p class = "p_date"><?php echo $rows['Posting_date'] ?></p>
									<h4 class = "p_description"><?php echo $rows['Post_Description'] ?></h3>
									<h4 class = "p_text"><?php echo  "$text_string" ?></h3>

							<?php
								}
								else{
							?>
									<?php echo "<img src='./placeholder.jpg' class = 'post_dummy'/>"; ?>

									<h3 class = "p_title"><?php echo $rows['Post_Title'] ?></h1>
									<p class = "p_date"><?php echo $rows['Posting_date'] ?></p>
									<h4 class = "p_description"><?php echo $rows['Post_Description'] ?></h3>
									<h5 class = "p_text"><?php echo  "$text_string" ?></h3>
							<?php
								}
							?>
							
					</div>
					<div class = "card d-block d-sm-block d-xl-none" style = "width:100%;margin-top:2%;border-radius:20px;">
							<?php 
							
				    			//select the relevant image associated with the post
				    			$post_id = $rows['Post_ID'];
				    			$sql_imagine = "SELECT DISTINCT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'da' AND Tip_asociere = 'postare'";
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
							<h3 class = "card-title"><?php echo $rows['Post_Title'] ?></h1>
							<p class = "card-title"><?php echo $rows['Posting_date'] ?></p>
							<h4 class = "card-text"><?php echo $rows['Post_Description'] ?></h3>
							<h5 class = "card-text"><?php echo  "$text_string" ?></h3>
							<div class="row">
								<a href="" class="btn btn-info btn-lg col-md-12" data-toggle="modal" data-target="#modalLoginForm">Share Post</a>
							</div>
						</div>
					</div>
				<?php
					}
				}
				?>
		</div>
		<!-- side page - some products -->
		<div class = "col-sm-12 col-xl-3">
			<h3 class = "path" style="text-align: center;"> LOW PRICE PRODUCTS </h3>
			<div class = "product_add">
				<?php
					$sql_query_produse = "SELECT P_name,P_ID FROM products ORDER BY P_price ASC LIMIT 3";
					if ($result = $mysqli->query($sql_query_produse)) {

		    		/* fetch associative array */
			    		while ($rows = $result->fetch_assoc()) {
				?>
				<div class = "product">
					<div class = "product_image">
						<?php 
							$product_id = $rows['P_ID'];
			    			//select the relevant image associated with the product
			    			$sql_imagine = "SELECT DISTINCT Imagine FROM imagini_website WHERE ID_Postare = $product_id AND LOWER(Main) = 'da' AND Tip_asociere ='produs'";
			    			$result_imag = $mysqli->query($sql_imagine);
			    			$row_imag  = $result_imag->fetch_assoc();

						if(mysqli_num_rows($result_imag) > 0){

						?>
						<?php echo "<img src='data:image/jpeg;base64," . base64_encode( $row_imag['Imagine'] ) . "' style='border-radius: 25px;' class = 'post_dummy'/>"; ?>
						<?php 
							}
							else{
						?>
							<?php echo "<img src='./placeholder.jpg' style='border-radius: 25px;' class = 'post_dummy'/>"; ?>
						<?php
							}
						?>
					</div>
					<div class = "product_description">
						<a href="view_product.php?varname=<?php echo $rows['P_name'] ?>"><?php echo $rows['P_name'] ?></a>
					</div>

				</div>
				<?php
					}
				}
				?>
			</div>
		</div>
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