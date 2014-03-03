#include<iostream>
#include<string>
#include<vector>

using namespace std;

string insertBefore(string in, char c, int i)
{
	string before = in.substr(0,i);
	string after = in.substr(i);
	return before + c + after;
}

vector<string> getPerm(string str)
{
	vector<string> v;
	if(str.length()==0) {
		return v;
	}

    v = getPerm(str.substr(1));
	char c = str[0];

	vector<string> vout;

	if (v.empty()) {
		v.push_back(string(1,c));
		return v;
	}

	for (vector<string>::iterator it = v.begin(); it != v.end(); it++) {
		string temp;
		temp = *it;
		for(int i=0; i<temp.length()+1; i++){
			string tempout = insertBefore(temp,c,i);
			vout.push_back(tempout);
		}
	}
    return vout;
}



int main()
{
	vector<string> out = getPerm("12345");
	for (vector<string>::iterator iter = out.begin(); iter != out.end(); iter++)
	{
		cout<<*iter<<endl;
	}
}
