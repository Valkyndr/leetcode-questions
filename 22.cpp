#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    
    vector<string> generateParenthesis(int n) {
        
        // - write each combination to buffer
        std::string buf(n*2, '.');
        int i = 0;
        
        // - store each combination
        std::vector<std::string> combinations;
        
        // - store no. of 'moves' can make
        int writes = n;
        
        // 'initialise' the sequence
        buf[i] = '.'; 
        
        while(true)
        {
            std::cout<<"idx is: "<<i<<std::endl;        
            if(i>=6) i--;
            // if(i>=6) exit(1);

            // - negative index indicates all paths travelled
            if(i<0) break;
            std::cout<<buf[i]<<std::endl;
            std::cout<<"buf is: "<<buf<<std::endl;

            // end reached if no writes left
            if(writes==0)
            {                
                for(unsigned int idx = i; idx<buf.length(); idx++) { buf[idx] = ')'; }
                combinations.push_back(buf);
                for(unsigned int idx = i; idx<buf.length(); idx++) { buf[idx] = '.'; }
                
                buf[i] = '.';
                writes--;
                i--;
            }
            
            else if(buf[i]=='.')
            {
                buf[i] = '(';
                writes--;
                i++;
            }
        
            else if(buf[i]=='(')
            {
                buf[i]==')';
                i++;
            }
            
            else if(buf[i]==')')
            {
                buf[i]=='.';
                writes--;
                i--;
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