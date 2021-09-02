//link：https://www.luogu.com.cn/problem/P3367
// Created by tan90 on 2021/9/1.
//并查集模板
#include <iostream>
using namespace std;
struct UniFind{
    const static int MAX=100005;
    int bin[MAX];
    int rk[MAX];
    UniFind(){
        for(int i=1;i<MAX-3;i++){
            bin[i]=i;
            rk[i]=i;
        }
    }
    int find(int x){
        if(x==bin[x]){
            return x;
        }
        return find(bin[x]);
    }
    int merge(int x,int y){
        bin[find(x)]=find(y);
    }
};
struct UniFindMemorize{
    const static int MAX=100005;
    int bin[MAX];
    int rk[MAX];
    UniFindMemorize(){
        for(int i=1;i<MAX-3;i++){
            bin[i]=i;
            rk[i]=i;
        }
    }
    int find(int x){
        if(x==bin[x]){
            return x;
        }
        return bin[x]=find(bin[x]);
    }
    int merge(int x,int y){
        bin[find(x)]=find(y);
    }
};
struct UniFindByRank{
    const static int MAX=100005;
    int bin[MAX];
    int rk[MAX];
    UniFindByRank(){
        for(int i=1;i<MAX-3;i++){
            bin[i]=i;
            rk[i]=i;
        }
    }
    int find(int x){
        if(x==bin[x]){
            return x;
        }
        return find(bin[x]);
    }
    void merge(int x,int y){
        x= find(x);y= find(y);
        if(x==y){
            return;
        }
        if(rk[x]<rk[y]){
            bin[x]=y;
        }
        else{
            bin[y]=x;
            if(rk[x]==rk[y]){
                rk[x]++;
            }
        }

    }
};
struct UniFindBoth{
    const static int MAX=100005;
    int bin[MAX];
    int rk[MAX];
    UniFindBoth(){
        for(int i=1;i<MAX-3;i++){
            bin[i]=i;
            rk[i]=i;
        }
    }
    int find(int x){
        if(x==bin[x]){
            return x;
        }
        return bin[x]=find(bin[x]);
    }
    void merge(int x,int y){
        x= find(x);y= find(y);
        if(x==y){
            return;
        }
        if(rk[x]<rk[y]){
            bin[x]=y;
        }
        else{
            bin[y]=x;
            if(rk[x]==rk[y]){
                rk[x]++;
            }
        }

    }
};

int main(){
    int n,m;
    cin>>n>>m;
    UniFindBoth uniFind;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            uniFind.merge(b,c);
        }else{
            if(uniFind.find(c)==uniFind.find(b)){
                cout<<"Y\n";
            }
            else{
                cout<<"N\n";
            }
        }
    }
    return 0;
}