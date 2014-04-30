#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool dividendneg = false;
        bool divisorneg = false;
        
        if (dividend<0) {
            dividendneg = true;
            dividend = -dividend;
        }
        
        if (divisor<0) {
            divisorneg = true;
            divisor = -divisor;
        }
        
        int out=0;
        while (dividend>0) {
			cout<<"divisor start from original."<<endl;
			cout<<"dividend: "<<dividend<<endl;
			cout<<"out: "<<out<<endl;
            
			int outadd = 1;
            int timedivisor = divisor;
            while (dividend>=timedivisor) {
				cout<<"add "<<outadd<<" to output"<<endl;
                out+=outadd;
                dividend -= timedivisor;
                outadd = outadd + outadd;
                timedivisor = timedivisor + timedivisor;
				if (timedivisor<0) {
					break;
				}
            }
            
            if (dividend < divisor) {
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



