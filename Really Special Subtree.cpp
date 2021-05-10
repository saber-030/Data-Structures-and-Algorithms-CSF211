int parent[10009];

int rank[10009];

void init(int n)

{
    
for(int i=0;i<=n+1;i++)
{
    parent[i]=i;
    rank[i]=0;
}
}

int find(int v)

{
    
if(parent[v]==v)
return v;
return parent[v]=find(parent[v]);
}

void union_set(int u,int v)

{
    
u=find(u);
v=find(v);
if(rank[u]==rank[v])
{
    parent[u]=v;
    rank[v]++;
}
else
{
    if(rank[u]>rank[v])
    parent[v]=u;
    else
    parent[u]=v;
}
}

struct edge

{
    
int x,y,r;
};

bool cmp(struct edge a,struct edge b)

{
    
if(a.r < b.r)
return true;
else if(a.r > b.r)
return false;
else
{
    int q=a.x+a.y+a.r;
    int w=b.x=+b.y+b.r;
    if(q<w)
    return true;
    else
    return false;
}
    
}

int main() 

{
    
    int n,m,i,x,y,r;
    cin>>n>>m;
    struct edge e[m+1]; 
    for(i=0;i<m;i++)
    {
        cin>>x>>y>>r;
        e[i].x=x;
        e[i].y=y;
        e[i].r=r;
    }
    sort(e,e+m,cmp);
    init(n);
    i=0;
    int wt=0;
    int ctr=0;
    while(ctr<(n-1) && i<m)
    {
        x=e[i].x;
        y=e[i].y;
        r=e[i].r;
        x=find(x);
        y=find(y);
        if(x!=y)
        {
            wt+=r;
            //cout<<wt<<endl;
            ctr++;
            union_set(x,y);
        }
        i++;
    }
    cout<<wt<<endl;
return 0;
}