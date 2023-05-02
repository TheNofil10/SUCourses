<?php
 if (isset($_GET["MedID"]) ) {
    $MedID = $_GET ["MedID"];

    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "Hospital";

    // Create connection
    $connection = new mysqli($servername, $username, $password, $database);

    $sql = "DELETE FROM prescribes WHERE MedID = $MedID";

    $connection->query($sql);
 }

 header("location:/Project/prescribes/index.php");
 exit;
?>