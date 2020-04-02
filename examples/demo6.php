<?php
use JsonTools\Di;

$di = new Di;

$di['db'] = new StdClass;
var_dump($di['db']);
$di['db'] = function () {
    return new StdClass;
};

var_dump($di->getDb());
$di['db'] = 'StdClass';
var_dump($di->get('db'));
$di['db'] = [
    'className'	=>	'StdClass'
];
var_dump($di->db);
