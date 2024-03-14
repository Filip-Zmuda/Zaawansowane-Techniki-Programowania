#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cassert>

std::vector<std::string> tokenize(const std::string & txt){
    std::vector<std::string>slowa;
    std::string x = "";
    for(int i=0; i<txt.length();i++){
        if(txt[i] == ' '){
            if(txt[i]==txt.length()-1){
                return slowa;
            }
//            if(txt[i+1]==' '){
//                i++;
//            }
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

int main() {
    std::string sentence = "Ala ";
    std::cout<<sentence.length()<<std::endl;
    std::vector<std::string> result = tokenize(sentence);
    assert(tokenize("Ala ma kota").size()==3);
    assert(tokenize("Robert Downey Jr.").size()==3);
    for(int i=0; i<result.size(); i++){
        std::cout<<result[i]<<std::endl;
    }
    std::cout<<result.size();
}
