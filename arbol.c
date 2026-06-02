#include "turtlec.h"

void fractalTree(Turtle *turtle, float length, int depth) {
    if(depth == 0 || length < 5)
        return;

    if(depth > 5)
        turtleSetColor(turtle, 120, 70, 20);
    else
        turtleSetColor(turtle, 0, 200, 0);

    turtleForward(turtle, length);

    turtleLeft(turtle, 30);
    fractalTree(turtle, length * 0.7, depth - 1);

    turtleRight(turtle, 30);
    fractalTree(turtle, length * 0.7, depth - 1);

    turtleRight(turtle, 30);
    fractalTree(turtle, length * 0.7, depth - 1);

    turtleLeft(turtle, 30);
    turtleBackward(turtle, length);
}

int main(void) {
    TurtleApp *app = turtleAppCreate(800, 600, "Arbol Fractal");

    if(app == NULL)
        return 1;

    Turtle *t = turtleAppGetTurtle(app);

    turtlePenUp(t);
    turtleGoTo(t, 400.0f, 550.0f);
    turtleLeft(t, 90);    
    turtlePenDown(t);

    fractalTree(t, 100.0f, 6);

    turtleAppRun(app);
    turtleAppDestroy(app);

    return 0;
}
//a) el caso base ocurre cuando la profundidad llega a 0
// b) realiza tres llamdas recursivas
// c) turtleLeft permite recuperar la orientacion original
// utilice chat gpt y los promps fueron para que explique el codigo y que me ayuda a poner generar el reto 1 , le pedi que me lo explique , tambien lo use para que me ayude a compilar
//#honestidad
