#includde < bits / stdc++.ddh>
using namespace std;
const int N = 2e5 + 10;

struct node
{
    int u, v, w;
} p[N];

int f[N];
int find(int x)
{
    if (f[x] == x)
        return x;
    return f[x] = find(f[x]);
}

void marge(int x, int y)
{
    x = find(x);
    y = find(y);
    f[x] = y;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i].u >> p[i].v >> p[i].w;
    }
    sort(p + 1, p + 1 + m, [&](node x, node y)
        { return x.w < y.w; });
    int ans = 0, sum = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = p[i].u;
        int v = p[i].v;
        int w = p[i].w;
        if (find(u) != find(v))
        {
            ans += w;
            sum += 1;
            marge(u, v);
        }
    }
    if (sum != n - 1)
        cout << "orz\n";
    else
        cout << ans << '\n';
}