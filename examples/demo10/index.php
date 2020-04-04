<?php
//di read config from ini or php file
use JsonDi\Di;
use JsonDi\Config\Adapter\Ini;
use JsonDi\Config\Adapter\Php;

$di = new Di;

//from ini file
$config = new Ini("local.ini");
$di->set('config', $config);
$di->set('db_read', function () {
    return array(
        'env'   =>  $this->config->app->ENV,
        'host'  =>  $this->config->database->DB_HOST
    );
});
var_dump($di->get('db_read'));

$di = new Di;
//from php file
$config = new Php("prod.php");
$di->set('config', $config);
$di->set('db_read', function () {
    return array(
        'env'   =>  $this->config->app->ENV,
        'host'  =>  $this->config->database->DB_HOST
    );
});
var_dump($di->get('db_read'));
