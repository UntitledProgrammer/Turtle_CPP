#include "Turtle/Turtle.h"

static void DrawL(np::Turtle* turtle, unsigned int size)
{
	turtle->SetRotation(0);
	turtle->Forward(size);
	turtle->Rotate(270);
	turtle->Forward(size/2);
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
	np::TurtleWindow window = np::TurtleWindow("My Turtle", 800, 800);
	window.SetScale(4, 4);
	np::Turtle turtle = np::Turtle(&window);
	window.Begin();
	turtle.SetColour(COLOUR_RED);

	turtle.Translate(glm::vec3(50, 10,0));
	DrawA(&turtle, 80);
	turtle.SetRotation(0);
	turtle.Translate(glm::vec3(100, 10, 0));
	DrawL(&turtle, 75);

	turtle.Translate(glm::vec3(19, 95, 0));
	turtle.SetRotation(270);
	turtle.Forward(122);

	window.End();
	return 0;
}