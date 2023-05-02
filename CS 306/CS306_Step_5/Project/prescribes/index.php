<!doctype html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title> Admin Panel</title>

    <link rel="shortcut icon" href="assets/images/fav.jpg">
    <link rel="stylesheet" href="assets/css/bootstrap.min.css">
    <link rel="stylesheet" href="assets/css/fontawsom-all.min.css">
     <link rel="stylesheet" href="assets/css/animate.css">
    <link rel="stylesheet" type="text/css" href="assets/css/style.css" />
</head>

<!-- ################# Header Starts Here#######################--->
    
<header id="menu-jk">
    
    <div id="nav-head" class="header-nav">
        <div class="container">
            <div class="row">
                <div class="col-lg-2 col-md-3 no-padding col-sm-12 nav-img">
                   <a data-toggle="collapse" data-target="#menu" href="#menu" ><i class="fas d-block d-md-none small-menu fa-bars"></i></a>
                </div>
                <div id="menu" class="col-lg-8 col-md-9 d-none d-md-block nav-item">
                    <ul>
                        <li><a href="/Project/AdminPanel/index.php">Home</a></li>
                        <li><a href="/Project/doctors/index.php">Doctors</a></li>
                        <li><a href="/Project/patients/index.php">Patients</a></li>
                        <li><a href="/Project/nurses/index.php">Nurses</a></li>  
                        <li><a href="/Project/rooms/index.php">Rooms</a></li>
                        <li><a href="/Project/medicines/index.php">Medicines</a></li>
                        <li><a href="/Project/appointments/index.php">Appointments</a></li>
                        
                    </ul>
                </div>
                
            </div>

        </div>
    </div>
</header>
<body>
    <div class="container my-5">
        <h2>List Medicines Prescribed by Doctors to Patients</h2>
        <a class="btn btn-primary" href="/Project/prescribes/create.php" role="button">Prescribe Medicine to Patient</a>
        <a class="btn btn-primary" href="/Project/prescribes/select.php" role="button">Search</a>
        <br>
        <table class="table">
            <thead>
                <tr>
                    <th>DocID</th>
                    <th>PatID</th>
                    <th>MedID</th>
                </tr>
            </thead>
            <tbody>
                <?php
                $servername = "localhost";
                $username = "root";
                $password = "";
                $database = "hospital";

                $connection = new mysqli($servername, $username, $password, $database);

                if ($connection -> connect_error) {
                    die("Connection failed: " . $connection->connect_error);
                }

                $sql = "SELECT * FROM prescribes";
                $result = $connection->query($sql);

                if (!$result) {
                    die("Invalid query: " . $connection->error);
                }

                while($row = $result -> fetch_assoc()){
                    echo "
                    <tr>
                        <td>$row[DocID]</td>
                        <td>$row[PatID]</td>
                        <td>$row[MedID]</td>
                        <td>
                            <a class='btn btn-danger btn-sm' href='/Project/prescribes/delete.php?MedID=$row[MedID]'>Delete</a>
                        </td>
                    </tr>
                    ";
                }
                ?>

                
            </tbody>
        </table>
    </div>
</body>
</html>





