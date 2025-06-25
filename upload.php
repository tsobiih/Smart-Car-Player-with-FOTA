<?php
$uploadDir = 'firmware/';
$versionFile = 'version.txt';

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    if (isset($_FILES['hexFile']) && isset($_POST['version'])) {
        $fileTmp = $_FILES['hexFile']['tmp_name'];
        $fileName = basename($_FILES['hexFile']['name']);
        $version = trim($_POST['version']);

        // Validate file extension
        if (pathinfo($fileName, PATHINFO_EXTENSION) !== 'hex') {
            echo "Only HEX files are allowed.";
            exit;
        }

        // Move the uploaded file
        $targetPath = $uploadDir . 'firmware.hex';
        if (move_uploaded_file($fileTmp, $targetPath)) {
            // Update version file
            file_put_contents($versionFile, $version);
            echo "Firmware uploaded successfully. Version updated to $version.";
        } else {
            echo "Failed to upload firmware.";
        }
    } else {
        echo "File or version not provided.";
    }
} else {
    echo "Invalid request.";
}
?>
