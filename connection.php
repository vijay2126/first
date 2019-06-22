<?php
$servername = "localhost";
$username = "root";
$password = "";
$database="hotal";
// Create connection
$name=$_POST["name"];
$email=$_POST["email"];
$pass=$_POST["pass"];
$mob=$_POST["num"];
$add=$_POST["add"];

$conn = new mysqli($servername, $username, $password,$database);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "INSERT INTO login (name, email,password ,mobile,addresh)
VALUES ('$name','$email','$pass','$mob','$add')";

if ($conn->query($sql) === TRUE) {
    ?>
	<script>

	window.location.replace("home_after.html");
	</script>
	<?php
	
	
}
 else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}


$conn->close();


?>
