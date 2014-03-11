#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
using namespace std;

vector<string> specialsort(vector<string> sv)
{
	map<string, list<string> > mymap;
	for (vector<string>::iterator iter = sv.begin(); iter != sv.end(); iter++) {
		string s = *iter;
		string ssort = s;
		sort(ssort.begin(),ssort.end());
		if (mymap.find(ssort) != mymap.end()){
			mymap[ssort].push_back(s);
		} else {
			list<string> templist;
			templist.push_back(s);
			mymap[ssort] = templist;
		}
	}
	
	vector<string> out;
	for (map<string,list<string> >::iterator iter = mymap.begin(); iter != mymap.end(); iter++) {
		list<string> templist = iter->second;
		for (list<string>::iterator it = templist.begin(); it != templist.end(); it++)
		{
			out.push_back(*it);
		}
	}
	
	return out;
}
int main()
{
	const char* ca[] = {"abc","cba","bc","a","z","abcd","dcba"};
	vector<string> v(ca, ca+7);
	vector<string> outv = specialsort(v);
	for (vector<string>::iterator it = outv.begin(); it != outv.end(); it++)
		cout << *it << endl;
	cout << "end" <<endl;
	return 0;
}
