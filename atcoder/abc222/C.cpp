#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<string> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> v(N * 2);
    for(int i = 0; i < 2 * N; i++) {
        v[i] = {0, i};
    }

    auto win = [](char c1, char c2) {
        if(c1 == 'G') {
            return c2 == 'C';
        } 
        if(c1 == 'C') {
            return c2 == 'P';
        }
        
        return c2 == 'G';
    };

    auto cmp = [](const auto& a, const auto& b) {
        if(a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    };

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            pair<int, int>& p1 = v[j * 2];
            pair<int, int>& p2 = v[j * 2 + 1];

            char c1 = A[p1.second][i];
            char c2 = A[p2.second][i];
            if(c1 != c2) {
                if(win(c1, c2)) {
                    p1.first += 1; 
                } else {
                    p2.first += 1;
                }
            }
        } 

        sort(v.begin(), v.end(), cmp);
    }

    for(int i = 0; i < N * 2; i++) {
        cout << v[i].second + 1 << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
