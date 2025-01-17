#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
private:
        vector<int> Parent,Rank,Size;
public:
        DisjointSet(int n){
                Parent.resize(n+1);
                Rank.resize(n+1,0);
                Size.resize(n+1,1);
                for(int i=0;i<n+1;i++) Parent[i]=i;
        }
        int findUParent(int node){
                if(node == Parent[node]) return node;
                return Parent[node]= findUParent(Parent[node]);
        }
        void unionByRank(int u,int v)
        {
                int ulp_u=findUParent(u);
                int ulp_v=findUParent(v);
                if(ulp_u == ulp_v) return;
                if(Rank[ulp_u] > Rank[ulp_v])   Parent[ulp_v]=ulp_u;
                else if(Rank[ulp_u] < Rank[ulp_v]) Parent[ulp_u]=ulp_v;
                else{
                        Parent[ulp_u]=ulp_v;
                        Rank[ulp_v]++;
                }

        }
        void unionBySize(int u,int v)
        {
                int ulp_u=findUParent(u);
                int ulp_v=findUParent(v);
                if(ulp_u == ulp_v) return;
                if(Size[ulp_u] > Size[ulp_v]){
                        Parent[ulp_v]=ulp_u;
                        Size[ulp_u] += Size[ulp_v];
                }
                else{
                        Parent[ulp_u]=ulp_v;
                        Size[ulp_v] += Size[ulp_u];
                }

        }

};
int main(){
        DisjointSet ds(7);
        ds.unionBySize(1,2);
        ds.unionBySize(2,3);
        ds.unionBySize(4,5);
        ds.unionBySize(6,7);
        ds.unionBySize(5,6);
        if(ds.findUParent(3) == ds.findUParent(7)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        ds.unionBySize(3,7);
        if(ds.findUParent(3) == ds.findUParent(7)) cout<<"YES";
        else cout<<"NO";
}