class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ones = 0;
        while(num2) ones += num2 & 1, num2 >>= 1LL;
        int mask = 0;
        for(int bit = 30; ~bit && ones; --bit) {
            if(num1 & (1LL << bit)) {
                mask |= (1LL << bit);
                --ones;
            }
        }

        for(int bit = 0; bit <= 30 && ones; ++bit) {
            if(!(mask & (1LL << bit))){
                mask |= (1LL << bit);
                --ones;
            }
        }
        return mask;
    }
};