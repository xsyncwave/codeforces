#include <bits/stdc++.h>

const int maxn = 5 * 1e5;
int cars[maxn] = { };

void solve() {
    int n, t; std::cin >> n >> t;
    
    for(int i = 0; i < n; i++) std::cin >> cars[i];
    
    int max_val = *std::max_element(std::begin(cars), std::begin(cars) + n);
    long long tot = std::accumulate(std::begin(cars), std::begin(cars) + n, 0LL);
    
    long long ans = std::max(1LL * max_val, (tot + t - 1) / (1LL * t));
    std::cout << ans << std::endl;
}

signed main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0); std::cout.tie(0);

    int t; std::cin >> t; while(t--) solve();
    return 0;
}
// g++ -std=c++20 <filename>.cpp
