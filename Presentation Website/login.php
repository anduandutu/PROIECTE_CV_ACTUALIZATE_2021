<?php
// Initialize the session
session_start();
// Include config file
require_once "config.php";
 
// Define variables and initialize with empty values
$email = $password = "";
$email_err = $password_err = "";
 
// Processing form data when form is submitted
if($_SERVER["REQUEST_METHOD"] == "POST"){
 
    // Check if username is empty
    if(empty(trim($_POST["email"]))){
        $email_err = "Please enter email.";
    } 
    else{
        $email = trim($_POST["email"]);
    }
    
    // Check if password is empty
    if(empty(trim($_POST["password"]))){
        $password_err = "Please enter your password.";
    }
    else{
        $password = trim($_POST["password"]);
    }
    // Validate credentials
    if(empty($email_err) && empty($password_err)){
        // Prepare a select statement
        $sql = "SELECT ID_Utilizator,Email,Parola,username FROM users WHERE Email = '$email' AND Parola = '$password' AND Blocked!='Yes';";
        if($stmt = $mysqli->prepare($sql)){
            // Attempt to execute the prepared statement
            if($stmt->execute()){
                // Store result
                $stmt->store_result();
                
                // Check if username exists, if yes then verify password
                if($stmt->num_rows == 1){                    
                    // Bind result variables
                    $stmt->bind_result($id, $mail, $pass, $username);
                    if($stmt->fetch()){

                            if($password == $pass and $mail == $email){
                                // Password is correct, so start a new session
                                session_start();
                                
                                // Store data in session variables
                                $_SESSION["loggedin"] = true;
                                $_SESSION["id"] = $id;
                                $_SESSION["email"] = $email;  
                                $_SESSION["username"] = $username;    
                                //initializare cos de cumparaturi gol                     
                                $sql_insert_comanda = "INSERT INTO liste_comenzi(ID_Utilizator,Data_comenzii,Total_comanda) VALUES((SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION["username"]."'),CURRENT_TIMESTAMP,0)";
                                $mysqli->query($sql_insert_comanda);
                                //vatriabila de sesiune este id-ul cosului nou creat
                                $sql_id_cos = "SELECT ID_Inregistrare FROM liste_comenzi WHERE ID_Utilizator =  (SELECT ID_Utilizator FROM users WHERE username = '".$_SESSION["username"]."') ORDER BY Data_comenzii DESC LIMIT 1";
                                $results = $mysqli->query($sql_id_cos);
                                $id_cos = $results->fetch_assoc();
                                $_SESSION["shopping_cart_no"] = $id_cos["ID_Inregistrare"];
                                $_SESSION["STATUS_COMANDA"] = 'NOT SENT';
                                // Redirect user to welcome page
                                header("location: index.php");
                            } else{
                                // Display an error message if password is not valid
                                $password_err = "The password/email you entered was not valid.";
                            }
                    }
                }
                else{
                    // Display an error message if username doesn't exist
                    $email_err = "No valid account found with that email.";
                }
            } 
            else{
                echo "Oops! Something went wrong. Please try again later.";
            }

            // Close statement
            $stmt->close();
        }
    }
    
    // Close connection
    $mysqli->close();
}
?>
 
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Login</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.css">
    <link rel="stylesheet" href="node_modules/bootstrap/dist/css/bootstrap.min.css">
    <link rel="stylesheet" href="node_modules/font-awesome/css/font-awesome.min.css">
    <link rel="stylesheet" href="node_modules/bootstrap-social/bootstrap-social.css">
    <style type="text/css">
        body{ font: 14px sans-serif; }
        .wrapper{ width: 350px; padding: 20px; }
    </style>
</head>
<body>
    <div class="wrapper">
        <h2>Login</h2>
        <p>Please fill in your credentials to login.</p>
        <form action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
            <div class="form-group row <?php echo (!empty($email_err)) ? 'has-error' : ''; ?>">
                <label>Email</label>
                <input type="text" name="email" class="form-control" value="<?php echo $email; ?>">
                <span class="help-block"><?php echo $email_err; ?></span>
            </div>    
            <div class="form-group row <?php echo (!empty($password_err)) ? 'has-error' : ''; ?>">
                <label>Password</label>
                <input type="password" name="password" class="form-control">
                <span class="help-block"><?php echo $password_err; ?></span>
            </div>
            <div class="form-group">
                <input type="submit" class="btn btn-primary" value="Login">
            </div>
            <p>Don't have an account? <a href="register.php">Sign up now</a>.</p>
        </form>
    </div>    
</body>
</html>
<script src="node_modules/jquery/dist/jquery.slim.min.js"></script>
<script src="node_modules/popper.js/dist/umd/popper.min.js"></script>
<script src="node_modules/bootstrap/dist/js/bootstrap.min.js"></script>