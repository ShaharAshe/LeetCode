#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool hasDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> dup_set;
        for (int &num : nums)
        {
            if (!dup_set.emplace(num).second)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3, 3};
    auto result = Solution().hasDuplicate(nums);

    std::cout << ((result) ? "true" : "false") << std::endl;

    return EXIT_SUCCESS;
}