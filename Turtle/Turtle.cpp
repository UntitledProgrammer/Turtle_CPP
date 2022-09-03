#include"Turtle.h"

//Constructors:
np::Turtle::Turtle(unsigned int width, unsigned int height) : window(new TurtleWindow("Turtle", width, height))
{
	transform = Mat4u(1);
	colour = Colour(0, 255, 0, 0);
}

np::Turtle::Turtle(TurtleWindow* window) : window(window)
{
	transform = Mat4u(1);
	colour = Colour(0, 255, 0, 0);
}

void np::Turtle::Translate(glm::vec3 translation)
{
	transform = glm::translate(transform, translation);
}

void np::Turtle::Rotate(glm::float32 degrees)
{
	transform = glm::rotate(transform, glm::radians(degrees), glm::vec3(0,0,1));
}

void np::Turtle::Forward(unsigned int steps)
{
	//Calculate start and end position.
	Vec3u p1= GetPosition();
	transform = glm::translate(transform, Vec3u(0, steps, 0));
	Vec3u p2 = GetPosition();

	//Draw line from the start point to the end point.
	SDL_SetRenderDrawColor(window->renderer, colour.GetRed(), colour.GetGreen(), colour.GetBlue(), SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(window->renderer, p1.x, p1.y, p2.x, p2.y);
}

void np::Turtle::Backward(unsigned int steps)
{
	//Calculate start and end position.
	Vec3u p1 = GetPosition();
	transform = glm::translate(transform, Vec3u(0, -(int)steps, 0));
	Vec3u p2 = GetPosition();

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
	return transform[3];
}
