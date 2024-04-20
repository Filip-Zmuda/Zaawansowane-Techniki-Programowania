#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include "tokenize.h"


TEST(TokenizeTest, HandlesNormalSentence) {
    EXPECT_EQ(tokenize("Ala ").size() , 1);
    EXPECT_EQ(tokenize("Robert Downey Jr.").size() , 3);
}

TEST(TokenizeTest, HandlesSpacesAfter) {    //grupa, nazwa testu
    EXPECT_EQ(tokenize("Ala ma kota").size() , 3);  //test jednostkowy
    EXPECT_EQ(tokenize("Ala    ").size(), 1);
}

TEST(TokenizeTest, HandlesSpacesInBetween) {
    EXPECT_EQ(tokenize("Ala  ma kota").size() , 3);
    EXPECT_EQ(tokenize("Robert Downey    Jr.   ").size() , 3);
}

TEST(TokenizeTest, HandlesSpacesBefore) {
    EXPECT_EQ(tokenize("   Ala ma kota").size() , 3);
    EXPECT_EQ(tokenize("    Ala   ma kota     ").size() , 3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}