#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;

    int n = 0;
    for(int i = 1; i <= N; i *= 2) {
        n += 1;
    }

    auto query = [](std::string&& t, int x, int y) {
        std::cout << t << ' ' << x + 1 << ' ' << y + 1 << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    std::vector<int> ans(N, 0);
    std::vector<int> res(N, 0); 
    
    for(int i = 1; i < N; i++) {
        res[i] = query("XOR", 0, i);
    }

    int zero = -1;
    for(int i = 1; i < N; i++) {
        if(res[i] == 0) {
            zero = i; 
            break;
        }
    }
    
    if(zero != -1) {
        ans[0] = query("AND", 0, zero);
        for(int i = 1; i < N; i++) {
            ans[i] = res[i] ^ ans[0];
        }
    } else {
        int p_1 = -1;
        int p_2 = -1;
        std::vector<int> seen(N, -1);
        for(int i = 1; i < N; i++) {
            if(seen[res[i]] != -1) {
                p_1 = seen[res[i]];
                p_2 = i;
                break;
            }
            seen[res[i]] = i;
        }

        if(p_1 != -1) {
            ans[p_1] = query("AND", p_1, p_2);            
            ans[0] = res[p_1] ^ ans[p_1];
            for(int i = 1; i < N; i++) {
                ans[i] = res[i] ^ ans[0];
            }
        } else {
            for(int i = 1; i < N; i++) {
                if(res[i] == N - 1) {
                    p_1 = i;
                    break;
                }
            }
            p_2 = p_1 == 1 ? 2 : 1;
            int a = N - 1;
            int b = res[p_2];
            int c = query("AND", p_1, p_2);
            int d = query("AND", 0, p_2);
            int x = 0;
            int y = 0;
            int z = 0;
            for(int i = 0; i < n; i++) {
                int b_1 = a & (1 << i) ? 1 : 0;
                int b_2 = b & (1 << i) ? 1 : 0;
                if(b_1 == 1 && b_2 == 1) {
                    if(c & (1 << i)) {
                        y |= 1 << i;
                        z |= 1 << i;
                    } else {
                        x |= 1 << i;
                    }
                } else if(b_1 == 0 && b_2 == 1) {
                    z |= 1 << i;    
                } else if(b_1 == 1 && b_2 == 0) {
                    if(d & (1 << i)) {
                        x |= 1 << i;
                        z |= 1 << i;
                    } else {
                        y |= 1 << i;
                    }
                }
            }

            ans[0] = x;
            for(int i = 1; i < N; i++) {
                ans[i] = res[i] ^ ans[0];
            }
        }
    }

    std::cout << "! ";
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
