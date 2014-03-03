#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

void printSubset(char* in, int level, int currentlen, char* out)
{
    if(level==strlen(in)) {
        for (int i=0;i<currentlen;i++){
            cout<<out[i];
	}
	cout<<endl;
	return;
    }


        

    out[currentlen] = in[level];
    printSubset(in,level+1,currentlen+1,out);
    printSubset(in,level+1,currentlen,out);
}

int main()
{
    char* in = "abcde";
    int len = strlen(in);
    char* out = new char[len];
    printSubset(in,0,0,out);    

    return 0;
}
