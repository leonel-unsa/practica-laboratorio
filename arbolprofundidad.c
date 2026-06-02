#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {

    if(depth == 0 || length < 5)
        return;

    turtleForward(turtle, length);

    turtleLeft(turtle, 30);
    fractalTree(turtle, length * 0.7, depth - 1);

    turtleRight(turtle, 60);
    fractalTree(turtle, length * 0.7, depth - 1);

    turtleLeft(turtle, 30);
    turtleBackward(turtle, length);
}

int main(void) {

    TurtleApp *app = turtleAppCreate(800, 600, "Fractal Tree Test");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 400.0f, 550.0f);
    turtlePenDown(t);

    turtleSetColor(t, 0, 255, 0);
    turtleSetSpeed(t, 10.0f);

    fractalTree(t, 120.0f, 7);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
