#include "Turtle/Turtle.h"

static void Six(np::Turtle* turtle, float size)
{
	turtle->SetRotation(np::RIGHT_EULER_ANGLES);
	turtle->Forward(size/2);
	turtle->Backward(size/2);
	turtle->SetRotation(np::DOWN_EULER_ANGLES);
	turtle->Forward(size);
	turtle->SetRotation(np::RIGHT_EULER_ANGLES);
	turtle->Forward(size/2);
	turtle->Rotate(270);
	turtle->Forward(size/2);
	turtle->Rotate(90);
	turtle->Backward(size / 2);
}

static void Seven(np::Turtle* turtle, float size)
{
	turtle->SetRotation(np::LEFT_EULER_ANGLES);
	turtle->Backward(size/2);
	turtle->SetRotation(np::DOWN_EULER_ANGLES);
	turtle->Rotate(12.0f);
	turtle->Forward(size + size * 0.05f);
}

void One(np::Turtle* turtle, float size)
{
	turtle->SetRotation(np::DOWN_EULER_ANGLES);
	turtle->Forward(size);
}

void Four(np::Turtle* turtle, float size)
{
	glm::vec3 start = turtle->GetPosition();
	float width = size * 0.5f;

	turtle->PenUp();
	turtle->SetRotation(np::DOWN_EULER_ANGLES);
	turtle->Forward(size/2); //Middle.
	turtle->PenDown();
	turtle->Rotate(90);
	glm::vec3 pos = turtle->GetPosition();
	turtle->Backward(width * 0.8f);
	turtle->Rotate(90);
	turtle->Forward(size * 0.20f);
	turtle->Backward(size * 0.20f);
	turtle->Rotate(90);
	turtle->Forward(width * 0.2f);
	turtle->Backward(width * 0.2f);
	turtle->Rotate(90);
	turtle->Forward(size / 2);
	turtle->Teleport(pos);
	turtle->SetRotation(np::UP_EULER_ANGLES + 30.0f);
	turtle->Forward(width + width * 0.1f);
}

int main(int argc, char* argv[])
{
	np::TurtleWindow window = np::TurtleWindow("My Turtle", 800, 800);
	window.SetScale(4, 4);
	np::Turtle turtle = np::Turtle(&window);
	turtle.SetColour(COLOUR_RED);

	//Window. (200,200);
	window.Begin();

	turtle.Teleport(glm::vec3(10, 10, 0));
	float size = 60.0f;


	//116.
	One(&turtle, size);
	turtle.Teleport(glm::vec3(20, 10, 0));
	One(&turtle, size);
	turtle.Teleport(glm::vec3(30, 10, 0));
	Six(&turtle, size);

	//74.
	turtle.Teleport(glm::vec3(100, 100, 0));
	Seven(&turtle, size);
	turtle.Teleport(glm::vec3(150, 100, 0));
	Four(&turtle, size);

	window.End();
	//!Window.
	return 0;
}