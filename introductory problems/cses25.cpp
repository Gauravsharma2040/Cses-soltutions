#include <bits/stdc++.h>
using namespace std;

string s;
bool vis[7][7];
int ans = 0;

// directions in order 'D','U','L','R'
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char movesChar[4] = {'D','U','L','R'};

void dfs(int r, int c, int idx) {
    // If we've used all 48 moves, check if at target
    if (idx == 48) {
        if (r == 6 && c == 0) ans++;
        return;
    }
    // If we reached the end too early, stop
    if (r == 6 && c == 0) return;

    // Pruning: if we're boxed so that we create unavoidable split, cut branch
    bool upBlocked    = (r == 0 || vis[r-1][c]);
    bool downBlocked  = (r == 6 || vis[r+1][c]);
    bool leftBlocked  = (c == 0 || vis[r][c-1]);
    bool rightBlocked = (c == 6 || vis[r][c+1]);

    // If vertical both blocked and horizontal both open -> trapped
    if (upBlocked && downBlocked && !leftBlocked && !rightBlocked) return;
    // If horizontal both blocked and vertical both open -> trapped
    if (leftBlocked && rightBlocked && !upBlocked && !downBlocked) return;

    char ch = s[idx];
    if (ch != '?') {
        int di = -1;
        if (ch == 'D') di = 0;
        else if (ch == 'U') di = 1;
        else if (ch == 'L') di = 2;
        else if (ch == 'R') di = 3;
        int nr = r + dr[di], nc = c + dc[di];
        if (nr < 0 || nr > 6 || nc < 0 || nc > 6) return;
        if (vis[nr][nc]) return;
        vis[nr][nc] = true;
        dfs(nr, nc, idx+1);
        vis[nr][nc] = false;
    } else {
        // try all 4 directions
        for (int di = 0; di < 4; ++di) {
            int nr = r + dr[di], nc = c + dc[di];
            if (nr < 0 || nr > 6 || nc < 0 || nc > 6) continue;
            if (vis[nr][nc]) continue;
            vis[nr][nc] = true;
            dfs(nr, nc, idx+1);
            vis[nr][nc] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!(cin >> s)) return 0;
    // s length should be 48
    memset(vis, 0, sizeof(vis));
    vis[0][0] = true;
    dfs(0, 0, 0);
    cout << ans << "\n";
    return 0;
}
