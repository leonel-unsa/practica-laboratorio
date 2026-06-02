#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth, float factor) {

    if(depth == 0 || length < 5)
        return;

    turtleForward(turtle, length);

    turtleLeft(turtle, 30);
    fractalTree(turtle, length * factor, depth - 1, factor);

    turtleRight(turtle, 60);
    fractalTree(turtle, length * factor, depth - 1, factor);

    turtleLeft(turtle, 30);
    turtleBackward(turtle, length);
}

int main(void) {

    TurtleApp *app = turtleAppCreate(800, 600, "Fractal Tree - TurtleC");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 400.0f, 460.0f);
    turtlePenDown(t);

    turtleSetColor(t, 0, 255, 0);
    turtleSetSpeed(t, 10.0f);

    float factor = 0.7f;

    fractalTree(t, 80.0f, 7, factor);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
