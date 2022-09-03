#include "Transform.h"

Transform::Transform() : translation(glm::vec3(0,0,0)), rotation(glm::vec3(0,0,0)), scale(glm::vec3(1,1,1)) {}

glm::mat4 Transform::GetMatrix()
{
	glm::mat4 transMatrix = glm::translate(translation);


}
