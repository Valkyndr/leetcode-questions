#include<algorithm>
#include<iostream>
#include<string>
#include<vector>

class Solution {
public:
    
    class Walker
    {
        int balance = 0;
        int length = 0;
    public:
        void read(char c)
        {
            length++;
            balance += (c=='(') ? 1 : 0;
        }
        
        int getBalance() const
        {
            // at time of read: '0' if well-formed, negative if not
            return this->balance;
        }

        int getLength() const
        {
            // return supposed 'length' of the string read by this walker
            return this->length;
        }
    };
    
    int longestValidParentheses(std::string s) {
            
        std::vector<Walker*> walkers;
        size_t max = 0;
        
        for(const char& c: s)
        {
            if(c=='(') walkers.push_back(new Walker());
            std::for_each(walkers.begin(), walkers.end(), [&](Walker* walker)
            {
                walker->read(c);
                
                // compare against largest string
                int balance = walker->getBalance();
                if(balance==0)
                {
                    max = (walker->getLength()>max) ? walker->getLength() : max;
                }
            });
            
            // debug
            std::for_each(walkers.begin(), walkers.end(), [=](const Walker* walker)
            {
                std::cout<<walker->getBalance()<<" ";
            });
            std::cout<<'\n';

            // remove 'dead walkers' (strings whose parentheses are no longer well formed)
            std::remove_if(walkers.begin(), walkers.end(), [=](Walker* walker)
            {
                return (walker->getBalance() < 0);
            });
        }
    }
};

int main()
{
    Solution solver;
    std::cout<<"ans is: "<<solver.longestValidParentheses("(()")<<'\n';
}