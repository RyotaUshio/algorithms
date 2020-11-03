#include <iostream>
#include <algorithm>
#include <ctime>
#include "sort.h"

int main()
{
  data* array;
  int size = 1000000;
  
  array = RandomArray(size, 0, 100);
  std::printf("QuickSort > ");
  TimeIt(QuickSort, array, size);
  IsSorted(array, size);
  std::free(array);

  array = RandomArray(size, 0, 100);
  std::printf("std::sort > ");

  std::clock_t start, end;
  start = clock();
  std::sort(array, array+size);
  end = clock();
  std::printf("Elasped: %.4g sec\n",(double)(end-start)/CLOCKS_PER_SEC);

  IsSorted(array, size);
  std::free(array);
}
