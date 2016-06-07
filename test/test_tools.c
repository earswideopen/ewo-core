#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "tools.h"

void TestModuloInc()
{
	assert_int_equal(ModuloInc(2, 256), 3);
	assert_int_equal(ModuloInc(256, 256), 0);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(TestModuloInc),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
