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
<link rel="stylesheet" href="style_list_events.css?version=6">
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


  function insert_answer($event_id, $answer, $username){ 
	/* Attempt to connect to MySQL database */
	$mysqli = new mysqli(DB_SERVER, DB_USERNAME, DB_PASSWORD, DB_NAME);
	 
	// Check connection
	if($mysqli === false){
	    die("ERROR: Could not connect. " . $mysqli->connect_error);
	}
  	$sql_verif_raspuns = "SELECT COUNT(Answer) AS Raspuns FROM events_answers WHERE Event_ID = $event_id AND User_ID = (SELECT ID_Utilizator FROM users WHERE username = '".$username."')";
  	if ($result = $mysqli->query($sql_verif_raspuns)){
  		$answered = mysqli_fetch_array($result);
  		if($answered['Raspuns'] == 1){
  			//Facem UPDATE
  			$sql_update = "UPDATE events_answers SET Answer = '".$answer."' WHERE Event_ID = $event_id AND User_ID = (SELECT ID_Utilizator FROM users WHERE username = '".$username."')";
  			$mysqli->query($sql_update);

  		}
  		else{
  			//Facem INSERT
  			$sql_insert = "INSERT INTO events_answers(Event_ID,User_ID,Answer) VALUES($event_id,(SELECT ID_Utilizator FROM users WHERE username = '".$username."'),'".$answer."')";
  			$mysqli->query($sql_insert);
  		}
  	}

  }
  
  if(isset($_GET['selected'])){
  	if(isset($_GET['answer'])){
  		if(isset($_GET['event'])){
  			insert_answer($_GET['event'],$_GET['answer'],$_SESSION['username']);
  		}
  	}
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
	<!-- main page start -->
						<div class="modal fade" id="modalLoginForm" tabindex="-1" role="dialog" aria-labelledby="myModalLabel"
						  aria-hidden="true">
						      <!-- DE TESTAT DUPA PUBLISHMENT OF WEBSITE -->
							  <div class="modal-dialog" role="document">
							    <div class="modal-content">
									<a href="http://www.facebook.com/sharer.php?u=<?php echo $_SERVER['PHP_SELF'];?>">
								        <span id="facebook" class="fa-stack fa-lg">
								            <i class="fa fa-facebook fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="http://twitter.com/share?text=<?php echo $row_on_page['Event_name'] ?>&url=<?php echo $_SERVER['PHP_SELF'];?>&hashtags=#silentKnightGames">
								        <span id="twitter" class="fa-stack fa-lg">
								            <i class="fa fa-twitter fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="http://pinterest.com/pin/create/button/?url=<?php echo $_SERVER['PHP_SELF'];?>&description=<?php echo $row_on_page['Event_Description'] ?>" class="pin-it-button" count-layout="horizontal">
								        <span id="pinterest" class="fa-stack fa-lg">
								            <i class="fa fa-pinterest-p fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="https://plus.google.com/share?url=<?php echo $_SERVER['PHP_SELF'];?>">
								        <span id="googleplus" class="fa-stack fa-lg">
								            <i class="fa fa-google-plus fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="https://www.linkedin.com/shareArticle?mini=true&url=<?php echo $_SERVER['PHP_SELF'];?>&title=<?php echo $row_on_page['Event_name'] ?>&source=SILENT KNIGHT GAMES">
								        <span id="linkedin" class="fa-stack fa-lg">
								            <i class="fa fa-linkedin fa-stack-1x"></i>
								        </span>
								    </a>
								    <a href="whatsapp://send?&text=<?php echo $_SERVER['PHP_SELF'];?>" data-action="share/whatsapp/share">
								        <span id="whatsapp" class="fa-stack fa-lg">
								            <i class="fa fa-whatsapp fa-stack-1x"></i>
								        </span>
								    </a>
							    </div>
							  </div>
							  <!--- --->
						</div>
	<!-- main page start -->

	<div class = "home_page">
		<!-- main page - articles -->
		<div class = "main_page">
			<h2 class = "path"> LIST OF EVENTS</h2>
			<?php
			$sql_query_posts = "SELECT E.ID_event,E.Event_name,E.Event_Description,E.Start_Date,E.End_Date FROM events E ORDER BY E.Start_Date DESC";
			if ($result = $mysqli->query($sql_query_posts)) {

				//get the number of total pages needed for display
	    		$results_per_page = 3;
				$no_pages_links = 3;
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
				$sql_limit_on_page='SELECT E.ID_event,E.Event_name,E.Event_Description,E.Start_Date,E.End_Date FROM events E ORDER BY E.Start_Date DESC LIMIT ' . $this_page_first_result . ',' .  $results_per_page;
				if ($result_on_page = $mysqli->query($sql_limit_on_page)){
					while($row_on_page = mysqli_fetch_array($result_on_page)) {

				?>
					<div class = "post d-none d-sm-none d-xl-block">
						<div class = "post_image">
							<?php 
							
				    			//select the relevant image associated with the post
				    			$event_id = $row_on_page['ID_event'];
				    			$sql_imagine = "SELECT Imagine FROM imagini_website WHERE ID_Postare = $event_id AND LOWER(Main) = 'da' AND Tip_asociere = 'eveniment'";
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
							<h2 class = "p_title"><?php echo $row_on_page['Event_name'] ?></h2>
							<p class = "p_date"><?php echo "Starting from : " .$row_on_page['Start_Date']." and ending on ".$row_on_page['End_Date'] ?></p>
							<h3 class = "p_description"><?php echo "Description: ".$row_on_page['Event_Description'] ?></h3>
							<br>

							<div class = "answers">
								<a class='read_more_buttons' href = "all_events.php?answer=no&selected=true&event=<?php echo $row_on_page['ID_event'] ?>"><u>NO</u></a>
								<a class='read_more_buttons' href = "all_events.php?answer=maybe&selected=true&event=<?php echo $row_on_page['ID_event'] ?>"><u>MAYBE</u></a>
								<a class='read_more_buttons' href = "all_events.php?answer=yes&selected=true&event=<?php echo $row_on_page['ID_event'] ?>"><u>YES</u></a>
								<a href="" class="read_more_buttons" data-toggle="modal" data-target="#modalLoginForm">
						    	Share Event</a>
							</div>
						</div>
					</div>

					<div class = "card d-block d-sm-block d-xl-none" style = "width:100%;margin-top:2%;border-radius:20px;">
							<?php 
							
				    			//select the relevant image associated with the post
				    			$event_id = $row_on_page['ID_event'];
				    			$sql_imagine = "SELECT Imagine FROM imagini_website WHERE ID_Postare = $event_id AND LOWER(Main) = 'da' AND Tip_asociere = 'eveniment'";
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
							<h4 class = "card-title" style="color:black;"><?php echo $row_on_page['Event_name'] ?></h4>
							<p class = "card-title" style="color:black;"><?php echo "Starting from : " .$row_on_page['Start_Date']." and ending on ".$row_on_page['End_Date'] ?></p>
							<h4 class = "card-title" style="color:black;"><?php echo "Description: ".$row_on_page['Event_Description'] ?></h4>
							<div class = "answers">
								<a class='read_more_buttons' href = "all_events.php?answer=no&selected=true&event=<?php echo $row_on_page['ID_event'] ?>"><u>NO</u></a>
								<a class='read_more_buttons' href = "all_events.php?answer=maybe&selected=true&event=<?php echo $row_on_page['ID_event'] ?>"><u>MAYBE</u></a>
								<a class='read_more_buttons' href = "all_events.php?answer=yes&selected=true&event=<?php echo $row_on_page['ID_event'] ?>"><u>YES</u></a>
								<a href="" class="read_more_buttons" data-toggle="modal" data-target="#modalLoginForm">
						    	Share Event</a>
							</div>
						</div>
					</div>
				<?php
					}
				}
				echo '<a href="all_events.php?inc=false&page=' .$page. '" class = "pages">Previous</a> ';
	    		//display links to pages
		    	if($page + $no_pages_links  <= $total_pages){
			    	for($pages = $page; $pages < $page + $no_pages_links ;$pages++){
			    			 echo '<a href="all_events.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
		    	else{
		   			$last_pages_display = $total_pages - $no_pages_links;
		    	}
		    	if($last_pages_display >= 0){
		    		for($pages = $last_pages_display + 1; $pages <=$total_pages;$pages++){
			    			 echo '<a href="all_events.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
		    	else{
		    		for($pages = 1; $pages <= $total_pages ;$pages++){
			    			 echo '<a href="all_events.php?page=' . $pages . '" class = "pages">' . $pages. '</a> ';
			    	}
		    	}
	    		echo '<a href="all_events.php?inc=true&page='. $page. '" class = "pages">Next</a> ';

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
  function myFunction() {
								   var x = document.URL;
								   document.getElementById("jinu").src = 'https://www.facebook.com/plugins/share_button.php?href='+x+'&layout=button_count&size=large&mobile_iframe=true&width=83&height=28&appId';
								  }
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