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

        static constexpr idx_t get_mid(const idx_t _start, const idx_t _end)
        {
            static_assert(_start<=_end);
            const idx_t length = _end - _start;
            return (length-length%2)/2;
        }

        // expose const indices
        const idx_t start, mid, end;

        Subrange& make_subrange(idx_t _start, idx_t _end)
        {
            idx_t t = start;
        }

        public:

        Subrange() = delete;
        template<typename T> Subrange()
        {}
        
        // 
        Subrange& make_left_range();
        Subrange& make_right_range();

    };

public:
    
    int search(std::vector<int>& nums, int target)
    {
       
    }
};

int main()
{

}