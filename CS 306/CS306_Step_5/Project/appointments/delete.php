<?php
 if (isset($_GET["AppID"]) ) {
    $AppID = $_GET ["AppID"];

    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "Hospital";

    // Create connection
    $connection = new mysqli($servername, $username, $password, $database);

    $sql = "DELETE FROM appointments WHERE AppID = $AppID";

    $connection->query($sql);
 }

 header("location:/Project/appointments/index.php");
 exit;
?>