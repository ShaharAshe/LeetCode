/* -- Id = 125 -- */

#include <iostream>
#include <string>
#include <cctype>
// #include <algorithm>

using std::string;

bool isPalindrome(string s) {
    for(size_t begin = 0, end = static_cast<size_t>(s.size()-1);
        begin != end && (begin < s.size()-1 && end > 0);
        ++begin, --end)
    {
        while (!std::isalpha(s[begin]) && !std::isdigit(s[begin]) && begin < s.size()-1)
            ++begin;
        while (!std::isalpha(s[end]) && !std::isdigit(s[end]) && end > 0)
            --end;
        
        if (end <= begin)
            break;

        if (((std::isalpha(s[begin]) || std::isdigit(s[begin])) &&
            (std::isalpha(s[end])) || std::isdigit(s[end])) &&
           (std::tolower(s[begin]) != std::tolower(s[end])))
        {
            return false;
        }
    }
    
    return true;
}


//string temp_s = s;
    
    // temp_s.erase(std::remove_if(temp_s.begin(), temp_s.end(), [](char c) {
       // return !std::isalpha(c);
    // }), temp_s.end());
    // for (auto &i : temp_s)
       // i = std::tolower(i);
        
    // std::cout << temp_s <<std::endl;


int main(int argc, char const *argv[])
{
    std::cout << isPalindrome("ab2a") << std::endl;

    return 0;
}
