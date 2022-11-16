<?php
session_start();
session_destroy();
header("Location:userDetail.php");