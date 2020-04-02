<?php
use JsonTools\Di;

class UserDao
{
}

class UserService
{
    public $userDao;
    public $userType;
    public $tempObj;
}

$di = new Di();
$di->set(
    'userService',
    [
        'className'	=>	UserService::class,
        'properties'=>[
            [
                'name'	=>	'userDao',
                'value'	=>	[
                    'type'	=>	'service',
                    'name'	=>	'userDao',//service name in the container
                ]
            ],
            [
                'name'	=>	'userType',
                'value'	=>	[
                    'type'	=>	'parameter',
                    'value'	=>	2,
                ]
            ],
            [
                'name'	=>	'tempObj',
                'value'	=>	[
                    'type'	=>	'instance',
                    'className'	=>	'StdClass',
                    'arguments'	=>	[]
                ]
            ]
        ]
    ]
);
var_dump($di->get('userService'));
