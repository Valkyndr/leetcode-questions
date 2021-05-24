#include<iostream>
#include<vector>
#include<tuple>
#include<stack>

class Solution {

    // alias to an explicit std::range instantiation
    typedef std::tuple<int, int> range;

    // light-weight class to access a subrange of some indexable object
    class Subrange
    {
        // alias to some type suited for indices
        typedef size_t idx_t;        

        // 
        const idx_t& start_idx;
        const idx_t& mid_idx;
        const idx_t& end_idx; 

        public:
        
        template<typename CONTAINER_TYPE> Subrange(CONTAINER_TYPE&& container)
        {
            
        }

        // return a Subrange object from some 
        template<typename CONTAINER_TYPE> Subrange make_subrange_of(CONTAINER_TYPE&& container)
        {
            

            return std::move(...);
        }
    };

public:
    
    int search(std::vector<int>& nums, int target)
    {
       
    }
};

int main()
{

}