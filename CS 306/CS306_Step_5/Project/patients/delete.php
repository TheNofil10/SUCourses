<?php
 if (isset($_GET["PatID"]) ) {
    $PatID = $_GET ["PatID"];

    $servername = "localhost";
    $username = "root";
    $password = "";
    $database = "Hospital";

    // Create connection
    $connection = new mysqli($servername, $username, $password, $database);

    $sql = "DELETE FROM Patients WHERE PatID = $PatID";

    $connection->query($sql);
 }

 header("location:/Project/patients/index.php");
 exit;
?>