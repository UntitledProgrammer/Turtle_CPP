#include "Transform.h"

Transform::Transform() : translation(glm::vec3(0,0,0)), rotation(glm::vec3(0,0,0)), scale(glm::vec3(1,1,1)) {}

glm::mat4 Transform::GetMatrix()
{
	glm::mat4 transMatrix = glm::translate(translation);

	glm::mat4 rotXMatrix = glm::rotate(rotation.x, glm::vec3(1, 0, 0));
	glm::mat4 rotYMatrix = glm::rotate(rotation.y, glm::vec3(0, 1, 0));
	glm::mat4 rotZMatrix = glm::rotate(rotation.z, glm::vec3(0, 0, 1));
	glm::mat4 scaleMatrix = glm::scale(scale);

	glm::mat4 rotMatrix = rotZMatrix * rotYMatrix * rotXMatrix;

	return transMatrix * rotMatrix * scaleMatrix;
}
