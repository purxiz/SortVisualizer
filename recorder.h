#ifndef RECORDER_H
#define RECORDER_H
#include "steps.h"
#include "state.h"

class Recorder {
  std::vector<Step*> &steps;
  State &state;
public:
  Recorder(std::vector<Step*> &_steps,State &_state):steps(_steps),state(_state){}
  ~Recorder(){}
  void swap(size_t i, size_t j){
    Step *op = new Swap(i,j);
    op->execute(state);
    steps.push_back(op);
  }
  bool cmp(size_t i, size_t j){
    Step *op = new Compare(i,j);
    op->execute(state);
    steps.push_back(op);
    return state.data[i] > state.data[j];
  }
  void finalize(size_t i){
    Step *op = new Finalize(i);
    op->execute(state);
    steps.push_back(op);  }
};
#endif
