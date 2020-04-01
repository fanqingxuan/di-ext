srcdir = /root/tools/ext
builddir = /root/tools/ext
top_srcdir = /root/tools/ext
top_builddir = /root/tools/ext
EGREP = /bin/grep -E
SED = /bin/sed
CONFIGURE_COMMAND = './configure' '--with-php-config=/usr/local/php/bin/php-config'
CONFIGURE_OPTIONS = '--with-php-config=/usr/local/php/bin/php-config'
SHLIB_SUFFIX_NAME = so
SHLIB_DL_SUFFIX_NAME = so
ZEND_EXT_TYPE = zend_extension
RE2C = re2c
AWK = gawk
shared_objects_tools = tools.lo kernel/main.lo kernel/memory.lo kernel/exception.lo kernel/debug.lo kernel/backtrace.lo kernel/object.lo kernel/array.lo kernel/string.lo kernel/fcall.lo kernel/require.lo kernel/file.lo kernel/operators.lo kernel/math.lo kernel/concat.lo kernel/variables.lo kernel/filter.lo kernel/iterator.lo kernel/time.lo kernel/exit.lo tools/collection.lo tools/config.lo tools/di/injectionawareinterface.lo tools/exception.lo tools/di/diinterface.lo tools/di/exception.lo tools/di/serviceinterface.lo tools/config/adapter/ini.lo tools/config/adapter/json.lo tools/config/adapter/php.lo tools/di.lo tools/di/abstractinjectionaware.lo tools/di/exception/serviceresolutionexception.lo tools/di/injectable.lo tools/di/service.lo tools/di/service/builder.lo tools/di/serviceproviderinterface.lo tools/helper/json.lo
PHP_PECL_EXTENSION = tools
TOOLS_SHARED_LIBADD =
PHP_MODULES = $(phplibdir)/tools.la
PHP_ZEND_EX =
all_targets = $(PHP_MODULES) $(PHP_ZEND_EX)
install_targets = install-modules install-headers
prefix = /usr/local/php
exec_prefix = $(prefix)
libdir = ${exec_prefix}/lib
prefix = /usr/local/php
phplibdir = /root/tools/ext/modules
phpincludedir = /usr/local/php/include/php
CC = cc
CFLAGS = -g -O2
CFLAGS_CLEAN = $(CFLAGS)
CPP = cc -E
CPPFLAGS = -DHAVE_CONFIG_H
CXX =
CXXFLAGS =
CXXFLAGS_CLEAN = $(CXXFLAGS)
EXTENSION_DIR = /usr/local/php/lib/php/extensions/no-debug-non-zts-20170718
PHP_EXECUTABLE = /usr/local/php/bin/php
EXTRA_LDFLAGS =
EXTRA_LIBS =
INCLUDES = -I/usr/local/php/include/php -I/usr/local/php/include/php/main -I/usr/local/php/include/php/TSRM -I/usr/local/php/include/php/Zend -I/usr/local/php/include/php/ext -I/usr/local/php/include/php/ext/date/lib
LFLAGS =
LDFLAGS =
SHARED_LIBTOOL =
LIBTOOL = $(SHELL) $(top_builddir)/libtool
SHELL = /bin/sh
INSTALL_HEADERS = ext/tools/php_TOOLS.h
mkinstalldirs = $(top_srcdir)/build/shtool mkdir -p
INSTALL = $(top_srcdir)/build/shtool install -c
INSTALL_DATA = $(INSTALL) -m 644

DEFS = -DPHP_ATOM_INC -I$(top_builddir)/include -I$(top_builddir)/main -I$(top_srcdir)
COMMON_FLAGS = $(DEFS) $(INCLUDES) $(EXTRA_INCLUDES) $(CPPFLAGS) $(PHP_FRAMEWORKPATH)

all: $(all_targets) 
	@echo
	@echo "Build complete."
	@echo "Don't forget to run 'make test'."
	@echo
	
build-modules: $(PHP_MODULES) $(PHP_ZEND_EX)

