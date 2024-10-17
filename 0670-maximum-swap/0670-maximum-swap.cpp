class Solution {
public:
    int maximumSwap(int num) {
        string a = to_string(num), mx = a;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = i + 1; j < a.size(); ++j) {
                swap(a[i], a[j]);
                mx = max(mx, a);
                swap(a[i], a[j]);
            }
        }
        return stoi(mx);
    }
};