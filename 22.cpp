#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        
        // - write each combination to buffer
        std::string buf(n*2, '.');
        
        // - store each combination
        std::vector<std::string> combinations;

        // 'initialise' the sequence
        // buf[idx] = '.'; 
        
        // open_br in bufcan be most 'n'
        int open_brs = n;

        // close_br must not exceed open_br in buf
        int close_brs = 0;

        // traver through buf
        int idx = 0;

        while(true)
        {
            // std::cout<<"idx: ["<<i<<"], writes: ["<<writes<<"]"<<", buffer is: "<<buf<<std::endl;

            // debug line:
            // if(i>=6) exit(1);
            
            // work is done when 'idx' is negative
            if(idx<0) break;

            // start padding routine
            if(open_brs<=0)
            {
                auto copy = buf;

                // can safely and lazily add ')' chars here
                for(unsigned int copy_idx = idx; copy_idx<copy.length(); copy_idx++)
                {
                    copy[copy_idx] = ')';
                }
                
                combinations.push_back(copy);
                idx--;
            }

            // initialize value here
            else if(buf[idx]=='.')
            {                  
                buf[idx] = '(';
                open_brs -= 1;
                close_brs += 1;
                idx++;
            }

            // if already wrote '(', write ')' and advance
            else if(buf[idx]=='(')
            {
                // '(' is changed indiscriminately
                open_brs += 1;
                close_brs -= 1;

                // if can, write closing bracket
                if(close_brs>0)
                {
                    buf[idx] = ')';
                    close_brs--;
                    idx++;
                }

                else // step back (all forward paths exhausted)
                {
                    buf[idx] = '.';
                    idx--;
                }                
            }
       
            else if(buf[idx]==')')
            {
                // '(' is changed indiscriminately
                close_brs += 1;

                // no paths left
                idx--;
            }

        }
        
        return combinations;
        
    }
};

int main()
{
    Solution driver;
    auto combos = driver.generateParenthesis(3);
    std::for_each(combos.begin(), combos.end(), [](const std::string& str)
    {
        std::cout<<str<<" ";
    });
    std::cout<<'\n';
}