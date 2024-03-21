#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cassert>

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

int main() {
    std::string sentence = "   Ala ma kota";
    std::cout<<sentence.length()<<std::endl;
    std::vector<std::string> result = tokenize(sentence);
    assert(tokenize("Ala ").size()==1);
    assert(tokenize("Ala ma kota").size()==3);
    assert(tokenize("Robert Downey Jr.").size()==3);
    assert(tokenize("Ala  ma kota").size()==3);
    assert(tokenize("Ala ma    kota").size()==3);
    assert(tokenize("Ala    ").size()==1);
    assert(tokenize("Ala ma kota    ").size()==3);
    assert(tokenize("Robert Downey    Jr.   ").size()==3);
    assert(tokenize("   Ala ma kota").size()==3);
    assert(tokenize("    Ala   ma kota     ").size()==3);
    for(int i=0; i<result.size(); i++){
        std::cout<<result[i]<<std::endl;
    }
    std::cout<<result.size();
}
