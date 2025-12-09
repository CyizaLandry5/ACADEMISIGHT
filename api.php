<?php
session_start();

$API_URL = "https://script.google.com/macros/s/AKfycbxCeEKDq3lB_8TyBJRuPQrpBYVxqqcy4v3jH5L0wkG_kLXdApTuoIl2YGadeTn_L_59/exec";

function call_api($payload) {
    global $API_URL;
    $ch = curl_init($API_URL);
    curl_setopt($ch, CURLOPT_POST, true);
    curl_setopt($ch, CURLOPT_HTTPHEADER, ['Content-Type: application/json']);
    curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($payload));
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);

    $res = curl_exec($ch);
    curl_close($ch);

    return json_decode($res, true);
}
?>
