#ifndef REPLAY_H
#define REPLAY_H
#include "steps.h"

class Replay {
  std::vector<Step*> &steps;
  std::vector<Step*>::iterator current;
  std::vector<int> &state;
public:
  Replay(std::vector<Step*> &_steps,std::vector<int> &_state):steps(_steps),state(_state){
    current = steps.begin();
  }
  Replay(std::vector<Step*> &_steps,std::vector<int> &_state,std::vector<Step*>::iterator _current):steps(_steps),state(_state),current(_current){}
  ~Replay(){
    for(std::vector<Step*>::iterator i = steps.begin(); i != steps.end(); i++){
      delete *i;
    }
    steps.clear();
  }
  Replay& operator++(){
    if(current != steps.end()&&(++current)!=steps.end()){
      (*current)->execute(state);
    }
    return *this;
  }
  Replay& operator--(){
    if(current != steps.begin()){
      (*current)->unexecute(state);
      current--;
    }
    return *this;
  }
};
#endif