#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>


class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, size_t> patterns_place;
        std::vector<std::vector<std::string>> res;

        for(const auto & s : strs)
        {
            std::string temp_s = s;
            std::sort(temp_s.begin(), temp_s.end());

            if(patterns_place.find(temp_s)==patterns_place.end()) {
                patterns_place[temp_s] = res.size();
                res.emplace_back(std::vector<std::string>{s});
            } else {
                res[patterns_place[temp_s]].emplace_back(s);
            }
        }
        return res;
    }
};


int main(){
    std::vector<std::string> strs = {"eat","tea","tan","ate","nat","bat"};

    auto res = Solution().groupAnagrams(strs);
    
    std::cout << "[";
    for(size_t i = 0; i < res.size(); i++)
    {
        std::cout << "[";
        for(size_t j = 0; j < res[i].size(); j++)
        {
            std::cout << res[i][j];
            if(j!=res[i].size()-1)
                std::cout << ", ";
        }
        std::cout << "]";
        if(i!=res.size()-1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;

    return EXIT_SUCCESS;
}