#pragma once
#define GLM_FORCE_RADIANS
#define PI 3.14159265

//Includes:
#include<glm/glm.hpp>
#include<glm/gtx/transform.hpp>
#include<glm/gtx/matrix_transform_2d.hpp>

#ifndef TRANSFORM_2D_H
#define TRANSFORM_2D_H

class Transform2D
{
protected:
	glm::vec2 scale;

public:
	//Static memebers:
	static constexpr glm::vec2 horizontal = glm::vec2(1, 0);
	static constexpr glm::vec2 vertical = glm::vec2(0, 1);

	//Attributes:
	glm::vec2 translation;
	float rotation;

	//Constructor:
	Transform2D();

	//Properties:
	void SetRotation(float degrees) { rotation = glm::radians(degrees); }
	void ApplyRotation(float degrees) { rotation += glm::radians(degrees); }

	//Methods:
	glm::mat3 GetMatrix();
	glm::vec2 Up()
	{
		return glm::vec2(glm::cos(rotation), glm::sin(rotation));
	}
};

#endif // !TRANSFORM_H