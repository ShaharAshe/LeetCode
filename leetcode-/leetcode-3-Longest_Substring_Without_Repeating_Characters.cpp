#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <unordered_map>


// int lengthOfLongestSubstring(std::string s) {
//     int max_len = 0;
//     std::vector<char> temp_res;
//     std::unordered_map<char, int> letter_in_seq;
//     for (size_t i = 0; i < s.size(); ++i){
//         if (letter_in_seq.find(s[i]) != letter_in_seq.end())
//         {
//             size_t res_len = letter_in_seq[s[i]];
//             for (size_t j = 0; j <= res_len; ++j)
//             {
//                 letter_in_seq.erase(temp_res.front());
//                 temp_res.erase(temp_res.begin());
//             }
//             for (size_t j = 0; j < temp_res.size(); ++j)
//                 letter_in_seq[temp_res[j]] = j;
//         }
//         letter_in_seq.emplace(std::make_pair(s[i], temp_res.size()));
//         temp_res.emplace_back(s[i]);
//         if (max_len < temp_res.size())
//                 max_len = temp_res.size();
//     }
//     return max_len;
// }




int main(){
    try
    {
        // std::string s = "abcabcbb";
        std::string s = "asljlj";
        int max_len_str = lengthOfLongestSubstring(s);
        std::cout << max_len_str << std::endl;
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}