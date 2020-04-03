
extern zend_class_entry *jsontools_di_serviceproviderinterface_ce;

ZEPHIR_INIT_CLASS(JsonTools_Di_ServiceProviderInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_serviceproviderinterface_register, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_di_serviceproviderinterface_register, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_di_serviceproviderinterface_register, 0, 0, 1)
#define arginfo_jsontools_di_serviceproviderinterface_register NULL
#endif

	ZEND_ARG_OBJ_INFO(0, di, JsonTools\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsontools_di_serviceproviderinterface_method_entry) {
	PHP_ABSTRACT_ME(JsonTools_Di_ServiceProviderInterface, register, arginfo_jsontools_di_serviceproviderinterface_register)
	PHP_FE_END
};
