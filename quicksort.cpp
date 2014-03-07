#include <iostream>

using namespace std;

void quicksort(int* a, int start, int end)
{
	if (start >= end)
		return;

	int pivot = a[(start + end)/2];
	
	int is = start;
	int ie = end;

	while (is < ie) {
		while (a[is] < pivot)
			is++;
		while (a[ie] > pivot)
			ie--;
		if (is < ie) {
			int temp = a[is];
			a[is] = a[ie];
			a[ie] = temp;
		}
	}
	
	quicksort(a, start, is-1);
	quicksort(a, is+1, end);
}

int main()
{
	int a[9] = {2,6,4,9,3,1,5,8,7};
	int len = sizeof(a)/sizeof(*a);
	quicksort(a, 0, len-1);
	for (int i=0; i<len; i++)
		cout<<a[i]<<endl;
}
