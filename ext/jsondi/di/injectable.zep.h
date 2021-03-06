
extern zend_class_entry *jsondi_di_injectable_ce;

ZEPHIR_INIT_CLASS(JsonDi_Di_Injectable);

PHP_METHOD(JsonDi_Di_Injectable, __get);
PHP_METHOD(JsonDi_Di_Injectable, __isset);
PHP_METHOD(JsonDi_Di_Injectable, getDI);
PHP_METHOD(JsonDi_Di_Injectable, setDI);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_injectable___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, propertyName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, propertyName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_injectable___isset, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_injectable___isset, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_di_injectable_getdi, 0, 0, JsonDi\\Di\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_injectable_getdi, 0, 0, IS_OBJECT, "JsonDi\\Di\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_injectable_setdi, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_di_injectable_setdi, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_di_injectable_setdi, 0, 0, 1)
#define arginfo_jsondi_di_injectable_setdi NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, JsonDi\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsondi_di_injectable_method_entry) {
	PHP_ME(JsonDi_Di_Injectable, __get, arginfo_jsondi_di_injectable___get, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di_Injectable, __isset, arginfo_jsondi_di_injectable___isset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di_Injectable, getDI, arginfo_jsondi_di_injectable_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Di_Injectable, setDI, arginfo_jsondi_di_injectable_setdi, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
