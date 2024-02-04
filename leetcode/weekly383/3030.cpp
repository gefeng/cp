#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

constexpr std::array<int, 4> DR = {0, 1, 0, -1};
constexpr std::array<int, 4> DC = {1, 0, -1, 0};

class Solution {
public:
    std::vector<std::vector<int>> resultGrid(std::vector<std::vector<int>>& image, int threshold) {
        int n = image.size();
        int m = image[0].size();
        std::vector<std::vector<std::pair<int, int>>> save(n, std::vector<std::pair<int, int>>(m, {0, 0}));
        std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
    
        for(int i = 0; i <= n - 3; i++) {
            for(int j = 0; j <= m - 3; j++) {
                bool ok = true;
                for(int r = 0; r < 3; r++) {
                    for(int c = 0; c < 3; c++) {
                        int x = i + r;
                        int y = j + c;
                        for(int d = 0; d < 4; d++) {
                            int nx = x + DR[d];
                            int ny = y + DC[d];
                            if(nx >= i && nx < i + 3 && ny >= j && ny < j + 3) {
                                if(std::abs(image[x][y] - image[nx][ny]) > threshold) {
                                    ok = false;
                                }
                            }
                        }
                    }
                }
                
                if(!ok) {
                    continue;
                }
                
                int sum = 0;
                for(int r = 0; r < 3; r++) {
                    for(int c = 0; c < 3; c++) {
                        int x = i + r;
                        int y = j + c;
                        sum += image[x][y];
                    }
                }
                
                for(int r = 0; r < 3; r++) {
                    for(int c = 0; c < 3; c++) {
                        int x = i + r;
                        int y = j + c;
                        save[x][y].first += sum / 9;
                        save[x][y].second += 1;
                    }
                }
            }
        }  
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(save[i][j].second == 0) {
                    ans[i][j] = image[i][j];
                } else {
                    ans[i][j] = save[i][j].first / save[i][j].second;
                }
            }
        }
        
        return ans;
    }
};
