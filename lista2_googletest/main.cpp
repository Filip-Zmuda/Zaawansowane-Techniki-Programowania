#include <iostream>
#include <gtest/gtest.h>
#include <vector>

std::vector<std::string> tokenize(const std::string & txt){
    std::vector<std::string>slowa;
    std::string x = "";
    for(int i=0; i<txt.length();i++){
        if(txt[i] == ' '){
            if(i==0){
                continue;
            }
            if(txt[i-1]==' '){
                if(i==txt.length()-1){
                    return slowa;
                }
                else{
                    continue;
                }
            }
            if(i==txt.length()-1){
                slowa.push_back(x);
                return slowa;
            }
            slowa.push_back(x);
            x = "";
        }
        else{
            x+=txt[i];
        }
    }
    slowa.push_back(x);
    return slowa;
}

TEST(TokenizeTest, HandlesNormalSentence) {
    EXPECT_EQ(tokenize("Ala ").size() , 1);
    EXPECT_EQ(tokenize("Robert Downey Jr.").size() , 3);
}

TEST(TokenizeTest, HandlesSpacesAfter) {
    EXPECT_EQ(tokenize("Ala ma kota").size() , 3);
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