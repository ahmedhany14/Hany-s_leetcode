class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> f1, f2;
        for(auto &i : arr1){
            string a = to_string(i), b = "";
            for(auto c: a){
                b += c;
                f1[b] = 1;
            }
        }
        for(auto &i : arr2){
            string a = to_string(i), b = "";
            for(auto c: a){
                b += c;
                f2[b] = 1;
            }
        }
        
        int answer = 0;
        
        for(auto &i : arr1){
            string a = to_string(i), b = "";
            for(auto c: a){
                b += c;
                if(f2[b]) answer = max(answer, int(b.size()));
            }
        }
        for(auto &i : arr2){
            string a = to_string(i), b = "";
            for(auto c: a){
                b += c;
                if(f1[b]) answer = max(answer, int(b.size()));
            }
        }
        return answer;
    }
};