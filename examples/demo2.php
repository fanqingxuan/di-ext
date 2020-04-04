<?php
use JsonDi\Di;
use JsonDi\Config;

$di = new Di;
$di->set('config', new Config(
    [
        'database'  =>  [
            'host'      =>  'localhost',
            'username'  =>  'root',
            'password'  =>  '111111'
        ]
    ]
));
class MysqlDb
{
    public function __construct($config)
    {
        print_r($config);
    }
}
$di->set('db', function () {
    return new MysqlDb($this->get('config')->database);//get the database config from container
});
var_dump($di->getDb());
