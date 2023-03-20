#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int open = 0;
    int close = 0;
    vector<pair<int, int>> v;  // ...))((...
    for(string s : A) {
        string t = "";
        for(char c : s) {
            if(!t.empty() && t.back() == '(' && c == ')') {
                t.pop_back();
            } else {
                t.push_back(c);
            }
        }

        if(!t.empty()) {
            if(t[0] == ')' && t.back() == '(') {
                int cnt = 0;
                for(char c : t) {
                    if(c == ')') {
                        cnt += 1;
                    } else {
                        break;
                    }
                }

                v.emplace_back(cnt, t.size() - cnt);
            } else {
                if(t[0] == ')') {
                    close += t.size();
                } else {
                    open += t.size();
                }
            }
        }
    }

    sort(v.begin(), v.end());

    auto cmp = [](const auto& a, const auto& b) {
        return a.second - a.first < b.second - b.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
    int sz = v.size();
    int i = 0;
    while(true) {
        while(i < sz && v[i].first <= open) {
            pq.emplace(v[i].first, v[i].second);
            i += 1;
        }     

        if(pq.empty()) {
            break;
        }

        pair<int, int> cur = pq.top();
        pq.pop();

        if(cur.first > open) {
            cout << "No" << '\n';
            return;
        }

        open += cur.second - cur.first;
    }

    if(i != sz || !pq.empty()) {
        cout << "No" << '\n';
        return;
    }

    cout << (open == close ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}
