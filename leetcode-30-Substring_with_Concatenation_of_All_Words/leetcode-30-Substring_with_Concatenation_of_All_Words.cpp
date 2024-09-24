#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>


class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        size_t word_len = words[0].size(),
               word_arr_len = words.size(),
               win_len = (word_arr_len*word_len);
        std::vector<int> res;

        if(s.size()<win_len)
            return res;

        std::unordered_map<std::string,int> appear_count;
        for(const auto& x:words){
            ++appear_count[x];
        }
        
        // --------------------------------------------
        
        for(size_t i = 0; i<(s.size()-(win_len-1)); ++i)
        {
            std::unordered_map<std::string,int> temp_chack;
            int look_for_count = word_arr_len;
            for(size_t j = i; (j+word_len)<=s.size(); j+=(word_len))
            {
                auto temp_word = s.substr(j,word_len);
                ++temp_chack[temp_word];
                --look_for_count;

                if(appear_count.find(temp_word) != appear_count.end())
                {
                    if(temp_chack[temp_word]>appear_count[temp_word]) {
                        break;
                    } else if(look_for_count <= 0) {
                        res.emplace_back(i);
                        
                        while((j+word_len)<s.size())
                        {
                            if(s.substr(i,win_len) == s.substr(++i,win_len))
                            {
                                ++j;
                                res.emplace_back((i));
                            } else {
                                --i;
                                break;
                            }
                        }
                        break;
                    }
                } else {
                    break;
                }
            }
        }
        return res;
    }
};


int main(){
    std::string s = "foofoogoofoo";
    std::vector<std::string> words = {"foo","goo","foo"};
    
    auto res = Solution().findSubstring(s, words);
    
    std::cout << "[";
    for (size_t i = 0; i<res.size(); ++i)
    {
        std::cout << res[i];
        if(i!=(res.size()-1))
        {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
    
    return EXIT_SUCCESS;
}