#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using LL = long long;

constexpr int R1 = 20;
constexpr int R2 = 10000;

std::vector<std::vector<int>> A = {
    {72, 64, 51, 57, 93, 97, 68}, 
    {62}, 
    {57, 94, 69, 79, 72}, 
    {80, 64, 92, 93, 64, 56}, 
    {70, 88, 95, 99, 78, 72, 65, 94}, 
    {57, 95, 81, 61}, 
    {79, 99}, 
    {68, 98, 62}};

std::vector<std::pair<int, int>> B = {{1, 19}, {1, 11}, {0, 6}, {0, 5}, {0, 7}, {2, 0}, {0, 2}, {0, 3}};
std::vector<std::vector<int>> C = {{17, 4, 7}, {3, 3, 2}, {19, 0, 4}, {7, 2, 0}, {2, 7, 5}, {5, 1, 6}, {11, 3, 1}, {13, 5, 6}};

/*std::vector<std::vector<LL>> A = {
    {79, 98}, 
    {54, 65, 75, 74}, 
    {79, 60, 97}, 
    {74}};

std::vector<std::pair<int, int>> B = {{1, 19}, {0, 6}, {2, 0}, {0, 3}};
std::vector<std::vector<int>> C = {{23, 2, 3}, {19, 2, 0}, {13, 1, 3}, {17, 0, 1}};*/

void solve() {
    std::vector<LL> cnt(A.size(), 0LL);

    std::vector<int> items;
    std::vector<std::vector<std::pair<int, int>>> save_op;
    std::vector<std::queue<int>> monkeys; 
    for(int i = 0; i < A.size(); i++) {
        monkeys.emplace_back();
        for(int x : A[i]) {
            monkeys[i].push(items.size());
            items.push_back(x);
            save_op.emplace_back();
        }
    }

    /*for(int m = 0; m < A.size(); m++) {
        std::cout << "Monkey: " << m << ' ';
        int sz = monkeys[m].size();
        while(sz--) {
            std::cout << items[monkeys[m].front()] << ' ';
            monkeys[m].pop();
        }
        std::cout << '\n';
    }*/

    for(int r = 0; r < R2; r++) {
        for(int m = 0; m < A.size(); m++) {
            int sz = monkeys[m].size();
            while(sz--) {
                int item = monkeys[m].front();
                monkeys[m].pop();
                    
                cnt[m] += 1LL;

                std::vector<std::pair<int, int>>& ops = save_op[item]; 
                int x = items[item];

                ops.push_back(B[m]);
                int div = C[m][0];
                
                for(std::pair<int, int>& op : ops) {
                    if(op.first == 0) {
                        x = (x + op.second) % div; 
                    } else if(op.first == 1) {
                        x = (x * op.second) % div;
                    } else {
                        x = (x * x) % div;
                    }
                }

                if(x == 0) {
                    monkeys[C[m][1]].push(item);
                } else {
                    monkeys[C[m][2]].push(item);
                }
            }
        }
    }

    std::sort(cnt.begin(), cnt.end(), std::greater<LL>());

    std::cout << cnt[0] << ' ' << cnt[1] << '\n';
    std::cout << cnt[0] * cnt[1] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    solve();
}
