#include <glib.h>
#include <stdio.h>

#include "main.h"

int main() {
  int k = 17;
  int num_list[4] = {10, 15, 3, 7};

  size_t size = sizeof(num_list) / sizeof(int);
  int result_count;
  char **results = run(k, num_list, size, &result_count);
  
  for (int i = 0; i < result_count; i++) {
    printf("%s\n", results[i]);
    free(results[i]);
  }

  free(results);
  return 0;
}
