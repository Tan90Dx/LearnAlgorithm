#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> map(n,vector<int>(n,0));
    vector<vector<bool>> flag(n,vector<bool>(n,false));
    int a,b,c;
    while(true){
        cin>>a>>b>>c;
        if(a==0){
            break;
        }
        a--;b--;
        map[a][b]=c;
    }
    return 0;
}
void bfs(const vector<vector<int>>& map, vector<vector<int>>& flag,const int& n){
    queue<pair<int,int>> que;
    int last=0;
    int move_x[]={0,1};
    int move_y[]={1,0};
    que.push(make_pair(0,0));
    while(!que.empty()){
        int x=que.front().first;
        int y=que.front().second;
        que.pop();
        flag[x][y]=true;
        for(int i=0;i<2;i++){
            int x_new=x+move_x[i];
            int y_new=x+move_y[i];
            int temp=last;
            if(x_new<n and y_new<n and flag[x_new][y_new]==false){
                if(last)
            }
        }
        if(x==n-1 and y==n-1){
            break;
        }
    }
}