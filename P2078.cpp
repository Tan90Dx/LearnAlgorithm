//link:https://www.luogu.com.cn/problem/P2078
// Created by tan90 on 2021/9/2.
//
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
            //这里确保了是1（小明，小红）是所有他的朋友的父节点，所以查询的时候，只需要比较他的父节点是不是1就能知道和他们是不是朋友
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
        //对于女性，处理方法就是取绝对值，因为数组下标不可能出现负数，一样的，不影响
    }
    int af=0,bf=0;
    //统计小明和小红各有多少个朋友，然后取最小的输出就是能组成的情侣数
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
