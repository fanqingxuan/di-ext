
extern zend_class_entry *jsondi_di_ce;

ZEPHIR_INIT_CLASS(JsonDi_Di);

PHP_METHOD(JsonDi_Di, __construct);
PHP_METHOD(JsonDi_Di, __call);
PHP_METHOD(JsonDi_Di, attempt);
PHP_METHOD(JsonDi_Di, get);
PHP_METHOD(JsonDi_Di, __get);
PHP_METHOD(JsonDi_Di, getDefault);
PHP_METHOD(JsonDi_Di, getRaw);
PHP_METHOD(JsonDi_Di, getService);
PHP_METHOD(JsonDi_Di, getServices);
PHP_METHOD(JsonDi_Di, getShared);
PHP_METHOD(JsonDi_Di, loadFromConfig);
PHP_METHOD(JsonDi_Di, loadFromPhp);
PHP_METHOD(JsonDi_Di, has);
PHP_METHOD(JsonDi_Di, offsetGet);
PHP_METHOD(JsonDi_Di, offsetExists);
PHP_METHOD(JsonDi_Di, offsetSet);
PHP_METHOD(JsonDi_Di, offsetUnset);
PHP_METHOD(JsonDi_Di, register);
PHP_METHOD(JsonDi_Di, remove);
PHP_METHOD(JsonDi_Di, reset);
PHP_METHOD(JsonDi_Di, set);
PHP_METHOD(JsonDi_Di, __set);
PHP_METHOD(JsonDi_Di, setDefault);
PHP_METHOD(JsonDi_Di, setService);
PHP_METHOD(JsonDi_Di, setShared);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di___call, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_ARRAY_INFO(0, arguments, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_attempt, 0, 0, 2)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_di_getdefault, 0, 0, JsonDi\\Di\\DiInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_getdefault, 0, 0, IS_OBJECT, "JsonDi\\Di\\DiInterface", 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_getraw, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_di_getservice, 0, 1, JsonDi\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_getservice, 0, 1, IS_OBJECT, "JsonDi\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_getservices, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_getservices, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_getshared, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_loadfromconfig, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_loadfromconfig, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_loadfromconfig, 0, 0, 1)
#define arginfo_jsondi_di_loadfromconfig NULL
#endif

	ZEND_ARG_OBJ_INFO(0, config, JsonDi\\Config, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_loadfromphp, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_loadfromphp, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_loadfromphp, 0, 0, 1)
#define arginfo_jsondi_di_loadfromphp NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_offsetset, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_offsetset, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_offsetset, 0, 0, 2)
#define arginfo_jsondi_di_offsetset NULL
#endif

	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_offsetunset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_offsetunset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_offsetunset, 0, 0, 1)
#define arginfo_jsondi_di_offsetunset NULL
#endif

	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_register, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_register, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_register, 0, 0, 1)
#define arginfo_jsondi_di_register NULL
#endif

	ZEND_ARG_OBJ_INFO(0, provider, JsonDi\\Di\\ServiceProviderInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_remove, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_remove, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_remove, 0, 0, 1)
#define arginfo_jsondi_di_remove NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_reset, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_reset, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_jsondi_di_reset NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_di_set, 0, 2, JsonDi\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_set, 0, 2, IS_OBJECT, "JsonDi\\Di\\ServiceInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_di___set, 0, 2, JsonDi\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di___set, 0, 2, IS_OBJECT, "JsonDi\\Di\\ServiceInterface", 0)
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
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_setdefault, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_setdefault, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_setdefault, 0, 0, 1)
#define arginfo_jsondi_di_setdefault NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, JsonDi\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_di_setservice, 0, 2, JsonDi\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_setservice, 0, 2, IS_OBJECT, "JsonDi\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_OBJ_INFO(0, rawDefinition, JsonDi\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_di_setshared, 0, 2, JsonDi\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_setshared, 0, 2, IS_OBJECT, "JsonDi\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsondi_di_method_entry) {
	PHP_ME(JsonDi_Di, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(JsonDi_Di, __call, arginfo_jsondi_di___call, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, attempt, arginfo_jsondi_di_attempt, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, get, arginfo_jsondi_di_get, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, __get, arginfo_jsondi_di___get, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, getDefault, arginfo_jsondi_di_getdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(JsonDi_Di, getRaw, arginfo_jsondi_di_getraw, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, getService, arginfo_jsondi_di_getservice, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, getServices, arginfo_jsondi_di_getservices, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, getShared, arginfo_jsondi_di_getshared, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, loadFromConfig, arginfo_jsondi_di_loadfromconfig, ZEND_ACC_PROTECTED)
	PHP_ME(JsonDi_Di, loadFromPhp, arginfo_jsondi_di_loadfromphp, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, has, arginfo_jsondi_di_has, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, offsetGet, arginfo_jsondi_di_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, offsetExists, arginfo_jsondi_di_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, offsetSet, arginfo_jsondi_di_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, offsetUnset, arginfo_jsondi_di_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, register, arginfo_jsondi_di_register, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, remove, arginfo_jsondi_di_remove, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, reset, arginfo_jsondi_di_reset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(JsonDi_Di, set, arginfo_jsondi_di_set, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, __set, arginfo_jsondi_di___set, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, setDefault, arginfo_jsondi_di_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(JsonDi_Di, setService, arginfo_jsondi_di_setservice, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di, setShared, arginfo_jsondi_di_setshared, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
