#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

struct vect {
    int x, y, z;
    vect(int x, int y, int z) : x(x), y(y), z(z) {}
};

std::vector<std::pair<vect, vect>> A;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

constexpr int N = 300;
void run_case1() {
    int n = A.size();

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                return a.first.z < b.first.z;
            });

    std::vector<std::vector<std::vector<int>>> occupied(N + 1, std::vector<std::vector<int>>(N + 1, std::vector<int>(N + 1, -1)));
    for(int x = 0; x <= N; x++) {
        for(int y = 0; y <= N; y++) {
            occupied[x][y][0] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        std::pair<vect, vect>& b = A[i];
        for(int z = N; z >= 0; z--) {
            bool found = false;
            for(int x = b.first.x; x <= b.second.x; x++) {
                for(int y = b.first.y; y <= b.second.y; y++) {
                    if(occupied[x][y][z] != -1) {
                        found = true;
                        break;
                    }
                } 
            }

            if(found) {
                for(int x = b.first.x; x <= b.second.x; x++) {
                    for(int y = b.first.y; y <= b.second.y; y++) {
                        for(int zz = b.first.z; zz <= b.second.z; zz++) {
                            occupied[x][y][z + 1 + zz - b.first.z] = i + 1;
                        }
                    }
                }
                break;
            }
        }
    }

    std::map<int, std::set<int>> m;
    for(int z = 1; z < N; z++) {
        for(int x = 0; x <= N; x++) {
            for(int y = 0; y <= N; y++) {
                int i = occupied[x][y][z];
                int j = occupied[x][y][z + 1];
                if(i != -1 && j != -1 && i != j) {
                    m[j].insert(i);
                }
            }
        } 
    }

    std::set<int> keep;
    for(int i = 1; i <= n; i++) {
        if(m[i].size() == 1) {
            keep.insert(*m[i].begin());
        }
    }

    std::cout << n - keep.size() << '\n';
}

void run_case2() {
    int n = A.size();

    std::sort(A.begin(), A.end(), [](const auto& a, const auto& b) {
                return a.first.z < b.first.z;
            });

    std::vector<std::vector<std::vector<int>>> occupied(N + 1, std::vector<std::vector<int>>(N + 1, std::vector<int>(N + 1, -1)));
    for(int x = 0; x <= N; x++) {
        for(int y = 0; y <= N; y++) {
            occupied[x][y][0] = 0;
        }
    }
    
    for(int i = 0; i < n; i++) {
        std::pair<vect, vect>& b = A[i];
        for(int z = N; z >= 0; z--) {
            bool found = false;
            for(int x = b.first.x; x <= b.second.x; x++) {
                for(int y = b.first.y; y <= b.second.y; y++) {
                    if(occupied[x][y][z] != -1) {
                        found = true;
                        break;
                    }
                } 
            }

            if(found) {
                for(int x = b.first.x; x <= b.second.x; x++) {
                    for(int y = b.first.y; y <= b.second.y; y++) {
                        for(int zz = b.first.z; zz <= b.second.z; zz++) {
                            occupied[x][y][z + 1 + zz - b.first.z] = i + 1;
                        }
                    }
                }
                break;
            }
        }
    }

    std::map<int, std::set<int>> m1;
    std::map<int, std::set<int>> m2;
    for(int z = 1; z < N; z++) {
        for(int x = 0; x <= N; x++) {
            for(int y = 0; y <= N; y++) {
                int i = occupied[x][y][z];
                int j = occupied[x][y][z + 1];
                if(i != -1 && j != -1 && i != j) {
                    m1[j].insert(i);
                    m2[i].insert(j);
                }
            }
        } 
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        std::map<int, std::set<int>> g1(m1);
        std::map<int, std::set<int>> g2(m2);
        
        std::set<int> cur;
        cur.insert(i);
        
        while(!cur.empty()) {
            std::set<int> nxt;
            for(int v : cur) {
                for(int nv : g2[v]) {
                    g1[nv].erase(v);
                    if(g1[nv].empty()) {
                        nxt.insert(nv);         
                        ans += 1;
                    }
                }
            }
            std::swap(cur, nxt);
        }
    }
    
    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::string S;
    while(std::getline(std::cin, S)) {
        int n = S.size();
        int i = 0;
        int x = 0;
        std::vector<int> p;
        while(i < n) {
            if(!is_digit(S[i])) {
                i += 1;
                continue;
            }
            while(i < n && is_digit(S[i])) {
                x = x * 10 + S[i++] - '0'; 
            }
            p.push_back(x);
            x = 0;
        }

        A.emplace_back(vect(p[0], p[1], p[2]), vect(p[3], p[4], p[5]));
    }
    
    //run_case1();
    run_case2();
}
