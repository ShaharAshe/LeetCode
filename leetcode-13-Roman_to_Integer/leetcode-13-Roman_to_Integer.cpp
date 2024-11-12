#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> roman_vals =
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        size_t s_len = s.size(),
               res = roman_vals[s[s_len-1]];

        for(int i = (s_len-2); 0<=i; --i)
        {
            char current = s[i],
                 prev = s[i+1];
            if(current == 'I' && (prev == 'V' || prev == 'X')) {
                res -= roman_vals['I'];
            } else if(current == 'X' && (prev == 'L' || prev == 'C')) {
                res -= roman_vals['X'];
            } else if(current == 'C' && (prev == 'D' || prev == 'M')) {
                res -= roman_vals['C'];
            } else {
                res += roman_vals[current];
            }
        }
        return res;
    }
};


int main() {
    std::string s = "III";
    auto res = Solution().romanToInt(s);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}