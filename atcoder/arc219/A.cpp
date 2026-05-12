#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

bool dfs(int M, std::vector<std::string>& A, std::vector<int>& now, int c, std::string& s, std::string& ans) {
    if(c == M && !now.empty()) {
        return false;
    }

    if(now.empty()) {
        ans = s;
        return true;
    }

    std::vector<int> a;
    std::vector<int> b;
    for(int i : now) {
        if(A[i][c] == '0') {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }

    s.push_back('0');
    if(dfs(M, A, b, c + 1, s, ans)) {
        return true;
    }
    s.pop_back();
    s.push_back('1');
    if(dfs(M, A, a, c + 1, s, ans)) {
        return true;
    }
    s.pop_back();
    return false;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::string ans = "";
    if(M > 2) {
        std::vector<int> now(N, 0);
        std::iota(now.begin(), now.end(), 0);
        std::string cand = "";
        if(dfs(M, A, now, 0, cand, ans)) {
            while(ans.size() != M) {
                ans.push_back('0');
            }
        } else {
            std::cout << "No" << '\n';
            return;
        }
    } else if(M == 1) {
        for(int i = 0; i < N; i++) {
            if(A[i][0] != A[0][0]) {
                std::cout << "No" << '\n';
                return;
            }
        }
        ans.push_back(A[0][0]);
    } else {
        std::vector<int> a;
        std::vector<int> b;
        for(int i = 0; i < N; i++) {
            if(A[i][0] == '0') {
                a.push_back(i);
            } else {
                b.push_back(i);
            }
        }
        if(a.empty()) {
            ans = "10";
        } else if(b.empty()) {
            ans = "00";
        } else {
            bool ok = true;
            for(int i : a) {
                if(A[i][1] != A[a[0]][1]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                ans = "1";
                ans.push_back(A[a[0]][1]);
            } else {
                ok = true;
                for(int i : b) {
                    if(A[i][1] != A[b[0]][1]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    ans = "0";
                    ans.push_back(A[b[0]][1]);
                } else {
                    std::cout << "No" << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "Yes" << '\n' << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
