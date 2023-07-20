/* -- Id = 88 -- */

#include <iostream>
#include <vector>

using std::vector;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    nums1.erase(nums1.begin()+(m), nums1.end());

    int count_1 = 0,
        count_2 = 0;
    int nm = m;

    if(m != 0 && n!= 0)
    {
        for (size_t i = 0; i < nm+n; ++i)
        {
            int val_1 = nums1[count_1],
                val_2 = nums2[count_2];
            
            if (val_1 <= val_2)
            {
                ++count_1;
            }
            else
            {
                nums1.insert(nums1.begin() + count_1, val_2);
                ++count_2;
                ++nm;
            }

            if (nm <= count_1 || n <= count_2)
                break;
        }
        
        if (m <= count_1)
        {
            while(count_2 < n)
            {
                nums1.emplace_back(nums2[count_2]);
                ++count_2;
            }
        }
    }
    else
    {
        if (n != 0)
        {
            while(count_2 < n)
            {
                nums1.emplace_back(nums2[count_2]);
                ++count_2;
            }
        }
    }
}


/*
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> final;
    int count_1 = 0,
        count_2 = 0;

    if (n !=0 && m != 0)
    {
        for(size_t i = 0; i < m+n; ++i)
        {
            int val_1 = nums1[count_1],
                val_2 = nums2[count_2];
        
            if (val_1 < val_2)
            {
                final.emplace_back(val_1);
                ++count_1;
            }
            else
            {
                final.emplace_back(val_2);
                ++count_2;
            }
        
            if (m <= count_1 || n <= count_2)
                break;
        }
        
        if (m <= count_1)
        {
            while(count_2 < n)
            {
                final.emplace_back(nums2[count_2]);
                ++count_2;
            }
        }
        else
        {
            while(count_1 < m)
            {
                final.emplace_back(nums1[count_1]);
                ++count_1;
            }
        }
    }
    else
    {
        if (m != 0)
        {
            while(count_1 < m)
            {
                final.emplace_back(nums1[count_1]);
                ++count_1;
            }
        }
        else
        {
            while(count_2 < n)
            {
                final.emplace_back(nums2[count_2]);
                ++count_2;
            }
        }
    }
    nums1 = final;
}
*/

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {0,0,3,0,0,0,0,0,0};
    vector<int> nums2 = {-1,1,1,1,2,3};
    merge(nums1, 3, nums2, 6);

    for (auto &i : nums1)
    {
    std::cout << i << std::endl;    
    }

    return 0;
}
