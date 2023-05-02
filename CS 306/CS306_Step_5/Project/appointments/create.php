<?php

$servername = "localhost";
$username = "root";
$password = "";
$database = "hospital";

$connection = new mysqli($servername, $username, $password, $database);

$AppID = "";
$Pat_Name = "";
$Doc_Name = "";
$Date = "";


$errorMessage = "";
$successMessage = "";

if ( $_SERVER['REQUEST_METHOD'] == 'POST'){
    $AppID = $_POST["AppID"];
    $Pat_Name = $_POST["Pat_Name"];
    $Doc_Name = $_POST["Doc_Name"];
    $Date = $_POST["Date"];

    do {
        if (empty($AppID) || empty($Pat_Name) || empty($Doc_Name) || empty($Date) ){
            $errorMessage = "All the fields are required";
            break;
        }

        //add new doctor to database
        $sql = "INSERT INTO appointments (AppID, Pat_Name, Doc_Name, Date)" .
            "VALUES ('$AppID', '$Pat_Name' , '$Doc_Name' , '$Date')";
        $result = $connection->query($sql);

        if (!$result) {
            $errorMessage = "Invalid query: " . $connection->error;
            break;
        }

        $AppID = "";
        $Pat_Name = "";
        $Doc_Name = "";
        $Date = "";

        $successMessage = "Nurse assigned Successfully!";

        header("location: /Project/homepage/index.php");
        exit;

    } while(false);
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
        <h2>New Appointment</h2>

        <?php
        if (!empty($errorMessage)){
            echo "
            <div class='alert alert-warning alert-dismissible fade show' role='alert'>
                <strong>$errorMessage</strong>
                <button type='button' class='btn-close' data-bs-dismiss='alert' aria-label='Close'></button>
            </div>
            ";
        }
        ?>

        <form method="post">

            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">AppID</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="AppID" value="<?php echo $AppID; ?>">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">Patient Name</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="Pat_Name" value="<?php echo $Pat_Name; ?>">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">Doctor Name</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="Doc_Name" value="<?php echo $Doc_Name; ?>">
                </div>
            </div>
            <div class="row mb-3">
                <label class="col-sm-3 col-form-label">Date</label>
                <div class="col-sm-6">
                    <input type="text" class="form-control" name="Date" value="<?php echo $Date; ?>">
                </div>
            </div>
            

            <?php
            if (!empty($successMessage)){
                echo "
                <div class='row mb-3'>
                    <div class='offset-sm-3 col-sm-6'>
                        <div class='alert alert-success alert-dismissible fade show' role= 'alert'>
                            <strong>$successMessage</strong>
                            <button type= 'button' class='btn-close' data-bs-dismiss='alert' aria-label='Close'></button>
                        </div>
                    </div> 
                </div>   
                ";
            }
            ?>

            <div class="row mb-3">
                <div class="offset-sm-3 col-sm-3 d-grid">
                    <button type="submit" class="btn btn-primary" href="/Project/homepage/index.php">Submit</button>
                </div>
                <div class="col-sm-3 d-grid">
                    <a class="btn btn-outline-primary" href="/Project/homepage/index.php" role="button">Cancel</a>
                </div>
            </div>
        </form>
    </div>
    
</body>
</html>