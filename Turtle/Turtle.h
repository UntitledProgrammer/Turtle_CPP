#pragma once
#ifndef TURTLE_H
#define TURTLE_H

//Includes:
#include"TurtleWindow.h"
#include"Transform.h"
#include<vector>
#include<glm/glm.hpp>
#include<glm/ext/matrix_transform.hpp>

namespace np
{
	class Turtle
	{
	private:
		//Attributes:
		TurtleWindow* window;
		Colour colour;
		bool active = true;

	public:
		Transform transform;

		//Constructors:
		Turtle(unsigned int width, unsigned int height);
		Turtle(TurtleWindow* window);

		//Properties:
		glm::vec3 GetPosition();
		void SetColour(Colour colour);
		void SetRotation(glm::float32 eulerAngle);

		//Methods:
		void Teleport(glm::vec3 translation);
		void Translate(glm::vec3 translation);
		void Rotate(glm::float32 eulerAngle);
		void Forward(unsigned int steps);
		void Backward(unsigned int steps);
		void PenUp();
		void PenDown();

	protected:
		//Protected methods:
		void DrawLine(glm::vec3 a, glm::vec3 b);
		glm::vec3 TranslateDirection(glm::vec3 direction, float steps);
	};

	constexpr float UP_EULER_ANGLES = 180.0f;
	constexpr float DOWN_EULER_ANGLES = 0.0f;
	constexpr float RIGHT_EULER_ANGLES = 270.0f;
	constexpr float LEFT_EULER_ANGLES = 90.0f;
}

#endif // !TURTLE_H