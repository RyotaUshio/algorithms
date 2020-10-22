#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


int main(int argc, char** argv)
{
  int size = 10;
  data* array = RandomArray(size, 0, 100);

  //  printf("before: "); PrintArray(array, size);

  QuickSort(array, size);
  
  //printf("after:  "); PrintArray(array, size);
  IsSorted(array, size);

  free(array);
  return 0;
}
