
extern zend_class_entry *jsontools_di_injectionawareinterface_ce;

ZEPHIR_INIT_CLASS(JsonTools_Di_InjectionAwareInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_injectionawareinterface_setdi, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_injectionawareinterface_setdi, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_injectionawareinterface_setdi, 0, 0, 1)
#define arginfo_jsontools_di_injectionawareinterface_setdi NULL
#endif

	ZEND_ARG_OBJ_INFO(0, container, JsonTools\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_di_injectionawareinterface_getdi, 0, 0, JsonTools\\Di\\DiInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_injectionawareinterface_getdi, 0, 0, IS_OBJECT, "JsonTools\\Di\\DiInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsontools_di_injectionawareinterface_method_entry) {
	PHP_ABSTRACT_ME(JsonTools_Di_InjectionAwareInterface, setDI, arginfo_jsontools_di_injectionawareinterface_setdi)
	PHP_ABSTRACT_ME(JsonTools_Di_InjectionAwareInterface, getDI, arginfo_jsontools_di_injectionawareinterface_getdi)
	PHP_FE_END
};
