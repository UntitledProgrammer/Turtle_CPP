#pragma once
#ifndef TURTLE_H
#define TURTLE_H

//Includes:
#include"TurtleWindow.h"
#include<vector>
#include<glm/glm.hpp>
#include<glm/ext/matrix_transform.hpp>

namespace np
{
	//Typedefs:
	typedef glm::vec<2, glm::float32> Vec2u;
	typedef glm::vec<3, glm::float32> Vec3u;
	typedef glm::mat<4, 4, glm::float32> Mat4u;

	class Turtle
	{
	private:
		//Attributes:
		TurtleWindow* window;
		Mat4u transform;
		Colour colour;


	public:
		//Constructors:
		Turtle(unsigned int width, unsigned int height);
		Turtle(TurtleWindow* window);

		//Properties:
		Vec3u GetPosition();

		//Methods:
		void Translate(glm::vec3 translation);
		void Rotate(glm::float32 degrees);
		void Forward(unsigned int steps);
		void Backward(unsigned int steps);
		void SetColour(Colour colour);
	};
}

#endif // !TURTLE_H