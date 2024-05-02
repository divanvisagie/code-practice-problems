#include <stdio.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>

#include "run.h"

static void test_case_1(void **state) {
  int result_count;
  char** results = run(17, (int[]){10, 15, 3, 7}, 4, &result_count);

  assert_int_equal(result_count, 1);
  assert_string_equal("7 and 10 add up to 17", results[0]);
}

static void test_case_2(void **state) {
  int result_count;
  char** results = run(14, (int[]){7, 10, 4, 7}, 4, &result_count);

  assert_int_equal(result_count, 2);
  assert_string_equal("4 and 10 add up to 14", results[0]);
  assert_string_equal("7 and 7 add up to 14", results[1]);
}

// Group all test cases together
int main(int argc, char *argv[]) {
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_case_1),
      cmocka_unit_test(test_case_2),
  };
  return cmocka_run_group_tests(tests, NULL, NULL);
}
