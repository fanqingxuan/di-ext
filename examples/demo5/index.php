<?php
use Tools\Di;
use Tools\Config;

class Test
{
}

$di = new Di;
$di->loadFromPhp('service.php');

var_dump($di);
