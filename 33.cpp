#include<functional>
#include<iostream>
#include<cassert>
#include<vector>
#include<tuple>
#include<stack>

class Solution {

    // light-weight class to access a subrange of some indexable object
    template<class T> class Subrange
    {
        // typedefs / aliases
        typedef size_t idx_t;

        // container reference shall be indexable via [] operators via integer values
        const T* const ref;

        idx_t get_mid_of(const idx_t lbound, const idx_t rbound) const
        {
            // this formula ensures the same middle index, regardless whether length even/odd
            return left + (length - (length%2) ) / 2;
        }

        const idx_t left, mid, right;
        const size_t length; 

        public:

        Subrange() = delete;
        Subrange(const idx_t _left, const idx_t _right, const T& _target):
            left(_left), right(right),
            mid(get_mid_of(_left, _right)), 
            length(_right - _left + 1),
            ref(&_target)
        {
            assert(_left>=0);
            assert(_right>=_left);
        }

    };


    public:

};

int main()
{

    // using Subrange = Solution::Subrange<std::vector>;
    typedef Solution::Subrange<std::vector<int>> Subrange;

}