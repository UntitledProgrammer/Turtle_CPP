#include"Turtle.h"

//Constructors:
np::Turtle::Turtle(unsigned int width, unsigned int height) : window(new TurtleWindow("Turtle", width, height))
{
	transform = Transform();
	colour = Colour(0, 255, 0, 0);
}

np::Turtle::Turtle(TurtleWindow* window) : window(window)
{
	transform = Transform();
	colour = Colour(0, 255, 0, 0);
}

void np::Turtle::Translate(glm::vec3 translation)
{
	transform.translation = translation;
}

void np::Turtle::Rotate(glm::float32 degrees)
{
	transform.rotation += WORLD_FORWARD * glm::radians(degrees);
}

void np::Turtle::SetRotation(glm::float32 degrees)
{
	transform.rotation = WORLD_FORWARD * glm::radians(degrees);
}

void np::Turtle::Forward(unsigned int steps)
{
	//Calculate start and end position.
	glm::vec3 p1 = transform.GetMatrix()[3];
	glm::vec3 p2 = glm::translate(transform.GetMatrix(), WORLD_UP * (float)steps)[3]; //Translate relative to local rotation.
	transform.translation = p2;

	//Draw line from the start point to the end point.
	SDL_SetRenderDrawColor(window->renderer, colour.GetRed(), colour.GetGreen(), colour.GetBlue(), SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(window->renderer, p1.x, p1.y, p2.x, p2.y);
}

void np::Turtle::Backward(unsigned int steps)
{
	//Calculate start and end position.
	glm::vec3 p1 = transform.GetMatrix()[3];
	glm::vec3 p2 = glm::translate(transform.GetMatrix(), WORLD_UP * -(float)steps)[3];
	transform.translation = p2;

	//Draw line from the start point to the end point.
	SDL_SetRenderDrawColor(window->renderer, colour.GetRed(), colour.GetGreen(), colour.GetBlue(), SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(window->renderer, p1.x, p1.y, p2.x, p2.y);
}


void np::Turtle::SetColour(Colour colour)
{
	this->colour = colour;
}

np::Vec3u np::Turtle::GetPosition()
{
	return glm::vec3(0);
}
