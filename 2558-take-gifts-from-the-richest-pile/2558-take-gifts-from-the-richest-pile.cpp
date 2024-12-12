class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q;
        for(auto i : gifts) q.emplace(i);
        
        while(k--){
            int top = q.top();
            q.pop();
            q.emplace(int(sqrt(top)));
        }
        long long sum = 0;
        while(q.size()) sum += q.top(), q.pop();
        return sum;
    }
};