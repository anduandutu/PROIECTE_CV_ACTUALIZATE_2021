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
<link rel="stylesheet" href="style_forums_list.css?version=4">
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
	      					<a href="all_article_posts.php" class="dropdown-item">Articles</a>
	                    </div>
                	</li>
                	<li class="nav-item dropdown">
                    	<a href="#" class="nav-link dropdown-toggle" data-toggle="dropdown">Products</a>
	                    <div class="dropdown-menu">
	                       	<a href="view_list_products.php?category=cards" class="dropdown-item ">Yu-Gi-Oh! cards</a>
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

	<div class = "home_page">
		<!-- main page - articles -->
		<div class = "main_page">
			<div class="row">
				<div class="col-12">
					<h2 class = "path"> LIST OF FORUM THREADS</h2>
				</div>
				<div class="col-12">
					<button><a style="color: black; font-size: 25px;" href = "forums_list.php?new_thread=true">Add a new forum thread</a></button>
				</div>
			</div>
			
			<?php
				if(isset($_GET['new_thread'])){
			?>
			<div class = "review">
				<form action="forums_list.php?submitted=true?>" method="post">
					<textarea name = "interventie" class = "recenzie" rows="4" cols="50">
					</textarea>
					<input type="submit" style="height: 40px; width: 100px;">
				</form>
			</div>
			<?php
				}
				if(isset($_GET['submitted'])){
					$interventie = $_POST["interventie"];
					$sql_insert_interventie = "INSERT INTO forums(Forum_Subject, Initiator, Data_initiere) VALUES('".$interventie."', (SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION['username']."'),CURRENT_TIMESTAMP)";
					$mysqli->query($sql_insert_interventie);
					$URL="forums_list.php";
					echo '<META HTTP-EQUIV="refresh" content="0;URL=' . $URL . '">';
				}
			?>
			<?php
			$sql_query_posts = "(SELECT ID_Forum,Forum_Subject, Data_initiere, Initiator FROM forums WHERE Initiator IN (SELECT ID_Utilizator FROM users WHERE username = 'admin') ORDER BY Data_initiere DESC) UNION (SELECT ID_Forum,Forum_Subject, Data_initiere, Initiator FROM forums WHERE Initiator IN (SELECT ID_Utilizator FROM users WHERE username != 'admin') ORDER BY Data_initiere DESC)";
			if ($result = $mysqli->query($sql_query_posts)) {

				//get the number of total pages needed for display
	    		$results_per_page = 2;
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
				$sql_limit_on_page="(SELECT ID_Forum,Forum_Subject, Data_initiere, Initiator FROM forums WHERE Initiator IN (SELECT ID_Utilizator FROM users WHERE username = 'admin') ORDER BY Data_initiere DESC) UNION (SELECT ID_Forum,Forum_Subject, Data_initiere, Initiator FROM forums WHERE Initiator IN (SELECT ID_Utilizator FROM users WHERE username != 'admin') ORDER BY Data_initiere DESC) LIMIT $this_page_first_result, $results_per_page";
				if ($result_on_page = $mysqli->query($sql_limit_on_page)){
					while($row_on_page = mysqli_fetch_array($result_on_page)) {

				?>
					<div class = "post" style="height: auto;">
						<div class = "row row-content_forum_item">
								<h3 class = "p_title col-12"><?php echo $row_on_page['Forum_Subject'] ?></h3>
								<?php 
								
					    			//Selectarea initiatorului
					    			$initiator_id = $row_on_page['Initiator'];
					    			$forum_id = $row_on_page['ID_Forum'];
					    			$sql_initiator= "SELECT Nume,Prenume,username AS UN FROM users WHERE ID_Utilizator = '".$initiator_id."'";
					    			$result_initiator= $mysqli->query($sql_initiator);
					    			$initiator = $result_initiator->fetch_assoc();
								?>
						</div>
						<div class="row row-content">
									<h4 class = "p_description col-12 d-none d-sm-none d-md-block"><?php echo "Created by : ".$initiator['Nume']." ".$initiator['Prenume']." (".$initiator['UN'].") on ".$row_on_page['Data_initiere']; ?></h4>
									<?php
										//Evidentierea numarului de interventii
										$sql_nr_interventii = "SELECT COUNT(*) AS nr_interventii FROM `forum_interventions` WHERE ID_Forum = $forum_id";
										$result_interventii = $mysqli->query($sql_nr_interventii);
										$interventii = mysqli_fetch_array($result_interventii);
										$nr_interventii = $interventii['nr_interventii'];

									?>
									<h4 class = "p_text col-12"><?php echo  "Replies: ".$nr_interventii ?></h4>
										<?php 
											//Evidentierea ultimei persoane care are o interventie
											$sql_ultima_interventie = "SELECT Nume,Prenume FROM users WHERE ID_Utilizator = (SELECT ID_Utilizator FROM `forum_interventions` WHERE ID_Forum = $forum_id ORDER BY Data_interventie DESC LIMIT 1)";
											$result_interventie= $mysqli->query($sql_ultima_interventie);
											$ultima_interventie = mysqli_fetch_array($result_interventie);
											if(mysqli_num_rows($result_interventie) > 0){
										?>
									<h4 class = "p_description col-12"><?php echo "Last intervention: ".$ultima_interventie['Nume']." ".$ultima_interventie['Prenume']; ?></h4>
								<?php
									}
								?>
						</div>
						<a href="view_forum_interventions.php?forum_no=<?php echo $row_on_page['ID_Forum'] ?>" class="col-12 col-md-4 offset-md-4 btn btn-info" style="height: 50px; font-size: 20px;">Open forum</a>						
					</div>
				<?php
					}
				}
				echo '<a style="color: black; font-size: 25px;" href="forums_list.php?inc=false&page=' .$page. '" class = "pages">Previous</a> ';
	    		//display links to pages
		    	if($page + $no_pages_links  <= $total_pages){
			    	for($pages = $page; $pages < $page + $no_pages_links ;$pages++){
			    			 echo '<a style="color: black; font-size: 25px;" href="forums_list.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
		    	else{
		   			$last_pages_display = $total_pages - $no_pages_links;
		    	}
		    	if($last_pages_display >= 0){
		    		for($pages = $last_pages_display + 1; $pages <=$total_pages;$pages++){
			    			 echo '<a style="color: black; font-size: 25px;" href="forums_list.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
		    	else{
		    		for($pages = 1; $pages <= $total_pages ;$pages++){
			    			 echo '<a style="color: black; font-size: 25px;" href="forums_list.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
	    		echo '<a style="color: black; font-size: 25px;" href="forums_list.php?inc=true&page='. $page. '" class = "pages">Next</a> ';

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