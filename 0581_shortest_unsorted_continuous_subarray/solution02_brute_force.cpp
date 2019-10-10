#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v = {2,1};
    int r = 0, l = v.size();
    for(int i = 0; i < v.size() - 1; i++){
	for(int j = i + 1; j < v.size(); j++){
	    if(v[j] < v[i]){
		r = max(j, r);
		l = min(i, l);
	    }
	}
    }
    int res = (r - l) < 0 ? 0 : r - l + 1;
    cout << res << endl;
    return 0;
}
