#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>


class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::unordered_map<char, std::string> pattern_to_s;
        std::unordered_map<std::string, char> s_to_pattern;
        
        size_t s_i = 0,
               p_i = 0;
        for(; p_i<pattern.size() && s_i<s.size(); ++p_i)
        {
            std::string word = "";
            while(s_i<s.size() && s[s_i]==' ')
            {
                ++s_i;
            }
            while(s_i<s.size() && s[s_i]!=' ')
            {
                word+=s[s_i++];
            }
            if(pattern_to_s.find(pattern[p_i])==pattern_to_s.end()) {
                pattern_to_s[pattern[p_i]] = word;
            } else if(pattern_to_s[pattern[p_i]] != word) {
                return false;
            }

            if(s_to_pattern.find(word)==s_to_pattern.end()) {
                s_to_pattern[word] = pattern[p_i];
            } else if(s_to_pattern[word] != pattern[p_i]) {
                return false;
            }
        }
        return (s_i<s.size() || p_i<pattern.size())? false : true;
    }
};


int main(){
    std::string pattern = "abba",
                s = "dog cat cat dog";

    auto res = Solution().wordPattern(pattern, s);

    if(res)
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;

    return EXIT_SUCCESS;
}