#include <vector>
#include <iostream>

using namespace std;

int getdigit(int i, int d)
{
	while (d > 1) {
		d--;
		i/=10;
	}

	return i%10;
}

int getnumofdigit(int i)
{
	int d = 0;
	while(i) {
		i/=10;
		d++;
	}
	return d;
}

void countingsort(vector<int> &vi, int d)
{
	vector<int> out(vi.size(),0);
	vector<int> c(10,0); // 0 to 9
	
	for (int i=0;i<vi.size();i++) {
		c[getdigit(vi[i],d)]++;
	}
	// c[i] now contains the number of elements equal to i.
		
	for (int i=1;i<10;i++) {
		c[i] += c[i-1];
	}
	// c[i] now contains the number of elements less than or equal to i
	
	for (int i=vi.size()-1;i>=0;i--) {
		out[c[getdigit(vi[i],d)]-1] = vi[i];
		c[getdigit(vi[i],d)]--;
	}
	vi = out;
}

void radixsort(vector<int> &vi)
{
	// first assume all int have same number of digits
	int d = getnumofdigit(vi[0]);
	for (int i=1;i<=d;i++) {
		countingsort(vi,i);
	}
}

int main()
{
	int a[] = {329,457,657,839,436,720,355};
	vector<int> vi(a,a+sizeof(a)/sizeof(a[0]));
	radixsort(vi);
	for (int i=0;i<vi.size();i++) {
		cout<<vi[i]<<" ";
	}
	cout<<endl;
	return 0;
}

