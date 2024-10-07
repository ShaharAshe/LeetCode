#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

class Solution {
public:
    int minLength(std::string s) {
        std::vector<char> pattern;
        int res = s.size();

        for(size_t i = 0; i<s.size(); ++i)
        {
            switch(s[i])
            {
                case 'A':
                {
                    pattern.emplace_back('A');
                    break;
                }
                case 'B':
                {
                    if(!pattern.empty())
                    {
                        if(pattern[pattern.size()-1] == 'A')
                        {
                            pattern.pop_back();
                            res -= 2;
                        } else {
                            pattern.clear();
                        }
                    }
                    break;
                }
                case 'C':
                {
                    pattern.emplace_back('C');
                    break;
                }
                case 'D':
                {
                    if(!pattern.empty())
                    {
                        if(pattern[pattern.size()-1] == 'C')
                        {
                            pattern.pop_back();
                            res -= 2;
                        } else {
                            pattern.clear();
                        }
                    }
                    break;
                }
                default:
                {
                    if(!pattern.empty())
                    {
                        pattern.clear();
                    }
                    break;
                }
            }
        }
        return res;
    }
};


int main(){
    std::string s = "ABFCACDB";

    auto res = Solution().minLength(s);

    std::cout << res << std::endl;

    return EXIT_SUCCESS;
}