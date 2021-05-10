#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second

typedef pair<pii,pii> query;


const int maxm = 30000;
const int maxn = 7;
const int maxq = (int)2e5+5;
int area[maxn][maxm];
int fst[maxn][maxm];
#define next odijofijd
pii to[maxn*maxm*(4+maxn)*2];
int len[maxn*maxm*(4+maxn)*2];
int next[maxn*maxm*(4+maxn)*2];

char tmp[maxm];
int n,m;	
int d[maxn][maxn][maxm];
query qs[maxq];
int ans[maxq];


const int gox[4] = {0,1,0,-1};
const int goy[4] = {1,0,-1,0};

int ecnt;
void add_edge(pii from, pii mto, int mlen)
{
    to[ecnt] = mto;
    len[ecnt] = mlen;
    next[ecnt] = fst[from.X][from.Y];
    fst[from.X][from.Y] = ecnt;
    ecnt++;
}

void dijkstra(int id, int sx, int sy, int LB, int RB)
{
     priority_queue<pair<int,pii> > u;
     for (int i = 0; i < n; i++)
        for (int j = LB; j <= RB; j++)
           d[id][i][j] = (int)1e9;
     u.push(mp(-area[sx][sy], mp(sx,sy)));
     d[id][sx][sy] = area[sx][sy];
     while (!u.empty())
     {
         pii cur = u.top().Y;
         bool cont = -u.top().X != d[id][cur.X][cur.Y];
         u.pop();
         if (cont) continue;
         for (int i = fst[cur.X][cur.Y]; i != -1; i = next[i])
         {
             pii cto = to[i];
             int nd = d[id][cur.X][cur.Y] + len[i];
             if (d[id][cto.X][cto.Y] > nd)
             {
                 d[id][cto.X][cto.Y] = min(nd, d[id][cto.X][cto.Y]);
                 u.push(mp(-d[id][cto.X][cto.Y], cto));
             }
         }
     }

}

int qids[maxq];
int tmp1[maxq], tmp2[maxq];

void solve(int LB, int RB, int ql, int qr)
{
    if (qr < ql) return;
    if (RB <= LB+1)
    {
        for (int ii = ql; ii <= qr; ii++)
        {
            int i = qids[ii];
            dijkstra(0, qs[i].X.X, qs[i].X.Y, LB, RB);
            ans[i] = d[0][qs[i].Y.X][qs[i].Y.Y];
        }
        return;
    }


    int mid = (LB+RB)/2;
    for (int i = 0; i < n; i++)
       dijkstra(i,i,mid,LB,RB);

    int cnt1 = 0, cnt2 = 0;
    for (int ii = ql; ii <= qr; ii++)
    {
        int i = qids[ii];
        if (qs[i].X.Y > qs[i].Y.Y) swap(qs[i].X, qs[i].Y);
        assert(qs[i].X.Y >= LB && qs[i].Y.Y <= RB);
        if (qs[i].X.Y <= mid && qs[i].Y.Y >= mid)
        {
            ans[i] = (int)1e9;
            for (int j = 0; j < n; j++)			
            {
                ans[i] = min(ans[i], d[j][qs[i].X.X][qs[i].X.Y] + d[j][qs[i].Y.X][qs[i].Y.Y] - area[j][mid]);	
            }		
        }
        else if (qs[i].Y.Y < mid) tmp1[cnt1++] = i;
        else if (qs[i].X.Y > mid) tmp2[cnt2++] = i;
        else assert(false);		
    }
    int lb = ql;
    for (int i = 0; i < cnt1; i++)
       qids[i+lb] = tmp1[i];
    for (int i = 0; i < cnt2; i++)
       qids[i+lb+cnt1] = tmp2[i];
    for (int i = 0; i < n; i++)
       for (int j = 0; j < n; j++)
          if (i != j)
          {
             add_edge(mp(i,mid), mp(j,mid), d[i][j][mid] - area[i][mid]);		  
          }   
    solve(LB, mid, lb, lb + cnt1-1);
    solve(mid, RB, lb+cnt1,lb+cnt1+cnt2-1);
}

int main()
{
    assert( scanf("%d%d", &n, &m) == 2 );
    for (int i = 0; i < n; i++)	
        for (int j = 0; j < m; j++) 
           scanf("%d", &area[i][j]);

    int q;
    assert( scanf("%d", &q) == 1 );
    for (int i = 0; i < q; i++) 
    {
       assert( scanf("%d%d%d%d", &qs[i].X.X, &qs[i].X.Y, &qs[i].Y.X, &qs[i].Y.Y) == 4 );
       ans[i] = (int)1e9;
    }
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
          fst[i][j] = -1;
    ecnt = 0;
    for (int i = 0; i < n; i++)
       for (int j = 0; j < m; j++)
       {
           for (int k = 0; k < 4; k++)
           {
               int ni = i + gox[k], nj = j + goy[k];
               if (ni >= 0 && ni < n && nj >= 0 && nj < m)
                  add_edge(mp(i,j),mp(ni,nj), area[ni][nj]);

           }
       }

    for (int i = 0; i < q; i++) qids[i] = i;
    solve(0, m-1, 0, q-1);
    for (int i = 0; i < q; i++)
       printf("%d\n", ans[i]);
    return 0;
}