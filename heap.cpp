#include <vector>
#include <iostream>

#define left(i) i*2
#define right(i) i*2+1

using namespace std;

class myheap {
public:
	vector<int> array;
	int heapsize;
	void heapify(int i);
	void buildheap(vector<int> v);
	void printheap() {
		cout<<"current heap: ";
		for (int i=1;i<=heapsize;i++) {
			cout<<array[i]<<" ";
		}
		cout<<endl;
	}
};

void myheap::heapify(int i)
{
	int maxi = i;
	if (left(i)<=heapsize && array[i]<array[left(i)]) {
		maxi = left(i);
	}
	if (right(i)<=heapsize && array[maxi]<array[right(i)]) {
		maxi = right(i);
	}
	if (maxi != i) {
		swap(array[i],array[maxi]);
		printheap();
		heapify(maxi);
	}
}

void myheap::buildheap(vector<int> v)
{
	array = v;
	array.insert(array.begin(),0);
	heapsize = array.size()-1;
	for (int i=heapsize/2; i>=1; i--) {
		// cout<<"heapify "<<i<<endl;
		heapify(i);
	}
}

vector<int> heapsort(vector<int> vi) {
	myheap h;
	h.buildheap(vi);
	h.printheap();
	vector<int> out;
	
	while (h.heapsize>0) {
		cout<<"push to output: "<<h.array[1]<<endl;
		out.push_back(h.array[1]);
		swap(h.array[1],h.array[h.heapsize]);
		h.heapsize--;
		h.heapify(1);
		h.printheap();
	}
	return out;
}

int main() {
	static const int a[] = {4,3,1,2,5,7,6,8};
	vector<int> v(a,a+sizeof(a)/sizeof(int));
	vector<int> out = heapsort(v);

	cout<<"output: ";
	for (int i=0;i<out.size();i++) {
		cout<<out[i]<<" ";	
	}
	cout<<endl;
	return 0;
}
