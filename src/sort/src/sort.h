#ifndef __SORT_H_INCLUDED__
#define __SORT_H_INCLUDED__


typedef int data;

/* Fundamental utilities */
data Random(data min, data max);
data* RandomArray(int size, data min, data max);
data* CopyArray(data* src, int size);
int IsSorted(data* array, int size);
void PrintArray(data* A, int size);
void TimeIt(void(*SortAlgorithm)(data*, int), data* A, int size);
void Swap(data* A, int i, int j);

/* Incremental approach */
void SelectionSort(data* A, int size);
void SelectionSortRecursive(data* A, int size);

void BubbleSort(data* A, int size);
void BubbleSortRecursive(data* A, int size);

void InsertionSort(data* A, int size);
void InsertionSortRecursive(data* A, int size, int sorted_length);

/* Divide-and-Conquer */
void MergeSort(data* A, int size);
void _MergeSort(data* A, data* B, int p, int r);
void Merge(data* A, data* B, int p, int q, int r);

void QuickSort(data* A, int size);
void _QuickSort(data* A, int p, int r);
int _Partition(data* A, int p, int r);
void RandomizedQuickSort(data* A, int size);
void _RandomizedQuickSort(data* A, int p, int r);
int _RandomizedPartition(data* A, int p, int r);

/* Heap & heap sort*/
typedef struct {
  int length;
  int heap_size;
  data* A;
} Heap;

int Parent(int i);
int Left(int i);
int Right(int i);

void Heapify(Heap* H, int i);
Heap BuildHeap(data* A, int size);
data ExtractMax(Heap* H);
void HeapSort(data* A, int size);

#endif /*__SORT_H_INCLUDED__ */
