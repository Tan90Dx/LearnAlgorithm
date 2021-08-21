//
// Created by tan90 on 2021/8/21.
// Link:https://www.luogu.com.cn/problem/P1003
#include <iostream>
#include <stack>
using namespace std;
struct Rectangle{
    //定义一个长方形的结构体，用两对pair保存长方形的左下，右上的顶点坐标
    pair<int,int> a;//左下
    pair<int,int> b;//右上
};
int main(){
    int n;
    stack<Rectangle> arr;//使用栈来保存所有长方体的数据
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,g,k;
        cin>>a>>b>>g>>k;
        Rectangle rectangle={make_pair(a,b), make_pair(a+g,b+k)};//计算顶点坐标
        arr.push(rectangle);//入栈
    }
    int ra,rb;//要判断的点
    cin>>ra>>rb;
    while(!arr.empty()){
        //倒序遍历，因为后铺的地毯一定在前面的地毯上
        int a,b,c,d;
        a=arr.top().a.first;
        b=arr.top().a.second;
        c=arr.top().b.first;
        d=arr.top().b.second;
        if(ra>=a and rb>=b and ra<=c and rb<=d){
            //如果这个点的坐标在两个顶点坐标范围内，那么则在地毯上
            cout<<n;
            break;
        }
        n--;
        arr.pop();//出栈
    }
    if(n==0){
        //如果没有找到，输出-1
        cout<<-1;
    }


}
