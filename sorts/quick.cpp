#include "../recorder.h"

// [s,m,a,l,l,e,r,l,a,r,g,e,r,u,n,s,o,r,t,e,d,...,pivot]
//                ^k          ^i
int partition(Recorder &rec, int begin, int end){
  int k = begin;

  for(int i = begin; i < end; i++){
    if(rec.cmp(end,i)){
      rec.swap(i,k);
      k++;
    }
  }

  rec.swap(end,k);
  return k;
}

void quickSort(Recorder &rec, int begin, int end){
  if(begin>=end){
    return;
  }
  int p = partition(rec,begin,end);
  rec.finalize(p);
  quickSort(rec,begin,p-1);
  quickSort(rec,p+1,end);
}