#include <cstdlib>
#include <iostream>
#include <string>

 bool isValid(std::string s) {
    std::string temp;
    
    for(auto i : s)
    {
        if(i == '(' || i == '[' || i == '{')
            temp.push_back(i);
        else
        {
            int len = temp.length()-1;
            if(temp.empty() ||
               ((i == ')' && temp[len] != '(' ) ||
               (i == ']' && temp[len] != '[' ) ||
               (i == '}' && temp[len] != '{' )))
               return false;
               
               temp.pop_back();
        }
    }
    
    return temp.empty();
 }

int main(int argc, char const *argv[])
{
    std::cout << isValid("(]") << std::endl;
    return EXIT_SUCCESS;
}
