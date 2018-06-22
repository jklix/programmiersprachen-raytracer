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
    glm::vec3 mini2{3.0, 4.0, 5.0};
    glm::vec3 maxi{100.0, 100.0, 100.0};
    glm::vec3 maxi2{-8.0, -8.0, -8.0};
    Box b1{mini, maxi};
    Box b2{mini2, maxi2};

    REQUIRE(b1.get_minimum().x == mini.x);
    REQUIRE(b1.get_minimum().y == mini.y);
    REQUIRE(b1.get_minimum().z == mini.z);
    REQUIRE(b1.area() == Approx(15000.0));
    REQUIRE(b2.area() == Approx(862.0));
    REQUIRE(b1.volume() == Approx(125000.0));
    REQUIRE(b2.volume() == Approx(-1716.0));

    //Sphere
    double radius{6.4};
    Color color{0.0f, 0.0f, 1.0f};
    
    Sphere s1{mini, radius};
    Sphere s2{mini, radius, "Kugel", color};

    REQUIRE(s1.get_radius() == 6.4);
    REQUIRE(s1.get_center().x == mini.x);
    REQUIRE(s1.get_center().y == mini.y);
    REQUIRE(s1.get_center().z == mini.z);
    REQUIRE(s1.area() == Approx(514.7185403641517242));
    REQUIRE(s1.volume() == Approx(1098.0662194435));
    REQUIRE(s2.get_color().r == 0.0f);
    REQUIRE(s2.get_color().g == 0.0f);
    REQUIRE(s2.get_color().b == 1.0f);
    REQUIRE(s2.get_name().compare("Kugel") == 0.0);

    
}






















int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
