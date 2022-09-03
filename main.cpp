#include "Turtle/Turtle.h"

static void DrawL(np::Turtle* turtle, unsigned int size)
{
	turtle->Rotate(90);
	turtle->Forward(size / 2);
	turtle->Rotate(90);
	turtle->Forward(size);
}

static void DrawA(np::Turtle* turtle, unsigned int size)
{
	turtle->Rotate(20);
	turtle->Forward(size);
	turtle->Backward(size);
	turtle->Rotate(320);
	turtle->Forward(size);
	turtle->Backward(size / 2);
	turtle->Rotate(110);
	turtle->Forward(size / 3);
}

int main(int argc, char* argv[])
{
	np::TurtleWindow window = np::TurtleWindow("My Turtle", 640, 480);
	np::Turtle turtle = np::Turtle(&window);
	window.Begin();
	turtle.SetColour(COLOUR_RED);

	turtle.Translate(glm::vec3(200, 200,0));
	DrawA(&turtle, 100);
	turtle.Rotate(270);
	turtle.Translate(glm::vec3(150, 50, 0));
	DrawL(&turtle, 100);

	window.End();
	SDL_Delay(10000);
	return 0;
}