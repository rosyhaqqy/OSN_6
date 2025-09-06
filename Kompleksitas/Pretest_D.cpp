#include <stdio.h>
#include <algorithm>
#define MX 250001
#define gc getchar
int ln[MX], rn[MX], sz[MX], sh[MX];
char vl[MX];
int read()
{
    int value = 0;
    bool ne = 0;
    char c = gc();
    while (c == ' ' || c == '\n')
        c = gc();
    if (c == '-')
    {
        ne = 1;
        c = gc();
    }
    while (c >= '0' && c <= '9')
    {
        value = (value << 3) + (value << 1) + c - '0';
        c = gc();
    }
    if (ne)
        value *= -1;
    return value;
}

void merge(int &t, int l, int r)
{
    if (!l || !r)
        t = l | r;
    else if (l > r)
        merge(rn[l], rn[l], r), t = l;
    else
        merge(ln[r], l, ln[r]), t = r;
    if (t)
        sz[t] = sz[ln[t]] + sz[rn[t]] + 1;
}

void split(int t, int &l, int &r, int sv)
{
    if (!t)
        l = r = 0;
    else if (sz[ln[t]] < sv)
        split(rn[t], rn[t], r, sv - sz[ln[t]] - 1), l = t;
    else
        split(ln[t], l, ln[t], sv), r = t;
    if (t)
        sz[t] = sz[ln[t]] + sz[rn[t]] + 1;
}

int main()
{
    int n = read(), m = read();
    for (int i = 0; i < n; i++)
        sh[i] = i + 1;
    for (int i = 1; i <= n; i++)
        sz[i] = 1, ln[i] = rn[i] = 0;
    std::random_shuffle(sh, sh + n);
    char cz = gc();
    while (cz == ' ' || cz == '\n')
        cz = gc();
    for (int i = 0; i < n; i++)
        vl[sh[i]] = cz, cz = gc();
    int lb = sh[0];
    for (int i = 1; i < n; i++)
        merge(lb, lb, sh[i]);
    while (m--)
    {
        int l = read(), r = read();
        int lz, mz, rz;
        split(lb, mz, rz, r);
        split(mz, lz, mz, l - 1);
        merge(lb, mz, lz);
        merge(lb, lb, rz);
    }
    for (int i = 1; i <= n; i++)
    {
        int md;
        split(lb, md, lb, 1);
        printf("%c", vl[md]);
    }
    puts("");
    return 0;
}