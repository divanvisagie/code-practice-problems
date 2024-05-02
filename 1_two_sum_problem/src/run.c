#include <glib.h>
#include <stdio.h>

const int STRING_SIZE = 64;

char **run(int k, int num_list[], size_t size, int *result_count) {
  GHashTable *set = g_hash_table_new(g_direct_hash, g_direct_equal);
  char **results = malloc(sizeof(char) * STRING_SIZE * size);
  *result_count = 0;

  for (int i = 0; i < size; i++) {
    int num = num_list[i];
    int compliment = k - num;

    if (g_hash_table_contains(set, GINT_TO_POINTER(compliment))) {
      char *result = malloc(sizeof(char) * STRING_SIZE);

      snprintf(result, STRING_SIZE, "%d and %d add up to %d", num_list[i], compliment, k);
      results[*result_count] = result;
      *result_count += 1;
    }

    g_hash_table_add(set, GINT_TO_POINTER(num));
  }

  g_hash_table_destroy(set);
  return results;
}
