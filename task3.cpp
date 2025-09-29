#include <iostream>
using namespace std;

int n=4;
int maze[4][4]={{1,1,1,1},
                {0,0,0,1},
                {1,1,0,1},
                {1,1,1,1}};
int sol[4][4];

bool safe(int x,int y){
    return (x>=0 && y>=0 && x<n && y<n && maze[x][y]==1);
}

bool path(int x,int y,int tx,int ty){
    if(x==tx && y==ty){
        sol[x][y]=1;
        return true;
    }
    if(safe(x,y)){
        if(sol[x][y]==1) return false;
        sol[x][y]=1;
        if(path(x+1,y,tx,ty)) return true;
        if(path(x,y+1,tx,ty)) return true;
        if(path(x-1,y,tx,ty)) return true;
        if(path(x,y-1,tx,ty)) return true;
        sol[x][y]=0;
    }
    return false;
}

int main(){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            sol[i][j]=0;

    int tx=2,ty=0;
    if(path(0,0,tx,ty)){
        cout<<"Path found:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        cout<<"No path"<<endl;
    }
}
