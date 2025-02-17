class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        string sub = "";
        set<string> ret;
        for (int mask = 0; mask < (1 << n); mask++) {
            sub.clear();
            for (int i = 0; i < n; i++)if (mask & (1 << i)){
                sub.push_back(tiles[i]);
            }
            sort(sub.begin(), sub.end());
            do {
                ret.insert(sub);
            } while(next_permutation(sub.begin(), sub.end()));
        }
        return ret.size() - 1;    
    }
};