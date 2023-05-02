<?php
 if (isset($_GET["MedID"]) ) {
    $MedID = $_GET ["MedID"];

    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "Hospital";

    // Create connection
    $connection = new mysqli($servername, $username, $password, $database);

    $sql = "DELETE FROM Medicines WHERE MedID = $MedID";

    $connection->query($sql);
 }

 header("location:/Project/medicines/index.php");
 exit;
?>