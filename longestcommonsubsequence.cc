#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<vector<int> > buildArray(vector<char> s1, vector<char> s2)
{
	vector<vector<int> > out;
	for (int i=0;i<s1.size();i++) {
		vector<int> temp(s2.size(),0);
		out.push_back(temp);
	}
	
	for (int i=0;i<s1.size();i++) {
		for (int j=0;j<s2.size();j++) {
			if (s1[i] == s2[j]) {
				out[i][j] = (i==0||j==0)? 1:1+out[i-1][j-1];
			} else {
				out[i][j] = max(j==0? 0:out[i][j-1], i==0? 0:out[i-1][j]);
			}
		}
	}
	return out;
}

void printResult(vector<vector<int> > &v, vector<char> s1, vector<char> s2)
{
	stack<char> output;
	int i = s1.size()-1;
	int j = s2.size()-1;
	
	while (i>0 && j>0) {
		//cout<<"i: "<<i<<" j: "<<j<<endl;
		if (s1[i] == s2[j]) {
			output.push(s1[i]);
			i--;
			j--;
		} else if (v[i][j-1] > v[i-1][j]) {
			j--;
		} else {
			i--;
		}
	}
	
	if (s1[i] == s2[j])
		output.push(s2[j]);

	while (!output.empty()) {
		cout<<output.top()<<" ";
		output.pop();
	}
	cout<<endl;
}

int main()
{
	char a[] = "ABCBDAB";
	char b[] = "BDCABA";
	vector<char> va(a,a+sizeof(a)/sizeof(a[0])-1);
	vector<char> vb(b,b+sizeof(b)/sizeof(b[0])-1);
	
	vector<vector<int> > vvi = buildArray(va,vb);
	printResult(vvi,va,vb);
	
	cout<<"table: "<<endl;
	for (int i=0;i<vvi.size();i++) {
		for (int j=0;j<vvi[0].size();j++) {
			cout<<vvi[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
