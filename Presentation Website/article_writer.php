<?php
	// Initialize the session
	session_start();
	// Include config file
	require_once "generate_xml.php";
  use PHPMailer\PHPMailer\PHPMailer;
  use PHPMailer\PHPMailer\Exception;
  use PHPMailer\PHPMailer\SMTP;
  require 'PHPMailer-master/src/Exception.php';
  require 'PHPMailer-master/src/PHPMailer.php';
  require 'PHPMailer-master/src/SMTP.php';
	
	if (isset($_GET['post_type'])) {
	   	$tip_articol = $_GET['post_type'];
	}
    if (isset($_POST['title'])) {
    	if(isset($_POST['description'])){
    		if(isset($_POST['content'])){
    			if(isset($_POST['post_type'])){
    				$title = $_POST['title'];
    				$description = $_POST['description'];
    				$content = $_POST['content'];
    				$post_type = $_POST['post_type'];
    				$sql_verif_post_title = "SELECT COUNT(*) AS articles FROM posts WHERE Post_Title = '".$title."'";
				  	if ($result = $mysqli->query($sql_verif_post_title)){
					  	$no_articles = mysqli_fetch_array($result);
					  	if($no_articles['articles'] == 1){
					  		echo "There is an article with that Post_Title!";
					  	}
					  	else{
					  		$sql_inserare = "INSERT INTO posts(Post_TEXT,Post_Description,Posting_date,Post_Title,Post_Type) VALUES('".$content."','".$description."',CURRENT_DATE,'".$title."','".$post_type."');";
					  		$mysqli->query($sql_inserare);
					  		echo "New Post:)";
					  	}
					}
				}
    		}
    	}
    }
    
    //ceva pentru ipload image
    if(isset($_POST["submit_post"])){

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
		$mail->Username = 'andrei.gheorghe901@gmail.com';
		//Password to use for SMTP authentication
		$mail->Password = '007005Ag!';
		//Set who the message is to be sent from
		$mail->setFrom('andrei.gheorghe901@gmail.com', 'Administrator');
		//Set an alternative reply-to address
		$mail->addReplyTo('andrei.gheorghe901@gmail.com', 'Administrator');
		//Set who the message is to be sent to
		$success = true;
		$sql_limit_on_page="SELECT Email FROM `users` WHERE username != 'admin' AND Blocked = 'no'";
		if ($result_on_page = $mysqli->query($sql_limit_on_page)){
			while($row_on_page = mysqli_fetch_array($result_on_page)) {
					$mail->addAddress($row_on_page['Email']);
			}
		}
		//Set the subject line
		$mail->Subject = 'New Post Update';
		//Read an HTML message body from an external file, convert referenced images to embedded,
		//convert HTML into a basic plain-text alternative body
		$mail->msgHTML("HELLO, a new post has been added . Type : ".$tip_articol. " Go to our website for more info: ...");
		//Replace the plain text body with one created manually
		$mail->AltBody = 'This is a plain-text message body';
		//send the message, check for errors
		if (!$mail->send()) {
			$success = false;

		} else {
			$success = true;
		}

		if($success == true){
			echo "Users have been notified!";
		}
		else{
			echo "Something went wrong!";
		}

		//if (count($_FILES > 0)){
			if(is_uploaded_file($_FILES['image']['tmp_name'])){
				$image = addslashes(file_get_contents($_FILES['image']['tmp_name']));
			}
		//}
		if(empty($image)){
			echo "<h2>There is no image selected</h2>";
		}
		else{
						$sql_id_post = "SELECT Post_ID AS ID_Postare FROM posts ORDER BY Post_ID DESC LIMIT 1";
						$result_id = $mysqli->query($sql_id_post);
						$id_post = mysqli_fetch_array($result_id);
						$id = $id_post["ID_Postare"];
						//insert image
						$sql_insert_main_image = "INSERT INTO imagini_website (Imagine, ID_Postare, Main, Tip_Asociere) VALUES('".$image."',$id,'Da','postare');";
						$mysqli->query($sql_insert_main_image);
						echo "<h2>Post Image Updated successfull</h2>";
		}
	}
