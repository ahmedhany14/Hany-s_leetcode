class Solution {
public:

    bool is_vowel(char a){
        return a == 'a' | a == 'e' | a == 'i' | a == 'o' | a == 'u'; 
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size() + 1);
        for(int i = 0; i < words.size(); ++i)
            prefix[i + 1] = prefix[i] + (is_vowel(words[i][0]) & is_vowel(words[i].back()));

        vector<int> answer;
        for(auto q: queries){
            int l = q[0], r = q[1] + 1;
            answer.push_back(prefix[r] - prefix[l]);
        }

        return answer;
    }
};