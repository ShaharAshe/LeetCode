#include <iostream>
#include <cstdlib>
#include <vector>

class KthLargest {
public:
    KthLargest(int k, std::vector<int>& nums)
    : m_nums(nums), m_k(k)
    {
        int max = -1;
        int min = INT_MAX;
        for(const auto x : nums){
            if(max<x)
                max = x;
            if(min>x)
                min = x;
        }
        
        if(max == -1)
        {
            min = 0;
        }
        std::vector<int> order_nums;
        min = abs(min);
        order_nums.resize((max+1)+min);
        
        for(const auto x : nums){
            ++order_nums[x+min];
        }

        size_t j = 0;
        for(size_t i = 0; i<order_nums.size(); ++i){
            while(order_nums[i])
            {
                this->m_nums[j++] = i-min;
                --order_nums[i];
            }
        }
    }
    
    int add(int val) {
        auto it = this ->m_nums.begin();
        while(it != this->m_nums.end() && *it<val)
        {
            ++it;
        }
        it = this->m_nums.insert(it, val);

        return this->m_nums[(this->m_nums.size()-(this->m_k))];
    }

private:
    std::vector<int> m_nums;
    int m_k;
};

int main(){
    int k = 3;
    std::vector<int> nums = {4, 5, 8, 2};

    // int k = 1;
    // std::vector<int> nums = {-2};

    KthLargest* obj = new KthLargest(k, nums);
    int param_1 = obj->add(3);
    int param_2 = obj->add(5);
    int param_3 = obj->add(10);
    int param_4 = obj->add(9);
    int param_5 = obj->add(4);


    // int param_1 = obj->add(-3);
    // int param_2 = obj->add(0);


    std::cout << param_1 << std::endl;
    std::cout << param_2 << std::endl;
    std::cout << param_3 << std::endl;
    std::cout << param_4 << std::endl;
    std::cout << param_5 << std::endl;

    return EXIT_SUCCESS;
}