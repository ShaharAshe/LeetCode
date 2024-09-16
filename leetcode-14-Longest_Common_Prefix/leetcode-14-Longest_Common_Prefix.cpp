#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>


std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string common;
    int min_len = strs[0].size();
    
    for(const auto& x:strs){
        if(x.size()<min_len){
            min_len = x.size();
        }
    }

    for(size_t i = 0; i<min_len; ++i){
        char c = strs[0][i];
        for(size_t j = 0; j<strs.size(); ++j){
            if(strs[j][i] != c)
            {
                return common;
            }
        }
        common += c;
    }
    return common;
}


int main(){
    std::vector<std::string> vec = {"flower","flow","flight"};
    
    auto res = longestCommonPrefix(vec);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}