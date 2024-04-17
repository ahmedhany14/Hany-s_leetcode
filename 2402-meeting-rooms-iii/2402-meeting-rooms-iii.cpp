class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        auto comp = [&](const array<long long, 2>& a, const array<long long, 2>& b) {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] > b[0];
        };
        priority_queue<array<long long, 2>, vector<array<long long, 2>>, decltype(comp)> busy_rooms(comp);
        priority_queue<int, vector<int>, greater<int>> free_rooms;
        unordered_map<int, int> room_used;
        long long most_used = 0, most_used_room = 0;
        for(int room = 0; room < n; room++)
            free_rooms.push(room);
        for(auto meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            while(!busy_rooms.empty() && busy_rooms.top()[0] <= start) {
                int room = busy_rooms.top()[1];
                busy_rooms.pop();
                free_rooms.push(room);
            }
            if(!free_rooms.empty()) {
                int room = free_rooms.top();
                free_rooms.pop();
                busy_rooms.push({end, room});
                ++room_used[room];
            } 
            else {
                auto [meeting_end, room] = busy_rooms.top();
                busy_rooms.pop();
                ++room_used[room];
                int duration = end - start;
                busy_rooms.push({meeting_end + duration, room});
            }
        }
        for(auto [room, used]: room_used) {
            if(used > most_used ||
              (used == most_used && room < most_used_room)) {
                most_used = room_used[room];
                most_used_room = room;
            }
        }
        return most_used_room;
    }
};