#include <iostream>
using namespace std;
struct UniFind{
    int bin[10005];
    UniFind(){
      for(int i=1;i<10003;i++){
          bin[i]=i;
      }
    };
    int find(int x){
        if(bin[x]==x){
            return x;
        }
        return bin[x]=find(bin[x]);
    }
    void merge(int x,int y){
        x=find(x);y=find(y);
        if(x==1){
            int t=x;
            x=y;
            y=t;
        }
        bin[x]=y;
    }
};

int main (){
    int n,m,p,q;
    UniFind a,b;
    cin>>n>>m>>p>>q;
    while(p--){
        int x,y;
        cin>>x>>y;
        a.merge(x,y);
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        b.merge(abs(x), abs(y));
    }
    int af=0,bf=0;
    for(int i=1;i<=n;i++){
        int t1=a.find(i);
        if(t1==1){
            af++;
        }
    }
    for(int i=1;i<=m;i++){
        int t2=b.find(i);
        if(t2==1){
            bf++;
        }
    }
    cout<<(af>bf?bf:af);
    return 0;
}