<?php
 if (isset($_GET["DocID"]) ) {
    $DocID = $_GET ["DocID"];

    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "Hospital";

    // Create connection
    $connection = new mysqli($servername, $username, $password, $database);

    $sql = "DELETE FROM Doctors WHERE DocID = $DocID";

    $connection->query($sql);
 }

 header("location:/Project/doctors/index.php");
 exit;
?>