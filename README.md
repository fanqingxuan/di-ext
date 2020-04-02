## a IOC container for php that implement as c extension.

This is a extension which implements Dependency Injection, it's itself a container and it  implements the 

Inversion of Control pattern.
### enviroment requirement 
**php7.0+**

### Install 
The same as other extensions like memcache,redis installation.
```php+HTML
cd XXX/ext
phpize
./configure --with-php-config=XXX/php-config
make && make install
add "extension=jsontools" in your php.ini file
```

If you want install it as php code that is you don't need install php-extension, Please install it from **[di](https://github.com/fanqingxuan/di)**. Both of them have the same usage. Please enjoy it.

### Basic Usage 

```php
use JsonTools\Di;

class Test
{
}

$di = new Di;
//注入的方式
$di->set('test', 'Test');
$di->set("test2", function () {
    return new Test;
});
$di->set("test3", Test::class);
$di->set('test4', new Test);

```

like you can see,there are serveral ways to register services as the follow list.

- string 

  ```php
  $di->set('test','Test');
  $di->set("test3",Test::class);
  ```

- object instance

  ```php
  $di->set('test5',new Test);
  ```

- Closures/Anonymous functions

  ```php
  $di->set("test2",function() {
  	return new Test;
  });
  ```

You can pass additonal parameters to closure function.

```php
use JsonTools\Di;
use JsonTools\Config;
$di = new Di;
$di->set('config',new Config(
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
$di->set('db',function () {
    return new MysqlDb($this->get('config')->database);//get the database config from container
});
```

also,you can pass parameter by using the key word of use.

```php
$config = [
    'host'      =>  'localhost',
    'username'  =>  'root',
    'password'  =>  '111111'
];
$di->set('db',function () use ($config) {
    return new MysqlDb($config);
});
```

### Advanced Usage

- #### Constructor Injection

  This is injection type can pass arguments to the class constructor.

  ```php
  class UserService 
  {
      protected $userDao;
      protected $userType;
      
      public function __construct(UserDao $userDao,$userType) 
      {
          $this->userDao  = $userDao;
          $this->userType = $userType;
      }
  }
  ```

  We can register the service this way.

  ```php
  $di->set(
      'userDao',
      [
  		'className'	=>	UserDao::class
      ]
  );
  $di->set(
  	'userService',
      [
          'className'	=>	UserService::class,
          'arguments'	=>	[
              [
                  'type'	=>	'service',
                  'name'	=>	'userDao',//another service name in the container
              ],
              [
                  'type'	=>	'parameter',
                  'value'	=>	3
              ]
          ]
      ]
  );
  ```

- #### Setter Injection

Some class have setters for injection with their specail demand. We modify the above service as the class with setters.

```php 
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
```

A service with setter injection can be registered as follows:

```php
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
```

- #### Properties Injection

 You can inject parameters directly into **public attributes** of the class:

```php
class UserService 
{
    public $userDao;
    public $userType;
    public $tempObj;
}
```

A service with properties injection can be registered as follows

```php
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
```

### More Advanced Usage

The next we will give a way that inject service from php file.

```php
//service.php
<?php
return [
    'testA' => [
        'className' => Test::class,
        'shared'    => true,
    ],
];
```

We can inject it to container as follows:

```php
use Json/Config;
$di->loadFromPhp('service.php');
```



### Array Syntax Usage

We introduce the usage with the set function above. In fact,the array syntax is also allowed to register as services.

```php
$di['db'] = new StdClass;
$di['db'] = function() {
    return new StdClass;
}
$di['db'] = 'StdClass';
$di['db'] = [
    'className'	=>	'StdClass'
]
```

### Property Syntax Usage

We can inject the object with the property usage. Actually,it use the magic methd to realize it.

```php
$di->db = new StdClass;
$di->db = function() {
    return new StdClass;
}
$di->db = StdClass::class;
$di->db = [
    'className'	=>	'stdClass'
];
```



### Get Services

- get method

  ```php
  $di->get('db');
  ```

- magic method

  ```php
  $di->getDb();
  ```

- array-access syntax

  ```php
  $di['db'];
  ```

- property syntax

  ```
  $di->db;
  ```



### Shared Services

Services can be registered as ‘shared’ services this means that they always will act as singletons. Once the service is resolved for the first time the same instance of it is returned every time.

```php
$di->setShared(
	'db',
    function() {
        return new MysqlDb();
    }
);
```

or use the set method with its third parameter as 'true'.

```php
$di->set(
	'db',
    function() {
        return new MysqlDb();
    },
    true
);
```

### Modify the Services

When the service is registered in the container,you can get it and modify it.

```php
class Test 
{
    
}
//register service
$di->set('test','StdClass');
//get service
$test = $di->getService('test');
//change the definition
$test->setDefinition(function() {
    return new Test;
});
//resolve the service
$test->resolve();
```

### Automatic Inject the DI Container into the service

DI Container is used for inject other service into it. but sometimes the service itself need the the other instance from the container. If a class or component requires the DI itself to locate services, the DI can automatically inject itself to the instances it creates, to do this, you need to extends the JsonTools\Di\AbstractInjectionAware class in your classes: 

```php
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
```

### Service Providers

Using the JsonTools\Di\ServiceProviderInterface  you now register services by context. You can move all your `$di->set()` calls to classes as follows. **Notice return void for the register function**.
```php
use JsonTools\Di\DiInterface;
use JsonTools\Di\ServiceProviderInterface;
class SessionServiceProvider implements ServiceProviderInterface 
{
    public function register(DiInterface $di):void
    {
        $di->set(
        	'session',
            'SessionClass'
        );
    }
}
$di->register(new SessionServiceProvider());
$di->get('session');
```