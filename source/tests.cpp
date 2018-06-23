#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>


#include "../framework/box.hpp"
#include "../framework/sphere.hpp"
#include "../framework/shape.hpp"

//Aufgabe 5.2/3
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


TEST_CASE("print", "[shape, box, sphere]")
{
  Color color {1.0f, 0.0f, 0.0f};
  
  glm::vec3 mini{20.0, 20.4, 30.0};
  glm::vec3 maxi{60.0, 85.3, 33.7};
  Box b1 {mini, maxi};
  Box b2 {mini, maxi, "Box", color};

  std::cout << b1 << "\n";
  std::cout << b2 << "\n";

  glm::vec3 center{50.0, 50.0, 50.0};
  double radius {15.8};
  Sphere s1 {center, radius};
  Sphere s2 {center, radius, "Kugel", color};

  std::cout << s1 << "\n";
  std::cout << s2 << "\n";
}

TEST_CASE ("intersect_ray_sphere", "[intersect]")
{
  //Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  //ray direction has to be normalized !
  //you can use:
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction {0.0f, 0.0f, 1.0f};

  //Sphere
  glm::vec3 sphere_center{0.0f, 0.0f,  5.0f};
  float sphere_radius {1.0f};

  float distance = 0.0f;
  auto result = glm::intersectRaySphere(
    ray_origin, ray_direction,
    sphere_center,
    sphere_radius * sphere_radius, //squared radius !!!
    distance);
  
  REQUIRE(distance == Approx(4.0f));


  glm::vec3 center {0.0, 0.0, 5.0};
  double radius {1.0};
  Color color {0.0f, 0.0f, 1.0f};

  Sphere s1 {center, radius, "Sphere 1", color};

  float distance2 = 0.0f;
  REQUIRE(!s1.intersect(Ray{}, distance));
  REQUIRE(distance == Approx(-4.0f));

  glm::vec3 center1 {0.0, 0.0, 6.0};

  Sphere s2 {center1, radius, "Sphere 2", color};

  float distance3 = 1.0f;
  REQUIRE(!s2.intersect(Ray{}, distance));
}

//Aufgabe 5.8

TEST_CASE("Kon-und Destrktoren", "[Aufgabe 5.8]")
{
  std::cout << "Aufgabe 5.8 \n";
  Color red {255, 0, 0};
  glm::vec3 position {0.0f, 0.0f, 0.0f};

  Sphere* s1 = new Sphere {position, 1.2f, "sphere0", red};
  Shape* s2 = new Sphere {position, 1.2f, "sphere1", red};

  s1 -> print (std::cout);
  s2 -> print (std::cout);

  delete s1;
  delete s2;
}





















int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
