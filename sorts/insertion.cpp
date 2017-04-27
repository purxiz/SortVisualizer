#include "../recorder.h"

void insertionSort(Recorder& rec, int l){
  for(int i = 1; i < l; i++){
    int k = i;
    while(k > 0 && rec.cmp(k-1,k)){
      rec.swap(k,k-1);
      k--;
    }
  }
}