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
                if(balance==0) max = (balance>max) ? balance : max;
            });
            
            // remove 'dead walkers' (strings whose parentheses are no longer well formed)
            std::remove_if(walkers.begin(), walkers.end(), [=](Walker* walker)
            {
                return (walker->getBalance() < 0);
            });
        }
        
        return max;
    }
};

int main()
{

}