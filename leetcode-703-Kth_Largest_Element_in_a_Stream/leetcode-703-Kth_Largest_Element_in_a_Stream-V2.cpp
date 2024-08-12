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
        
        if(min == INT_MAX)
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
        if(!this->m_nums.size())
        {
            this->m_nums.emplace_back(val);
            return val;
        }
        // auto it = this ->m_nums.begin();
        int start = 0;
        int end = this->m_nums.size();
        int mid = (start + end)/2;
        while(start != mid && end != mid)
        {
            if(val<this->m_nums[mid])
            {
                end = mid;
                    mid = (start + end)/2;
            } else {
                start = mid;
                mid = (start + end)/2;
            }
        }
        if(val > this->m_nums[mid])
            this->m_nums.insert(this->m_nums.begin()+mid+1, val);
        else
            this->m_nums.insert(this->m_nums.begin()+mid, val);

        return this->m_nums[(this->m_nums.size()-(this->m_k))];
    }

private:
    std::vector<int> m_nums;
    int m_k;
};


int main(){
    // int k = 3;
    // std::vector<int> nums = {4, 5, 8, 2};

    int k = 1;
    std::vector<int> nums = {-2};

    KthLargest* obj = new KthLargest(k, nums);
    // int param_1 = obj->add(3);
    // int param_2 = obj->add(5);
    // int param_3 = obj->add(10);
    // int param_4 = obj->add(9);
    // int param_5 = obj->add(4);


    int param_1 = obj->add(-3);
    int param_2 = obj->add(0);


    std::cout << param_1 << std::endl;
    std::cout << param_2 << std::endl;
    // std::cout << param_3 << std::endl;
    // std::cout << param_4 << std::endl;
    // std::cout << param_5 << std::endl;

    return EXIT_SUCCESS;
}