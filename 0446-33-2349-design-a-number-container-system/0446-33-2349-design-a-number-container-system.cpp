class NumberContainers {
public:

    NumberContainers() {
    }
    
    void change(int index, int number) {
        if(appears_index.find(index) != appears_index.end()){
            int last_appear = appears_index[index]; // constains number;
            idx[last_appear].erase(index);
            if(idx[last_appear].size() == 0) idx.erase(last_appear);
        }
        idx[number].insert(index); // add index
        appears_index[index] = number; // changed last number
    }
    
    int find(int number) {
        if(idx[number].size()) return *idx[number].begin();
        return -1;     
    }
private:
    unordered_map<int, int> appears_index;
    unordered_map<int, set<int>> idx;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */