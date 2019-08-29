// Rairakhia, Darshak Deepan
// ddr7657
// 2019-07-18
//--------#---------#---------#---------#--------#
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "support.h"

//--------#---------#---------#---------#--------#
//********//********//********//********//******//
// LEFT() and RIGHT() are useful in maxHeapify().
// PARENT() is useful in buildMaxHeap().
//********//********//********//********//******//
static inline int LEFT(int i)   { return 2*i; }
static inline int RIGHT(int i)  { return 2*i+1; }
static inline int PARENT(int i) { return floor(i/2); }
static void maxHeapify( int *A, int size, int heapsize, int i )
{
  //********//********//********//********//******//
  // Put your MAX-HEAPIFY routine here.
  // A is a pointer to the first element in the array to be sorted.
  // size is the number of elements in the array.
  // heapsize is the current size of the heap in the array.
  // i is the root of the subtree to maxHeapify.
  //
  // There's an exchangeInt() routine defined in support.h.
  //********//********//********//********//******//
  
  int ell = LEFT(i);
  int arr = RIGHT(i);
  int largest, temp;

  if(ell <= heapsize && *(A+(ell-1)) > *(A+(i-1)))
  { 
    largest = ell;
  } 
  else
  {
    largest = i;
  }

  if(arr <= heapsize && *(A+(arr-1)) > *(A+(largest-1)))
  {
    largest = arr;
  }

  if(largest != i)
  {
    exchangeInt( (A+(i-1)), (A+(largest-1)) );
    maxHeapify( A, size, heapsize, largest );
  }
}

static void buildMaxHeap( int *A, int size )
{
  //********//********//********//********//******//
  // Put your BUILD-MAX-HEAP routine here.
  // A is a pointer to the first element in the array to be sorted.
  // size is the number of elements in the array.
  //********//********//********//********//******//
  int heapsize = size;
  for(int i=floor(size/2); i>0; i--)
  {
    maxHeapify( A, size, heapsize, i );
  }
}

void heapSort( int *A, int size )
{
  //********//********//********//********//******//
  // Put your HEAP sort routine here.
  // A is a pointer to the first element in the array to be sorted.
  // size is the number of elements in the array.
  //
  // There's an exchangeInt() routine defined in support.h.
  //********//********//********//********//******//
  int tmp;
  int heapsize=size;
  buildMaxHeap( A, size );
  for(int j=size; j>1; j--)
  {
    exchangeInt( A, (A+(j-1)) );
    heapsize--;
    maxHeapify( A, size, heapsize, 1 ); 
  }
}
//--------#---------#---------#---------#--------#
static int *L;
static int *R;

static void merge( int *A, int p, int q, int r )
{
  //********//********//********//********//******//
  // Put your MERGE routine here.
  // A is a pointer to the first element in the array to be sorted.
  // p is the low element of the range to merge.
  // q is the middle element of the range to merge.
  // r is the high element of the range to merge.
  //
  // When you write this routine, you can use the L and R arrays
  // as the extra space subarrays.  They have already been
  // allocated for you.  Do NOT deallocate them yourself.
  //
  // INT_MAX is useful as an approximation of infinity.
  //********//********//********//********//******//
  int i, j; 
  int n1 = q-p+1;
  int n2 = r-q;
  int k;
  for(i=0; i<n1; i++)
  {
    L[i] = A[p+i];
  }
  for(j=0; j<n2; j++)
  {
    R[j] = A[q+j+1];
  }

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = 0;
  j = 0;
  
  for(k = p; k <= r; k++)
  {
    if(L[i]<=R[j])
    {
    A[k] = L[i];
    i++;
    }
    else
    {
      A[k] = R[j];
      j++;
    }
  }
  
}

static void mergeSort( int *A, int p, int r )
{
  //********//********//********//********//******//
  // Put your MERGE sort routine here. 
  // A is a pointer to the first element in the array to be sorted.
  // p is the low element of the range to sort.
  // r is the high element of the range to sort.
  //********//********//********//********//******//
  if(p < r)
  {
    int q = floor((p+(r-1))/2);
    mergeSort(A,p,q);
    mergeSort(A,q+1, r);
    merge(A,p,q,r);
  }
}

//--------#---------#---------#---------#--------#
// DO NOT CHANGE THIS FUNCTION!
//--------#---------#---------#---------#--------#
void mergeSortTop( int *A, int size )
{
  L = (int *) malloc( ( size/2 + 1 + 1 )*sizeof(int) );
  R = (int *) malloc( ( size/2 + 1 + 1 )*sizeof(int) );

  mergeSort( A, 0, size-1 );

  free( L );
  free( R );
}

//--------#---------#---------#---------#--------#
