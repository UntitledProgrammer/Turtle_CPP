#include "Transform2D.h"

Transform2D::Transform2D() : translation(glm::vec2(0,0)), rotation(0.0f), scale(glm::vec2(1,1)) {}

void Transform2D::SetRotation(float eulerAngles){ { rotation = glm::radians(eulerAngles); } }

void Transform2D::AddRotation(float eulerAngle){ { rotation += glm::radians(eulerAngle); } }

glm::mat3 Transform2D::GetMatrix()
{
	glm::mat3 r = glm::rotate(glm::mat3(1), rotation);
	glm::mat3 t = glm::translate(glm::mat3(1), translation);
	return glm::rotate(t, rotation);
}

glm::vec2 Transform2D::Up(){ return glm::vec2(glm::cos(rotation), glm::sin(rotation)); }