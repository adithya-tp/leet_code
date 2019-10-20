class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        long long m_num, m_denom, new_m_num, new_m_denom;
        m_num = (c[1][1] - c[0][1]);
        m_denom = (c[1][0] - c[0][0]);
        for(int i = 1; i < c.size() - 1; i++){
            new_m_num = (c[i+1][1] - c[i][1]);
            new_m_denom = (c[i+1][0] - c[i][0]);
            if(new_m_denom * m_num != new_m_num * m_denom)
                return false;
        }
        return true;
        
    }
};
