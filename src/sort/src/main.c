#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


int main(int argc, char** argv)
{
  int size = 10000; // N=10^7 -> O(nlogn)~1-2sec, N=10^5 -> O(n^2)~13sec
  data* array = RandomArray(size, 0, 100);
  data* array_ = CopyArray(array, size);
  data* array__ = CopyArray(array_, size);

  printf("N = %d\n", size);

  printf("QuickSort > ");
  TimeIt(QuickSort, array, size);
  IsSorted(array, size);

  printf("InsertionSort > ");
  TimeIt(InsertionSort, array_, size);
  IsSorted(array_, size);

  printf("MergeSort > ");
  TimeIt(MergeSort, array__, size);
  IsSorted(array__, size);

  free(array); free(array_); free(array__);
  return 0;
}
