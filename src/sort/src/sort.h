#ifndef __SORT_H_INCLUDED__
#define __SORT_H_INCLUDED__


typedef int data;

/* Fundamental utilities */
data* RandomArray(int size, data min, data max);
data* CopyArray(data* src, int size);
int IsSorted(data* array, int size);
void PrintArray(data* A, int size);
void TimeIt();
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



#endif /*__SORT_H_INCLUDED__ */
