<?php
$host = "localhost";
$db_name = "proiect_php";
$username = "root";
$password = "";
 
try{
    $con = new PDO("mysql:host={$host};dbname={$db_name}", $username, $password);
}
 
catch(PDOException $exception){
    //to handle connection error
    echo "Connection error: " . $exception->getMessage();
}
// select the image 
$query = "select * from produse WHERE ID_Produs = ?"; 
$stmt = $con->prepare( $query );
 
// bind the name of the image you want to select
$stmt->bindParam(1, $_GET['ID_Produs']);
$stmt->execute();
 
// to verify if a record is found
$num = $stmt->rowCount();
 
if( $num ){
    // if found
    $row = $stmt->fetch(PDO::FETCH_ASSOC);
    
    // specify header with content type,
    // you can do header("Content-type: image/jpg"); for jpg,
    // header("Content-type: image/gif"); for gif, etc.
    header("Content-type: image/jpg");
    
    //display the image data
    echo $row['Imagine_Produs'];
    exit;
}else{
    //if no image found with the given id,
    //load/query your default image here
}
?>