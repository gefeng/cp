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
    
    std::vector<int> A(N);
    int cnt_0 = 0;
    int cnt_2 = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        if(A[i] == 0) {
            cnt_0 += 1;
        } else if(A[i] == 2) {
            cnt_2 += 1;
        }
    }

    std::vector<std::pair<int, int>> ans;

    auto solve_01 = [&](int l, int r) {
        int p_0 = r;
        int p_1 = l;
        int cnt = 0;
        while(p_1 < p_0) {
            while(p_1 < p_0 && A[p_1] != 1) {
                p_1 += 1;
            }
            while(p_1 < p_0 && A[p_0] != 0) {
                p_0 -= 1;
            }
            if(p_1 < p_0) {
                ans.emplace_back(p_1, p_0);
                cnt += 1;
                std::swap(A[p_1], A[p_0]);
                p_1 += 1;
                p_0 -= 1;
            }
        }
        return cnt;
    };

    auto solve_12 = [&](int l, int r) {
        int p_1 = r;
        int p_2 = l;
        int cnt = 0;
        while(p_2 < p_1) {
            while(p_2 < p_1 && A[p_2] != 2) {
                p_2 += 1;
            }
            while(p_1 > p_2 && A[p_1] != 1) {
                p_1 -= 1;
            }
            if(p_2 < p_1) {
                ans.emplace_back(p_2, p_1);
                cnt += 1;
                std::swap(A[p_2], A[p_1]);
                p_2 += 1;
                p_1 -= 1;
            }
        }
        return cnt;
    };

    if(cnt_0 == 0) {
        solve_12(0, N - 1);
    } else if(cnt_2 == 0) {
        solve_01(0, N - 1);
    } else {
        int p_1 = -1;
        int last = N - 1;
        while(last >= 0 && A[last] == 2) {
            last -= 1;
        }
        
        for(int i = last; i >= 0; i--) {
            if(A[i] == 1) {
                p_1 = i;
                break;
            }
        }

        if(p_1 != last) {
            ans.emplace_back(p_1, last);
            std::swap(A[p_1], A[last]);
            p_1 = last;
        }

        int l = 0;
        int p_0 = last;
        while(l < last) {
            while(p_0 >= l && A[p_0] != 0) {
                p_0 -= 1;
            }
            while(p_1 >= l && A[p_1] != 1) {
                p_1 -= 1;
            }

            if(A[l] == 0) {
                l += 1;
                continue;
            }

            if(A[l] == 1) {
                if(p_0 > l) {
                    ans.emplace_back(l, p_0);
                    std::swap(A[l], A[p_0]);
                }
            } else if(A[l] == 2) {
                if(p_1 > l) {
                    ans.emplace_back(l, p_1);
                    A[l] -= 1;
                    A[p_1] += 1;
                }
                if(p_0 > l) {
                    ans.emplace_back(l, p_0);
                    A[l] -= 1;
                    A[p_0] += 1;
                }
            }
            l += 1;
        }
    }

    for(int i = 1; i < N; i++) {
        assert(A[i] >= A[i - 1]);
    }
    
    int size = ans.size();
    assert(size <= N);
    std::cout << size << '\n';
    for(int i = 0; i < size; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
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
