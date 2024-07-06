class Solution {
public:
    int passThePillow(int n, int time) {
        int cnt = 1, f = 1;
        while(time--){
            cnt += f;
            if(cnt == n) f = -1;
            if(cnt == 1) f = 1;
        }
        return cnt;
    }
};