class Pair {
    public:
    int x, y, t;
    Pair(int x, int y, int t) {
        this->x = x;
        this->y = y;
        this->t = t;
    }
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<Pair> q;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    q.push(Pair(i, j, 0));
                }
            }
        }

        int ans = 0;
        
        while(!q.empty()) {
            Pair pair = q.front();
            q.pop();

            int curr_x = pair.x;
            int curr_y = pair.y;
            int curr_time = pair.t;

            if(curr_x - 1 >= 0 && grid[curr_x - 1][curr_y] == 1) {
                grid[curr_x - 1][curr_y] = 2;
                q.push(Pair(curr_x - 1, curr_y, curr_time + 1));
                ans = curr_time + 1;
            }

            if(curr_x + 1 < rows && grid[curr_x + 1][curr_y] == 1) {
                grid[curr_x + 1][curr_y] = 2;
                q.push(Pair(curr_x + 1, curr_y, curr_time + 1));
                ans = curr_time + 1;
            }

            if(curr_y - 1 >= 0 && grid[curr_x][curr_y - 1] == 1) {
                grid[curr_x][curr_y - 1] = 2;
                q.push(Pair(curr_x, curr_y - 1, curr_time + 1));
                ans = curr_time + 1;
            }

            if(curr_y + 1 < cols && grid[curr_x][curr_y + 1] == 1) {
                grid[curr_x][curr_y + 1] = 2;
                q.push(Pair(curr_x, curr_y + 1, curr_time + 1));
                ans = curr_time + 1;
            }
        }

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return ans;
    }
};