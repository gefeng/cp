#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <numeric>

std::vector<int> sort_cyclic_shifts(std::string const& s) {
    int n = s.size();
    const int alphabet = 256;
    std::vector<int> p(n), c(n), cnt(std::max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    std::vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            std::pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            std::pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

std::vector<int> suffix_array_construction(std::string s) {
    s += "$";
    std::vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

void run_case() {
    std::string S;
    std::cin >> S;

    std::vector<int> sa = suffix_array_construction(S);

    auto bs = [&](std::string& t) {
        int n = S.size();
        int m = t.size();
        int lo = 0;
        int hi = n - 1;
        int res = n;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;

            std::string s = S.substr(sa[mid], std::min(n - sa[mid], m));
            if(s >= t) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    };

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        std::string T;
        std::cin >> T;

        int l = bs(T);
        T.push_back('~');
        int r = bs(T); 
        std::cout << r - l << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}
