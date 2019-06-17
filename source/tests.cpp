#define CATCH_CONFIG_RUNNER
// Include von lokalem / projektinternem File
#include "shape.hpp"

// Include von File aus einer Fremdbibliothek
#include <catch.hpp>

// Standard - Headers
#include <iostream>


// exercise 5.1
TEST_CASE("virtual shape", "[virtual_shape]" ) 
{

}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
