#ifndef App_hpp
#define App_hpp

#include "GlutApp.h"
#include "replay.h"
#include "state.h"
#include <vector>

class App: public GlutApp {
    // Maintain app state here
    State state;
    Replay quick, heap, slow, insert, shell, bubble, comb;
    Replay* rep;
    int speed, counter;
public:
    // Constructor, to initialize state
    App(const char* label, int x, int y, int w, int h);

    // These are the events we want to handle
    void draw();
    void idle();
    void keyPress(unsigned char key);
    void specialKeyPress(int key);
};

#endif
