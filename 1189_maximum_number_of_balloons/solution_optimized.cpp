class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> text_dict;
        for(char c : text){
            text_dict[c]++;
        }
        return min(text_dict['b'], min(text_dict['a'], min(text_dict['n'], min(text_dict['l'] / 2, text_dict['o'] / 2))));
    }
};
