#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using LL = long long;

void run_case() {
    LL L, R;
    std::cin >> L >> R;

    auto f = [](LL x) {
        std::vector<int> d;
        while(x) {
            d.push_back(x % 10LL);
            x /= 10LL;
        }
        reverse(d.begin(), d.end());
        return d;
    };

    std::vector<int> d1 = f(L);
    std::vector<int> d2 = f(R);
    
    int m = d1.size();
    int n = d2.size();
    LL ans = 0LL;

    if(m != n) {
        for(int i = 0; i < std::max(m, n) - 1; i++) {
            ans = ans * 10LL + 9LL;
        }
        std::cout << ans << '\n';
        return;
    }

    int k = -1;
    for(int i = 0; i < n; i++) {
        if(d1[i] != d2[i]) {
            k = i;
            break;
        }
    }

    if(k == -1) {
        std::cout << L << '\n';
        return;
    }

    int min_d = 10;
    int max_d = -1;
    for(int i = 0; i < k; i++) {
        ans = ans * 10LL + d1[i];
        min_d = std::min(min_d, d1[i]);
        max_d = std::max(max_d, d1[i]);
    }

    int lb = min_d;
    int ub = max_d;
    int best = 10;
    LL prefix = ans;
    if(k == n - 1) {
        for(int i = 0; i < 10; i++) {
            if(i >= d1[k] && i <= d2[k]) {
                lb = std::min(min_d, i); 
                ub = std::max(max_d, i);
                LL x = prefix * 10LL + i;
                if(ub - lb < best) {
                    best = ub - lb;
                    ans = x;
                }
            }            
        }

        std::cout << ans << '\n';
        return;
    }

    for(int i = 0; i < 10; i++) {
        lb = min_d;
        ub = max_d;
        if(i > d1[k] && i < d2[k]) {
            lb = std::min(min_d, i); 
            ub = std::max(max_d, i);
            LL x = prefix * 10LL + i; 

            for(int j = k + 1; j < n; j++) {
                x = x * 10LL + lb;
            }

            if(ub - lb < best) {
                best = ub - lb;
                ans = x;
            }
        } else if(i == d1[k]) {
            for(int j = k; j < n; j++) {
                lb = std::min(min_d, i);
                ub = std::max(max_d, i);
                LL x = prefix * 10LL + i;
                LL y = x;
                for(int t = k + 1; t <= j; t++) {
                    y = y * 10LL + d1[t];
                    lb = std::min(lb, d1[t]);
                    ub = std::max(ub, d1[t]);
                } 

                if(j + 1 < n) {
                    for(int d = d1[j + 1] + 1; d < 10; d++) {
                        LL z = y;
                        z = z * 10LL + d;
                        int lb_c = std::min(lb, d);
                        int ub_c = std::max(ub, d);
                        
                        for(int t = j + 2; t < n; t++) {
                            z = z * 10LL + lb; 
                        }

                        if(ub_c - lb_c < best && z >= L && z <= R) {
                            best = ub_c - lb_c;
                            ans = z;
                        }
                    }
                } else {
                    if(ub - lb < best) {
                        best = ub - lb;
                        ans = y;
                    } 
                }

            }
        } else if(i == d2[k]) {
            for(int j = k; j < n; j++) {
                lb = std::min(min_d, i);
                ub = std::max(max_d, i);
                LL x = prefix * 10LL + i;
                LL y = x;
                for(int t = k + 1; t <= j; t++) {
                    y = y * 10LL + d2[t];
                    lb = std::min(lb, d2[t]);
                    ub = std::max(ub, d2[t]);
                } 

                if(j + 1 < n) {
                    for(int d = d2[j + 1] - 1; d >= 0; d--) {
                        LL z = y;
                        z = z * 10LL + d;
                        int lb_c = std::min(lb, d);
                        int ub_c = std::max(ub, d);
                        
                        for(int t = j + 2; t < n; t++) {
                            z = z * 10LL + lb; 
                        }

                        if(ub_c - lb_c < best && z >= L && z <= R) {
                            best = ub_c - lb_c;
                            ans = z;
                        }
                    }
                } else {
                    if(ub - lb < best) {
                        best = ub - lb;
                        ans = y;
                    } 
                }
            }
        }
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
