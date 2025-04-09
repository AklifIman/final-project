<?php
include("db_connect.php");

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $username = htmlspecialchars($_POST['username']);
    $password = $_POST['password'];

   
    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

    
    $sql = "INSERT INTO admin (username, password) VALUES (?, ?)";
    $stmt = mysqli_prepare($connect, $sql);

    if ($stmt) {
    
        mysqli_stmt_bind_param($stmt, "ss", $username, $hashed_password);

       
        if (mysqli_stmt_execute($stmt)) {
            echo "Admin registered successfully!";
        } else {
            echo "Error: " . mysqli_error($connect);
        }

        mysqli_stmt_close($stmt);
    } else {
        echo "SQL Error: " . mysqli_error($connect);
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Sporty Login</title>
    <style>
        /* Center the login form */
        body {
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            background: url('sports-background.jpg') no-repeat center center/cover;
            font-family: Arial, sans-serif;
            margin: 0;
        }

        .login-container {
            background: rgba(0, 0, 0, 0.8);
            padding: 30px;
            border-radius: 10px;
            box-shadow: 0px 0px 10px rgba(255, 255, 255, 0.5);
            color: white;
            text-align: center;
            width: 350px;
        }

        .login-container h2 {
            margin-bottom: 20px;
            color: #ff4500;
        }

        .login-container label {
            display: block;
            margin: 10px 0 5px;
            font-weight: bold;
        }

        .login-container input {
            width: 100%;
            padding: 10px;
            margin-bottom: 15px;
            border: none;
            border-radius: 5px;
            font-size: 16px;
        }

        .login-container button {
            background: #ff4500;
            color: white;
            padding: 12px;
            border: none;
            border-radius: 5px;
            width: 100%;
            cursor: pointer;
            font-size: 18px;
            font-weight: bold;
            transition: 0.3s;
        }

        .login-container button:hover {
            background: #ff6500;
        }
    </style>
</head>
<body>
    <div class="login-container">
        <h2>Sporty Login</h2>
        <form action="" method="POST">
            <label for="username">Username:</label>
            <input type="text" id="username" name="username" required>
            
            <label for="password">Password:</label>
            <input type="password" id="password" name="password" required>
            
            <button type="submit">Login</button>
        </form>
    </div>
</body>
</html>

