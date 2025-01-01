class Solution {
public:
    int maxScore(string s) {
        int ones = 0, zeros = 0, answer = 0;
        for(auto a: s) ones += a == '1';

        for(int i = 0; i < s.size() - 1; ++i){
            ones -= s[i] == '1';
            zeros += s[i] == '0';
            answer = max(answer, ones + zeros);
        }

        return answer;
    }
};