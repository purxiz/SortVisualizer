#include "shuffle.h"
// Fisher Yates shuffle
void shuffle(std::vector<int>& state){
  for(int i = state.size(); i > 1; i--){
    int k = std::rand() % i;
    
    int tmp = state[k];
    state[k] = state[i-1];
    state[i-1] = tmp;
  }
}