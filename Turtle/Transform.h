#pragma once
//Includes:
#include<glm/glm.hpp>
#include<glm/ext/matrix_common.hpp>
#include<glm/ext/matrix_transform.hpp>

#ifndef TRANSFORM_H
#define TRANSFORM_H

class Transform
{
protected:
	//Attributes:
	glm::vec3 translation;
	glm::vec3 rotation;
	glm::vec3 scale;

public:
	//Constructor:
	Transform();

	//Methods:
	glm::mat4 GetMatrix();
};

#endif // !TRANSFORM_H