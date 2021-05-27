#include<functional>
#include<iostream>
#include<cassert>
#include<vector>
#include<tuple>
#include<stack>

class Solution {

    // light-weight class to access a subrange of some indexable object
    class Subrange
    {
        // typedefs / aliases 
        typedef size_t idx_t;
        typedef std::vector<int> cont_t;

        // expose const indices
        const idx_t start, end;
        const cont_t& collection;

        // review type signatures here 
        // typedef idx_t(idx_t, idx_t) calc_func;

        // private factory function to generate a copy
        Subrange& make_copy(idx_t _start, idx_t _end) const
        {
            constSubrange cpy = Subrange(collection, _start, _end);
            return std::move(cpy);
        }

        // calculate index to midpoint (this value is same whether even/odd length)
        static constexpr idx_t get_mid_of_range(const idx_t _start, const idx_t _end)
        {
            // params are non-negative and ordered
            assert(_start<=_end);
            assert(_start>=0);

            // mid-index calculated is equal regardless if odd/even 'length'
            const idx_t length = _end - _start;
            return (length-length%2)/2;
        }

        public:

        // constructors (no default)
        Subrange() = delete;
        Subrange(const cont_t& container, const idx_t& _start, const idx_t& _end): start(_start), end(_end), collection(container)
        {
            
        }

        // getters
        idx_t left() const { return this->start; }
        idx_t right() const { return this->end; }
        idx_t mid() const 
        {
            return get_mid_of_range(this->start, this->end);
        }

        // factory functions to generate subdivisions
        auto make_left = std::bind(make_copy, collection, start, end);

    };

    public:

};

int main()
{

}