#include "recorder.h"


void combSort(Recorder rec, int l){
  bool sorted = false;
  int gap = l;
  while(!sorted){
    if(gap > 1){
      gap = (gap*2)/3;
    }else{
      gap = 1;
      sorted = true;
    }
    for(int k = gap; k < l; k++){
      if(rec.cmp(k-gap,k)){
        rec.swap(k,k-gap);
        sorted = false;
      }
    }
  }
}