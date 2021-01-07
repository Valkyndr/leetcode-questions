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
            // debug line:
            if(i>=6) exit(1);

            // negative index indicates all paths travelled
            if(i<0) break;

            // end reached if no writes left
            if(writes<=0)
            {                
                for(unsigned int idx = i; idx<buf.length(); idx++) { buf[idx] = ')'; }
                combinations.push_back(buf);
                for(unsigned int idx = i; idx<buf.length(); idx++) { buf[idx] = '.'; }
                
                buf[i] = '.';
                writes++;
                i--;
            }
            
            else if(buf[i]=='.')
            {
                std::cout<<"writes is: "<<writes<<std::endl;
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
                writes++;
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