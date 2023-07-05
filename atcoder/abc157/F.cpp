#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <iomanip>

constexpr double EPS = 1e-9;
constexpr int MAX = 200;

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<std::array<int, 3>> A(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            std::cin >> A[i][j];
        }
    }

    auto get_distance = [](double x1, double y1, double x2, double y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    };

    auto get_intersection = [](double x1, double y1, double r1, double x2, double y2, double r2) {
        std::vector<std::pair<double, double>> res;
        
        double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        if(r1 + r2 < d) {
            return res;
        }

        if(abs(d + r2 - r1) < EPS) {
            double ratio = r1 / d;
            res.emplace_back((x2 - x1) * ratio + x1, (y2 - y1) * ratio + y1); 
        } else if(abs(d + r1 - r2) < EPS) {
            double ratio = r2 / d;
            res.emplace_back((x1 - x2) * ratio + x2, (y1 - y2) * ratio + y2);
        } else if(abs(r1 + r2 - d) < EPS) {
            double ratio = r1 / d;
            res.emplace_back((x2 - x1) * ratio + x1, (y2 - y1) * ratio + y1);
        } else {
            double r12 = r1 * r1;
            double r22 = r2 * r2;
            double d2 = d * d;
            double l = (r12 - r22 + d2) / (2.0 * d);
            double h = sqrt(r12 - l * l);
            for(int sign = -1; sign <= 1; sign += 2) {
                double x = l / d * (x2 - x1) + sign * h / d * (y2 - y1) + x1;
                double y = l / d * (y2 - y1) - sign * h / d * (x2 - x1) + y1;
                res.emplace_back(x, y);
            }
        }

        return res;
    };

    double lo = 0.0;
    double hi = 2e5;
    double ans = 0.0;
    int rep = MAX;
    while(rep--) {
        double mid = (lo + hi) / 2.0;
        
        std::vector<std::pair<double, double>> candidates;
        
        for(int i = 0; i < N; i++) {
            candidates.emplace_back(A[i][0], A[i][1]);
        }

        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                for(auto [x, y] : get_intersection(A[i][0], A[i][1], mid / A[i][2], A[j][0], A[j][1], mid / A[j][2])) {
                    candidates.emplace_back(x, y);
                }
            }
        }

        bool found = false;
        for(auto [x, y] : candidates) {
            int cnt = 0;
            for(int i = 0; i < N; i++) {
                double d = get_distance(x, y, A[i][0], A[i][1]); 
                double r = mid / A[i][2]; 
                if(d < r + EPS) {
                    cnt += 1;
                }
            }

            if(cnt >= K) {
                found = true;
                break;
            }
        }

        if(found) {
            ans = mid;
            hi = mid;
        } else {
            lo = mid;
        }
    }

    std::cout << std::setprecision(20) << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
