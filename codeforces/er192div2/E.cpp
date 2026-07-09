#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <bit>

constexpr int INF = static_cast<int>(2e9) + 10;

void run_case() {
    int L, R, N;
    std::cin >> L >> R >> N;
    
    int k = 0;
    int now = 1;
    while(now * 2 <= R) {
        now *= 2;
        k++;
    }

    auto generate = [&](int x, int y) {
        std::string cand = "";
        int hx = 0;
        int hy = 0;
        for(int i = 0; i < 30; i++) {
            if(x & (1 << i)) {
                hx = i;
            }

            if(y & (1 << i)) {
                hy = i;
            }
        }

        for(int i = 0, bx = hx, by = hy; i < N; i++, bx = (bx - 1 + hx + 1) % (hx + 1), by = (by - 1 + hy + 1) % (hy + 1)) {
            int b1 = (x & (1 << bx)) ? 1 : 0;
            int b2 = (y & (1 << by)) ? 1 : 0;
            cand.push_back(static_cast<char>((b1 & b2) + '0'));
        }

        return cand;
    };

    std::string ans = "";
    if(k > 1 && now >= L && now / 2 >= L) {
        int n = (k + 1) * k;
        for(int i = 0; i < N; i++) {
            ans.push_back(i % n == 0 ? '1' : '0');
        }
    } else if(now >= L) {
        std::vector<int> a;
        int x = L;
        while(x < now) {
            a.push_back(x);
            for(int i = 0; i < 30; i++) {
                if(x & (1 << i)) {
                    if((x + (1 << i)) < now) {
                        x += (1 << i);
                    } else {
                        bool end = true;
                        for(int j = i - 1; j >= 0; j--) {
                            if((x + (1 << j)) < now) {
                                x += (1 << j);
                                end = false;
                                break;
                            }
                        }
                        if(end) {
                            x = R + 1;
                        }
                    }
                    break;
                }
            }
        }
        x = now + 1;
        while(x <= R) {
            a.push_back(x);
            for(int i = 0; i < 30; i++) {
                if(x & (1 << i)) {
                    if((x + (1 << i)) <= R) {
                        x += (1 << i);
                    } else {
                        bool end = true;
                        for(int j = i - 1; j >= 0; j--) {
                            if((x + (1 << j)) <= R) {
                                x += (1 << j);
                                end = false;
                                break;
                            }
                        }
                        if(end) {
                            x = R + 1;
                        }
                    }
                    break;
                }
            }
        }
        for(int i = 0; i < a.size(); i++) {
            std::string cand = generate(a[i], now);
            if(ans.empty() || cand < ans) {
                ans = cand;
            }
        }
    } else {
        std::vector<int> a;
        int x = L;
        while(x <= R) {
            a.push_back(x);
            for(int i = 0; i < 30; i++) {
                if(x & (1 << i)) {
                    if((x + (1 << i)) <= R) {
                        x += (1 << i);
                    } else {
                        bool end = true;
                        for(int j = i - 1; j >= 0; j--) {
                            if((x + (1 << j)) <= R) {
                                x += (1 << j);
                                end = false;
                                break;
                            }
                        }
                        if(end) {
                            x = R + 1;
                        }
                    }
                    break;
                }
            }
        }
        
        int cand1 = 0;
        int cand2 = 0;
        int min_v = INF;
        for(int x1 : a) {
            for(int x2 : a) {
                if(x1 != x2) {
                    if((x1 & x2) < min_v) {
                        min_v = x1 & x2;
                        cand1 = x1;
                        cand2 = x2;
                    }
                }
            }
        }
        ans = generate(cand1, cand2);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}
