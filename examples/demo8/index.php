<?php
use JsonTools\Di;

require_once 'SessionServiceProvider.php';
require_once('ConfigServiceProvider.php');
$di = new Di;
$di->register(new SessionServiceProvider());
$di->register(new ConfigServiceProvider());
var_dump($di->config);
var_dump($di->get('session'));
