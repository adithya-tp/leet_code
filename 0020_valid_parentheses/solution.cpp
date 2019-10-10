class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, bool> opening{
                {'{', true},
                {'[', true},
                {'(', true}
        };
        unordered_map<char, char> open_close{
                {'{', '}'},
                {'[', ']'},
                {'(', ')'}
        };
        stack<char> stk;
        int count = 0;
        for(char& i : s){
            if(!(opening.find(i) == opening.end())){
                stk.push(i);
                count++;
            }
            else{
                if(!stk.empty()){
                    char h = stk.top();
                    stk.pop();
                    count--;
                    //if closing bracket doesn't match, return false
                    if(!(i == open_close.at(h))){
                        cout << "Unbalanced!" << endl;
                        return false;
                    }

                }
                else{
                    cout << "Unbalanced!" << endl;
                    return false;
                }
            }
        }
        if(count == 0){
            cout << "Balanced!" << endl;
            return true;
        }
        else{
            cout << "Unbalanced" << endl;
            return false;
        }
    }
};
