#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void rotate(vector<vector<char>>& m) {
    int n = m.size();
    vector<vector<char>> res(n, vector<char>(n, '.'));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            res[j][n - i - 1] = m[i][j];
        }
    }
    swap(m, res);
}

bool match(vector<vector<char>>& s, vector<vector<char>>& t) {
    int n = s.size();
    vector<pair<int, int>> s1;
    vector<pair<int, int>> s2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(s[i][j] == '#') {
                s1.emplace_back(i, j);
            }
            if(t[i][j] == '#') {
                s2.emplace_back(i, j);
            }
        }
    }

    if(s1.size() != s2.size()) {
        return false;
    }

    int d1 = s1[0].first - s2[0].first;
    int d2 = s1[0].second - s2[0].second;
    for(int i = 0; i < s1.size(); i++) {
        if(s1[i].first - s2[i].first != d1 || s1[i].second - s2[i].second != d2) {
            return false;
        }
    }
    return true;
}

void run_case() {
    int N;
    cin >> N;

    vector<vector<char>> S(N, vector<char>(N, '.'));
    vector<vector<char>> T(N, vector<char>(N, '.'));

    for(int i = 0; i < N; i++) {
        string X;
        cin >> X;
        for(int j = 0; j < N; j++) {
            S[i][j] = X[j];
        }
    }

    for(int i = 0; i < N; i++) {
        string X;
        cin >> X;
        for(int j = 0; j < N; j++) {
            T[i][j] = X[j];
        }
    }

    for(int i = 0; i < 4; i++) {
        rotate(T);
        if(match(S, T)) {
            cout << "Yes" << '\n';
            return;
        }
    }

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
