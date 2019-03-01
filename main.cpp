//
//  main.cpp
//  nik codeforces problems
//
//  Created by PREEYADARSHEE DEV on 15/06/18.
//  Copyright © 2018 PREEYADARSHEE DEV. All rights reserved.
//
// train hard win easy :D
// by the way nik is love
// nik is motivation
// going off the grid for some time
//
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ll long long
#define ss second
#define ff first
#define fr(i,a,b) for(ll i=a;i<b;i++)
#define f(i,n) fr(i,0,n)
#define rf(i,b,a) for(ll i=b-1;i>=a;i--)
#define r(i,n) rf(i,n,0)
#define inf 1<<30
#define eps 0.000000001
#define endl '\n'
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // lets fuck bfs anf dfs
    while(1)
    {
        int n,m;
        cin>>n>>m;
        if(n==0&&m==0)
            return 0;
        vector<int> adj[n+1];
        f(i,m)
        {
            int a,b;
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        vector<int> cnt;
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            if(adj[i].size()%2)
            {
                cnt.pb(i);
            }
            if(adj[i].size()==0)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            cout<<"Poor Koorosh"<<endl;
            continue;
        }
        if(cnt.size()==0)
            cout<<0<<endl;
        else if(cnt.size()==1)
            cout<<"Poor Koorosh"<<endl;
        else
        {
            queue<int> q;
            vector<int> vis(n+1,0);
            vector<int> parent(n+1,-1);
            vector<int> dis(n+1,inf);
            if(adj[cnt.back()].size()<=2)
            {
                cout<<"Poor Koorosh"<<endl;
                continue;
            }
            q.push(cnt.back());
            vis[cnt.back()]=1;
            dis[cnt.back()]=0;
            while(!q.empty())
            {
                int v=q.front();
                q.pop();
                for(int i:adj[v])
                {
                    if(vis[i]==0&&adj[i].size()>2)
                    {
                        vis[i]=1;
                        parent[i]=v;
                        dis[i]=dis[v]+1;
                        q.push(i);
                    }
                }
            }
            if(dis[cnt[0]]==inf)
            {
                cout<<"Poor Koorosh"<<endl;
            }
            else
            {
                cout<<dis[cnt[0]]<<endl;
            }
        }
    }
}
