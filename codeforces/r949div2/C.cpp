#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    int pre = -1;
    std::vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        if(A[i] != -1) {
            ans[i] = A[i];
            if(pre != -1) {
                int l = pre;
                int r = i;
                int x = A[l];
                int y = A[r];
                bool found = false;
                while(l < r) {
                    if(x == y) {
                        found = true;
                        break;
                    } 

                    if(x * 2 == y || x * 2 + 1 == y) {
                        found = true;
                        ans[++l] = y;
                        break;
                    }
                    if(y * 2 == x || y * 2 + 1 == x) {
                        found = true;
                        ans[--r] = x;
                        break;
                    }

                    if(x > y) {
                        x /= 2;
                        if(l + 1 >= r) {
                            break;
                        }
                        ans[++l] = x;
                    } else {
                        y /= 2;
                        if(r - 1 <= l) {
                            break;
                        }
                        ans[--r] = y;
                    }
                }

                if(!found || (r - l) % 2 == 1) {
                    std::cout << -1 << '\n';
                    return;
                }

                for(int j = l + 1, t = 0; j < r; j++, t ^= 1) {
                    if(t == 0) {
                        ans[j] = ans[j - 1] * 2;
                    } else {
                        ans[j] = ans[j - 1] / 2;
                    }
                }
            }
            pre = i;
        } 
    }

    if(ans[0] == 0) {
        for(int i = 0; i < N; i++) {
            if(ans[i] != 0) {
                for(int j = i - 1, t = 0; j >= 0; j--, t ^= 1) {
                    if(t == 0) {
                        ans[j] = ans[j + 1] * 2;
                    } else {
                        ans[j] = ans[j + 1] / 2;
                    }
                }
                break;
            }
        }
    }

    if(ans.back() == 0) {
        for(int i = N - 1; i >= 0; i--){
            if(ans[i] != 0) {
                for(int j = i + 1, t = 0; j < N; j++, t ^= 1) {
                    if(t == 0) {
                        ans[j] = ans[j - 1] * 2;
                    } else {
                        ans[j] = ans[j - 1] / 2;
                    }
                }
                break;
            }
        }
    }

    if(ans.back() == 0) {
        ans[0] = 1;
        for(int i = 1, t = 0; i < N; i++, t ^= 1) {
            if(t == 0) {
                ans[i] = ans[i - 1] * 2;
            } else {
                ans[i] = ans[i - 1] / 2;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << " \n"[i == N - 1];
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
