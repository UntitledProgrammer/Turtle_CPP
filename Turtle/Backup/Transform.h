#pragma once
//Includes:
#include<glm/glm.hpp>
#include<glm/gtx/transform.hpp>

#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform
{
public:
	//Static memebers:
	static constexpr glm::vec3 horizontal = glm::vec3(1, 0, 0);
	static constexpr glm::vec3 vertical = glm::vec3(0, 1, 0);
	static constexpr glm::vec3 depth = glm::vec3(0, 0, 1);

	//Attributes:
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;

public:
	//Constructor:
	Transform();

	//Methods:
	glm::mat4 GetMatrix();
	glm::vec3 LocaliseDirection(glm::vec3 direction)
	{
		return glm::normalize(glm::translate(GetMatrix(), direction)[3] - GetMatrix()[3]);
	}
};

#endif // !TRANSFORM_H