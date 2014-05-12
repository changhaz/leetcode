#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
		vector<int> prefixarr = buildprefixarr(needle);
		int hlen = strlen(haystack);
		int nlen = strlen(needle);

		int j = 0;
		int i = 0;
		int iori = 0;
		cout<<"nlen: "<<nlen<<endl;
		while (i <= hlen-nlen) {
			while (j < nlen && haystack[i+j] == needle[j])
				j++;
			if (j == nlen)
				return haystack+i;
			if (j > 0) {
				i += j - (prefixarr[j-1]+1);
				j = prefixarr[j-1] + 1;
			}
			else
				i++;
		}
		return NULL;
	}

	vector<int> buildprefixarr(char* c) {
		int clen = strlen(c);
		vector<int> prefixarr(clen,-1);
		
		int j = 0; // length of the longest match

		for (int i = 1; i < clen; i++) {
			if (c[i] == c[j]) {
				prefixarr[i] = j;
				j++;
			} else if (j == 0) {
				continue;
			} else {
				// if not match, decide what is the proper j
				j = prefixarr[j-1]+1;
				i--; // keep i unchanged
			}
		}
		return prefixarr;
	}
};

int main() {
	char* sa = "ababaca";
	char* sb = "ababababacad";
	Solution s;
	char* out = s.strStr(sb,sa);
	for (int i=0;i<strlen(out);i++)
		cout<<out[i]<<" ";
	return 0;
}
