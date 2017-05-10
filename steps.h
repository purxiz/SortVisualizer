#ifndef STEPS_H
#define STEPS_H
#include<stdlib.h>
#include<vector>
#include "state.h"

enum color {WHITE,GREEN,RED,BLUE};

class Step {
public:
  Step(){}
  virtual ~Step(){}
  virtual void execute(State& state){
    state.step++;
  }
  virtual void unexecute(State& state){
    state.step--;
  }
  virtual color getColor(size_t){return WHITE;}
};

class Swap : public Step {
  size_t i,j;
public:
  Swap(size_t i, size_t j):i(i),j(j){}
  ~Swap(){}
  void execute(State &state){
    Step::execute(state);
    int tmp = state.data[i];
    state.data[i] = state.data[j];
    state.data[j] = tmp;
  }
  void unexecute(State &state){
    Step::unexecute(state);
    int tmp = state.data[i];
    state.data[i] = state.data[j];
    state.data[j] = tmp;
  }
  color getColor(size_t x){
    if(x == i || x == j){
      return BLUE;
    }
    return WHITE;
  }
};

class Finalize : public Step {
  size_t i;
public:
  Finalize(size_t i):i(i){}
  ~Finalize(){}
  color getColor(size_t x){
    if(x == i){
      return GREEN;
    }
    return WHITE;
  }
};

class Compare : public Step {
  size_t i,j;
public:
  Compare(size_t i, size_t j):i(i),j(j){}
  ~Compare(){}
  color getColor(size_t x){
    if(x == i || x == j){
      return RED;
    }
    return WHITE;
  }
};
#endif
