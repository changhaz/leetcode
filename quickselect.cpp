#include <vector>
#include <iostream>
#include <stdlib.h>
using namespace std;

int partition(vector<int> &vi, int starti, int endi)
{
	swap(vi[starti+rand()%(endi-starti+1)],vi[endi]);
	int i = starti-1;
	for (int j=starti; j<endi; j++) {
		if (vi[j] < vi[endi]) {
			i++;
			swap(vi[i], vi[j]);
		}
	}
	i++;
	swap(vi[i], vi[endi]);
	return i;
}

void printvector(vector<int> v)
{
	for (int i=0;i<v.size();i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int quickselect(vector<int> vi, int starti, int endi, int k)
{
	int m = partition(vi, starti, endi);
	cout<<"m = "<<m<<" starti = "<<starti<<" endi = "<<endi<<" k = "<<k<<endl;
	printvector(vi);
	if (k == m)
		return vi[m];
	if (k < m) {
		return quickselect(vi, starti, m-1, k);
	} else {
		return quickselect(vi, m+1, endi, k);
	}
}

int main()
{
	int a[] = {2,8,7,0,1,3,5,6,4,9};
	vector<int> vi(a,a+sizeof(a)/sizeof(a[0]));
	int out = quickselect(vi, 0, vi.size()-1, 8);
	cout<<"answer: "<<out<<endl;
	return 0;
}
