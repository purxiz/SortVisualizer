#ifndef RECORDER_H
#define RECORDER_H
#include "steps.h"

class Recorder {
  std::vector<Step*> &steps;
  std::vector<int> &state;
public:
  Recorder(std::vector<Step*> &_steps,std::vector<int> &_state):steps(_steps),state(_state){}
  ~Recorder(){}
  void swap(size_t i, size_t j){
    Step *op = new Swap(i,j);
    op->execute(state);
    steps.push_back(op);
  }
  bool cmp(size_t i, size_t j){
    steps.push_back(new Compare(i,j));
    return state[i] > state[j];
  }
  void finalize(size_t i){
    steps.push_back(new Finalize(i));
  }
};
#endif