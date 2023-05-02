<?php
 if (isset($_GET["RoomID"]) ) {
    $RoomID = $_GET ["RoomID"];

    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "Hospital";

    // Create connection
    $connection = new mysqli($servername, $username, $password, $database);

    $sql = "DELETE FROM assigns WHERE RoomID = $RoomID";

    $connection->query($sql);
 }

 header("location:/Project/assigns/index.php");
 exit;
?>