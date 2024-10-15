class Solution {
public:
    long long minimumSteps(string s) {
        long long ones = 0, left = 0, right = (int) s.size() - 1, answer = 0;

        while (~right and s[right] == '1') --right;

        while (left <= right) {
            if (s[left] == '1')
                while (left <= right and s[left] == '1') ++left, ones++;
            else
                answer += ones, ++left;
        }
        return answer;
    }
};
