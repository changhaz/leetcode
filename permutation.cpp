#include<iostream>
#include<cstring>

using namespace std;

void doPermutation(char* in, int index, bool* b, char* out)
{
    int len = strlen(in);
	
	if(index == len) {
		cout<<out<<endl;
		return;
	}

    char thisC = in[index];

	for (int i=0; i<len; i++) {
		if (!b[i]) {
			out[i] = thisC;
			b[i] = true;
			doPermutation(in, index+1, b, out);
			b[i] = false;
		}
	}
}

int main()
{
	char* in = new char[10];
	strcpy(in,"abcd");
	int len = strlen(in);
	bool* b = new bool[len];
	for (int i=0;i<len;i++) {
		b[i] = false;
	}
	char* out = new char[len];

	doPermutation(in,0,b,out);
}
