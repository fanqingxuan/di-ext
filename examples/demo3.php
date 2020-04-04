<?php
use JsonDi\Di;

class UserDao
{
}

class UserService
{
    protected $userDao;
    protected $userType;

    public function setUserDao(UserDao $userDao)
    {
        $this->userDao = $userDao;
    }

    public function setUserType($userType)
    {
        $this->userType = $userType;
    }
}

$di = new Di();

$di->set(
    'userService',
    [
        'className'	=>	'UserService',
        'calls'		=>	[
            [
                'method'	=>	'setUserDao',
                'arguments'	=>	[
                    [
                        'type'	=>	'service',
                        'name'	=>	'userDao',
                    ]
                ]
            ],
            [
                'method'	=>	'setUserType',
                'arguments'	=>	[
                    [
                        'type'	=>	'parameter',
                        'value'	=>	3
                    ]
                ]
            ]
        ]
    ]
);
var_dump($di->get('userService'));
