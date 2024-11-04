class Solution {
public:
    string compressedString(string word) {
        string answer = "";
        int i = 0 ;
        while(i < word.size()){
            int cnt = 0, j = i;
            while(cnt < 9 and i < word.size() and word[i] == word[j]) i++, cnt++;
            answer += to_string(cnt) + word[j];
        }
        return answer;
    }
};