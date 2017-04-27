// Build a heap from an element and two proper heaps
#include "../recorder.h"

//                   v2*top+1
// arr = [...,el,...,~,~, ...]
//            ^top   ^heads of proper heaps
void maxHeapify(Recorder &rec, int top, int length){
  while(top*2+1 < length){
    int child = top*2+1;
    if(rec.cmp(child,top)){
      if(child+1 < length && rec.cmp(child+1,child)){
        rec.swap(top,child+1);
        top = child+1;
      }else{
        rec.swap(top,child);
        top = child;
      }
    }else if(child+1 < length && rec.cmp(child+1,top)){
      rec.swap(top,child+1);
      top = child+1;
    }else
      break;
  }
}

// Converts an array into a heap
void buildMaxHeap(Recorder &rec, int length){
  for(int i = (length+1)/2; i >= 0; i--){
    maxHeapify(rec,i,length);
  }
}

void heapSort(Recorder &rec, int length){
  buildMaxHeap(rec,length);
  for(int i = length-1; i > 0; i--){
    // Move the largest element to the end
    rec.swap(0,i);

    //Reestablish the heap property
    maxHeapify(rec,0,i);
  }
}