/* -- Id = 1 -- */

#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> myMap;
    
    for (size_t i = 0; i < nums.size(); ++i)
    {
        myMap[nums[i]] = i;
    }

    for (size_t i = 0; i < nums.size(); ++i)
    {
        if(myMap.find(target-nums[i]) != myMap.end() &&
        myMap[(target-nums[i])] != i)
        {
            std::vector<int> v;
            v.push_back(i);
            v.push_back(myMap[(target-nums[i])]);
            return v;
        }
    }
        std::vector<int> v;
        v.push_back(555);
        return v;
}

int main(int argc, char const *argv[])
{
    std::vector<int> a;
    a.push_back(2);
    a.push_back(7);
    a.push_back(11);
    a.push_back(15);

    std::vector<int> v = twoSum(a, 9);
    for (auto i : v)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}


