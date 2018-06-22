#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>


#include "../framework/box.hpp"
#include "../framework/sphere.hpp"
#include "../framework/shape.hpp"

//Aufgabe 5.2
TEST_CASE("area_volume","[5.2]")
{
    //box
    glm::vec3 mini{50.0, 50.0, 50.0};
    glm::vec3 maxi{100.0, 100.0, 100.0};
    Box b1{};

    REQUIRE(b1.get_minimum().x == mini.x);
    REQUIRE(b1.get_minimum().y == mini.y);
    REQUIRE(b1.get_minimum().z == mini.z);
    
}






















int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
