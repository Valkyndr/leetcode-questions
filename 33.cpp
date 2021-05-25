#include<iostream>
#include<cassert>
#include<vector>
#include<tuple>
#include<stack>

class Solution {

    // light-weight class to access a subrange of some indexable object
    class Subrange
    {
        // alias to some type suited for indices
        typedef size_t idx_t; 

        // hold some reference to some container here
        const int& reference;

        // calculate index to midpoint (this value is same whether even/odd length)
        static constexpr idx_t get_mid(const idx_t _start, const idx_t _end)
        {
            // params are non-negative and ordered
            assert(_start<=_end);
            assert(_start>=0);

            // mid-index calculated is equal regardless if odd/even 'length'
            const idx_t length = _end - _start;
            return (length-length%2)/2;
        }

        // expose const indices
        const idx_t start, mid, end;

        public:

    };

    public:

};

int main()
{

}