
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "jsontools.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *jsontools_di_injectionawareinterface_ce;
zend_class_entry *jsontools_di_diinterface_ce;
zend_class_entry *jsontools_di_serviceinterface_ce;
zend_class_entry *jsontools_di_serviceproviderinterface_ce;
zend_class_entry *jsontools_collection_ce;
zend_class_entry *jsontools_config_ce;
zend_class_entry *jsontools_exception_ce;
zend_class_entry *jsontools_di_exception_ce;
zend_class_entry *jsontools_config_adapter_ini_ce;
zend_class_entry *jsontools_config_adapter_php_ce;
zend_class_entry *jsontools_di_abstractinjectionaware_ce;
zend_class_entry *jsontools_di_ce;
zend_class_entry *jsontools_di_exception_serviceresolutionexception_ce;
zend_class_entry *jsontools_di_injectable_ce;
zend_class_entry *jsontools_di_service_builder_ce;
zend_class_entry *jsontools_di_service_ce;
zend_class_entry *jsontools_helper_json_ce;

ZEND_DECLARE_MODULE_GLOBALS(jsontools)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(jsontools)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(JsonTools_Di_InjectionAwareInterface);
	ZEPHIR_INIT(JsonTools_Di_DiInterface);
	ZEPHIR_INIT(JsonTools_Di_ServiceInterface);
	ZEPHIR_INIT(JsonTools_Di_ServiceProviderInterface);
	ZEPHIR_INIT(JsonTools_Collection);
	ZEPHIR_INIT(JsonTools_Config);
	ZEPHIR_INIT(JsonTools_Exception);
	ZEPHIR_INIT(JsonTools_Di_Exception);
	ZEPHIR_INIT(JsonTools_Config_Adapter_Ini);
	ZEPHIR_INIT(JsonTools_Config_Adapter_Php);
	ZEPHIR_INIT(JsonTools_Di);
	ZEPHIR_INIT(JsonTools_Di_AbstractInjectionAware);
	ZEPHIR_INIT(JsonTools_Di_Exception_ServiceResolutionException);
	ZEPHIR_INIT(JsonTools_Di_Injectable);
	ZEPHIR_INIT(JsonTools_Di_Service);
	ZEPHIR_INIT(JsonTools_Di_Service_Builder);
	ZEPHIR_INIT(JsonTools_Helper_Json);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(jsontools)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_jsontools_globals *jsontools_globals TSRMLS_DC)
{
	jsontools_globals->initialized = 0;

	/* Cache Enabled */
	jsontools_globals->cache_enabled = 1;

	/* Recursive Lock */
	jsontools_globals->recursive_lock = 0;

	/* Static cache */
	memset(jsontools_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_jsontools_globals *jsontools_globals TSRMLS_DC)
{
	
}

static PHP_RINIT_FUNCTION(jsontools)
{
	zend_jsontools_globals *jsontools_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	jsontools_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(jsontools_globals_ptr);
	zephir_initialize_memory(jsontools_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(jsontools)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(jsontools)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_JSONTOOLS_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_JSONTOOLS_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_JSONTOOLS_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_JSONTOOLS_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_JSONTOOLS_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(jsontools)
{
	php_zephir_init_globals(jsontools_globals);
	php_zephir_init_module_globals(jsontools_globals);
}

static PHP_GSHUTDOWN_FUNCTION(jsontools)
{
	
}


zend_function_entry php_jsontools_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_jsontools_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry jsontools_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_jsontools_deps,
	PHP_JSONTOOLS_EXTNAME,
	php_jsontools_functions,
	PHP_MINIT(jsontools),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(jsontools),
#else
	NULL,
#endif
	PHP_RINIT(jsontools),
	PHP_RSHUTDOWN(jsontools),
	PHP_MINFO(jsontools),
	PHP_JSONTOOLS_VERSION,
	ZEND_MODULE_GLOBALS(jsontools),
	PHP_GINIT(jsontools),
	PHP_GSHUTDOWN(jsontools),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(jsontools),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_JSONTOOLS
ZEND_GET_MODULE(jsontools)
#endif
