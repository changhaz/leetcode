#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool dividendneg = false;
        bool divisorneg = false;
        
        double a = dividend;
        double b = divisor;
        
        if (a<0) {
            dividendneg = true;
            a = -a;
        }
        
        if (b<0) {
            divisorneg = true;
            b = -b;
        }
        
        int out=0;
        while (a>0) {
            int outadd = 1;
            double timedivisor = b;
            while (a>=timedivisor) {
                out+=outadd;
                a -= timedivisor;
                outadd = outadd + outadd;
                timedivisor = timedivisor + timedivisor;
            }
            
            if (a < b) {
                break;
            }
        }
         
        if (dividendneg)
            out = -out;
        
        if (divisorneg)
            out = -out;
            
        return out;
        
    }
};

int main()
{
	Solution* s = new Solution();
	int out = s->divide(2147483647,1);
	cout<<"output: "<<out<<endl;
}



