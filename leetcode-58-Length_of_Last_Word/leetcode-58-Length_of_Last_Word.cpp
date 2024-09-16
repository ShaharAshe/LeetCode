#include <iostream>
#include <cstdlib>
#include <string>

int lengthOfLastWord(std::string s) {
    int i = s.size()-1;
    while(0<=i && s[i] == ' ')
    {
        --i;
    }
    
    int res = 0;
    while(0<=i && s[i] != ' ')
    {
        ++res;
        --i;
    }
    return res;
}


int main(){
    std::string s = "Hello World";

    auto res = lengthOfLastWord(s);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}