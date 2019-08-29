#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
const int maxn = 52;
const int maxc = 1001;
//orig
int n, x0[maxn], x1[maxn], y0[maxn], y1[maxn], z0[maxn], z1[maxn];
//sparse
int nx, ny, nz, xs[2 * maxn], ys[2 * maxn], zs[2 * maxn]; 

const int dx[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 1, -1};

int color[maxn * 2][maxn * 2][maxn * 2];

struct Cell {
    int x, y, z;
    Cell(int x = 0, int y = 0, int z = 0): x(x), y(y), z(z) {}
    
    bool is_legal() {
        return x >= 0 && x < nx - 1 && y >= 0 && y < ny - 1 && z >= 0 && z < nz - 1;
    }

    Cell neighbor(int dir) {
        return Cell(x + dx[dir], y + dy[dir], z + dz[dir]);
    }

    int volume() {
        return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
    }

    int area(int dir) {
        if (dir <= 1) {
            return (ys[y + 1] - ys[y]) * (zs[z + 1] - zs[z]);
        } else if (dir <= 3) {
            return (xs[x + 1] - xs[x]) * (zs[z + 1] - zs[z]);
        } 
        return (xs[x + 1] - xs[x]) * (ys[y + 1] - ys[y]);
    }

    void set_vis() {
        color[x][y][z] = 2;
    }

    bool is_vis() {
        return color[x][y][z] == 2;
    }

    bool is_box() {
        return color[x][y][z] == 1;
    }
};

void discrete(int &n, int a[]) {
    sort(a, a + n);
    n = unique(a, a + n) - a;
}

int get_pos(int a[], int n, int tar) {
    return lower_bound(a, a + n, tar) - a;
}

void read_case() {
    scanf("%d", &n);
    xs[0] = ys[0] = zs[0] = 0;
    xs[1] = ys[1] = zs[1] = maxc;
    nx = ny = nz = 2;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &x0[i], &y0[i], &z0[i], &x1[i], &y1[i], &z1[i]);
        x1[i] += x0[i]; y1[i] += y0[i]; z1[i] += z0[i];
        xs[nx++] = x0[i]; xs[nx++] = x1[i];
        ys[ny++] = y0[i]; ys[ny++] = y1[i];
        zs[nz++] = z0[i]; zs[nz++] = z1[i];
    }
    discrete(nx, xs);
    discrete(ny, ys);
    discrete(nz, zs);
    //init
    memset(color, 0, sizeof(color));
    //print color for box cell
    for (int i = 0; i < n; i++) {
        int xpos = get_pos(xs, nx, x0[i]), xpos1 = get_pos(xs, nx, x1[i]);
        int ypos = get_pos(ys, ny, y0[i]), ypos1 = get_pos(ys, ny, y1[i]);
        int zpos = get_pos(zs, nz, z0[i]), zpos1 = get_pos(zs, nz, z1[i]);
        for (int ix = xpos; ix < xpos1; ix++) {
            for (int iy = ypos; iy < ypos1; iy++) {
                for (int iz = zpos; iz < zpos1; iz++) {
                    color[ix][iy][iz] = 1;
                }
            }
        }
    }
}

void solve(int &v, int &s) {
    queue<Cell> q;
    Cell a = Cell(0, 0, 0);
    a.set_vis();   //注意初始入队 set vis
    q.push(a);
    while(!q.empty()) {
        a = q.front(); q.pop();
        v += a.volume();
        for (int i = 0; i < 6; i++) {
            Cell b = a.neighbor(i);
            if (b.is_legal()) {
                if (b.is_box()) {
                    s += b.area(i);
                } else if (!b.is_vis()) {
                        b.set_vis();
                        q.push(b);
                }
            }
        }
    }
    return;
}
int main() {
    #ifdef D
        freopen("data.in", "r", stdin);
    #endif
    int T;
    scanf("%d", &T);
    while(T--) {
        read_case();
        int v = 0, s = 0;
        solve(v, s);
        printf("%d %d\n", s, maxc * maxc * maxc - v);
    }
    return 0;
}