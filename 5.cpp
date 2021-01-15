#include<iostream>
#include<string>
using namespace std;

class Solution 
{
public: 
    
    // character to signal a 'falsy' value
    static const char INVALID_CHAR = '?';    
        
    // store word to avoid assing args to helpers
    std::string word;
        
    char charAt(size_t idx)
    {
        if(idx<0||idx>=this->word.size())
        {
            // if out of range, return 'false' char
            return INVALID_CHAR;
        }
        
        else return this->word[idx];
    }
    
    string longestPalindrome(string s) 
    {        
        // store to avoid passing 's' into helpers each time
        this->word = s;
        
        // store indices to longest palindrome (initialize)
        size_t l_idx = 0, r_idx = 0;            
        
        for(size_t idx = 0; idx<s.length(); idx++)
        {            
            // start separate routines based on 'type' of palindrome
            
            // palindrome with two 'central characters' i.e. 'abba'
            for(size_t dist = 0; dist<s.length() ; dist++)
            {
                if(charAt(idx-dist)!=charAt(idx+1+dist))
                {
                    if((2*dist)+2>r_idx-l_idx)
                    {
                        l_idx = idx-dist, r_idx = idx+dist+1;
                    }
                    break;
                }
            }
        
            // palindrome with only 1 'central character' i.e. 'aba'
            for(size_t dist = 0; dist<s.length() ; dist++)
            {

                if(charAt(idx-dist)!=charAt(idx+dist))
                {
                    if((2*dist)+1>r_idx-l_idx)
                    {                        
                        l_idx = idx-dist, r_idx = idx+dist;
                    }
                    break;
                }

            }        

        }
        

        // remember: indices delineate longest found palindrome
        return s.substr(l_idx, r_idx-l_idx);

    }    

};

int main()
{
    Solution solver;
    std::cout<<solver.longestPalindrome("abba")<<std::endl;
}