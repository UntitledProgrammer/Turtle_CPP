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
	//Typedefs:
	typedef glm::vec<2, glm::float32> Vec2u;
	typedef glm::vec<3, glm::float32> Vec3u;
	typedef glm::mat<4, 4, glm::float32> Mat4u;

	class Turtle
	{
	private:
		//Attributes:
		TurtleWindow* window;
		Transform transform;
		Colour colour;
		const glm::vec3 WORLD_FORWARD = glm::vec3(0, 0, 1), WORLD_UP = glm::vec3(0,1,0);


	public:
		//Constructors:
		Turtle(unsigned int width, unsigned int height);
		Turtle(TurtleWindow* window);

		//Properties:
		Vec3u GetPosition();

		//Methods:
		void Translate(glm::vec3 translation);
		void Rotate(glm::float32 degrees);
		void SetRotation(glm::float32 degrees);
		void Forward(unsigned int steps);
		void Backward(unsigned int steps);
		void SetColour(Colour colour);
	};
}

#endif // !TURTLE_H