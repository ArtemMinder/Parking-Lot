#include "gtest/gtest.h"
#include "../src/gtest.cc"
#include "../googletest/googletest/src/gtest-death-test.cc"
#include "src/gtest-filepath.cc"
#include "../googletest/googletest/src/gtest-matchers.cc"
#include "../googletest/googletest/src/gtest-port.cc"
#include "../googletest/googletest/src/gtest-printers.cc"
#include "../googletest/googletest/src/gtest-test-part.cc"
#include "../googletest/googletest/src/gtest-typed-test.cc"

int i = 5;

TEST(i,i){
    ASSERT_EQ(i,5);
}

int g_main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
