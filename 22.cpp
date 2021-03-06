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

        // traverse through buf
        int idx = 0, direction = 1;

        while(true)
        {
            std::cout<<"idx: ["<<idx<<"], open_brackets left: ["<<open_brs<<"], closing brackets left: ["<<close_brs<<"], buffer is: "<<buf<<std::endl;

            // debug line:
            // if(i>=6) exit(1);
            
            // work is done when 'idx' is negative
            if(idx<0) break;

            // start padding routine IFF was traversing forward
            if((direction>0)&&open_brs<=0)
            {
                auto copy = buf;

                // can safely and lazily add ')' chars here
                for(unsigned int copy_idx = idx; copy_idx<copy.length(); copy_idx++)
                {
                    copy[copy_idx] = ')';
                }
                
                // debug:
                std::cout<<"sending string: "<<copy<<'\n';

                combinations.push_back(copy);
                direction = -1;
            }

            // initialize value here
            else if(buf[idx]=='.')
            {                  
                buf[idx] = '(';
                open_brs -= 1;
                close_brs += 1;
                direction = 1;
            }

            // if already wrote '(', write ')' and advance
            else if(buf[idx]=='(')
            {
                // '(' is changed indiscriminately
                open_brs++;
                close_brs--;

                // if can, write closing bracket
                if(close_brs>0)
                {
                    buf[idx] = ')';
                    close_brs--;
                    direction = 1;
                }

                else // step back (all forward paths exhausted)
                {
                    buf[idx] = '.';
                    direction = -1;
                }                
            }
       
            else if(buf[idx]==')')
            {
                // '(' is changed indiscriminately
                close_brs += 1;

                // 'reset' char at this idx to 'empty'
                buf[idx] = '.';

                // no paths left
                direction = -1;
            }

            // direction should have been set in any of previous if cases
            idx += direction;

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