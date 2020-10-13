#include "gtest/gtest.h"
#include "../src/gtest.cc"
#include "../googletest/googletest/src/gtest-death-test.cc"
#include "src/gtest-filepath.cc"
#include "../googletest/googletest/src/gtest-matchers.cc"
#include "../googletest/googletest/src/gtest-port.cc"
#include "../googletest/googletest/src/gtest-printers.cc"
#include "../googletest/googletest/src/gtest-test-part.cc"
#include "../googletest/googletest/src/gtest-typed-test.cc"

TEST(ParkingLot, test1){
    ASSERT_EQ(1, 1);
}
TEST(ParkingLot, test2){
     ASSERT_NE(1, 2);
}
TEST(ParkingLot, test3){
    ASSERT_LT(1, 2);
}
TEST(ParkingLot, test4){
    ASSERT_LE(1, 2);
}
TEST(ParkingLot, test5){
    ASSERT_GT(2, 1);
}
TEST(ParkingLot, test6){
    ASSERT_GE(2, 2);
}

int g_main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
