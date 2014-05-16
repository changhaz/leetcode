#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void qsort(vector<int> &a, int si, int ei)
{
	if (si >= ei)
		return;

	int ir = (rand() % (ei-si+1)) + si;
	swap(a[ir], a[ei]);

	int i = si-1;
	for (int j=si; j<ei; j++) {
		if (a[j]<a[ei]) {
			i++;
			swap(a[i], a[j]);
		}
	}

	i++;
	swap(a[i], a[ei]);

	qsort(a, si, i-1);
	qsort(a, i+1, ei);
}

int main()
{
	//int a[] = {2,8,7,1,3,5,6,4};
	//int a[] = {2,8,6,6,8,1,5,7,2,1,4,4,3,5,6,4};
	int a[] = {2,2,2,2,2,2,2,2,2,8};

	vector<int> v(a, a+sizeof(a)/sizeof(int));
	qsort(v, 0, v.size()-1);
	
	for (int i=0;i<v.size();i++) {
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
