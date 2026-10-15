class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 方向陣列：依序為 北、東、南、西
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        // 將障礙物放入 unordered_set 中，方便以 O(1) 的時間複雜度進行查詢
        // 為了將座標 (x, y) 壓入 set，可以使用字串組合或自定義 hash，最簡單的是將其組合成一個 long long
        auto hash_fn = [](const vector<int>& obs) -> long long {
            return ((long long)(obs[0] + 30000) << 16) ^ (obs[1] + 30000);
        };
        
        unordered_set<long long> obstacle_set;
        for (const auto& obs : obstacles) {
            obstacle_set.insert(hash_fn(obs));
        }
        
        int x = 0, y = 0;
        int dir = 0; // 0: 北, 1: 東, 2: 南, 3: 西
        int max_dist_sq = 0;
        
        for (int cmd : commands) {
            if (cmd == -2) {
                // 向左轉 90 度
                dir = (dir + 3) % 4;
            } else if (cmd == -1) {
                // 向右轉 90 度
                dir = (dir + 1) % 4;
            } else {
                // 前進 cmd 步，一步一步走以檢查障礙物
                for (int i = 0; i < cmd; ++i) {
                    int next_x = x + dx[dir];
                    int next_y = y + dy[dir];
                    
                    vector<int> next_pos = {next_x, next_y};
                    if (obstacle_set.count(hash_fn(next_pos))) {
                        // 遇到障礙物，停止前進
                        break;
                    }
                    
                    x = next_x;
                    y = next_y;
                    max_dist_sq = max(max_dist_sq, x * x + y * y);
                }
            }
        }
        
        return max_dist_sq;
    }
};