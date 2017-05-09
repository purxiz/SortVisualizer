#include "recorder.h"

void shellSort(Recorder rec, int l){
  for(int gap = l/2; gap > 0; gap /= 2){
    for(int i = gap; i < l; i += 1){
      int k = i;
      while(k - gap >= 0 && rec.cmp(k-gap,k)){
        rec.swap(k,k-gap);
        k -= gap;
      }
    }
  }
}