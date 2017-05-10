#ifndef REPLAY_H
#define REPLAY_H
#include "steps.h"
#include "state.h"
#include <string>

class Replay {
  std::vector<Step*> steps;
  std::vector<Step*>::iterator current;
  State &state;
public:
  const char * name;
  Replay(State &_state, const char * name):state(_state), name(name){
    current = steps.begin();
  }
  ~Replay(){
    for(std::vector<Step*>::iterator i = steps.begin(); i != steps.end(); i++){
      delete *i;
    }
  }
  Replay& operator++(){
    if(current != steps.end()&&current!=(--steps.end())){
      current++;
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

  void gotoEnd(){
    current = steps.end();
    if(current != steps.begin()){
      current--;
    }
  }

  void reset(){
    while(current != steps.begin()){
      (*current)->unexecute(state);
      current--;
    }
  }

  Step* step(){
    return *current;
  }
  std::vector<Step*>& getSteps(){
    return steps;
  }

};
#endif
