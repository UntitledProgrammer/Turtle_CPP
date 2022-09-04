#include"Turtle.h"

#define POSITION_COLUMN 3

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

void np::Turtle::Teleport(glm::vec3 translation)
{
	transform.translation = translation;
}

void np::Turtle::Translate(glm::vec3 translation)
{
	glm::vec3 p1 = transform.GetMatrix()[POSITION_COLUMN];
	transform.translation = translation;
	DrawLine(p1, transform.GetMatrix()[POSITION_COLUMN]);
}

void np::Turtle::Rotate(glm::float32 degrees){ transform.rotation += WORLD_FORWARD * glm::radians(degrees); }

void np::Turtle::SetRotation(glm::float32 degrees){ transform.rotation = WORLD_FORWARD * glm::radians(degrees); }

void np::Turtle::Forward(unsigned int steps)
{
	DrawLine(TranslateDirection(WORLD_UP, steps), transform.GetMatrix()[POSITION_COLUMN]);
}

void np::Turtle::Backward(unsigned int steps)
{
	DrawLine(TranslateDirection(WORLD_UP * -1.0f, steps), transform.GetMatrix()[POSITION_COLUMN]);
}


void np::Turtle::SetColour(Colour colour){ this->colour = colour; }

glm::vec3 np::Turtle::GetPosition(){ return transform.GetMatrix()[POSITION_COLUMN]; }

void np::Turtle::PenUp() { active = false; }
void np::Turtle::PenDown() { active = true; }

void np::Turtle::DrawLine(glm::vec3 a, glm::vec3 b)
{
	if (!active) return;

	//Draw line from the start point to the end point.
	SDL_SetRenderDrawColor(window->renderer, colour.GetRed(), colour.GetGreen(), colour.GetBlue(), SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(window->renderer, a.x, a.y, b.x, b.y);
}

glm::vec3 np::Turtle::TranslateDirection(glm::vec3 direction, float steps)
{
	//Calculate start and end position.
	glm::vec3 p1 = transform.GetMatrix()[3];
	glm::vec3 p2 = glm::translate(transform.GetMatrix(), direction * steps)[3];
	transform.translation = p2;
	return p2;
}