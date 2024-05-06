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

    std::vector<std::pair<int, int>> a;
    std::vector<std::pair<int, int>> b;
    for(int i = 0; i < N; i++) {
        int X, Y;
        std::cin >> X >> Y;
        if((X + Y) % 2 == 0) {
            a.emplace_back((X + Y) / 2, (Y - X) / 2);
        } else {
            b.emplace_back((X + Y + 1) / 2, (Y - X - 1) / 2); // ?
        }
    }

    int64_t ans = 0;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    int64_t sum = 0;
    for(int i = 1; i < a.size(); i++) {
        sum += int64_t(a[i].first - a[i - 1].first) * i;
        ans += sum;
    } 
    
    sum = 0;
    for(int i = 1; i < b.size(); i++) {
        sum += int64_t(b[i].first - b[i - 1].first) * i;
        ans += sum;
    }

    std::sort(a.begin(), a.end(), [](const auto& x, const auto& y) {
                return x.second < y.second;
            });
    std::sort(b.begin(), b.end(), [](const auto& x, const auto& y) {
                return x.second < y.second;
            });

    sum = 0;
    for(int i = 1; i < a.size(); i++) {
        sum += int64_t(a[i].second - a[i - 1].second) * i;
        ans += sum;
    }

    sum = 0;
    for(int i = 1; i < b.size(); i++) {
        sum += int64_t(b[i].second - b[i - 1].second) * i;
        ans += sum;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
