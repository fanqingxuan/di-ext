
extern zend_class_entry *tools_di_ce;

ZEPHIR_INIT_CLASS(Tools_Di);

PHP_METHOD(Tools_Di, __construct);
PHP_METHOD(Tools_Di, __call);
PHP_METHOD(Tools_Di, attempt);
PHP_METHOD(Tools_Di, get);
PHP_METHOD(Tools_Di, __get);
PHP_METHOD(Tools_Di, getDefault);
PHP_METHOD(Tools_Di, getRaw);
PHP_METHOD(Tools_Di, getService);
PHP_METHOD(Tools_Di, getServices);
PHP_METHOD(Tools_Di, getShared);
PHP_METHOD(Tools_Di, loadFromConfig);
PHP_METHOD(Tools_Di, loadFromPhp);
PHP_METHOD(Tools_Di, has);
PHP_METHOD(Tools_Di, offsetGet);
PHP_METHOD(Tools_Di, offsetExists);
PHP_METHOD(Tools_Di, offsetSet);
PHP_METHOD(Tools_Di, offsetUnset);
PHP_METHOD(Tools_Di, register);
PHP_METHOD(Tools_Di, remove);
PHP_METHOD(Tools_Di, reset);
PHP_METHOD(Tools_Di, set);
PHP_METHOD(Tools_Di, __set);
PHP_METHOD(Tools_Di, setDefault);
PHP_METHOD(Tools_Di, setService);
PHP_METHOD(Tools_Di, setShared);

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di___call, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_attempt, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, definition)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, shared)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_getdefault, 0, 0, Tools\\Di\\DiInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_getdefault, 0, 0, IS_OBJECT, "Tools\\Di\\DiInterface", 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_getraw, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_getservice, 0, 1, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_getservice, 0, 1, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_getservices, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_getservices, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_getshared, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_loadfromconfig, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_loadfromconfig, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_loadfromconfig, 0, 0, 1)
#define arginfo_tools_di_loadfromconfig NULL
#endif

	ZEND_ARG_OBJ_INFO(0, config, Tools\\Config, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_loadfromphp, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_loadfromphp, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_loadfromphp, 0, 0, 1)
#define arginfo_tools_di_loadfromphp NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_offsetset, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_offsetset, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_offsetset, 0, 0, 2)
#define arginfo_tools_di_offsetset NULL
#endif

	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_offsetunset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_offsetunset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_offsetunset, 0, 0, 1)
#define arginfo_tools_di_offsetunset NULL
#endif

	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_register, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_register, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_register, 0, 0, 1)
#define arginfo_tools_di_register NULL
#endif

	ZEND_ARG_OBJ_INFO(0, provider, Tools\\Di\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_remove, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_remove, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_remove, 0, 0, 1)
#define arginfo_tools_di_remove NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_reset, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_reset, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_tools_di_reset NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_set, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_set, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, definition)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, shared)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di___set, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di___set, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_setdefault, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_setdefault, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_setdefault, 0, 0, 1)
#define arginfo_tools_di_setdefault NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, Tools\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_setservice, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_setservice, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_OBJ_INFO(0, rawDefinition, Tools\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_setshared, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_setshared, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(tools_di_method_entry) {
	PHP_ME(Tools_Di, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Tools_Di, __call, arginfo_tools_di___call, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, attempt, arginfo_tools_di_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, get, arginfo_tools_di_get, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, __get, arginfo_tools_di___get, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, getDefault, arginfo_tools_di_getdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Tools_Di, getRaw, arginfo_tools_di_getraw, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, getService, arginfo_tools_di_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, getServices, arginfo_tools_di_getservices, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, getShared, arginfo_tools_di_getshared, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, loadFromConfig, arginfo_tools_di_loadfromconfig, ZEND_ACC_PROTECTED)
	PHP_ME(Tools_Di, loadFromPhp, arginfo_tools_di_loadfromphp, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, has, arginfo_tools_di_has, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, offsetGet, arginfo_tools_di_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, offsetExists, arginfo_tools_di_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, offsetSet, arginfo_tools_di_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, offsetUnset, arginfo_tools_di_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, register, arginfo_tools_di_register, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, remove, arginfo_tools_di_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, reset, arginfo_tools_di_reset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Tools_Di, set, arginfo_tools_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, __set, arginfo_tools_di___set, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, setDefault, arginfo_tools_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Tools_Di, setService, arginfo_tools_di_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(Tools_Di, setShared, arginfo_tools_di_setshared, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
