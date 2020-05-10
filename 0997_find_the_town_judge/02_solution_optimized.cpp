// If you are trusted by N - 1 people and you trust no people then you are the judge
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trusted(N + 1, 0);
        for(vector<int> pair : trust) {
            trusted[pair[1]]++;
            trusted[pair[0]]--;
        }
        for(int i = 1; i <= N; i++) {
            if(trusted[i] == N - 1)
                return i;
        }
        return -1;
    }
};
