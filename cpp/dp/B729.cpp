#include <iostream>
#include <vector>
#include <cstdint>
const int maxn = 1005;
int a[maxn][maxn];
int b[maxn][maxn];
int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
    int N, M; std::cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            std::cin >> a[i][j];
            b[i][j] = a[i][j] + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (a[i][j]) continue;
            if (b[i][j] - b[i-1][j] > 0) ans++;
            if (b[i][j] - b[i][j-1] > 0) ans++;
            if ((b[N][j] - b[i][j]) - b[N][j-1] + b[i][j-1] > 0) ans++;
            if ((b[i][M] - b[i][j]) - b[i-1][M] + b[i-1][j] > 0) ans++;
        }
    }
    std::cout << ans << '\n';
    return 0;   
}