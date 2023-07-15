#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(N);
    std::vector<std::vector<int>> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];

        int C;
        std::cin >> C;
        
        B[i].resize(C, 0);
        for(int j = 0; j < C; j++) {
            std::cin >> B[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j) {
                if(A[i] >= A[j]) {
                    std::vector<int> f1(101, 0);
                    std::vector<int> f2(101, 0);
                    for(int x : B[i]) {
                        f1[x] += 1;
                    }
                    for(int x : B[j]) {
                        f2[x] += 1;
                    }

                    bool ok = true;
                    for(int k = 0; k <= 100; k++) {
                        if(f1[k] && !f2[k]) {
                            ok = false;
                            break;
                        }
                    }

                    if(ok) {
                        bool larger = A[i] > A[j];
                        bool lack = false;
                        for(int k = 0; k <= 100; k++) {
                            if(f2[k] && !f1[k]) {
                                lack = true;
                                break;
                            }
                        }

                        if(larger || lack) {
                            std::cout << "Yes" << '\n';
                            return;
                        }
                    }
                }
            }
        }
    }

    std::cout << "No" << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
