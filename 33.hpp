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

        public:

        idx_t get_mid_of(const idx_t lbound, const idx_t rbound) const
        {
            size_t _length = rbound - lbound;

            // this formula ensures the same middle index, regardless whether length even/odd
            return lbound + (_length - (_length%2) ) / 2;
        }

        public:

        std::function<idx_t(idx_t, idx_t)> get_mid_of_left = std::bind(&Solution::Subrange<T>::get_mid_of, this, this->left, this->mid);
        std::function<idx_t(idx_t, idx_t)> get_mid_of_right = std::bind(&Solution::Subrange<T>::get_mid_of, this, this->mid, this->right);

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

        // debug methods
        void print() const
        {
            for(idx_t idx = 0; idx < length; idx++)
            {
                std::cout<<(*ref)[left+idx]<<" ";
            }
            std::cout<<std::endl;
        }

        // factory methods
        Subrange make_left() const
        {
            return Subrange(this -> left, this->get_mid_of_left(), *(this->ref));
        }
    };

    public:

};

// int main()
// {

//     // using Subrange = Solution::Subrange<std::vector>;
//     typedef Solution::Subrange<std::vector<int>> Subrange;

//     std::vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8} ;
//     Subrange myrange(2, 5, nums);
//     // Subrange leftrange = myrange.make_left();

//     std::cout<<myrange.get_mid_of(0,4)<<std::endl;

//     myrange.print(); 

// }