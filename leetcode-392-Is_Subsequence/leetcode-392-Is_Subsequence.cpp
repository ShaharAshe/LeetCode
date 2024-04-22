#include <cstdlib>
#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t) {
    size_t t_i = 0;
    bool is_apear = (s.size() && t.size()) || (!s.size());
    for (size_t s_i = 0; s_i < s.size() && t_i < t.size() && is_apear ; ++s_i)
    {
        is_apear = false;
        for (; t_i < t.size() && !is_apear ; ++t_i)
            is_apear = (s[s_i] == t[t_i]);

        if(t_i == t.size() && s_i != s.size()-1)
            is_apear = false;
    }
    return is_apear;
}

int main(){
    // std::string s = "b",
    //             t = "c";
    std::string s = "abc",
                t = "ahbgdc";
    std::cout << isSubsequence(s, t) << std::endl;
    return EXIT_SUCCESS;
}