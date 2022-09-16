#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL cross_product(LL x1, LL y1, LL x2, LL y2) {
    return x1 * y2 - x2 * y1;
}
void gen_convex_hull(const vector<pair<int, int>>& A, vector<pair<int, int>>& convex_hull) {
    int n = A.size();

    vector<pair<int, int>> s;
    s.reserve(n);

    for(const pair<int, int>& v : A) {
        while(s.size() > 1 && 
              cross_product(s.back().first - s[s.size() - 2].first, s.back().second - s[s.size() - 2].second, 
                            v.first - s.back().first, v.second - s.back().second) <= 0) {
            s.pop_back();
        }
        s.emplace_back(v.first, v.second);
    }

    for(int i = 0; i < s.size(); i++) {
        convex_hull.emplace_back(s[i].first, s[i].second);
    }

    s = vector<pair<int, int>>();
    s.reserve(n);

    for(const pair<int, int>& v : A) {
        while(s.size() > 1 && 
              cross_product(s.back().first - s[s.size() - 2].first, s.back().second - s[s.size() - 2].second, 
                            v.first - s.back().first, v.second - s.back().second) >= 0) {
            s.pop_back();
        }
        s.emplace_back(v.first, v.second);
    }

    for(int i = 1; i < s.size() - 1; i++) {
        convex_hull.emplace_back(s[i].first, s[i].second);
    } 
}

LL dijkstra(vector<pair<int, int>>& v, int k, int d, pair<int, int>& st, pair<int, int>& ed) {
    int n = v.size();

    vector<LL> best_d(n, -1);
    vector<bool> visited(n, false);
    
    int v_st = 0;
    int v_ed = 0;
    for(int i = 0; i < n; i++) {
        pair<int, int>& p = v[i];
        if(p.first == st.first && p.second == st.second) {
            v_st = i; 
        }
        if(p.first == ed.first && p.second == ed.second) {
            v_ed = i;
        }
    }

    best_d[v_st] = 0LL;
    for(int i = 0; i < n; i++) {
        int cur = -1;
        for(int j = 0; j < n; j++) {
            if(visited[j]) {
                continue;
            }
            if(cur == -1 || 
               (best_d[cur] == -1 && best_d[j] >= 0) || 
               (best_d[cur] >= 0 && best_d[j] >= 0 && best_d[cur] > best_d[j])) {
                cur = j;
            }
        }

        if(best_d[cur] == -1) {
            return -1;
        }
        if(cur == v_ed) {
            break;
        }

        visited[cur] = true;
        for(int j = 0; j < n; j++) {
            if(visited[j]) {
                continue;
            }
            int x1 = v[cur].first;
            int y1 = v[cur].second;
            int x2 = v[j].first;
            int y2 = v[j].second;
            LL x = x1 - x2;
            LL y = y1 - y2;
            LL x_2 = x * x;
            LL y_2 = y * y;
            LL d_2 = (LL)d * d;
            if(x_2 <= d_2 && y_2 <= d_2 && x_2 + y_2 <= d_2) {
                LL cost = best_d[cur] + max((LL)k, x_2 + y_2);
                if(best_d[j] == -1 || cost < best_d[j]) {
                    best_d[j] = cost;
                }
            }
        }
    }

    return best_d[v_ed];
}

void run_case(int T) {
    int N, K, D;
    cin >> N >> K >> D;

    vector<pair<int, int>> A(N, {0, 0});
    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        cin >> A[i].second;
    }

    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if(a.first == b.first) {
            return a.second > b.second;
        } 
        return a.first < b.first;
    };
    sort(A.begin(), A.end(), cmp);

    vector<pair<int, int>> convex_hull;
    gen_convex_hull(A, convex_hull);

    LL ans = dijkstra(convex_hull, K, D, A[0], A[N - 1]);
    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}
