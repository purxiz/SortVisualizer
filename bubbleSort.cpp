#include "recorder.h"

void bubbleSort(Recorder rec, int l){
  for(int i = l-1; i > 0; i--){
    for(int k = 1; k <= i; k++){
      if(rec.cmp(k-1,k)){
        rec.swap(k,k-1);
      }
    }
    rec.finalize(i);
  }
}