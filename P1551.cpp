//
// Created by tan90 on 2021/9/1.
//染色法,wa第七个点
#include <iostream>
#include <list>
#include <vector>
using namespace std;
int main(){
    int n,m,p;
    int id=1;
    cout<<(3<<2);
    cin>>n>>m>>p;
    vector<int> arr(n+1,-1);//开一个人数+1的数组，这个数组从1开始，arr【i】的值代表第i个人的颜色，初始值为-1
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        /**两个人的关系体现在数组上只有这几种情况
         * 1.如果arr【a】和arr【b】的值都为-1，说明他们还没有和任何人有关系，处理方法是给他们赋予相同的颜色
         * 2.arr【a】为-1,arr【b】的值不为-1, 说明a没有和任何人有关系,处理方法是把b的颜色给a
         * 3.arr【b】为-1,arr【a】的值不为-1, 说明b没有和任何人有关系,处理方法是把a的颜色给b
         * 4.arr[a]和arr[b]的值都不为-1,说明a和b之前具有独立的亲属关系,处理方法是遍历整个数组,将所有值为arr[b]的元素替换为arr[a]
         **/
        if(arr[a]==arr[b] and arr[a]==-1){
//            arr[a]=arr[b]==id++;
            arr[a]=id;
            arr[b]=id;
            id++;
        }
        else if(arr[a]==-1 and arr[b]!=-1){
            arr[a]=arr[b];
        }
        else if(arr[a]!=-1 and arr[b]==-1){
            arr[b]=arr[a];
        }
        else if(arr[a]!=arr[b]){
            int t=arr[b];
            for(int j=1;j<=n;j++){
                if(arr[j]==t){
                    arr[j]=arr[a];
                }
            }
        }
    }
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        /**判断的逻辑:
         * 1.如果两个值任意一个为-1,那么他们绝对没有亲属关系
         * 2.如果a不等于b,那么没有亲属关系
         * 3.如果a等于b,那么他们有亲属关系
         */
        if(arr[a]==-1||arr[b]==-1){
            cout<<"No"<<'\n';
        }
        else if(arr[a]!=arr[b]){
            cout<<"No"<<'\n';

        }
        else{
            cout<<"Yes"<<'\n';
        }
    }
    return 0;
}

//并查集法 ac
struct UniFind{
    const static int MAX=10005;
    int bin[MAX]{};
    UniFind(){
        for(int i=1;i<MAX-3;i++){
            bin[i]=i;
        }
    };
    int find(const int& x){
        if(bin[x]==x){
            return x;
        }
        return find(bin[x]);
    }
    void merge(int a,int b){
        bin[find(a)]=find(b);
    }
};
int main() {
    int n,m,p;
    cin>>n>>m>>p;
    UniFind uniFind;
    while(m--){
        int a,b;
        cin>>a>>b;
        uniFind.merge(a,b);
    }
    while(p--){
        int a,b;
        cin>>a>>b;
        if(uniFind.find(a)==uniFind.find(b)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

}
#include <iostream>
#include <list>
#include <vector>
#include <sstream>
using namespace std;
struct UniFind{
    const static int MAX=100005;
    int bin[MAX];
    UniFind(){
        for(int i=1;i<MAX-3;i++){
            //一开始都自立门户
            bin[i]=i;
        }
    }
    int find(int x){
        if(bin[x]==x){
            //如果要去询问的人是自己,那么自己就是BOSS
            return x;
        }
        int t=find(bin[x]);//不是就递归的寻找祖先
        bin[x]=t;//路径压缩(记忆化),前面已经找到了当前的祖先,所以就直接保存,避免了第二次访问又再一次重复递归过程
        return t;
    }
    void merge(int x,int y){
        bin[find(x)]=find(y);//合并就直接把x的祖先从x替换为y的祖先
    }
};
struct UniFindByRank{
    const static int MAX=100005;
    int bin[MAX];
    int rk[MAX];
    UniFindByRank(){
        for(int i=1;i<MAX-3;i++)
            bin[i]=i;
    }
    int find(int x){
        if(bin[x]==x){
            return x;
        }
        return bin[x]= find(bin[x]);
    }
    void merge(int x,int y){
        x= find(x);y=find(y);
        if(x==y)return;
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
int main() {
    int n,m,p;
    cin>>n>>m>>p;
    UniFindByRank uniFind;
    while(m--){
        int a,b;
        cin>>a>>b;
        uniFind.merge(a,b);
    }
    while(p--){
        int a,b;
        cin>>a>>b;
        if(uniFind.find(a)==uniFind.find(b)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }

}

