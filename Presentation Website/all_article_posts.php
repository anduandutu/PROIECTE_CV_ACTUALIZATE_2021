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
<link rel="stylesheet" href="style_list_results.css?version = 7">
<link rel="stylesheet" href="node_modules/bootstrap/dist/css/bootstrap.min.css">
<link rel="stylesheet" href="node_modules/font-awesome/css/font-awesome.min.css">
<link rel="stylesheet" href="node_modules/bootstrap-social/bootstrap-social.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
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
                    <li class="nav-item"><a class="nav-link" href="index.php"><span class="fa fa-home fa-lg"></span> Home</a></li>
                    <li class="nav-item dropdown">
                    	<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown">News</a>
	                    <div class="dropdown-menu">
	                       	<a href="all_blog_posts.php" class="dropdown-item">Blog</a>
	      					<a href="all_article_posts.php" class="dropdown-item active">Articles</a>
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

	<div class = "home_page">
		<!-- main page - articles -->
		<div class = "main_page">
			<h2 class = "path"> LIST OF ARTICLES</h2>
			<?php
			$sql_query_posts = "SELECT Post_TEXT, Post_Description , Posting_date, Post_Title, Post_ID FROM posts WHERE Post_Type = 'article' ORDER BY Posting_date DESC";
			if ($result = $mysqli->query($sql_query_posts)) {

				//get the number of total pages needed for display
	    		$results_per_page = 5;
				$no_pages_links = 5;
	    		$total_no_posts = mysqli_num_rows($result);
	    		if($total_no_posts/$results_per_page > 1){
	    			if($total_no_posts % $results_per_page == 0){
	    				$total_pages = $total_no_posts/$results_per_page;
	    			}
	    			else{
	    				$total_pages = floor($total_no_posts/$results_per_page + 1);
	    			}
	    		}
	    		else{
	    			$total_pages = 1;
	    		}

	    		// determine which page number visitor is currently on
				if (!isset($_GET['page'])) {
				  	$page = 1;
				} else {
				  	$page = $_GET['page'];
				}

				//setting page according to previous and next buttons
				if (isset($_GET['inc'])){
						if($_GET['inc'] == 'false'){
							if($page - 1 >= 1){
								$page = $page - 1;
							}
							else{
								$page = 1;
							}
						}
						else if ($_GET['inc'] == 'true'){
							if($page + 1 <= $total_pages){
								$page = $page + 1;
							}
							else{
								$page = $total_pages;
							}
						}
				}

				// determine the sql LIMIT starting number for the results on the displaying page
				$this_page_first_result = ($page-1)*$results_per_page;

				// retrieve selected results from database and display them on page
				$sql_limit_on_page='SELECT Post_TEXT, Post_Description , Posting_date, Post_Title, Post_ID FROM posts WHERE Post_Type = "article" ORDER BY Posting_date DESC LIMIT ' . $this_page_first_result . ',' .  $results_per_page;
				if ($result_on_page = $mysqli->query($sql_limit_on_page)){
					while($row_on_page = mysqli_fetch_array($result_on_page)) {
				  	
				  	$string = $row_on_page['Post_TEXT'];
		    		$pozitie = 180;
		    		if(strpos($string, '<img') !== false){
		    			$pozitie = strpos($string, '<img');
		    		}
		    		$text_string = (strlen($string) > $pozitie) ? substr($string,0,$pozitie).'...' : $string;

				?>
					<div class = "media border p-3 d-none d-sm-none d-xl-block" style=" width: auto; height: 300px;">
						<div class = "media-left">
							<?php 
							
				    			//select the relevant image associated with the post
				    			$post_id = $row_on_page['Post_ID'];
				    			$sql_imagine = "SELECT DISTINCT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'da' AND Tip_asociere = 'postare'";
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
						<div class = "media-body">
							<h2 class = "p_title"><?php echo $row_on_page['Post_Title'] ?></h2>
							<p class = "p_date"><?php echo $row_on_page['Posting_date'] ?></p>
							<h5 class = "p_description"><?php echo "Description: ".$row_on_page['Post_Description'] ?></h3>
							<h5 class  = "p_text" ><?php echo  "$text_string" ?></h3>
							<br>
							<a href="view_article_full_post.php?post_no=<?php echo $row_on_page['Post_ID'] ?>" class = "btn btn-info" style="float:right;">Read more</a>
						</div>
					</div>
					<div class="card d-block d-sm-block d-xl-none" style="width:auto">
							<?php 
							
				    			//select the relevant image associated with the post
				    			$post_id = $row_on_page['Post_ID'];
				    			$sql_imagine = "SELECT DISTINCT Imagine FROM imagini_website WHERE ID_Postare = $post_id AND LOWER(Main) = 'da' AND Tip_asociere = 'postare'";
				    			$result_imag= $mysqli->query($sql_imagine);
				    			$row_imag = $result_imag->fetch_assoc();
				    			if(mysqli_num_rows($result_imag) > 0){

							?>
								<?php echo "<img class='card-img-top'  alt='Card image' src='data:image/jpeg;base64," . base64_encode( $row_imag['Imagine'] ) . "'/>"; ?>
							<?php 
								}
								else{
							?>
								<?php echo "<img src='./placeholder.jpg' class='card-img-top'  alt='Card image'/>"; ?>
							<?php
								}
							?>
					    <div class="card-body">
					      <h3 class="card-title" style="color:black;"><?php echo $row_on_page['Post_Title']." Posted on ".$row_on_page['Posting_date'] ?></h3>
					      <p class="card-text" style="color:black;"><?php echo "Description: ".$row_on_page['Post_Description'] ?></p>
					      <a href="view_article_full_post.php?post_no=<?php echo $row_on_page['Post_ID'] ?>" class="btn btn-primary">Read More</a>
					    </div>
					</div>
				<?php
					}
				}
				echo '<a href="all_article_posts.php?inc=false&page=' .$page. '" class = "pages">Previous</a> ';
	    		//display links to pages
		    	if($page + $no_pages_links  <= $total_pages){
			    	for($pages = $page; $pages < $page + $no_pages_links ;$pages++){
			    			 echo '<a href="all_article_posts.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
		    	else{
		   			$last_pages_display = $total_pages - $no_pages_links;
		    	}
		    	if($last_pages_display >= 0){
		    		for($pages = $last_pages_display + 1; $pages <=$total_pages;$pages++){
			    			 echo '<a href="all_article_posts.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
		    	else{
		    		for($pages = 1; $pages <= $total_pages ;$pages++){
			    			 echo '<a href="all_article_posts.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
	    		echo '<a href="all_article_posts.php?inc=true&page='. $page. '" class = "pages">Next</a> ';

			}
			?>
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