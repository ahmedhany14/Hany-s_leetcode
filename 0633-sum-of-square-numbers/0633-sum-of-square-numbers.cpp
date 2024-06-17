class Solution {
public:
    bool judgeSquareSum(int c) {
        set<long long> sq;
        for(long long i = 0; i * i <= c; ++i) sq.insert(i * i);
        for(auto i : sq) if(sq.find(c - i) != sq.end()) return 1;
        return 0;
    }
};