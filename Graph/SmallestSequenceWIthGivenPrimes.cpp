/* the idea is to start traversing the rectangle co-ordinates one by one
from each (i,j) i have 8 choices to move , for doing this i will use 
queue and visited array , visited help in reducing same call 
at each (i,j) i will first check wheter the point lies inside any circle or
not by calculating it distance from centre of each circle ,if distance is greater than 
r then point lies outside the circle , after my queue is empty if the (x,y)
co-ordinate is marked as visited means it is possible to reach there */

// these are the moves which i can take from any position i,j 
int dpx[8]={1,1,1,-1,-1,-1,0,0};
int dpy[8]={-1,1,0,1,-1,0,-1,1};

// this function is used to check wheter the i,j column lies inside the rectangle or not
bool valid(int x,int y,int A,int B){
    if(x<0||x>A||y<0||y>B){
        return false;
    }
    return true;
}

// this function check wheter the point x,y lies inside any circle or not
bool inCircle(int x,int y,int C,int D,vector<int>&E,vector<int>&F){
    for(int i=0;i<C;i++){
        if(((x-E[i])*(x-E[i])+(y-F[i])*(y-F[i]))<=(D*D))
         return true;
    }
    return false;
}

string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
          // visited array
          bool vis[A+1][B+1];
          memset(vis,false,sizeof(vis));
          queue<pair<int,int>> myque;
          myque.push({0,0});
          vis[0][0]=true;
          // first checking wheter the point (0,0) lies in circle or not
          if(inCircle(0,0,C,D,E,F))
           return "NO";
          
          
          while(myque.size()){
              // pick first element of queue
              pair<int,int> temp=myque.front();
              myque.pop();
              // checking all 8 possible moves
              for(int i=0;i<8;i++){
                  int a=temp.first+dpx[i];
                  int b=temp.second+dpy[i];
                  if(!vis[a][b]&&valid(a,b,A,B)&&!inCircle(a,b,C,D,E,F)){
                     
                      myque.push({a,b});
                      vis[a][b]=true;
                  }
              }
          } 
          if(vis[A][B])
          return "YES";
          else
          return "NO";
    
}
