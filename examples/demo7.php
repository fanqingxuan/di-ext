<?php
use JsonTools\Di;
use JsonTools\Di\AbstractInjectionAware;

class Mysql
{
    public function select()
    {
        return "this is select";
    }
}

class HomeController extends AbstractInjectionAware
{
    public function say()
    {
        echo $this->container->get('db')->select();
    }
}

$di = new Di;
$di->set('db', Mysql::class);

$di->set('home', HomeController::class);
$di->get('home')->say();
var_dump($di->get('home')->getDi()->get('db'));
