
extern zend_class_entry *tools_di_serviceproviderinterface_ce;

ZEPHIR_INIT_CLASS(Tools_Di_ServiceProviderInterface);

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_serviceproviderinterface_register, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_tools_di_serviceproviderinterface_register, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_tools_di_serviceproviderinterface_register, 0, 0, 1)
#define arginfo_tools_di_serviceproviderinterface_register NULL
#endif

	ZEND_ARG_OBJ_INFO(0, di, Tools\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(tools_di_serviceproviderinterface_method_entry) {
	PHP_ABSTRACT_ME(Tools_Di_ServiceProviderInterface, register, arginfo_tools_di_serviceproviderinterface_register)
	PHP_FE_END
};
