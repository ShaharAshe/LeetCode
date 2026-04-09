#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    std::string encode(std::vector<std::string>& strs) {
        std::string result = "";

        for (auto &str : strs){
            result += str + _eostr_flag;
        }
        
        return result;
    }

    std::vector<std::string> decode(std::string s) {
        std::vector<std::string> result;
        size_t eostr_flag_size = _eostr_flag.size();
        size_t eostd_pos = s.find(_eostr_flag);
        while(eostd_pos != s.npos) {
            std::string sub_str = s.substr(0, eostd_pos);
            result.emplace_back(sub_str);
            s.erase(0, eostd_pos+eostr_flag_size);
            eostd_pos = s.find(_eostr_flag);
        }
        return result;
    }
private:
    std::string _eostr_flag = "<eostr>";
};

int main() {
    std::vector<std::string> dummy_input{"Hello","World"};

    auto result_encode = Solution().encode(dummy_input);

    std::cout << result_encode << std::endl;

    auto result_decode = Solution().decode(result_encode);

    for (auto &c : result_decode) {
        std::cout << c << " ";
    }
    std::cout << std::endl;
    

    return EXIT_SUCCESS;
}
