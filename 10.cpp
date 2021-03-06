#include<iostream>
#include<string>
using namespace std;

class Solution {
    
    public:
    
    bool isMatch(string s, string p) {
    
        // traverse through input string
        auto itr = s.begin();
        
        for(unsigned int idx = 0; idx<p.length(); idx++)
        {
            // - '*' is not a 'hard-value'
            if(p[idx]=='*') continue;

            // return false if itr reaches end here! (since regexes yet remain, but no characters left)
            if(itr>=s.end()) return false;

            // start repeater routine if next char is '*'
            if(idx+1<p.length()&&(p[idx+1]=='*'))
            {
                // declare terminator
                char stop = '\0';
                
                // set stop_idx as first non-hard-value character
                for(unsigned int stop_idx=idx+2; stop_idx<p.length(); stop_idx++)
                {
                    if(p[stop_idx]!='*'&&p[stop_idx]!='.')
                    {
                        stop = p[stop_idx];
                        break;
                    }
                }
             
                // debug: 
                std::cout<<"regex is: "<<p[idx]<<", stop is: "<<stop;
                std::cout<<", iterator at: "<<itr-s.begin()<<std::endl;

                // special case: if stop character is same as repeating regex
                if(p[idx]==stop)
                {
                    // number of characters to not consume
                    unsigned int reserve_size = 0; 
                                    
                    // look ahead at how many regexes to reserve for
                    for(unsigned int look_idx = idx+2; look_idx<p.length(); look_idx++)
                    {
                        if(p[look_idx]!=stop) break; // only look at characters equal need reserve for
                        reserve_size++;
                    }

                    // define consumption here
                    while(itr!=s.end())
                    {   
                        // quit as soon as consuming a character leaves not enough characters to consume
                        if(itr+reserve_size>=s.end()&&*(itr+reserve_size)!=stop) break;
                        std::advance(itr, 1);                    
                    }

                    // rest of routine can be skipped
                    continue;
                }

                // 'consume' characters from input until found terminating character (i.e. 'stop')
                while(itr!=s.end())
                {   
                    if(*itr==stop) break;
                    if(p[idx]!='.'&&(p[idx]!=*itr)) break;
                    std::advance(itr, 1);
                }
            }
            
            else // match only a single character
            {                
                // MUST fail if not a match here
                // (also remember '.' matches all)
                if(p[idx]==*itr||p[idx]=='.')
                    std::advance(itr, 1);
                else
                {                    
                    return false;
                }
            }
        }

        // if itr is not at end, there remain unconsumed characters
        return (itr==s.end());
        
    }
};

int main()
{
    Solution driver;
    std::cout<<driver.isMatch("aaa", "ab*a*c*a")<<std::endl;
}