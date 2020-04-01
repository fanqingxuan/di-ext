PHP_ARG_ENABLE(tools, whether to enable tools, [ --enable-tools   Enable Tools])

if test "$PHP_TOOLS" = "yes"; then

	

	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, TOOLS_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_TOOLS, 1, [Whether you have Tools])
	tools_sources="tools.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c tools/collection.zep.c
	tools/config.zep.c
	tools/di/injectionawareinterface.zep.c
	tools/exception.zep.c
	tools/di/diinterface.zep.c
	tools/di/exception.zep.c
	tools/di/serviceinterface.zep.c
	tools/config/adapter/ini.zep.c
	tools/config/adapter/json.zep.c
	tools/config/adapter/php.zep.c
	tools/di.zep.c
	tools/di/abstractinjectionaware.zep.c
	tools/di/exception/serviceresolutionexception.zep.c
	tools/di/injectable.zep.c
	tools/di/service.zep.c
	tools/di/service/builder.zep.c
	tools/di/serviceproviderinterface.zep.c
	tools/helper/json.zep.c "
	PHP_NEW_EXTENSION(tools, $tools_sources, $ext_shared,, )
	PHP_SUBST(TOOLS_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([tools], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([tools], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/tools], [php_TOOLS.h])

fi
