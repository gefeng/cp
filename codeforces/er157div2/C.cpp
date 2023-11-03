#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::vector<std::map<int, std::map<int, int64_t>>> a(11);
    for(std::string& s : A) {
        int len = s.size();
        for(int i = 2; i <= 10; i += 2) {
            if(len > i / 2) {
                int sum = 0;
                for(int j = 0; j < i / 2; j++) {
                    sum += s[len - j - 1] - '0';
                }
                for(int j = 0; j < len - i / 2; j++) {
                    sum -= s[j] - '0';
                }

                if(sum > 0) {
                    a[i][len][sum] += 1;
                }

                sum = 0;
                for(int j = 0; j < i / 2; j++) {
                    sum += s[j] - '0';
                }
                for(int j = 0; j < len - i / 2; j++) {
                    sum -= s[len - j - 1] - '0';
                }
                if(sum > 0) {
                    a[i][len][sum] += 1;
                }
            }
        }
    }

    int64_t ans = 0;
    for(std::string& s : A) {
        int len = s.size();
        for(int i = 2; i <= 10; i += 2) {
            if(len < i / 2) {
                int sum = 0;
                for(int j = 0; j < len; j++) {
                    sum += s[j] - '0';
                }

                ans += a[i][i - len][sum];
            }
        }
    }

    std::map<int, std::map<int, int>> m;
    for(std::string& s : A) {
        int len = s.size();
        int sum = 0;
        for(int i = 0; i < len; i++) {
            sum += s[i] - '0';
        }

        m[sum][len] += 1;
    }

    for(std::string& s : A) {
        int len = s.size();
        int sum = 0;
        for(int i = 0; i < len; i++) {
            sum += s[i] - '0';
        }

        ans += m[sum][len];
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}
