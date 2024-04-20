#include <bits/stdc++.h>

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
