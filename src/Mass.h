#include <glm/glm.hpp>

struct Mass {
    Mass();

    void update();

    float mass;
    glm::vec3 position;
    glm::vec3 velocity;
    glm::vec3 acceleration;
};
