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
public:
	//Static memebers:
	static constexpr glm::vec2 horizontal = glm::vec2(1, 0);
	static constexpr glm::vec2 vertical = glm::vec2(0, 1);

	//Attributes:
	glm::vec2 scale;
	glm::vec2 translation;
	/// <summary>Rotation is messured in radians.</summary>
	float rotation;

	//Constructor:
	Transform2D();

	//Properties:
	void SetRotation(float eulerAngles);
	void AddRotation(float eulerAngle);

	//Methods:
	glm::mat3 GetMatrix();
	glm::vec2 Up();
};

#endif // !TRANSFORM_H