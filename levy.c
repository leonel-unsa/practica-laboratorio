#include <math.h>
#include "turtlec.h"

void levy(Turtle *turtle, float length, int depth) {

    if(depth == 0) {
        turtleForward(turtle, length);
        return;
    }

    turtleLeft(turtle, 45);
    levy(turtle, length / sqrt(2), depth - 1);

    turtleRight(turtle, 90);
    levy(turtle, length / sqrt(2), depth - 1);

    turtleLeft(turtle, 45);
}

int main(void) {

    TurtleApp *app = turtleAppCreate(800, 600, "Curva de Levy C");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 150.0f, 350.0f);
    turtlePenDown(t);

    turtleSetColor(t, 0, 150, 255);
    turtleSetSpeed(t, 10.0f);

    levy(t, 200.0f, 10);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
