
extern zend_class_entry *tools_di_serviceinterface_ce;

ZEPHIR_INIT_CLASS(Tools_Di_ServiceInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_serviceinterface_getparameter, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, position)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_serviceinterface_isresolved, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_serviceinterface_isresolved, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_serviceinterface_isshared, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_serviceinterface_isshared, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_serviceinterface_resolve, 0, 0, 0)
	ZEND_ARG_INFO(0, parameters)
	ZEND_ARG_OBJ_INFO(0, container, Tools\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_serviceinterface_setdefinition, 0, 0, 1)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_tools_di_serviceinterface_setparameter, 0, 2, Tools\\Di\\ServiceInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_serviceinterface_setparameter, 0, 2, IS_OBJECT, "Tools\\Di\\ServiceInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, position)
#endif
	ZEND_ARG_ARRAY_INFO(0, parameter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_serviceinterface_setshared, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, shared, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, shared)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(tools_di_serviceinterface_method_entry) {
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, getDefinition, NULL)
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, getParameter, arginfo_tools_di_serviceinterface_getparameter)
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, isResolved, arginfo_tools_di_serviceinterface_isresolved)
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, isShared, arginfo_tools_di_serviceinterface_isshared)
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, resolve, arginfo_tools_di_serviceinterface_resolve)
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, setDefinition, arginfo_tools_di_serviceinterface_setdefinition)
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, setParameter, arginfo_tools_di_serviceinterface_setparameter)
	PHP_ABSTRACT_ME(Tools_Di_ServiceInterface, setShared, arginfo_tools_di_serviceinterface_setshared)
	PHP_FE_END
};