#define CATCH_CONFIG_RUNNER
// Include von lokalem / projektinternem File
#include <shape.hpp>
#include <box.hpp>
#include <sphere.hpp>

// Include von File aus einer Fremdbibliothek
#include <catch.hpp>

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

  Box b2{"Hans", Color{0.5,0.3,0.5},glm::vec3{-4,-3,2}, glm::vec3{6,2,3}};
  Sphere s2{"Marie", Color{0.1,0.3,0.8},glm::vec3{-4,-3,2}, 4};
  REQUIRE(b2.area() == 2*50 + 2 * 5 + 2 * 10);
  REQUIRE(b2.volume() == 50);
  REQUIRE(s2.area() == Approx(4*M_PI*pow(4, 2)));
  REQUIRE(s2.volume() == Approx((4.f/3.f)*M_PI*pow(4, 3)));
}

// exercise 5.4
TEST_CASE("print", "[print]" ) 
{
  Box b2{"Hans", Color{0.5,0.3,0.5},glm::vec3{-4,-3,2}, glm::vec3{6,2,3}};
  Sphere s2{"Marie", Color{0.1,0.3,0.8},glm::vec3{-4,-3,2}, 4};
  std::cout << b2 << s2;
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
