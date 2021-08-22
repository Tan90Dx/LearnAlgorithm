#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,last;

void dfs(vector<vector<int>>&, int , int , int, int, int,int );

int main(){
    cin>>n;
    vector<vector<int>> map(n,vector<int>(n,0));
//    vector<vector<int>> flag(n,vector<int>(n,0));
    int a,b,c;
    while(true){
        cin>>a>>b>>c;
        if(a==0){
            break;
        }
        a--;b--;
        map[a][b]=c;
    }
    dfs(map,0,0,0,0,0,0);
    cout<<last;
    return 0;
}


void dfs( vector<vector<int>>& map,int x,int y,int a, int b,int total_xy,int total_ab){
    if(x>=n or y>=n or a>=n or b >=n){
        return;
    }
    if(x==n-1 and y==n-1 and a==n-1 and b==n-1){
        cout<<total_ab+total_xy<<endl;
        return ;

    }
    //Right Right
    const int temp_xy=map[x][y];
    const int temp_ab=map[a][b];
    map[x][y]=0;
    map[a][b]=0;
    dfs(map,x+1,y,a+1,b,total_xy+temp_xy,total_ab+temp_ab);
    map[x][y]=temp_xy;
    map[a][b]=temp_ab;

    //down down
    map[x][y]=0;
    map[a][b]=0;
    dfs(map,x,y+1,a,b+1,total_xy+temp_xy,total_ab+temp_ab);
    map[x][y]=temp_xy;
    map[a][b]=temp_ab;

    //down right
    map[x][y]=0;
    map[a][b]=0;
    dfs(map,x,y+1,a+1,b,total_xy+temp_xy,total_ab+temp_ab);
    map[x][y]=temp_xy;
    map[a][b]=temp_ab;

    //right down
    map[x][y]=0;
    map[a][b]=0;
    dfs(map,x+1,y,a,b+1,total_xy+temp_xy,total_ab+temp_ab);
    map[x][y]=temp_xy;
    map[a][b]=temp_ab;





}
