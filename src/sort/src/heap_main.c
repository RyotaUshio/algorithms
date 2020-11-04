#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


int main(void)
{
  int size = 100;
  data* array = RandomArray(size, 0, 100);
  PrintArray(array, size);

  HeapSort(array, size);
  PrintArray(array, size);
  
  free(array);
  
  return 0;
}
