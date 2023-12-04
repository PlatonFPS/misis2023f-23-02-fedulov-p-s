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
  
  arr.Resize(0);
  arr.Resize(4);
  CHECK(arr[0] == 0);
  arr[0] = 2.1;
  arr[1] = 2;
  arr[3] = 5;
  CHECK(arr[3] == 5);
  arr.Resize(2);
  CHECK_THROWS(arr[3]);
  CHECK(arr[1] == 2);
  CHECK(arr[0] == doctest::Approx(2.1));
  arr.Resize(4);
  CHECK(arr[3] == 0);
}