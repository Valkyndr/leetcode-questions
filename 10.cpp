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

                // 'consume' characters from input until found terminating character (i.e. 'stop')
                while(itr!=s.end())
                {   
                    if(*itr==stop) 
                    {
                        if(itr+1<s.end())
                        {
                            std::cout<<"char is: "<<*(itr+1)<<std::endl;
                        }

                        // let repeater consume as many chars as possible
                        if(itr+1<s.end()&&*(itr+1)!=stop)
                        {
                            // let next sub-regex handle this otherwise
                            break; 
                        }                        
                    }

                    // else if(*itr!='.'&&*itr!=p[idx]) break;
                    // if(*itr=='.') std::cout<<"here!"<<std::endl; // dot '.' matches all characters
                    if(p[idx]!='.'&&(p[idx]!=*itr)) break;
                    std::cout<<"consuming: "<<*itr<<std::endl;
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
                    std::cout<<"iterator has landed at: "<<itr-s.begin()<<std::endl;
                    return false;
                }
            }
        }

        std::cout<<"iterator has landed at: "<<itr-s.begin()<<std::endl;

        // if itr is not at end, there remain unconsumed characters
        return (itr==s.end());
        
    }
};

int main()
{
    Solution driver;
    std::cout<<driver.isMatch("aaa", "a*a")<<std::endl;
}