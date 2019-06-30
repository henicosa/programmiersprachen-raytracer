#define CATCH_CONFIG_RUNNER
// Include von lokalem / projektinternem File
#include <shape.hpp>
#include <box.hpp>
#include <sphere.hpp>

// Include von File aus einer Fremdbibliothek
#include <catch.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>

// Standard - Headers
#include <iostream>


// exercise 5.2
TEST_CASE("area and volume", "[area_and_volume]" ) 
{
  Box b1{};
  Sphere s1{};
  REQUIRE(b1.area() == 6);
  REQUIRE(b1.volume() == 1);
  REQUIRE(s1.area() == Approx(4*M_PI));
  REQUIRE(s1.volume() == Approx((4.f/3.f)*M_PI));

  Box b2{"Hans", Color{0.5f,0.3f,0.5f},glm::vec3{-4.0f,-3.0f,2.0f}, glm::vec3{6.0f,2.0f,3.0f}};
  Sphere s2{"Marie", Color{0.1f,0.3f,0.8f},glm::vec3{-4.0f,-3.0f,2.0f}, 4.0f};
  REQUIRE(b2.area() == 2*50 + 2 * 5 + 2 * 10);
  REQUIRE(b2.volume() == 50);
  REQUIRE(s2.area() == Approx(4*M_PI*pow(4, 2)));
  REQUIRE(s2.volume() == Approx((4.f/3.f)*M_PI*pow(4, 3)));
}

// exercise 5.4 + 5.5
TEST_CASE("print", "[print]" ) 
{
  Box b2{"Hans", Color{0.5f,0.3f,0.5f},glm::vec3{-4.0f,-3.0f,2.0f}, glm::vec3{6.0f,2.0f,3.0f}};
  Sphere s2{"Marie", Color{0.1f,0.3f,0.8f},glm::vec3{-4.0f,-3.0f,2.0f}, 4.0f};
  std::cout << b2 << s2;
}

// exercise 5.6
TEST_CASE ("intersect_ray_sphere", "[intersect]")
{
  // Ray
  // ray direction has to be normalized !
  // you can use :
  // v = glm :: normalize ( some_vector )

  Ray ray = Ray{glm::vec3{0.0f, 0.0f, 0.0f},glm::vec3{0.0f, 0.0f, 1.0f}};
  // Sphere
  Color c = Color{0.1f,0.3f,0.8f};
  Sphere s{"Marie", Color{0.1f,0.3f,0.8f},glm::vec3{0.0f ,0.0f , 5.0f}, 1.0f};
  
  auto result = s.intersect(ray);
  REQUIRE(result.intersected == true);
  REQUIRE(result.distance == Approx(4.0f));
  REQUIRE(result.x_color == c);
  REQUIRE(result.x_name == "Marie");
  auto v = glm::vec3{0.0f ,0.0f , 1.0f};
  REQUIRE(result.intersection_direction == v);
  auto m = glm::vec3{0.0f ,0.0f , 4.0f};
  REQUIRE(result.intersection_point == m);

  Ray ray2 = Ray{glm::vec3{0.0f, 0.0f, 2.0f},
    glm::normalize(glm::vec3{0.0f, -5.0f, 0.0f})};
  // Sphere
  Sphere s2{"Knut", Color{0.2f,0.5f,0.3f},glm::vec3{0.0f ,-5.0f , 0.0f}, 2.0f};
  auto result3 = s2.intersect(ray2);

  auto result2 = s2.intersect(ray);
  REQUIRE(result2.intersected == false);
  REQUIRE(result3.intersected == true);
  auto p = glm::vec3{0.0f, -5.0f, 2.0f};
  REQUIRE(result3.intersection_point == p);
  
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
