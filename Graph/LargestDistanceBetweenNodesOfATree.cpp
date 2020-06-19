pair<int,int> bfs(int x,vector<int> adj[],int v)
{
    vector<bool> visited(v,false);
    queue<pair<int,int>> q;
    visited[x]=true;
    q.push(make_pair(x,0));
    pair<int,int> temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        for(int i=0;i<adj[temp.first].size();i++)
        {
            if(!visited[adj[temp.first][i]])
            {
                visited[adj[temp.first][i]]=true;
                q.push(make_pair(adj[temp.first][i],temp.second+1));
            }
        }
    }
    return temp;
}



int Solution::solve(vector<int> &A) {
    if(A.size()==0||A.size()==1) return 0;
    vector<int> adj[A.size()];
    int v=A.size();
    int i;
    for(i=0;i<v;i++)
    {
        if(A[i]==-1) continue;
        
        adj[i].push_back(A[i]);
        adj[A[i]].push_back(i);
    }
    
    
    pair<int,int> p1,p2;
    p1=bfs(0,adj,v);
    p2=bfs(p1.first,adj,v);
    return p2.second;
    
}