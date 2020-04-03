
extern zend_class_entry *jsontools_config_adapter_php_ce;

ZEPHIR_INIT_CLASS(JsonTools_Config_Adapter_Php);

PHP_METHOD(JsonTools_Config_Adapter_Php, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_config_adapter_php___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, filePath)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsontools_config_adapter_php_method_entry) {
	PHP_ME(JsonTools_Config_Adapter_Php, __construct, arginfo_jsontools_config_adapter_php___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
