class Solution {
public:
    int minBitFlips(int start, int goal) {
        int bits = 0;
        while (start or goal) {
            bits += ((start & 1) != (goal & 1));
            start /= 2;
            goal /= 2;
        }
        return bits;
    }
};