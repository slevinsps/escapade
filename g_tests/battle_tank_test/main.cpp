#include "tst_test.h"

#include <gtest/gtest.h>
#include <movement_test.h>
#include <rot_movement_test.h>
#include <forward_movement_test.h>

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


