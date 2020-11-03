#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/* O(n^2) algorithms: SelectionSort < InsertionSort << BubbleSort */
/*                    faster <<<<.....................<<<< slower */

int main(int argc, char** argv)
{
  int size = 1000000;

  printf("N = %d\n", size);
  
  data* array = RandomArray(size, 0, 100);
  printf("QuickSort > ");
  TimeIt(QuickSort, array, size);
  IsSorted(array, size);
  free(array);

  /* array = RandomArray(size, 0, 100); */
  /* printf("BubbleSortRecursive > "); */
  /* TimeIt(BubbleSortRecursive, array, size); */
  /* IsSorted(array, size); */
  /* free(array); */

  array = RandomArray(size, 0, 100);
  printf("MergeSort > ");
  TimeIt(MergeSort, array, size);
  IsSorted(array, size);
  free(array);

  array = RandomArray(size, 0, 100);
  printf("HeapSort > ");
  TimeIt(HeapSort, array, size);
  IsSorted(array, size);
  free(array);

  return 0;
}
