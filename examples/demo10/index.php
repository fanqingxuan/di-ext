<?php
//di read config from ini or php file
use Tools\Di;
use Tools\Config\Adapter\Ini;
use Tools\Config\Adapter\Php;

$di = new Di;

//from ini file
$config = new Ini("local.ini");
$di['config'] = $config;
$di->set('db_read', function () {
    return array(
        'env'   =>  $this->config->app->ENV,
        'host'  =>  $this->config->database->DB_HOST
    );
});
var_dump($di->get('db_read'));

//from php file
$config = new Php("prod.php");
$di['config'] = $config;
$di->set('db_read', function () {
    return array(
        'env'   =>  $this->config->app->ENV,
        'host'  =>  $this->config->database->DB_HOST
    );
});
var_dump($di->get('db_read'));
