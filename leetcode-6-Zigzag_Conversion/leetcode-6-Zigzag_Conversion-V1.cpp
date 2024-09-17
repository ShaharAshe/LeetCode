#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>


std::string convert(std::string s, int numRows) {
    std::vector<std::vector<char>> zig;
    for(size_t i = 0; i<numRows; ++i){
        std::vector<char> temp_row;
        temp_row.resize(s.size(),'-');
        zig.emplace_back(temp_row);
    }

    size_t col = 0,
            i = 0;
    while(i<s.size())
    {
        int row = 0;
        while(i<s.size() && row<numRows)
        {
            zig[row++][col] = s[i++];
        }
        --row;
        while(i<s.size() && 1<row && col<s.size())
        {
            zig[--row][++col] = s[i++];
        }
        ++col;
    }

    std::string res;
    for(size_t row = 0; row<numRows; ++row)
    {
        for(size_t col = 0; col<s.size(); ++col)
        {
            if(zig[row][col] != '-')
            {
                res += zig[row][col];
            }
        }
    }

    return res;
}


int main(){
    std::string s = "PAYPALISHIRING";
    int numRows = 3;

    auto res = convert(s, numRows);
    
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}