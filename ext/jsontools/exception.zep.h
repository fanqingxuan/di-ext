
extern zend_class_entry *jsontools_exception_ce;

ZEPHIR_INIT_CLASS(JsonTools_Exception);

PHP_METHOD(JsonTools_Exception, containerServiceNotFound);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_exception_containerservicenotfound, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_exception_containerservicenotfound, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, service, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, service)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsontools_exception_method_entry) {
	PHP_ME(JsonTools_Exception, containerServiceNotFound, arginfo_jsontools_exception_containerservicenotfound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
