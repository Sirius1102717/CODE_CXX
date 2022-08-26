#include <bits/stdc++.h>
using namespace std;

char mp[7][7];
int r, c, k;
bool vr[7], vc[7];
int ar[7], ac[7];
int nb = 0;

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false);
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        cin >> mp[i];
        for (int j = 0; j < c; j++) {
            if (mp[i][j] == '#') {
                nb++;
                ar[i]++;
            }
        }
    }
    for (int i = 0; i < c; i++) {
        int tmp = 0;
        for (int j = 0; j < r; j++) {
            if (mp[j][i] == '#') {
                tmp++;
            }
        }
        ac[i] = tmp;
    }
    int res = 0;

    for (int i = 0; i < (1 << r); i++) {
        for (int j = 0; j < (1 << c); j++) {
            int tmp = nb;
            vector<int> col, row;
            for (int l = 0; l < r; l++) {
                if (i >> l & 1) {
                    row.emplace_back(l);
                }
            }
            for (int l = 0; l < c; l++) {
                if (j >> l & 1) {
                    col.emplace_back(l);
                }
            }
            for (int rr : row) {
                tmp -= ar[rr];
            }
            for (int cc : col) {
                tmp -= ac[cc];
            }
            for (int rr : row) {
                for (int cc : col) {
                    if (mp[rr][cc] == '#') {
                        tmp++;
                    }
                }
            }
            res += tmp == k ? 1 : 0;
        }
    }

    cout << res << "\n";
    return 0;
}
