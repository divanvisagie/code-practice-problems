#include <glib.h>
#include <stdio.h>

int productify(int *input, int size, int exclude) {
  int acc = 1;
  for (int i = 0; i < size; i++) {
    if (i == exclude) {
      continue;
    }
    acc = acc * input[i];
  }
  return acc;
}

int *do_to_array(int *input, int size) {
  int *calculated = malloc(size * sizeof(int));

  for (int i = 0; i < size; i++) {
    calculated[i] = productify(input, size, i);
  }

  return calculated;
}

void print_array(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i == (size - 1)) {
      continue;
    }
    printf(" ,");
  }
  printf("]\n");
}

int main() {
  int input[5] = {1, 2, 3, 4, 5};

  int *ans = do_to_array(input, 5);
  print_array(ans, 5);

  int input_2[3] = {3, 2, 1};
  int *ans_2 = do_to_array(input_2, 3);
  print_array(ans_2, 3);

  return 0;
}
