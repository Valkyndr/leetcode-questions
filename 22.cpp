#include<iostream>
#include<string>
#include<vector>
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
            }

            else if(buf[idx]=='.')
            {
                open_brs -= 1;
                close_brs += 1;
                idx++;
            }
       
        }
        
        return combinations;
        
    }
};

int main()
{
    Solution driver;
    driver.generateParenthesis(3);
}