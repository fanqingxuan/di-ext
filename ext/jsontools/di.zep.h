
extern zend_class_entry *jsontools_di_ce;

ZEPHIR_INIT_CLASS(JsonTools_Di);

PHP_METHOD(JsonTools_Di, __construct);
PHP_METHOD(JsonTools_Di, __call);
PHP_METHOD(JsonTools_Di, attempt);
PHP_METHOD(JsonTools_Di, get);
PHP_METHOD(JsonTools_Di, __get);
PHP_METHOD(JsonTools_Di, getDefault);
PHP_METHOD(JsonTools_Di, getRaw);
PHP_METHOD(JsonTools_Di, getService);
PHP_METHOD(JsonTools_Di, getServices);
PHP_METHOD(JsonTools_Di, getShared);
PHP_METHOD(JsonTools_Di, loadFromConfig);
PHP_METHOD(JsonTools_Di, loadFromPhp);
PHP_METHOD(JsonTools_Di, has);
PHP_METHOD(JsonTools_Di, offsetGet);
PHP_METHOD(JsonTools_Di, offsetExists);
PHP_METHOD(JsonTools_Di, offsetSet);
PHP_METHOD(JsonTools_Di, offsetUnset);
PHP_METHOD(JsonTools_Di, register);
PHP_METHOD(JsonTools_Di, remove);
PHP_METHOD(JsonTools_Di, reset);
PHP_METHOD(JsonTools_Di, set);
PHP_METHOD(JsonTools_Di, __set);
PHP_METHOD(JsonTools_Di, setDefault);
PHP_METHOD(JsonTools_Di, setService);
PHP_METHOD(JsonTools_Di, setShared);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di___call, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_attempt, 0, 0, 2)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_di_getdefault, 0, 0, JsonTools\\Di\\DiInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_getdefault, 0, 0, IS_OBJECT, "JsonTools\\Di\\DiInterface", 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_getraw, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_di_getservice, 0, 1, JsonTools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_getservice, 0, 1, IS_OBJECT, "JsonTools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_getservices, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_getservices, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_getshared, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_loadfromconfig, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_loadfromconfig, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_loadfromconfig, 0, 0, 1)
#define arginfo_jsontools_di_loadfromconfig NULL
#endif

	ZEND_ARG_OBJ_INFO(0, config, JsonTools\\Config, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_loadfromphp, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_loadfromphp, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_loadfromphp, 0, 0, 1)
#define arginfo_jsontools_di_loadfromphp NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_offsetset, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_offsetset, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_offsetset, 0, 0, 2)
#define arginfo_jsontools_di_offsetset NULL
#endif

	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_offsetunset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_offsetunset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_offsetunset, 0, 0, 1)
#define arginfo_jsontools_di_offsetunset NULL
#endif

	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_register, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_register, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_register, 0, 0, 1)
#define arginfo_jsontools_di_register NULL
#endif

	ZEND_ARG_OBJ_INFO(0, provider, JsonTools\\Di\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_remove, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_remove, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_remove, 0, 0, 1)
#define arginfo_jsontools_di_remove NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_reset, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_reset, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_jsontools_di_reset NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_di_set, 0, 2, JsonTools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_set, 0, 2, IS_OBJECT, "JsonTools\\Di\\ServiceInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_di___set, 0, 2, JsonTools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di___set, 0, 2, IS_OBJECT, "JsonTools\\Di\\ServiceInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_setdefault, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_setdefault, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_setdefault, 0, 0, 1)
#define arginfo_jsontools_di_setdefault NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, JsonTools\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_di_setservice, 0, 2, JsonTools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_setservice, 0, 2, IS_OBJECT, "JsonTools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_OBJ_INFO(0, rawDefinition, JsonTools\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_di_setshared, 0, 2, JsonTools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_setshared, 0, 2, IS_OBJECT, "JsonTools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsontools_di_method_entry) {
	PHP_ME(JsonTools_Di, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(JsonTools_Di, __call, arginfo_jsontools_di___call, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, attempt, arginfo_jsontools_di_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, get, arginfo_jsontools_di_get, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, __get, arginfo_jsontools_di___get, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, getDefault, arginfo_jsontools_di_getdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(JsonTools_Di, getRaw, arginfo_jsontools_di_getraw, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, getService, arginfo_jsontools_di_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, getServices, arginfo_jsontools_di_getservices, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, getShared, arginfo_jsontools_di_getshared, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, loadFromConfig, arginfo_jsontools_di_loadfromconfig, ZEND_ACC_PROTECTED)
	PHP_ME(JsonTools_Di, loadFromPhp, arginfo_jsontools_di_loadfromphp, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, has, arginfo_jsontools_di_has, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, offsetGet, arginfo_jsontools_di_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, offsetExists, arginfo_jsontools_di_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, offsetSet, arginfo_jsontools_di_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, offsetUnset, arginfo_jsontools_di_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, register, arginfo_jsontools_di_register, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, remove, arginfo_jsontools_di_remove, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, reset, arginfo_jsontools_di_reset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(JsonTools_Di, set, arginfo_jsontools_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, __set, arginfo_jsontools_di___set, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, setDefault, arginfo_jsontools_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(JsonTools_Di, setService, arginfo_jsontools_di_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Di, setShared, arginfo_jsontools_di_setshared, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
