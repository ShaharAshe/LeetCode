#include <iostream>
#include <cstdlib>
#include <string>
#include <unordered_map>


class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        size_t letters_c = t.size(), str_c = s.size();
        if(str_c<letters_c || s.empty() || t.empty()){
            return "";
        }

        std::unordered_map<char, size_t> letters;
        for(const auto& x:t)
        {
            ++letters[x];
        }

        // -------------------------------
        
        size_t left = 0, right = 0,
               min_len = INT_MAX, min_left = 0,
               count_l = letters_c;
        std::unordered_map<char, size_t> chack_l;

        while(right<str_c)
        {
            while(count_l)
            {
                if(right<str_c)
                {
                    if(letters.find(s[right]) != letters.end())
                    {
                        if((chack_l[s[right]]++) < letters[s[right]])
                        {
                            --count_l;
                        }
                        if(chack_l[s[right]] == letters[s[right]] &&!(count_l))
                        {
                            ++right;
                            break;
                        }
                    }
                } else {
                    break;
                }
                ++right;
            }
            if(((right-left)<min_len) && !count_l)
            {
                min_len = (right-left);
                min_left = left;
            }
            while(!count_l)
            {
                char a = s[left];
                if(letters.find(a) != letters.end())
                {
                    if(--chack_l[a] < letters[a])
                    {
                        ++count_l;
                        ++left;
                        break;
                    }
                }
                if(str_c<(++left))
                {
                    break;
                }
                if((right-left)<min_len)
                {
                    min_len = (right-left);
                    min_left = left;
                }
            }
        }
        return (min_len == INT_MAX)?(""):(s.substr(min_left,min_len));
    }
};


int main(){
    std::string s = "ADOBECODEBANC",
                t = "ABC";

    auto res = Solution().minWindow(s, t);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}