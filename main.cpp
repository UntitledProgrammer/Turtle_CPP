#include "Turtle/Turtle.h"

static void Six(np::Turtle* turtle, float size)
{
	turtle->SetRotation(RIGHT_EULER_ANGLES);
	turtle->Forward(size/2);
	turtle->Backward(size/2);
	turtle->SetRotation(DOWN_EULER_ANGLES);
	turtle->Forward(size);
	turtle->SetRotation(RIGHT_EULER_ANGLES);
	turtle->Forward(size/2);
	turtle->Rotate(270);
	turtle->Forward(size/2);
	turtle->Rotate(90);
	turtle->Backward(size / 2);
}

static void Seven(np::Turtle* turtle, float size)
{
	turtle->SetRotation(LEFT_EULER_ANGLES);
	turtle->Backward(size/2);
	turtle->SetRotation(DOWN_EULER_ANGLES);
	turtle->Rotate(12.0f);
	turtle->Forward(size + size * 0.05f);
}

void One(np::Turtle* turtle, float size)
{
	turtle->SetRotation(DOWN_EULER_ANGLES);
	turtle->Forward(size);
}

void Four(np::Turtle* turtle, float size)
{
	turtle->SetRotation(DOWN_EULER_ANGLES);
	turtle->Forward(size /2);
	turtle->Rotate(90);
	turtle->Backward(size/4);
	turtle->SetRotation(UP_EULER_ANGLES);
	turtle->Forward(size / 2);
	turtle->Backward(size / 2);
	turtle->Rotate(90);
	turtle->Backward(size / 8);
	turtle->SetRotation(UP_EULER_ANGLES);
	turtle->Backward(size / 2);
	turtle->Forward(size / 2);
	turtle->SetRotation(LEFT_EULER_ANGLES);
	turtle->Forward(size / 4);
	turtle->Rotate(120);
	turtle->Forward(size/2 + size/4);
}

int main(int argc, char* argv[])
{
	np::TurtleWindow window = np::TurtleWindow("My Turtle", 800, 800);
	window.SetScale(4, 4);
	np::Turtle turtle = np::Turtle(&window);
	turtle.SetColour(COLOUR_RED);

	//Window. (200,200);
	window.Begin();


	turtle.Translate(glm::vec3(10, 10, 0));
	float size = 60.0f;


	//116.
	One(&turtle, size);
	turtle.Translate(glm::vec3(20, 10, 0));
	One(&turtle, size);
	turtle.Translate(glm::vec3(30, 10, 0));
	Six(&turtle, size);

	//74.
	turtle.Translate(glm::vec3(100, 100, 0));
	Seven(&turtle, size);
	turtle.Translate(glm::vec3(150, 100, 0));
	Four(&turtle, size);

	window.End();
	//!Window.
	return 0;
}