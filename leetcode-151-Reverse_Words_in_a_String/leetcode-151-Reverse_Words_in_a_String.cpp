#include <iostream>
#include <cstdlib>
#include <string>


std::string reverseWords(std::string s) {
    std::string res;
    size_t i = 0;
    while(i<s.size()){
        while(i<s.size() && s[i] == ' '){
            ++i;
        }
        std::string temp_s;
        while(i<s.size() && s[i] != ' '){
            temp_s += s[i];
            ++i;
        }
        if(temp_s.empty()){
            break;
        }
        if(!res.empty()){
            temp_s+=' ';
        }
        res = temp_s+res;
    }
    return res;
}


int main(){
    std::string s = "the sky is blue";

    auto res = reverseWords(s);
    
    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}