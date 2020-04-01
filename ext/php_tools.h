
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_TOOLS_H
#define PHP_TOOLS_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_TOOLS_NAME        "tools"
#define PHP_TOOLS_VERSION     "1.0.0"
#define PHP_TOOLS_EXTNAME     "tools"
#define PHP_TOOLS_AUTHOR      "Json"
#define PHP_TOOLS_ZEPVERSION  "0.12.12-1094502"
#define PHP_TOOLS_DESCRIPTION ""



ZEND_BEGIN_MODULE_GLOBALS(tools)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(tools)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(tools)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(tools, v)
#else
	#define ZEPHIR_GLOBAL(v) (tools_globals.v)
#endif

#ifdef ZTS
	void ***tsrm_ls;
	#define ZEPHIR_VGLOBAL ((zend_tools_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(tools_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(tools_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def tools_globals
#define zend_zephir_globals_def zend_tools_globals

extern zend_module_entry tools_module_entry;
#define phpext_tools_ptr &tools_module_entry

#endif
