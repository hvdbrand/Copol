/*
 * CopolTest.cpp
 *
 *  Created on: 21 mei 2016
 *      Author: HBrand
 */

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../src/main.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleMock(&argc, argv);
  RUN_ALL_TESTS();
  return 0;
}


