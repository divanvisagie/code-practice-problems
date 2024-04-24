#include <glib.h>
#include <stdio.h>

int main() {
  int k = 17;
  int num_list[4] = {10, 15, 3, 7};

  GHashTable *set = g_hash_table_new(g_direct_hash, g_direct_equal);

  size_t size = sizeof(num_list) / sizeof(int);
  for (int i = 0; i < size; i++) {
    int num = num_list[i];
    int compliment = k - num;

    if (g_hash_table_contains(set, GINT_TO_POINTER(compliment))) {
      printf("%d and %d add up to %d\n", num_list[i], compliment, k);
    }

    g_hash_table_add(set, GINT_TO_POINTER(num));
  }

  // Memory cleanup
  g_hash_table_destroy(set);
  return 0;
}
