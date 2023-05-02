<?php
 if (isset($_GET["NurseID"]) ) {
    $NurseID = $_GET ["NurseID"];

    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "Hospital";

    // Create connection
    $connection = new mysqli($servername, $username, $password, $database);

    $sql = "DELETE FROM Nurses WHERE NurseID = $NurseID";

    $connection->query($sql);
 }

 header("location:/Project/nurses/index.php");
 exit;
?>