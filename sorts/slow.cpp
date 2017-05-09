#include "../recorder.h"

void slowSort(Recorder& rec, int begin, int end){
  if(begin >= end) return;
  int middle = (begin + end) / 2;
  slowSort(rec, begin, middle);
  slowSort(rec, middle + 1, end);
  if(rec.cmp(middle,end)){
    rec.swap(middle, end);
    rec.finalize(end);
  }
  slowSort(rec, begin, end-1);
}
