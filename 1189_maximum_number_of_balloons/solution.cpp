class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> text_dict;
        int times = 0, times2 = 0;
        for(char c : text){
            text_dict[c]++;
        }
        times = min(text_dict['b'], text_dict['a']);
        times = min(times, text_dict['n']);
        times2 = min(text_dict['l'], text_dict['o']);
        if(times == 0 || times2 == 0)
            return 0;
        times2 = (times2 % 2 == 0) ? (times2 / 2) : (times2 - 1) / 2;   
        return min(times, times2);
    }
};