?>
<!DOCTYPE html>
<html>
<head>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
	<link rel="stylesheet" href="style_home_page.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.0/jquery.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.js"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
	<script src="https://kit.fontawesome.com/176f7cb89c.js" crossorigin="anonymous"></script>
	<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jqueryui/1.12.1/jquery-ui.css" />
	<title>Blog & Article Editor</title>
</head>
<body onLoad = "enableEditMode();">
	<a href="index.php" class = "logo" title = "home" alt = "home" style="float: left;">
		<img alt="Home" src="./home.jpg" style="width: 100px; height: 50px;">
	</a>
	<div style="text-align: justify; background-color: gray; margin-left: 23%; margin-right: 23%;" name = "Title">
		<?php
			if($tip_articol == 'blog'){
		?>
		<h2>Blog Title</h2>
		<?php
			}
			else{
		?>
		<h2>Article Title</h2>
		<?php
			}
		?>
		<button onclick="execCmd('bold','Title');"><i class="fa fa-bold"></i></button>
		<button onclick="execCmd('italic','Title');"><i class="fa fa-italic"></i></button>
		<button onclick="execCmd('underline','Title');"><i class="fa fa-underline"></i></button>
		<button onclick="execCmd('strikeThrough','Title');"><i class="fa fa-strikethrough"></i></button>
		<button onclick="execCmd('justifyLeft','Title');"><i class="fa fa-align-left"></i></button>
		<button onclick="execCmd('justifyCenter','Title');"><i class="fa fa-align-center"></i></button>
		<button onclick="execCmd('justifyRight','Title');"><i class="fa fa-align-right"></i></button>
		<button onclick="execCmd('justifyFull','Title');"><i class="fa fa-align-justify"></i></button>
		<button onclick="execCmd('Cut','Title');"><i class="fa fa-cut"></i></button>
		<button onclick="execCmd('Copy','Title');"><i class="fa fa-copy"></i></button>

		<!--<button onclick="execCmd('indent','Title');"><i class="fa fa-indent"></i></button>
		<button onclick="execCmd('outdent','Title');"><i class="fa fa-dedent"></i></button>
		<button onclick="execCmd('subscript','Title');"><i class="fa fa-subscript"></i></button>
		<button onclick="execCmd('superscript','Title');"><i class="fa fa-superscript"></i></button>-->

		<button onclick="execCmd('undo','Title');"><i class="fa fa-undo"></i></button>
		<button onclick="execCmd('redo','Title');"><i class="fa fa-repeat"></i></button>

		<!--<button onclick="execCmd('insertUnorderedList','Title');"><i class="fa fa-list-ul"></i></button>
		<button onclick="execCmd('insertOrderedList','Title');"><i class="fa fa-list-ol"></i></button>
		<button onclick="execCmd('insertParagraph','Title');"><i class="fa fa-paragraph"></i></button>-->

		<select onchange="execCommandWithArg('formatBlock',this.value,'Title');">
			<option value="H1">H1</option>
			<option value="H2">H2</option>
			<option value="H3">H3</option>
			<option value="H4">H4</option>
			<option value="H5">H5</option>
			<option value="H6">H6</option>
		</select>
		<select onchange="execCommandWithArg('fontName',this.value,'Title');">
			<option value="Arial">Arial</option>
			<option value="Comic Sans MS">Comic Sans MS</option>
			<option value="Tahoma">Tahoma</option>
			<option value="Times New Roman">Times New Roman</option>
			<option value="Georgia">Georgia</option>
			<option value="Courier New">Courier New</option>
			<option value="Verdana">Verdana</option>
		</select>
		<select onchange="execCommandWithArg('fontSize',this.value,'Title');">
			<option value="1">1</option>
			<option value="2">2</option>
			<option value="3">3</option>
			<option value="4">4</option>
			<option value="5">5</option>
			<option value="6">6</option>
			<option value="7">7</option>
		</select>
		<!--
		<button onclick="execCommandWithArg('createLink',prompt('Enter a URL','http://'),'Title');"><i class="fa fa-link"></i></button>
		<button onclick="execCmd('unlink','Title');"><i class="fa fa-unlink"></i></button>
		<br>
		<button onclick="execCmd('insertHorizontalRule','Title');">HR</button>
		<button onclick="toggleEdit('Title');">TOGGLE EDIT</button>
		<button onclick="toggleSource('Title');"><i class="fa fa-code"></i></button>-->
		Fore Color: <input type="color" onchange="execCommandWithArg('foreColor',this.value,'Title');">
		Background: <input type="color" onchange="execCommandWithArg('hiliteColor',this.value,'Title');">
		<button onclick="execCmd('selectAll','Title');">Select All</button>
		<!--<button onclick="getImageURL('Title');"><i class="fa fa-file-image-o"></i></button>
		<input type='file' accept='image/*' onchange="openImage(event,'Title')"><br>-->
	</div>
	<br>
	<iframe name="richTextField_Title" style="width:1000px;height: auto;min-height: 100px;font-size: 12px; background-color: white;"></iframe>
	<div style="text-align: justify; background-color: gray; margin-left: 23%; margin-right: 23%;">
		<?php
			if($tip_articol == 'blog'){
		?>
		<h2>Blog Description</h2>
		<?php
			}
			else{
		?>
		<h2>Article Description</h2>
		<?php
			}
		?>
		<button onclick="execCmd('bold','Description');"><i class="fa fa-bold"></i></button>
		<button onclick="execCmd('italic','Description');"><i class="fa fa-italic"></i></button>
		<button onclick="execCmd('underline','Description');"><i class="fa fa-underline"></i></button>
		<button onclick="execCmd('strikeThrough','Description');"><i class="fa fa-strikethrough"></i></button>
		<button onclick="execCmd('justifyLeft','Description');"><i class="fa fa-align-left"></i></button>
		<button onclick="execCmd('justifyCenter','Description');"><i class="fa fa-align-center"></i></button>
		<button onclick="execCmd('justifyRight','Description');"><i class="fa fa-align-right"></i></button>
		<button onclick="execCmd('justifyFull','Description');"><i class="fa fa-align-justify"></i></button>
		<button onclick="execCmd('Cut','Description');"><i class="fa fa-cut"></i></button>
		<button onclick="execCmd('Copy','Description');"><i class="fa fa-copy"></i></button>
		<!--
		<button onclick="execCmd('indent','Description');"><i class="fa fa-indent"></i></button>
		<button onclick="execCmd('outdent','Description');"><i class="fa fa-dedent"></i></button>
		<button onclick="execCmd('subscript','Description');"><i class="fa fa-subscript"></i></button>
		<button onclick="execCmd('superscript','Description');"><i class="fa fa-superscript"></i></button>-->
		<button onclick="execCmd('undo','Description');"><i class="fa fa-undo"></i></button>
		<button onclick="execCmd('redo','Description');"><i class="fa fa-repeat"></i></button>
		<!--
		<button onclick="execCmd('insertUnorderedList','Description');"><i class="fa fa-list-ul"></i></button>
		<button onclick="execCmd('insertOrderedList','Description');"><i class="fa fa-list-ol"></i></button>
		<button onclick="execCmd('insertParagraph','Description');"><i class="fa fa-paragraph"></i></button>-->
		<select onchange="execCommandWithArg('formatBlock',this.value,'Description');">
			<option value="H1">H1</option>
			<option value="H2">H2</option>
			<option value="H3">H3</option>
			<option value="H4">H4</option>
			<option value="H5">H5</option>
			<option value="H6">H6</option>
		</select>
		<select onchange="execCommandWithArg('fontName',this.value,'Description');">
			<option value="Arial">Arial</option>
			<option value="Comic Sans MS">Comic Sans MS</option>
			<option value="Tahoma">Tahoma</option>
			<option value="Times New Roman">Times New Roman</option>
			<option value="Georgia">Georgia</option>
			<option value="Courier New">Courier New</option>
			<option value="Verdana">Verdana</option>
		</select>
		<select onchange="execCommandWithArg('fontSize',this.value,'Description');">
			<option value="1">1</option>
			<option value="2">2</option>
			<option value="3">3</option>
			<option value="4">4</option>
			<option value="5">5</option>
			<option value="6">6</option>
			<option value="7">7</option>
		</select>
		<!--
		<button onclick="execCommandWithArg('createLink',prompt('Enter a URL','http://'),'Description');"><i class="fa fa-link"></i></button>
		<button onclick="execCmd('unlink','Description');"><i class="fa fa-unlink"></i></button>
		<br>
		<button onclick="execCmd('insertHorizontalRule','Description');">HR</button>
		<button onclick="toggleEdit('Description');">TOGGLE EDIT</button>
		<button onclick="toggleSource('Description');"><i class="fa fa-code"></i></button>-->
		Fore Color: <input type="color" onchange="execCommandWithArg('foreColor',this.value,'Description');">
		Background: <input type="color" onchange="execCommandWithArg('hiliteColor',this.value,'Description');">
		<button onclick="execCmd('selectAll','Description');">Select All</button>
		<!--<button onclick="getImageURL('Description');"><i class="fa fa-file-image-o"></i></button>
		<input type='file' accept='image/*' onchange="openImage(event,'Description')"><br>-->
	</div>
	<br>
	<iframe name="richTextField_Description" style="width:1000px;height: auto;min-height: 200px;font-size: 12px; background-color: white;"></iframe>
	<div style="text-align: justify; background-color: gray; margin-left: 23%; margin-right: 23%;">
		<?php
			if($tip_articol == 'blog'){
		?>
		<h2>Blog Content</h2>
		<?php
			}
			else{
		?>
		<h2>Article Content</h2>
		<?php
			}
		?>
		<button onclick="execCmd('bold','Content');"><i class="fa fa-bold"></i></button>
		<button onclick="execCmd('italic','Content');"><i class="fa fa-italic"></i></button>
		<button onclick="execCmd('underline','Content');"><i class="fa fa-underline"></i></button>
		<button onclick="execCmd('strikeThrough','Content');"><i class="fa fa-strikethrough"></i></button>
		<button onclick="execCmd('justifyLeft','Content');"><i class="fa fa-align-left"></i></button>
		<button onclick="execCmd('justifyCenter','Content');"><i class="fa fa-align-center"></i></button>
		<button onclick="execCmd('justifyRight','Content');"><i class="fa fa-align-right"></i></button>
		<button onclick="execCmd('justifyFull','Content');"><i class="fa fa-align-justify"></i></button>
		<button onclick="execCmd('Cut','Content');"><i class="fa fa-cut"></i></button>
		<button onclick="execCmd('Copy','Content');"><i class="fa fa-copy"></i></button>
		<button onclick="execCmd('indent','Content');"><i class="fa fa-indent"></i></button>
		<button onclick="execCmd('outdent','Content');"><i class="fa fa-dedent"></i></button>
		<button onclick="execCmd('subscript','Content');"><i class="fa fa-subscript"></i></button>
		<button onclick="execCmd('superscript','Content');"><i class="fa fa-superscript"></i></button>
		<button onclick="execCmd('undo','Content');"><i class="fa fa-undo"></i></button>
		<button onclick="execCmd('redo','Content');"><i class="fa fa-repeat"></i></button>
		<button onclick="execCmd('insertUnorderedList','Content');"><i class="fa fa-list-ul"></i></button>
		<button onclick="execCmd('insertOrderedList','Content');"><i class="fa fa-list-ol"></i></button>
		<button onclick="execCmd('insertParagraph','Content');"><i class="fa fa-paragraph"></i></button>
		<select onchange="execCommandWithArg('formatBlock',this.value,'Content');">
			<option value="H1">H1</option>
			<option value="H2">H2</option>
			<option value="H3">H3</option>
			<option value="H4">H4</option>
			<option value="H5">H5</option>
			<option value="H6">H6</option>
		</select>
		<select onchange="execCommandWithArg('fontName',this.value,'Content');">
			<option value="Arial">Arial</option>
			<option value="Comic Sans MS">Comic Sans MS</option>
			<option value="Tahoma">Tahoma</option>
			<option value="Times New Roman">Times New Roman</option>
			<option value="Georgia">Georgia</option>
			<option value="Courier New">Courier New</option>
			<option value="Verdana">Verdana</option>
		</select>
		<select onchange="execCommandWithArg('fontSize',this.value,'Content');">
			<option value="1">1</option>
			<option value="2">2</option>
			<option value="3">3</option>
			<option value="4">4</option>
			<option value="5">5</option>
			<option value="6">6</option>
			<option value="7">7</option>
		</select>
		<button onclick="execCommandWithArg('createLink',prompt('Enter a URL','http://'),'Content');"><i class="fa fa-link"></i></button>
		<button onclick="execCmd('unlink','Content');"><i class="fa fa-unlink"></i></button>
		<br>
		<button onclick="execCmd('insertHorizontalRule','Content');">HR</button>
		<button onclick="toggleEdit('Content');">TOGGLE EDIT</button>
		<button onclick="toggleSource('Content');"><i class="fa fa-code"></i></button>
		Fore Color: <input type="color" onchange="execCommandWithArg('foreColor',this.value,'Content');">
		Background: <input type="color" onchange="execCommandWithArg('hiliteColor',this.value,'Content');">
		<button onclick="execCmd('selectAll','Content');">Select All</button>
		<button onclick="getImageURL('Content');"><i class="fa fa-file-image-o"></i></button>
		<input type='file' accept='image/*' onchange="openImage(event,'Content')"><br>
	</div>
	<br>
	<iframe name="richTextField_Content" style="width:1000px;height: auto;min-height: 500px;font-size: 12px; background-color: white;"></iframe>
	<br>
		<?php
			if($tip_articol == 'blog'){
		?>
			<input type="submit"  onclick="uploadPost('blog');" style="height: 50px;width: 1000px; font-size: 20px;">
		<?php
			}
			else{
		?>
			<input type="submit"  onclick="uploadPost('article');" style="height: 50px;width: 1000px; font-size: 20px;">
		<?php
			}
		?>
	<?php
			if($tip_articol == 'blog'){
		?>
		<form method="POST" action="article_writer.php?post_type='blog'" enctype="multipart/form-data">
			<h2 style="color:white;">Incarcati imaginea principala asociata postarii (DUPA CE SCRIETI POSTAREA) : </h2>
			<input type="file" name="image">
			<br>
			<input type="submit" name="submit_post" style="width: 700px;height: 50px;">
		</form>
		<?php
			}
			else{
		?>
		<form method="POST" action="article_writer.php?post_type='article'" enctype="multipart/form-data">
			<h2 style="color:white;">Incarcati imaginea principala asociata postarii (DUPA CE SCRIETI POSTAREA) : </h2>
			<input type="file" name="image">
			<br>
			<input type="submit" name="submit_post" style="width: 700px;height: 50px;">
		</form>
		<?php
			}
		?>

	<script type="text/javascript">
		var sendSourceCode_Content = false;
		var sendSourceCode_Title = false;
		var sendSourceCode_Description = false;
		var isInEditMode_Title = true;
		var isInEditMode_Description = true;
		var isInEditMode_Content= true;

		var openImage = function(event,location) {
		    var input = event.target;

		    var reader = new FileReader();
		    reader.onloadend = function(){
		      var dataURL = reader.result;
		      var img  = new Image(100,100);
			  img.src = dataURL;
			  if(location == 'Title'){
				  richTextField_Title.document.getElementsByTagName('body')[0].appendChild(img);
			  }
			  else if (location == 'Content'){
			  	  richTextField_Content.document.getElementsByTagName('body')[0].appendChild(img);
			  }
			  else if ( location == 'Description'){
			  	  richTextField_Description.document.getElementsByTagName('body')[0].appendChild(img);
			  }
		    };	   
		    reader.readAsDataURL(input.files[0]);
		  };


		function getImageURL(location){
			var imgSrc = prompt('Enter image location', '');  
			var img  = new Image(100,100);
			img.src = imgSrc;
			if(location == 'Title'){
			    if(imgSrc != null){
			        richTextField_Title.document.execCommand('insertImage', false, img);   
			    }
			}
			else if(location == 'Description'){
				if(imgSrc != null){
			        richTextField_Description.document.execCommand('insertImage', false, img);   
			    }
			}
			else if(location == 'Content'){
				if(imgSrc != null){
			        richTextField_Content.document.execCommand('insertImage', false, img);   
			    }
			}
		}


		function enableEditMode(){
			richTextField_Content.document.designMode = 'On';
			richTextField_Description.document.designMode = 'On';
			richTextField_Title.document.designMode = 'On';
		}

		function execCmd(command,reference){
			if(reference == 'Content'){
				richTextField_Content.document.execCommand(command, false, null);
			}
			else if(reference == 'Description'){
				richTextField_Description.document.execCommand(command,false,null);
			}
			else if(reference == 'Title'){
				richTextField_Title.document.execCommand(command,false,null);
			}
		}

		function execCommandWithArg(command,arg,reference){
			if(reference == 'Content'){
				richTextField_Content.document.execCommand(command,false,arg);
			}
			else if(reference == 'Description'){
				richTextField_Description.document.execCommand(command,false,arg);
			}
			else if(reference == 'Title'){
				richTextField_Title.document.execCommand(command,false,arg);
			}
		}

		function toggleSource(reference){
			if(reference == 'Content'){
				if(sendSourceCode_Content){
					richTextField_Content.document.getElementsByTagName('body')[0].innerHTML = richTextField_Content.document.getElementsByTagName('body')[0].textContent;
					sendSourceCode_Content = false;
				}
				else{
					richTextField_Content.document.getElementsByTagName('body')[0].textContent = richTextField_Content.document.getElementsByTagName('body')[0].innerHTML;
					alert(richTextField_Content.document.getElementsByTagName('body')[0].innerHTML)
					sendSourceCode_Content = true;
				}
			}
			else if(reference == 'Description'){
				if(sendSourceCode_Description){
					richTextField_Description.document.getElementsByTagName('body')[0].innerHTML = richTextField_Description.document.getElementsByTagName('body')[0].textContent;
					sendSourceCode_Description = false;
				}
				else{
					richTextField_Description.document.getElementsByTagName('body')[0].textContent = richTextField_Description.document.getElementsByTagName('body')[0].innerHTML;
					alert(richTextField_Description.document.getElementsByTagName('body')[0].innerHTML)
					sendSourceCode_Description = true;
				}
			}
			else if(reference == 'Title'){
				if(sendSourceCode_Title){
					richTextField_Title.document.getElementsByTagName('body')[0].innerHTML = richTextField_Title.document.getElementsByTagName('body')[0].textContent;
					sendSourceCode_Title = false;
				}
				else{
					richTextField_Title.document.getElementsByTagName('body')[0].textContent = richTextField_Title.document.getElementsByTagName('body')[0].innerHTML;
					alert(richTextField_Title.document.getElementsByTagName('body')[0].innerHTML)
					sendSourceCode_Title = true;
				}
			}

		}

		function toggleEdit(reference){
			if(reference == 'Content'){
				if(isInEditMode_Content){
					richTextField_Content.document.designMode = 'Off';
					isInEditMode_Content = false;
				}
				else{
					richTextField_Content.document.designMode = 'On';
					isInEditMode_Content = true;
				}
			}
			else if(reference == 'Description'){
				if(isInEditMode_Description){
					richTextField_Description.document.designMode = 'Off';
					isInEditMode_Description = false;
				}
				else{
					richTextField_Description.document.designMode = 'On';
					isInEditMode_Description = true;
				}
			}
			else if(reference == 'Title'){
				if(isInEditMode_Title){
					richTextField_Title.document.designMode = 'Off';
					isInEditMode_Title = false;
				}
				else{
					richTextField_Title.document.designMode = 'On';
					isInEditMode_Title = true;
				}
			}

		}

		function uploadPost(post_type){
				var title = richTextField_Title.document.getElementsByTagName('body')[0].innerHTML;
				var description = richTextField_Description.document.getElementsByTagName('body')[0].innerHTML;
				var content = richTextField_Content.document.getElementsByTagName('body')[0].innerHTML;
				$.ajax({
				    url: 'article_writer.php',
				    type: 'post',
				    data: { "title": title,"description" : description, "content" : content, "post_type" :  post_type},
				    success: function(response) { alert(response); }
				});
		}
	</script>
</body>
</html>