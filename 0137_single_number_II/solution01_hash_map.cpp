#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> v = {0,1,0,1,0,1,99};
    unordered_map<int, int> counts;
    for(int i=0; i < v.size(); i++){
	counts[v[i]]++;
    }
    for(int i : v){
	if(counts[i] == 1){
	    cout << i <<  endl;
	    return 0;
	}
    }
}
