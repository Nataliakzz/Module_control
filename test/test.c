#include <check.h>
#include "../src/calculator.h"

START_TEST(test_eval_expr_simple)
        {
                const char *expr = "2+3";
                int expected = 5;
                int actual = eval_expr(expr);
                ck_assert_msg(expected == actual, "Expected %d but got %d for expression '%s'", expected, actual, expr);
        }
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab13");

	tcase_add_test(tc_core, test_eval_expr_simple);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
