#include <stdio.h>
#include <stdlib.h>

int main() {

  int num = 30;
  int *p = &num;
  printf("%p\n", p);
  printf("%d\n", *p);
  printf("%d\n", *(p + 1699));

  return 0;
}
