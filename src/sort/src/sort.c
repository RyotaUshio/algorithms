#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sort.h"


/* Fundamental utilities */

data* RandomArray(int size, data min, data max)
{
  // dynamically allcate memory for an array with specified size.
  data* array = (data*)malloc(size * sizeof(data));
  double uniform;
  srand((unsigned int)time(NULL));
  for(int i=0; i<size; i++)
    {
      uniform = rand() / (double)RAND_MAX;
      array[i] = (data)(uniform * (double)(max - min)) + min;
    }
  return array;
}


int IsSorted(data* A, int size)
{
  data previous_value = A[0];
  for(int i=1; i<size; i++){
    if(A[i] < previous_value){
      printf("NOT SORTED\n");
      return 0;
    }
    previous_value = A[i];
  }
  printf("CORRECTLY SORTED\n");
  return 1;
}


void PrintArray(data* A, int size)
{
  for(int i=0; i<size; i++){
    printf("%d", A[i]);
    if(i < size - 1)
      printf(",  ");
  }
  printf("\n");
}


void Swap(data* A, int i, int j)
{
  data tmp = A[i];
  A[i] = A[j];
  A[j] = tmp;
}



/* Incremental approach */

void SelectionSort(data* A, int size)
{
  int i, j;
  int min_index;
  data tmp;

  for(i=0; i<size; i++)
    {
      min_index = i;
      for(j=i+1; j<size; j++)
	if(A[j] < A[min_index])
	  min_index = j;

      Swap(A, i, min_index);
    }
}


void SelectionSortRecursive(data* A, int size)
{
  if(size)
    {
      int min_index = 0;
      for(int j=1; j<size; j++)
	if(A[j] < A[min_index])
	  min_index = j;

      Swap(A, 0, min_index);
      SelectionSortRecursive(A+1, size-1);
    }
}


void BubbleSort(data* A, int size)
{
  int i, j;
  data tmp;
  for(i=0; i<size; i++){
    for(j=size-1; j>i; j--){
      if(A[j-1] > A[j]){
	Swap(A, j-1, j);
      }
    }
  }
}


void BubbleSortRecursive(data* A, int size)
{
  if(size){
    data tmp;
    for(int j=size-1; j>0; j--){
      if(A[j-1] > A[j]){
	Swap(A, j-1, j);
      }
    }
    BubbleSortRecursive(A+1, size-1);
  }
}


void InsertionSort(data* A, int size)
{
  int i, j;
  for(i=1; i<size; i++){
    for(j=i-1; j>=0; j--){
      if(A[j] < A[j+1])
	break;
      Swap(A, j, j+1);
    }
  }
}


void InsertionSortRecursive(data* A, int size, int sorted_length)
{
  if(sorted_length < size)
    { 
      data key = A[sorted_length];
      int j = sorted_length-1;
      while( (j >= 0) && (A[j] > key) )
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1] = key;
      InsertionSortRecursive(A, size, sorted_length+1);
    } 
}



/* Divide-and-Conquer */

void MergeSort(data* A, int size)
{
  data* B = (data*)malloc(size * sizeof(data));
  _MergeSort(A, B, 0, size-1);
  free(B);
}


void _MergeSort(data* A, data* B, int p, int r)
{
  // B: temporary array
  if(p < r)
    {
      int q = (p+r)/2;
      _MergeSort(A, B, p, q);
      _MergeSort(A, B, q+1, r);
      Merge(A, B, p, q, r);
    }
}


void Merge(data* A, data* B, int p, int q, int r)
{
  // A[p...q|q+1...r]
  //   i---> j----->
  // B[p...........r]
  //   k----------->
  int i, j, k;
  for(i=p, j=q+1, k=p; k<=r; k++)
    {
      if(i > q)
	B[k] = A[j++];
      else if(j > r)
	B[k] = A[i++];
      else if(A[i] < A[j])
	B[k] = A[i++];
      else
	B[k] = A[j++];
    }

  for(k=p; k<=r; k++)
    A[k] = B[k];
}


void QuickSort(data* A, int size)
{
  _QuickSort(A, 0, size-1);
}


void _QuickSort(data* A, int p, int r)
{
  if(p < r)
    {
      int q = _Partition(A, p, r);
      _QuickSort(A, p, q);
      _QuickSort(A, q+1, r);
    }
}


int _Partition(data* A, int p, int r)
{
  data pivot = A[p];
  int i = p;
  int j = r;
  while(1)
    {
      for(; A[i]<pivot; i++){}
      for(; A[j]>pivot; j--){}
      if(i >= j) return j;
      Swap(A, i++, j--);
    }
}
