#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>


class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        std::unordered_map<char,char> iso_s_m,
                                      iso_t_m;
        for(size_t i = 0; i<t.size(); ++i)
        {
            char s_c = s[i],
                 t_c = t[i];
            
            if(iso_s_m.find(s_c) == iso_s_m.end()) {
                iso_s_m[s_c] = t_c;
            } else if(iso_s_m[s_c]!=t_c) {
                return false;
            }

            if(iso_t_m.find(t_c) == iso_t_m.end()) {
                iso_t_m[t_c] = s_c;
            } else if(iso_t_m[t_c]!=s_c) {
                return false;
            }
        }
        return true;
    }
};


int main(){
    std::string s = "egg",
                t = "add";

    auto res = Solution().isIsomorphic(s,t);

    if (res)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    return EXIT_SUCCESS;
}