libphp$(PHP_MAJOR_VERSION).la: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(LIBTOOL) --mode=link $(CC) $(CFLAGS) $(EXTRA_CFLAGS) -rpath $(phptempdir) $(EXTRA_LDFLAGS) $(LDFLAGS) $(PHP_RPATHS) $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@
	-@$(LIBTOOL) --silent --mode=install cp $@ $(phptempdir)/$@ >/dev/null 2>&1

libs/libphp$(PHP_MAJOR_VERSION).bundle: $(PHP_GLOBAL_OBJS) $(PHP_SAPI_OBJS)
	$(CC) $(MH_BUNDLE_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) $(EXTRA_LDFLAGS) $(PHP_GLOBAL_OBJS:.lo=.o) $(PHP_SAPI_OBJS:.lo=.o) $(PHP_FRAMEWORKS) $(EXTRA_LIBS) $(ZEND_EXTRA_LIBS) -o $@ && cp $@ libs/libphp$(PHP_MAJOR_VERSION).so

install: $(all_targets) $(install_targets)

install-sapi: $(OVERALL_TARGET)
	@echo "Installing PHP SAPI module:       $(PHP_SAPI)"
	-@$(mkinstalldirs) $(INSTALL_ROOT)$(bindir)
	-@if test ! -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); then \
		for i in 0.0.0 0.0 0; do \
			if test -r $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i; then \
				$(LN_S) $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME).$$i $(phptempdir)/libphp$(PHP_MAJOR_VERSION).$(SHLIB_DL_SUFFIX_NAME); \
				break; \
			fi; \
		done; \
	fi
	@$(INSTALL_IT)

