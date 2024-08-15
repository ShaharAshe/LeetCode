#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>


bool lemonadeChange(std::vector<int>& bills) {
    std::unordered_map<int, size_t> count_appears = {{5, 0},
                                                     {10, 0}};
    
    for(size_t i = 0; i<bills.size(); ++i)
    {
        if(i == 0 && bills[i] != 5)
            return false;
        switch (bills[i])
        {
            case 5:
            {
                ++count_appears[bills[i]];
                continue;
            }
            case 10:
            {
                if(count_appears[5])
                {
                    ++count_appears[bills[i]];
                    --count_appears[5];
                    break;
                }
                return false;
            }
            case 20:
            {
                if(count_appears[5] >= 1 && count_appears[10] >= 1) {
                    count_appears[5] -= 1;
                    count_appears[10] -= 1;
                    break;
                } else if(count_appears[5] >= 3) {
                    count_appears[5] -= 3;
                    break;
                }
                return false;
            }
        }
    }
    return true;
}

int main(){
    // std::vector<int> vec = {5,5,5,10,20};
    
    // std::vector<int> vec = {5,5,10,10,20};

    // std::vector<int> vec = {5,5,5,5,10,5,20,10,5,5};

    // std::vector<int> vec = {5,5,5,5,10,5,10,10,10,20};

    // std::vector<int> vec = {5,5,5,10,5,5,10,20,20,20};

    std::vector<int> vec = {5,5,5,5,20,20,5,5,5,5};
    
    auto res = lemonadeChange(vec);
    std::cout << res << std::endl;
    
    return EXIT_SUCCESS;
}