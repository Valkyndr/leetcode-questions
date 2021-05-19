#include<iostream>
#include<vector>
#include<tuple>
#include<stack>

class Solution {

    // alias to an explicit std::range instantiation
    typedef std::tuple<int, int> range;

public:
    
    int search(std::vector<int>& nums, int target)
    {
        std::stack<range> ranges;
        range const *buf;

        // initiate sequence by placing first range (indices to first and last elements on stack)
        ranges.push(std::move(std::make_tuple<int,int>(0, ranges.size()-1)));

        // as long as have ranges not explored...
        while(!ranges.empty())
        {
            // retrive top range
            buf = std::move(&ranges.top()); ranges.pop();

            // make checks here

            /*
                1.  if buf[0] == buf[1] then terminate this stack (skip to next loop)
            */

            // get middle index
            int split_idx = 
        }

       
    }
};

int main()
{

}