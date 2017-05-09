#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "replay.h"
#include <vector>

class App: public GlutApp {
    // Maintain app state here
    std::vector<int> state;
    Replay quick, heap, slow, insert;
    Replay* rep;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);
    
    // These are the events we want to handle
    void draw();
    void keyPress(unsigned char key);
    void specialKeyPress(int key);
};

#endif
