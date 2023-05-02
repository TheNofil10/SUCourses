<?php

$servername = "localhost";
$username = "root";
$password = "";
$database = "hospital";

$connection = new mysqli($servername, $username, $password, $database);

$result = NULL;

if(isset($_POST['search'])){
    $search_term = mysql_real_escape_string($_POST['search_box']);
    $sql = "SELECT * FROM Patients WHERE Name = '{$search_term}' ";
    $result = $connection->query($sql);
}


?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hospital</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/css/bootstrap.min.css">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.2.2/dist/js/bootstrap.bundle.min.js"></script>
</head>
<body>
<div class="container my-5">
<div class="row mb-3">
 <form class="col-form-label" name="search_form" method="POST" action="select.php">
 Name:<div class="col-sm-4"><input class="form-control" type="text" name="search_box" value="" /></div><br> <input class="btn btn-outline-primary" type="submit" name="search" value="Search the table...">

            <a class="btn btn-outline-primary" href="/Project/patients/index.php" role="button">Cancel</a>
                
                 
</form>
</div>
<table class="table">
<tr>

    <td><strong>ID</strong></td>
    <td><strong>Name</strong></td>
    <td><strong>Age</strong></td>
    <td><strong>Diagnosis</strong></td>
</tr>
<?php
if($result != NULL){
 while($row = $result -> fetch_assoc()){?>
    <tr>
        <td><?php echo $row['PatID']; ?></td> 
        <td><?php echo $row['Name']; ?></td>
        <td><?php echo $row['Age']; ?></td>
        <td><?php echo $row['Diagnosis']; ?></td>
    </tr>

<?php }} ?>
     
 </table>
 </div> 
 </body>
</html>