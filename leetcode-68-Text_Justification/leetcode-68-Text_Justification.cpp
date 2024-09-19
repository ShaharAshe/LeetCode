#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> res;

    std::vector<std::string> temp_res;
    size_t count_chars = 0;
    for(size_t i = 0; i<words.size(); ++i)
    {
        int temp_res_s = (temp_res.empty())? 0 : (temp_res.size()-1);
        int t = (count_chars+(words[i].size()+temp_res_s));
        if((t+1)<=maxWidth || (temp_res.empty()))
        {
            temp_res.emplace_back(words[i]);
            count_chars += (words[i].size());
        } else {
            int rem = (maxWidth-count_chars);
            int c_add = !(temp_res.size()-1)?0:(rem/(temp_res.size()-1));
            for(size_t j = 0; j<temp_res.size()-1; ++j)
            {
                temp_res[j].append(c_add,' ');
                count_chars += c_add;
            }
            rem = (maxWidth-count_chars);
            res.emplace_back("");
            size_t res_s = res.size();
            for(size_t j = 0; j<temp_res.size() || j<rem; ++j)
            {
                if(j<temp_res.size())
                {
                    res[res_s-1] += temp_res[j%temp_res.size()];
                }
                if(j<rem)
                {
                    res[res_s-1] += ' ';
                }
            }
            temp_res.clear();
            count_chars = 0;
            --i;
        }
        if(i==(words.size()-1))
        {
            int rem = (maxWidth-count_chars);
            res.emplace_back("");
            for(size_t j = 0; j<temp_res.size(); ++j)
            {
                res[res.size()-1] += temp_res[j];
                if(rem)
                {
                    res[res.size()-1] += ' ';
                } else {
                    break;
                }
                --rem;
            }
            res[res.size()-1].append(rem,' ');
        }
    }
    return res;
}


int main(){
    // std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    // int maxWidth = 16;

    // std::vector<std::string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    // int maxWidth = 20;

    // std::vector<std::string> words = {"What","must","be","acknowledgment","shall","be"};
    // int maxWidth = 16;

    std::vector<std::string> words = {"Listen","to","many,","speak","to","a","few."};
    int maxWidth = 6;

    auto res = fullJustify(words, maxWidth);
    
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