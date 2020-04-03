
extern zend_class_entry *jsontools_collection_ce;

ZEPHIR_INIT_CLASS(JsonTools_Collection);

PHP_METHOD(JsonTools_Collection, __construct);
PHP_METHOD(JsonTools_Collection, __get);
PHP_METHOD(JsonTools_Collection, __isset);
PHP_METHOD(JsonTools_Collection, __set);
PHP_METHOD(JsonTools_Collection, __unset);
PHP_METHOD(JsonTools_Collection, clear);
PHP_METHOD(JsonTools_Collection, count);
PHP_METHOD(JsonTools_Collection, get);
PHP_METHOD(JsonTools_Collection, getIterator);
PHP_METHOD(JsonTools_Collection, getKeys);
PHP_METHOD(JsonTools_Collection, getValues);
PHP_METHOD(JsonTools_Collection, has);
PHP_METHOD(JsonTools_Collection, init);
PHP_METHOD(JsonTools_Collection, jsonSerialize);
PHP_METHOD(JsonTools_Collection, offsetExists);
PHP_METHOD(JsonTools_Collection, offsetGet);
PHP_METHOD(JsonTools_Collection, offsetSet);
PHP_METHOD(JsonTools_Collection, offsetUnset);
PHP_METHOD(JsonTools_Collection, remove);
PHP_METHOD(JsonTools_Collection, set);
PHP_METHOD(JsonTools_Collection, serialize);
PHP_METHOD(JsonTools_Collection, toArray);
PHP_METHOD(JsonTools_Collection, toJson);
PHP_METHOD(JsonTools_Collection, unserialize);
PHP_METHOD(JsonTools_Collection, setData);
zend_object *zephir_init_properties_JsonTools_Collection(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, insensitive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, insensitive)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection___isset, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection___isset, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection___set, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection___set, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection___set, 0, 0, 2)
#define arginfo_jsontools_collection___set NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection___unset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection___unset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection___unset, 0, 0, 1)
#define arginfo_jsontools_collection___unset NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_clear, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_clear, 0, 0, IS_VOID, NULL, 0)
#endif
ZEND_END_ARG_INFO()
#else
#define arginfo_jsontools_collection_clear NULL
#endif

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_count, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_count, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, cast, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, cast)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_jsontools_collection_getiterator, 0, 0, Traversable, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_getiterator, 0, 0, IS_OBJECT, "Traversable", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_getkeys, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_getkeys, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, insensitive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, insensitive)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_getvalues, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_getvalues, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_init, 0, 0, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_init, 0, 0, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_init, 0, 0, 0)
#define arginfo_jsontools_collection_init NULL
#endif

	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_jsonserialize, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_jsonserialize, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_offsetexists, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_offsetexists, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_offsetset, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_offsetset, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_offsetset, 0, 0, 2)
#define arginfo_jsontools_collection_offsetset NULL
#endif

	ZEND_ARG_INFO(0, element)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_offsetunset, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_offsetunset, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_offsetunset, 0, 0, 1)
#define arginfo_jsontools_collection_offsetunset NULL
#endif

	ZEND_ARG_INFO(0, element)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_remove, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_remove, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_remove, 0, 0, 1)
#define arginfo_jsontools_collection_remove NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_set, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_set, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_set, 0, 0, 2)
#define arginfo_jsontools_collection_set NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_serialize, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_serialize, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_tojson, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_tojson, 0, 0, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, options, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, options)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_unserialize, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_unserialize, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_unserialize, 0, 0, 1)
#define arginfo_jsontools_collection_unserialize NULL
#endif

	ZEND_ARG_INFO(0, serialized)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_setdata, 0, 2, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_jsontools_collection_setdata, 0, 2, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_jsontools_collection_setdata, 0, 0, 2)
#define arginfo_jsontools_collection_setdata NULL
#endif

#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, element, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, element)
#endif
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(jsontools_collection_method_entry) {
	PHP_ME(JsonTools_Collection, __construct, arginfo_jsontools_collection___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(JsonTools_Collection, __get, arginfo_jsontools_collection___get, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, __isset, arginfo_jsontools_collection___isset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, __set, arginfo_jsontools_collection___set, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, __unset, arginfo_jsontools_collection___unset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, clear, arginfo_jsontools_collection_clear, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, count, arginfo_jsontools_collection_count, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, get, arginfo_jsontools_collection_get, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, getIterator, arginfo_jsontools_collection_getiterator, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, getKeys, arginfo_jsontools_collection_getkeys, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, getValues, arginfo_jsontools_collection_getvalues, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, has, arginfo_jsontools_collection_has, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, init, arginfo_jsontools_collection_init, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, jsonSerialize, arginfo_jsontools_collection_jsonserialize, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, offsetExists, arginfo_jsontools_collection_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, offsetGet, arginfo_jsontools_collection_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, offsetSet, arginfo_jsontools_collection_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, offsetUnset, arginfo_jsontools_collection_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, remove, arginfo_jsontools_collection_remove, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, set, arginfo_jsontools_collection_set, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, serialize, arginfo_jsontools_collection_serialize, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, toArray, arginfo_jsontools_collection_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, toJson, arginfo_jsontools_collection_tojson, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, unserialize, arginfo_jsontools_collection_unserialize, ZEND_ACC_PUBLIC)
	PHP_ME(JsonTools_Collection, setData, arginfo_jsontools_collection_setdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
