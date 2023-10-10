/* -- Id = 2390 -- */

#include <cstdlib>
#include <iostream>
#include <string>

 std::string removeStars(std::string s) {
    std::string trimed_str;
    
    for (auto i : s) {
        if(i != '*') {
            trimed_str.push_back(i);
        }
        else {
            trimed_str.pop_back();
        }
    }
    
    return trimed_str;
}

int main(int argc, char const *argv[])
{
    std::cout << removeStars("leet**cod*e") << std::endl;
    return EXIT_SUCCESS;
}
