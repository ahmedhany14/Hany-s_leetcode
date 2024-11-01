class Solution {
public:
    string makeFancyString(string s) {
        string answer;;
        answer.push_back(s[0]);
        int seg = 0;
        for(int i =  1; i < s.size(); ++i){
            if(answer.back() == s[i]){
                seg++;
                if(seg < 2)  answer.push_back(s[i]);           
            }
            else answer.push_back(s[i]), seg = 0;
        }
        return answer;
    }
};