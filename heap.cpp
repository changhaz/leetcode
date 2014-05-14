#include <vector>
#include <iostream>

#define left(i) i*2
#define right(i) i*2+1
#define parent(i) i/2

using namespace std;

class myheap {
public:
	vector<int> array;
	int heapsize;
	myheap() {
		array.push_back(0);
		heapsize = 0;
	}
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

class priorityq {
public:
	myheap h;
	void insert(int i);
	int maximum();
	int extractMax();
	void increaseKey(int i, int k);
};

void priorityq::insert(int i) {
	h.heapsize++;
	h.array.push_back(i);
	
	int j = h.heapsize;
	while (parent(j)>0 && h.array[parent(j)]<h.array[j]) {
		swap(h.array[parent(j)],h.array[j]);
		j = parent(j);
	}	
}

int priorityq::maximum() {
	if (h.heapsize <= 0) return -1;
	return h.array[1];
}

int priorityq::extractMax() {
	if (h.heapsize <= 0) return -1;
	int out = h.array[1];
	swap(h.array[1], h.array[h.heapsize]);
	h.heapsize--;
	h.heapify(1);
	return out;
}

void priorityq::increaseKey(int i, int k) {
	h.array[i] = k;
	while (parent(i)>0 && h.array[parent(i)]<h.array[i]) {
		swap(h.array[parent(i)],h.array[i]);
		i = parent(i);
	}
}

int main() {
/*
	test for heapsort 

	static const int a[] = {4,3,1,2,5,7,6,8};
	vector<int> v(a,a+sizeof(a)/sizeof(int));
	vector<int> out = heapsort(v);

	cout<<"output: ";
	for (int i=0;i<out.size();i++) {
		cout<<out[i]<<" ";	
	}
	cout<<endl;
*/
	priorityq pq;
	pq.insert(6);
	pq.insert(3);
	pq.insert(9);
	pq.insert(-10);
	pq.insert(1);
	
	cout << "max: "<<pq.maximum()<<endl;
	pq.extractMax();
	cout << "max: "<<pq.maximum()<<endl;
	
	pq.increaseKey(3,100);
	cout << "max: "<<pq.maximum()<<endl;

	return 0;
}
