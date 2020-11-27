/*
 * factorial_test.cpp
 *
 *  Created on: 31-Oct-2020
 *      Author: anantha
 */

#include "factorial.h"
#include "gtest/gtest.h"
#include <string>
#include <filesystem>
#include <iostream>

class VV{
public:
    std::string v = "teddy";
    const std::string& getV(){
        return v;
    }
};

TEST(IntegerFunctionTest, negative) {
        EXPECT_EQ(1, factorial(-5));
        EXPECT_EQ(1, factorial(-1));
        EXPECT_GT(factorial(-10), 0);
}

TEST(IntegerFunctionTest, zero) {


         EXPECT_EQ(1, factorial(0));

         std::filesystem::path fs = "res:/rootname";
         std::filesystem::path fs2 = "C:node";
         std::cout<<fs.lexically_relative(fs2)<<std::endl;
         VV one;
         std::string c = one.getV();// = "terry";
         c = "t";
         std::cout<<c<<" "<<one.getV()<<std::endl;
         //std::Sstring
}

TEST(IntegerFunctionTest, postive) {
         EXPECT_EQ(1, factorial(1));
         EXPECT_EQ(2, factorial(2));
         EXPECT_EQ(6, factorial(3));
         EXPECT_EQ(40320, factorial(8));
}
TEST(MyTestSuitName, MyTestCaseName) {
    int actual = 1;
    EXPECT_GT(actual, 0);
    EXPECT_EQ(1, actual) << "Should be equal to one";
}
