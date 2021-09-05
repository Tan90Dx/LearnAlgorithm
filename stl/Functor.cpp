//
// Created by tan90 on 2021/9/2.
//
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <vector>
using namespace std;
template<typename elementType,int* a>//非类型形参
struct FunctionObject{
    int t;//函数对象可以存储状态
    int operator()(const elementType & element){//若后面加const表示常成员函数，不能改变成员变量的值
        t++;
        cout<<element<<" ";
    }
    FunctionObject(){
        t=0;
        cout<<*a<<"bb\n";
    }
};
int bb=3;
int main(){
    int n,m;
    unordered_set<string> set;
    vector<int> arr{1,2,3,4,5,6};
    bb++;
    FunctionObject<int,&bb> functionObject;
//    for_each(arr.begin(),arr.end(), FunctionObject<int>());//匿名函数对象
    functionObject=for_each(arr.begin(),arr.end(),functionObject);//匿名函数对象
    //for_Each返回仿函数的最终状态
    cout<<endl<<functionObject.t;


    return 0;
}
