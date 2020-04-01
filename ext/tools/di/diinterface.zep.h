
extern zend_class_entry *tools_di_diinterface_ce;

ZEPHIR_INIT_CLASS(Tools_Di_DiInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_diinterface_attempt, 0, 0, 2)
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_diinterface_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_diinterface_getdefault, 0, 0, Tools\\Di\\DiInterface, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_getdefault, 0, 0, IS_OBJECT, "Tools\\Di\\DiInterface", 1)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_diinterface_getraw, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_diinterface_getservice, 0, 1, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_getservice, 0, 1, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_getservices, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_getservices, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_diinterface_getshared, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, parameters)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_remove, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_remove, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_diinterface_remove, 0, 0, 1)
#define arginfo_tools_di_diinterface_remove NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_reset, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_reset, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_tools_di_diinterface_reset NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_diinterface_set, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_set, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
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

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_setdefault, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_setdefault, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_diinterface_setdefault, 0, 0, 1)
#define arginfo_tools_di_diinterface_setdefault NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, Tools\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_diinterface_setservice, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_setservice, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_OBJ_INFO(0, rawDefinition, Tools\\Di\\ServiceInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_diinterface_setshared, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_diinterface_setshared, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(tools_di_diinterface_method_entry) {
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, attempt, arginfo_tools_di_diinterface_attempt)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, get, arginfo_tools_di_diinterface_get)
	ZEND_FENTRY(getDefault, NULL, arginfo_tools_di_diinterface_getdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, getRaw, arginfo_tools_di_diinterface_getraw)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, getService, arginfo_tools_di_diinterface_getservice)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, getServices, arginfo_tools_di_diinterface_getservices)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, getShared, arginfo_tools_di_diinterface_getshared)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, has, arginfo_tools_di_diinterface_has)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, remove, arginfo_tools_di_diinterface_remove)
	ZEND_FENTRY(reset, NULL, arginfo_tools_di_diinterface_reset, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, set, arginfo_tools_di_diinterface_set)
	ZEND_FENTRY(setDefault, NULL, arginfo_tools_di_diinterface_setdefault, ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, setService, arginfo_tools_di_diinterface_setservice)
	PHP_ABSTRACT_ME(Tools_Di_DiInterface, setShared, arginfo_tools_di_diinterface_setshared)
	PHP_FE_END
};
