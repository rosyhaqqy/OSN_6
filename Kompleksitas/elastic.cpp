#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#define PI 3.14159265358979323846
#define mx 10000000000
#define mp make_pair
#define gc getchar
using namespace std;
int n;
int cx[3000], cy[3000], cr[3000];
double adj[3001][3001];
int GetInt()
{
    int r = 0;
    char c;
    while (1)
    {
        c = gc();
        if (c == ' ' || c == '\n')
            continue;
        else
            break;
    }
    r = c - '0';
    while (1)
    {
        c = gc();
        if (c >= '0' && c <= '9')
            r = 10 * r + c - '0';
        else
            break;
    }
    return r;
}

void MSTPrim()
{
    int vis[n];
    double dist[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = mx;
        vis[i] = 0;
    }
    double ans = 0;
    dist[0] = 0;
    int v = 0;
    for (int i = 0; i < n; i++)
    {
        vis[v] = 1;
        double mn = mx;
        int u = v;
        ans += dist[v];
        for (int j = 0; j < n; j++)
        {
            if (!vis[j])
            {
                if (dist[j] > adj[v][j])
                {
                    dist[j] = adj[v][j];
                }
                if (dist[j] < mn)
                {
                    mn = dist[j];
                    u = j;
                }
            }
        }
        v = u;
    }
    printf("%.3lf\n", ans);
}
void getDist(double x, double y, double r, int j)
{
    for (int i = 0; i < j; i++)
    {
        double xx = cx[i];
        double yy = cy[i];
        double rr = cr[i];
        double dist = sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
        if (r == rr)
        {
            adj[i][j] = adj[j][i] = 2 * dist + 2 * PI * r;
        }
        else
        {
            double diffR = abs(r - rr);
            double gs = sqrt(dist * dist - diffR * diffR);
            double a1, a2;
            a2 = 2 * acos(diffR / dist);
            a1 = 2 * PI - a2;
            double elastic;
            double j1, j2;
            if (r > rr)
            {
                j1 = rr * a2;
                j2 = r * a1;
            }
            else
            {
                j1 = rr * a1;
                j2 = r * a2;
            }
            elastic = j1 + j2 + 2 * gs;
            adj[i][j] = adj[j][i] = elastic;
        }
    }
}
void solve()
{
    for (int i = 0; i < n; i++)
    {
        int x = GetInt(), y = GetInt(), r = GetInt();
        getDist((double)x, (double)y, (double)r, i);
        cx[i] = x;
        cy[i] = y;
        cr[i] = r;
    }
    MSTPrim();
}
int main()
{
    while (1)
    {
        scanf("%d", &n);
        if (n == -1)
            break;
        solve();
    }
    return 0;
}