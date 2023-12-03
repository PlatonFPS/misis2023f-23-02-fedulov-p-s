#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <dynarr/dynarr.hpp>

#include <iostream>

TEST_CASE("DynArr test") {
  DynArr arr;

  CHECK(arr.Size() == 0);
  CHECK_THROWS(arr[0]);
  arr.Resize(5);
  CHECK(arr.Size() == 5);
  CHECK_THROWS(arr.Resize(-1));

  CHECK_THROWS(arr[6]);

  arr[0] = 4;
  CHECK(arr[0] == 4);

  arr[1] = 6;
  CHECK(arr[1] == 6);
  CHECK(arr[0] == 4);
  CHECK(arr[0] != arr[1]);
  
  arr.Resize(8);
  CHECK(arr[7] == 0);
  
  arr.Resize(2);
  CHECK(arr[1] == 6);
}