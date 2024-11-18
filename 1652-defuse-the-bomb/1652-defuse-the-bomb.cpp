class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ret(n, 0), frontStep(n + 1, 0), backStep(n, 0);
        for(int i = 0;i < n; ++i){
            frontStep[i] = i + 1;
        }
        frontStep[n - 1] = 0;
        for(int i = 1;i < n; ++i){
            backStep[i] = i - 1;
        }
        backStep[0] = n - 1;
        
        if(!k) return ret;
        int sign = k < 0 ? -1 : 1;
        for(int i = 0; i < n; ++i){
            int idx = k < 0 ? backStep[i] : frontStep[i];
            int answer = 0, steps = abs(k);
            while(steps--){
                answer += code[idx];
                idx = k < 0 ? backStep[idx] : frontStep[idx];
            }
            ret[i] = answer;
        }
        return ret;
    }
};