#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "sort.h"


/* Fundamental utilities */

data Random(data min, data max)
{
  double uniform;
  data ret;
  srand((unsigned int)clock());
  //srand((unsigned int)time(NULL));
  
  uniform = rand() / (double)RAND_MAX;
  ret = (data)(uniform * (double)(max - min)) + min;

  return ret;
}


data* RandomArray(int size, data min, data max)
{
  // dynamically allcate memory for an array with specified size.
  data* array = (data*)malloc(size * sizeof(data));
  for(int i=0; i<size; i++)
    array[i] = Random(max, min);
    
  return array;
}


data* CopyArray(data* src, int size)
{
  data* cp = (data*)malloc(size * sizeof(data));
  int i;
  for(i=0; i<size; i++) cp[i] = src[i];
  return cp;
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


void TimeIt(void(*SortAlgorithm)(data*, int), data* A, int size)
{
  clock_t start, end;
  start = clock();
  SortAlgorithm(A, size);
  end = clock();
  printf("Elasped: %.4g sec\n",(double)(end-start)/CLOCKS_PER_SEC);
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
      if(i > q)            B[k] = A[j++];
      else if(j > r)       B[k] = A[i++];
      else if(A[i] < A[j]) B[k] = A[i++];
      else                 B[k] = A[j++];
    }

  for(k=p; k<=r; k++)      A[k] = B[k];
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
  int i, j;
  for(i=p, j=r; ; i++, j--)
    {
      while(A[i]<pivot) i++;
      while(A[j]>pivot) j--;
      if(i >= j) return j;
      Swap(A, i, j);
    }
}


void RandomizedQuickSort(data* A, int size)
{
  _RandomizedQuickSort(A, 0, size-1);
}


void _RandomizedQuickSort(data* A, int p, int r)
{
  if(p < r)
    {
      int q = _RandomizedPartition(A, p, r);
      _RandomizedQuickSort(A, p, q);
      _RandomizedQuickSort(A, q+1, r);
    }
}


int _RandomizedPartition(data* A, int p, int r)
{
  Swap(A, p, Random(p, r));
  return _Partition(A, p, r);
}



/* Heap & heap sort*/

int Parent(int i)
{
  return i/2;
}


int Left(int i)
{
  return 2*i;
}


int Right(int i)
{
  return 2*i + 1;
}


void Heapify(Heap* H, int i)
{
  data largest = i;
  int left = Left(i);
  int right = Right(i);
  if(left <= H->heap_size - 1)
    largest = ( (H->A[i]) > (H->A[left]) ) ? i : left;
  if(right <= H->heap_size - 1)
    largest = ( (H->A[largest]) > (H->A[right]) ) ? largest : right;

  if(largest != i)
    {
      Swap(H->A, largest, i);
      Heapify(H, largest);
    }
}


Heap BuildHeap(data* A, int size)
{
  Heap H;
  H.length = size;
  H.heap_size = size;
  H.A = A;
  
  for(int i=Parent(H.heap_size-1); i>=0; i--)
    Heapify(&H, i);

  return H;
}


data ExtractMax(Heap* H)
{
  data max = H->A[0];
  H->A[0] = H->A[H->heap_size-1];
  H->heap_size -= 1;
  Heapify(H, 0);
  return max;
}


void HeapSort(data* A, int size)
{
  Heap H = BuildHeap(A, size);
  for(int i=size-1; i>0; i--)
    A[i] = ExtractMax(&H);
}
