#include "Transform.h"

Transform::Transform() : translation(glm::vec3(0,0,0)), rotation(glm::vec3(0,0,0)), scale(glm::vec3(1,1,1)) {}

glm::mat4 Transform::GetMatrix()
{
	return glm::translate(translation) * (glm::rotate(rotation.z, depth) * glm::rotate(rotation.y, vertical) * glm::rotate(rotation.x, horizontal)) * glm::scale(scale);
}
