#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int L, R;
    std::cin >> L >> R;

    auto get_digits = [](int x) {
        std::vector<int> digits; 
        while(x) {
            digits.push_back(x % 10);
            x /= 10;
        }
        std::reverse(digits.begin(), digits.end());
        return digits;
    };

    std::vector<int> a = get_digits(L);
    std::vector<int> b = get_digits(R);

    int size = a.size();
    int ans = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] == b[i]) {
            ans += 2;
        } else {
            if(a[i] + 1 == b[i]) {
                int cnt_1 = 1;
                int cnt_2 = 1;
                for(int j = i + 1; j < size; j++) {
                    if(a[j] == 9) {
                        cnt_1 += 1;
                        if(b[j] == 9) {
                            cnt_1 += 1;
                        }
                    } else if(a[j] == 8) {
                        if(b[j] == 9) {
                            cnt_1 += 1;
                        } 
                        break;
                    } else {
                        break;
                    }
                }

                for(int j = i + 1; j < size; j++) {
                    if(b[j] == 0) {
                        cnt_2 += 1;
                        if(a[j] == 0) {
                            cnt_2 += 1;
                        }
                    } else if(b[j] == 1) {
                        if(a[j] == 0) {
                            cnt_2 += 1;
                        }
                        break;
                    } else {
                        break;
                    }
                }

                ans += std::min(cnt_1, cnt_2);
            }
            break;
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