install-modules: build-modules
	@test -d modules && \
	$(mkinstalldirs) $(INSTALL_ROOT)$(EXTENSION_DIR)
	@echo "Installing shared extensions:     $(INSTALL_ROOT)$(EXTENSION_DIR)/"
	@rm -f modules/*.la >/dev/null 2>&1
	@$(INSTALL) modules/* $(INSTALL_ROOT)$(EXTENSION_DIR)

install-headers:
	-@if test "$(INSTALL_HEADERS)"; then \
		for i in `echo $(INSTALL_HEADERS)`; do \
			i=`$(top_srcdir)/build/shtool path -d $$i`; \
			paths="$$paths $(INSTALL_ROOT)$(phpincludedir)/$$i"; \
		done; \
		$(mkinstalldirs) $$paths && \
		echo "Installing header files:          $(INSTALL_ROOT)$(phpincludedir)/" && \
		for i in `echo $(INSTALL_HEADERS)`; do \
			if test "$(PHP_PECL_EXTENSION)"; then \
				src=`echo $$i | $(SED) -e "s#ext/$(PHP_PECL_EXTENSION)/##g"`; \
			else \
				src=$$i; \
			fi; \
			if test -f "$(top_srcdir)/$$src"; then \
				$(INSTALL_DATA) $(top_srcdir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			elif test -f "$(top_builddir)/$$src"; then \
				$(INSTALL_DATA) $(top_builddir)/$$src $(INSTALL_ROOT)$(phpincludedir)/$$i; \
			else \
				(cd $(top_srcdir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i; \
				cd $(top_builddir)/$$src && $(INSTALL_DATA) *.h $(INSTALL_ROOT)$(phpincludedir)/$$i) 2>/dev/null || true; \
			fi \
		done; \
	fi

PHP_TEST_SETTINGS = -d 'open_basedir=' -d 'output_buffering=0' -d 'memory_limit=-1'
PHP_TEST_SHARED_EXTENSIONS =  ` \
	if test "x$(PHP_MODULES)" != "x"; then \
		for i in $(PHP_MODULES)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d extension=$$dlname"; \
		done; \
	fi; \
	if test "x$(PHP_ZEND_EX)" != "x"; then \
		for i in $(PHP_ZEND_EX)""; do \
			. $$i; $(top_srcdir)/build/shtool echo -n -- " -d $(ZEND_EXT_TYPE)=$(top_builddir)/modules/$$dlname"; \
		done; \
	fi`
PHP_DEPRECATED_DIRECTIVES_REGEX = '^(define_syslog_variables|register_(globals|long_arrays)?|safe_mode|magic_quotes_(gpc|runtime|sybase)?|(zend_)?extension(_debug)?(_ts)?)[\t\ ]*='

test: all
	-@if test ! -z "$(PHP_EXECUTABLE)" && test -x "$(PHP_EXECUTABLE)"; then \
		INI_FILE=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r 'echo php_ini_loaded_file();' 2> /dev/null`; \
		if test "$$INI_FILE"; then \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_FILE" > $(top_builddir)/tmp-php.ini; \
		else \
			echo > $(top_builddir)/tmp-php.ini; \
		fi; \
		INI_SCANNED_PATH=`$(PHP_EXECUTABLE) -d 'display_errors=stderr' -r '$$a = explode(",\n", trim(php_ini_scanned_files())); echo $$a[0];' 2> /dev/null`; \
		if test "$$INI_SCANNED_PATH"; then \
			INI_SCANNED_PATH=`$(top_srcdir)/build/shtool path -d $$INI_SCANNED_PATH`; \
			$(EGREP) -h -v $(PHP_DEPRECATED_DIRECTIVES_REGEX) "$$INI_SCANNED_PATH"/*.ini >> $(top_builddir)/tmp-php.ini; \
		fi; \
		TEST_PHP_EXECUTABLE=$(PHP_EXECUTABLE) \
		TEST_PHP_SRCDIR=$(top_srcdir) \
		CC="$(CC)" \
			$(PHP_EXECUTABLE) -n -c $(top_builddir)/tmp-php.ini $(PHP_TEST_SETTINGS) $(top_srcdir)/run-tests.php -n -c $(top_builddir)/tmp-php.ini -d extension_dir=$(top_builddir)/modules/ $(PHP_TEST_SHARED_EXTENSIONS) $(TESTS); \
	else \
		echo "ERROR: Cannot run tests without CLI sapi."; \
	fi

clean:
	find . -name \*.gcno -o -name \*.gcda | xargs rm -f
	find . -name \*.lo -o -name \*.o | xargs rm -f
	find . -name \*.la -o -name \*.a | xargs rm -f 
	find . -name \*.so | xargs rm -f
	find . -name .libs -a -type d|xargs rm -rf
	rm -f libphp$(PHP_MAJOR_VERSION).la $(SAPI_CLI_PATH) $(OVERALL_TARGET) modules/* libs/*

distclean: clean
	rm -f Makefile config.cache config.log config.status Makefile.objects Makefile.fragments libtool main/php_config.h stamp-h sapi/apache/libphp$(PHP_MAJOR_VERSION).module buildmk.stamp
	$(EGREP) define'.*include/php' $(top_srcdir)/configure | $(SED) 's/.*>//'|xargs rm -f

.PHONY: all clean install distclean test
.NOEXPORT:
tools.lo: /root/tools/ext/tools.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools.c -o tools.lo 
kernel/main.lo: /root/tools/ext/kernel/main.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/main.c -o kernel/main.lo 
kernel/memory.lo: /root/tools/ext/kernel/memory.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/memory.c -o kernel/memory.lo 
kernel/exception.lo: /root/tools/ext/kernel/exception.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/exception.c -o kernel/exception.lo 
kernel/debug.lo: /root/tools/ext/kernel/debug.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/debug.c -o kernel/debug.lo 
kernel/backtrace.lo: /root/tools/ext/kernel/backtrace.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/backtrace.c -o kernel/backtrace.lo 
kernel/object.lo: /root/tools/ext/kernel/object.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/object.c -o kernel/object.lo 
kernel/array.lo: /root/tools/ext/kernel/array.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/array.c -o kernel/array.lo 
kernel/string.lo: /root/tools/ext/kernel/string.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/string.c -o kernel/string.lo 
kernel/fcall.lo: /root/tools/ext/kernel/fcall.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/fcall.c -o kernel/fcall.lo 
kernel/require.lo: /root/tools/ext/kernel/require.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/require.c -o kernel/require.lo 
kernel/file.lo: /root/tools/ext/kernel/file.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/file.c -o kernel/file.lo 
kernel/operators.lo: /root/tools/ext/kernel/operators.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/operators.c -o kernel/operators.lo 
kernel/math.lo: /root/tools/ext/kernel/math.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/math.c -o kernel/math.lo 
kernel/concat.lo: /root/tools/ext/kernel/concat.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/concat.c -o kernel/concat.lo 
kernel/variables.lo: /root/tools/ext/kernel/variables.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/variables.c -o kernel/variables.lo 
kernel/filter.lo: /root/tools/ext/kernel/filter.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/filter.c -o kernel/filter.lo 
kernel/iterator.lo: /root/tools/ext/kernel/iterator.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/iterator.c -o kernel/iterator.lo 
kernel/time.lo: /root/tools/ext/kernel/time.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/time.c -o kernel/time.lo 
kernel/exit.lo: /root/tools/ext/kernel/exit.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/kernel/exit.c -o kernel/exit.lo 
tools/collection.lo: /root/tools/ext/tools/collection.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/collection.zep.c -o tools/collection.lo 
tools/config.lo: /root/tools/ext/tools/config.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/config.zep.c -o tools/config.lo 
tools/di/injectionawareinterface.lo: /root/tools/ext/tools/di/injectionawareinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/injectionawareinterface.zep.c -o tools/di/injectionawareinterface.lo 
tools/exception.lo: /root/tools/ext/tools/exception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/exception.zep.c -o tools/exception.lo 
tools/di/diinterface.lo: /root/tools/ext/tools/di/diinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/diinterface.zep.c -o tools/di/diinterface.lo 
tools/di/exception.lo: /root/tools/ext/tools/di/exception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/exception.zep.c -o tools/di/exception.lo 
tools/di/serviceinterface.lo: /root/tools/ext/tools/di/serviceinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/serviceinterface.zep.c -o tools/di/serviceinterface.lo 
tools/config/adapter/ini.lo: /root/tools/ext/tools/config/adapter/ini.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/config/adapter/ini.zep.c -o tools/config/adapter/ini.lo 
tools/config/adapter/json.lo: /root/tools/ext/tools/config/adapter/json.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/config/adapter/json.zep.c -o tools/config/adapter/json.lo 
tools/config/adapter/php.lo: /root/tools/ext/tools/config/adapter/php.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/config/adapter/php.zep.c -o tools/config/adapter/php.lo 
tools/di.lo: /root/tools/ext/tools/di.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di.zep.c -o tools/di.lo 
tools/di/abstractinjectionaware.lo: /root/tools/ext/tools/di/abstractinjectionaware.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/abstractinjectionaware.zep.c -o tools/di/abstractinjectionaware.lo 
tools/di/exception/serviceresolutionexception.lo: /root/tools/ext/tools/di/exception/serviceresolutionexception.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/exception/serviceresolutionexception.zep.c -o tools/di/exception/serviceresolutionexception.lo 
tools/di/injectable.lo: /root/tools/ext/tools/di/injectable.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/injectable.zep.c -o tools/di/injectable.lo 
tools/di/service.lo: /root/tools/ext/tools/di/service.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/service.zep.c -o tools/di/service.lo 
tools/di/service/builder.lo: /root/tools/ext/tools/di/service/builder.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/service/builder.zep.c -o tools/di/service/builder.lo 
tools/di/serviceproviderinterface.lo: /root/tools/ext/tools/di/serviceproviderinterface.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/di/serviceproviderinterface.zep.c -o tools/di/serviceproviderinterface.lo 
tools/helper/json.lo: /root/tools/ext/tools/helper/json.zep.c
	$(LIBTOOL) --mode=compile $(CC)  -I. -I/root/tools/ext $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS)  -c /root/tools/ext/tools/helper/json.zep.c -o tools/helper/json.lo 
$(phplibdir)/tools.la: ./tools.la
	$(LIBTOOL) --mode=install cp ./tools.la $(phplibdir)

./tools.la: $(shared_objects_tools) $(TOOLS_SHARED_DEPENDENCIES)
	$(LIBTOOL) --mode=link $(CC) $(COMMON_FLAGS) $(CFLAGS_CLEAN) $(EXTRA_CFLAGS) $(LDFLAGS) -o $@ -export-dynamic -avoid-version -prefer-pic -module -rpath $(phplibdir) $(EXTRA_LDFLAGS) $(shared_objects_tools) $(TOOLS_SHARED_LIBADD)

