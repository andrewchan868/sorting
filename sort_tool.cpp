// **********
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2020/9/15 Mu-Ting Wu]
//  Student    [T10902309]
// **********

#include "sort_tool.h"
#include<iostream>
#include <cstdlib>
using namespace std;

// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
    // Function : Insertion sort
    // TODO : Please complete insertion sort code here
    //start
  int key;
  int i;
  for(int j = 1; j <data.size(); j++)
  {
     key=data[j];
     i = j - 1;
     while(data[i]>key && i>=0){
         data[i+1]=data[i];
         i = i - 1;
     }
     data[i+1]=key;
  }
    //end
}

// Quick sort method
void SortTool::QuickSort(vector<int>& data){
    QuickSortSubVector(data, 0, data.size() - 1);
}
// Sort subvector (Quick sort)
void SortTool::QuickSortSubVector(vector<int>& data, int low, int high) {
    // Function : Quick sort subvector
    // TODO : Please complete QuickSortSubVector code here
    // Hint : recursively call itself
    //        Partition function is needed
    // start
   
   if (low < high) {
     int pivot = Partition(data, low, high);
     QuickSortSubVector(data, low, pivot - 1);
     QuickSortSubVector(data, pivot + 1, high);
   }
    // end
}


int SortTool::Partition(vector<int>& data, int low, int high) {
    // Function : Partition the vector 
    // TODO : Please complete the function
    // Hint : Textbook page 171
    //start

   // cout<<(low+high)/2<<endl;
   int pivotindex = rand()%(high-low)+low;
   int pivot = data[pivotindex];
   swap(data[high],data[pivotindex]);

   int i=low;
   int j=low;
   for(int j=low;j<high;j++){
       if(data[j]<=pivot){
           swap(data[j],data[i]);
           i++;
       }
   }
   swap(data[high],data[i]);
   return i;
}


   //end


// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    MergeSortSubVector(data, 0, data.size() - 1);
}

// comparison based sort
// Sort subvector (Merge sort)
void SortTool::MergeSortSubVector(vector<int>& data, int low, int high) {
    // Function : Merge sort subvector
    // TODO : Please complete MergeSortSubVector code here
    // Hint : recursively call itself
    //        Merge function is needed
    //start

   /*
   [a1 ....  an ]

   [a1 ... middle1][middle2 ..an]
   [a1...middle11][ ....] [...][....]

    ......
     [size=1][size=1]  [s=1][s=1]
     [   size=2    ]   [s=2]
     
     .... [a1 .........an]

   */
    int middle1;
    int middle2;
    if (high - low <= 1) {
        if(data[low]>data[high]){
        swap(data[low],data[high]);
        }
        return;
    }
    middle1 = (low+high)/2;
    middle2 = middle1+1;
    MergeSortSubVector(data,low,middle1); 
    MergeSortSubVector(data,middle2,high); 
    Merge(data,low,middle1,middle2,high);
    //end
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    // Function : Merge two sorted subvector
    // TODO : Please complete the function
    //start
   int i, j, k, numberleft, numberright;
  numberleft = middle1-low+1; numberright = high-middle1;
  int leftarr[numberleft], rightarr[numberright];//
   for(i = 0; i<numberleft; i++)
      leftarr[i] = data[low+i];
   for(j = 0; j<numberright; j++)
      rightarr[j] = data[middle1+1+j];
   i = 0; j = 0; k = low;
   while(i < numberleft && j<numberright) {
      if(leftarr[i] <= rightarr[j]) {
         data[k] = leftarr[i];
         i++;
      }else{
         data[k] = rightarr[j];
         j++;
      }
      k++;
   }
   while(i<numberleft) {       
      data[k] = leftarr[i];
      i++; k++;
   }
   while(j<numberright) {     
      data[k] = rightarr[j];
      j++; k++;
   }   
    //end
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    BuildMaxHeap(data); //convert data -> heap =>data[0]
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        MaxHeapify(data,0);
    }
}

void SortTool::MaxHeapify(vector<int>& data, int root) {
    // Function : Make tree with given root be a max-heap if both right and left sub-tree are max-heap
    // TODO : Please complete max-heapify code here
    //start

    int left = 2*root + 1; 
    int right = 2*root + 2;
    int largest = root;
    
    if ((left <heapSize) && (data[left]>data[root])){
        largest = left;
        }

    if ((right < heapSize && (data[right]>data[largest]))){
        largest = right;
        }

    if (largest != root) {
        swap(data[largest],data[root]);
        MaxHeapify(data,largest);
    }
    //end
    
}


//Build max heap
void SortTool::BuildMaxHeap(vector<int>& data) {  // 

    heapSize = data.size(); // initialize heap size
    // Function : Make input data become a max-heap
    // TODO : Please complete BuildMaxHeap code here
    // Function to build a Max-Heap from the given array
    // Index of last non-leaf node
    //start//
    int start = (heapSize / 2) - 1;
    for (int i = start; i >= 0; i--) {
        MaxHeapify(data, i);
        //MaxHeapify(data, heapSize,i);
    }
    //end
}
