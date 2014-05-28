#include <iostream>
#include <vector>

using namespace std;

int knapsack(vector<int> vi, vector<int> wi, int w)
{
	int n = vi.size();
	
	vector<vector<int> > vvi;
	vector<vector<int> > result;

	for (int i=0;i<=n;i++) {
		vector<int> temp(w+1,0);
		vvi.push_back(temp);
		result.push_back(temp);
	}

	for (int i=1;i<=n;i++) {
		for (int j=1;j<=w;j++) {
			if (wi[i-1]>j) {
				vvi[i][j] = vvi[i-1][j];
				continue;
			}
			cout<<"For item "<<i<<", weight "<<j<< ", if taken: "<<vvi[i-1][j-wi[i-1]]+vi[i-1]<<", if not taken: "<<vvi[i-1][j]<<endl;
			vvi[i][j] = max(vvi[i-1][j-wi[i-1]]+vi[i-1], vvi[i-1][j]);
			if (vvi[i][j] != vvi[i-1][j]) {
				// taken
				result[i][j] = 1;
			}
		}
	}
	
	// output result
	cout<<"result: ";
	int i = n;
	int j = w;
	while (i>=0) {
		if (result[i][j]) {
			cout<<"("<<vi[i-1]<<","<<wi[i-1]<<") ";
			j -= wi[i-1];
		}
		i--;
	}
	cout<<endl;
	return vvi[n][w];
}

int main()
{
	int v[] = {60,100,120};
	int w[] = {10,20,30};
	vector<int> vi(v,v+sizeof(v)/sizeof(v[0]));
	vector<int> wi(w,w+sizeof(w)/sizeof(w[0]));
	
	int out = knapsack(vi,wi,50);
	cout<<"max value: "<<out<<endl;
}
