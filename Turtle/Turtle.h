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
		bool active = true;


	public:
		//Constructors:
		Turtle(unsigned int width, unsigned int height);
		Turtle(TurtleWindow* window);

		//Properties:
		glm::vec3 GetPosition();
		void SetColour(Colour colour);
		void SetRotation(glm::float32 degrees);

		//Methods:
		void Teleport(glm::vec3 translation);
		void Translate(glm::vec3 translation);
		void Rotate(glm::float32 degrees);
		void Forward(unsigned int steps);
		void Backward(unsigned int steps);
		void PenUp();
		void PenDown();

	protected:
		//Protected methods:
		void DrawLine(glm::vec3 a, glm::vec3 b);
		glm::vec3 TranslateDirection(glm::vec3 direction, float steps);
	};

	#define UP_EULER_ANGLES 180.0f
	#define DOWN_EULER_ANGLES 0.0f
	#define RIGHT_EULER_ANGLES 270.0f
	#define LEFT_EULER_ANGLES 90.0f
}

#endif // !TURTLE_H