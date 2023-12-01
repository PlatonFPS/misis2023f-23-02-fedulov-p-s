#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <dynarr/dynarr.hpp>

#include <iostream>

TEST_CASE("DynArr constructor") {
  DynArr arr;
  CHECK(arr.Size() == 0);
  CHECK_THROWS(arr[0]);
  arr.Resize(5);
  CHECK(arr.Size() == 5);
  CHECK_THROWS(arr.Resize(-1));
}