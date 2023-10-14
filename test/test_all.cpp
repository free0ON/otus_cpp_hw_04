#include <gtest/gtest.h>
#include "TAbstractIP.h"
/**
 *
 */

TEST(HW04_SFINAE, print_ip)
{
    EXPECT_EQ(print_ip( int8_t{-1} ), "255"); // 255
    EXPECT_EQ(print_ip( int16_t{0} ), "0.0"); // 0.0
    EXPECT_EQ(print_ip( int32_t{2130706433} ), "127.0.0.1"); // 127.0.0.1
    EXPECT_EQ(print_ip( int64_t{8875824491850138409} ), "123.45.67.89.101.112.131.41");// 123.45.67.89.101.112.131.41
    EXPECT_EQ(print_ip( std::string{"Hello, World!"} ), "Hello, World!"); // Hello, World!
    EXPECT_EQ(print_ip( std::vector<int>{100, 200, 300, 400} ), "100.200.300.400"); // 100.200.300.400
    EXPECT_EQ(print_ip( std::list<short>{400, 300, 200, 100} ), "400.300.200.100"); // 400.300.200.100
}