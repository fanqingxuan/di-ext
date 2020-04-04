
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_JSONDI_H
#define PHP_JSONDI_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_JSONDI_NAME        "jsondi"
#define PHP_JSONDI_VERSION     "1.0.0"
#define PHP_JSONDI_EXTNAME     "jsondi"
#define PHP_JSONDI_AUTHOR      "Json"
#define PHP_JSONDI_ZEPVERSION  "0.12.12-1094502"
#define PHP_JSONDI_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(jsondi)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(jsondi)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(jsondi)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(jsondi, v)
#else
	#define ZEPHIR_GLOBAL(v) (jsondi_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_jsondi_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(jsondi_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(jsondi_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def jsondi_globals
#define zend_zephir_globals_def zend_jsondi_globals

extern zend_module_entry jsondi_module_entry;
#define phpext_jsondi_ptr &jsondi_module_entry

#endif
