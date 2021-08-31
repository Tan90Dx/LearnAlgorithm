//link:https://www.luogu.com.cn/problem/P1449
// Created by tan90 on 2021/8/30.
//思路：遇到数字持续读入直到遇见点号，转为数字存入栈中，遇见运算符出两个栈，执行运算
#include <iostream>
#include <cstdio>
#include <string>
using namespace  std;
struct stack{
    //手写栈
    int arr[10010];
    int p=-1;
    void push(const int& c){
        arr[++p]=c;
    }
    void pop(){
        p--;
    }
    int getTop(){
        return arr[p];
    }
};
int main(){
    string str;
    stack s;
    cin>>str;
    int p=0;
    string temp="";
    while (str[p]!='@'){
        if(str[p]>='0'&&str[p]<'9'){
            temp.push_back(str[p]);
        }
        else if(str[p]=='.'){
            int n=0,t=1;
            for(int i=temp.length()-1;i>=0;i--){
                //手写字符串转数字
                n+=(temp[i]-'0')*t;
                t*=10;
            }
            s.push(n);
            temp.clear();
        }
        else if(str[p]=='-'){
            int a=s.getTop();
            s.pop();
            int b=s.getTop();
            s.pop();
            int t=b-a;
            s.push(t);
        }
        else if(str[p]=='+'){
            int a=s.getTop();
            s.pop();
            int b=s.getTop();
            s.pop();
            int t=b+a;
            s.push(t);
        }
        else if(str[p]=='*'){
            int a=s.getTop();
            s.pop();
            int b=s.getTop();
            s.pop();
            int t=b*a;
            s.push(t);
        }
        else if(str[p]=='/'){
            int a=s.getTop();
            s.pop();
            int b=s.getTop();
            s.pop();
            int t=b/a;
            s.push(t);
        }
        p++;

    }
    cout<<s.getTop();

    return 0;
}

