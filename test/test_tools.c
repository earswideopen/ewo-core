#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>
#include <sys/types.h>
#include <pwd.h>

#include "../src/tools.h"

void TestModuloInc()
{
	assert_int_equal(ModuloInc(2, 256), 3);
	assert_int_equal(ModuloInc(256, 256), 0);
}

void TestGetHomeDir()
{
	assert_non_null(GetHomeDir());
}

void TestIsFileExist()
{

	const char *file_exist = "/home/mattberjon/.ewo.json";
	const char *file_donot_exist = "/home/mattberjon/donot_exist.json";


	assert_int_equal(IsFileExist(file_exist), 0);
	assert_int_equal(IsFileExist(file_donot_exist), 2);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(TestModuloInc),
		cmocka_unit_test(TestGetHomeDir),
		cmocka_unit_test(TestIsFileExist),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
