#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int H, W;
    std::cin >> H >> W;

    std::string t = "snuke";
    std::string rt = "ekuns";

    std::vector<std::string> G(H);
    for(int i = 0; i < H; i++) {
        std::cin >> G[i];
    }

    for(int i = 0; i < H; i++) {
        if(G[i].find(t) != std::string::npos) {
            int st = G[i].find(t); 
            for(int j = 0; j < 5; j++) {
                std::cout << i + 1 << ' ' << j + st + 1 << '\n'; 
            }
            return;
        }

        if(G[i].find(rt) != std::string::npos) {
            int st = G[i].find(rt); 
            for(int j = 4; j >= 0; j--) {
                std::cout << i + 1 << ' ' << j + st + 1 << '\n'; 
            }
            return;
        }
    }

    for(int i = 0; i < W; i++) {
        std::string s;
        for(int j = 0; j < H; j++) {
            s.push_back(G[j][i]);
        }

        if(s.find(t) != std::string::npos) {
            int st = s.find(t); 
            for(int j = 0; j < 5; j++) {
                std::cout << j + st + 1 << ' ' << i + 1 << '\n'; 
            }
            return;
        }

        if(s.find(rt) != std::string::npos) {
            int st = s.find(rt); 
            for(int j = 4; j >= 0; j--) {
                std::cout << j + st + 1 << ' ' << i + 1 << '\n'; 
            }
            return;
        }
    }

    for(int i = 0; i < W; i++) {
        int r = 0;
        int c = i;
        std::string s;
        while(r >= 0 && c >= 0 && r < H && c < W) {
           s.push_back(G[r][c]); 
           r += 1;
           c += 1;
        } 

        if(s.find(t) != std::string::npos) {
            int st = s.find(t);
            for(int j = 0; j < 5; j++) {
                std::cout << j + st + 1 << ' ' << i + st + j + 1 << '\n';
            }
            return;
        }

        if(s.find(rt) != std::string::npos) {
            int st = s.find(rt);
            for(int j = 4; j >= 0; j--) {
                std::cout << j + st + 1 << ' ' << i + st + j + 1 << '\n';
            } 
            return;
        }
    }


    for(int i = 0; i < H; i++) {
        int r = i;
        int c = 0;
        std::string s;
        
        while(r >= 0 && c >= 0 && r < H && c < W) {
           s.push_back(G[r][c]); 
           r += 1;
           c += 1;
        } 

        if(s.find(t) != std::string::npos) {
            int st = s.find(t);
            for(int j = 0; j < 5; j++) {
                std::cout << i + j + st + 1 << ' ' << j + st + 1 << '\n';
            }
            return;
        }

        if(s.find(rt) != std::string::npos) {
            int st = s.find(rt);
            for(int j = 4; j >= 0; j--) {
                std::cout << i + j + st + 1 << ' ' << j + st + 1 << '\n';
            } 
            return;
        }
    }

    
    for(int i = W - 1; i >= 0; i--) {
        int r = 0;
        int c = i;
        std::string s;
        while(r >= 0 && c >= 0 && r < H && c < W) {
           s.push_back(G[r][c]); 
           r += 1;
           c -= 1;
        } 

        if(s.find(t) != std::string::npos) {
            int st = s.find(t);
            for(int j = 0; j < 5; j++) {
                std::cout << j + st + 1 << ' ' << i - st - j + 1 << '\n';
            }
            return;
        }

        if(s.find(rt) != std::string::npos) {
            int st = s.find(rt);
            for(int j = 4; j >= 0; j--) {
                std::cout << j + st + 1 << ' ' << i - st - j + 1 << '\n';
            } 
            return;
        }
    }

    for(int i = 0; i < H; i++) {
        int r = i;
        int c = W - 1;
        std::string s;
        
        while(r >= 0 && c >= 0 && r < H && c < W) {
           s.push_back(G[r][c]); 
           r += 1;
           c -= 1;
        } 

        if(s.find(t) != std::string::npos) {
            int st = s.find(t);
            for(int j = 0; j < 5; j++) {
                std::cout << i + j + st + 1 << ' ' << W - 1 - st - j + 1 << '\n';
            }
            return;
        }

        if(s.find(rt) != std::string::npos) {
            int st = s.find(rt);
            for(int j = 4; j >= 0; j--) {
                std::cout << i + j + st + 1 << ' ' << W - 1 - st - j + 1 << '\n';
            } 
            return;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
