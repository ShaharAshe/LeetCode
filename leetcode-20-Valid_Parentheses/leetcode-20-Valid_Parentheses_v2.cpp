/* -- Id = 20 -- */

#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>


bool isValid(std::string s) {
    std::stack<char> check_s;

    for (auto &i : s)
    {
        if(i == '(' ||
           i == '{' ||
           i == '[')
        {
            check_s.push(i);
        }
        else{
            if(check_s.size() != 0 && ((i == ')' && check_s.top() == '(')||
               (i == '}' && check_s.top() == '{')||
               (i == ']' && check_s.top() == '[')))
               check_s.pop();
            else
                return false;
        }
    }
    
    return check_s.size() == 0; 
}

int main(int argc, char const *argv[])
{
    std::cout << isValid("]") << std::endl;
    
    return EXIT_SUCCESS;
}
