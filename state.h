#ifndef STATE_H
#define STATE_H
#include <vector>

struct State{
  int step;
  std::vector<int> data;
  State():step(1){}
};

#endif
