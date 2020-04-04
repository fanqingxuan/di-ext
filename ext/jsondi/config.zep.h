
extern zend_class_entry *jsondi_config_ce;

ZEPHIR_INIT_CLASS(JsonDi_Config);

PHP_METHOD(JsonDi_Config, getPathDelimiter);
PHP_METHOD(JsonDi_Config, merge);
PHP_METHOD(JsonDi_Config, path);
PHP_METHOD(JsonDi_Config, setPathDelimiter);
PHP_METHOD(JsonDi_Config, toArray);
PHP_METHOD(JsonDi_Config, internalMerge);
PHP_METHOD(JsonDi_Config, setData);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_getpathdelimiter, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_getpathdelimiter, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_config_merge, 0, 1, JsonDi\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_merge, 0, 1, IS_OBJECT, "JsonDi\\Config", 0)
#endif
	ZEND_ARG_INFO(0, toMerge)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_config_path, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, path)
#endif
	ZEND_ARG_INFO(0, defaultValue)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsondi_config_setpathdelimiter, 0, 0, JsonDi\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_setpathdelimiter, 0, 0, IS_OBJECT, "JsonDi\\Config", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, delimiter, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, delimiter)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_internalmerge, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_internalmerge, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, source, 0)
	ZEND_ARG_ARRAY_INFO(0, target, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_setdata, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsondi_config_setdata, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsondi_config_setdata, 0, 0, 2)
#define arginfo_jsondi_config_setdata NULL
#endif

	ZEND_ARG_INFO(0, element)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsondi_config_method_entry) {
	PHP_ME(JsonDi_Config, getPathDelimiter, arginfo_jsondi_config_getpathdelimiter, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Config, merge, arginfo_jsondi_config_merge, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Config, path, arginfo_jsondi_config_path, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Config, setPathDelimiter, arginfo_jsondi_config_setpathdelimiter, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Config, toArray, arginfo_jsondi_config_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(JsonDi_Config, internalMerge, arginfo_jsondi_config_internalmerge, ZEND_ACC_FINAL|ZEND_ACC_PROTECTED)
	PHP_ME(JsonDi_Config, setData, arginfo_jsondi_config_setdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
