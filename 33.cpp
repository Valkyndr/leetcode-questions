#include<iostream>

class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        const size_t start_idx = 0, end_idx = nums.size()-1;
        const int start_value = nums[start_idx], end_value = nums[end_value];
        
        if(start_value==target) return start_idx;
        else if(end_value==target) return end_idx;
        else
        {
            
        }
        
    }
};

int main()
{

}