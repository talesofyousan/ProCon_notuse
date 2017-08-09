//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1166&lang=jp

 #include<iostream>
 #include<vector>
 #include<queue>

 using namespace std;

 struct data{
     int x;
     int y;
 };

 int main(){

    while(1){
        int H,W;

        cin >> W >> H;
        cin.ignore();

        if(H+W == 0){
            break;
        }

        int distance[H][W];
        int dx[4] = {1,0,-1,0};
        int dy[4] = {0,1,0,-1};

        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                distance[i][j] = -1;
            }
        }

        int maze[2*H-1][W];
        for(int i=0;i<2*H-1;i++){
            if(i%2 == 0){
                for(int j=0;j<W-1;j++){
                    int a;
                    cin >> a;
                    maze[i][j] = a;
                }
                cin.ignore();
                maze[i][W-1] = -1;
            }else{
                for(int j=0;j<W;j++){
                    int a;
                    cin >> a;
                    maze[i][j] = a;
                }
                cin.ignore();
            }
        }

        data pos;
        pos.x = 0; pos.y = 0;
        queue<data> que;

        que.push(pos);
        distance[0][0] = 0;

        while(que.empty()==false){
            //cout << "-------------" << endl;

            data cur= que.front();
            que.pop();

            //cout << cur.x << "," << cur.y << endl;

            int nx = -1;
            int ny = -1;

            for(int i=0;i<4;i++){
                
                switch(i){
                    case 0:
                        //cout << "maze[" << 2*cur.y<<"]["<<cur.x<<"]="<<maze[2*cur.y][cur.x]<<endl;
                        if(cur.x != W-1 && maze[2*cur.y][cur.x] == 0){
                            nx = cur.x + dx[i];
                            ny = cur.y + dy[i];
                        }
                        break;
                    case 1:
                        //cout << "maze[" << 2*cur.y+1<<"]["<<cur.x<<"]="<<maze[2*cur.y+1][cur.x]<<endl;
                        if(cur.y != H-1 && maze[2*cur.y+1][cur.x] == 0){
                            nx = cur.x + dx[i];
                            ny = cur.y + dy[i];
                        }
                        break;
                    case 2:
                        //cout << "maze[" << 2*cur.y<<"]["<<cur.x-1<<"]="<<maze[2*cur.y][cur.x-1]<<endl;
                        if(cur.x != 0 && maze[2*cur.y][cur.x-1] == 0){
                            nx = cur.x + dx[i];
                            ny = cur.y + dy[i];
                        }
                        break;
                    case 3:
                        //cout << "maze[" << 2*cur.y-1<<"]["<<cur.x<<"]="<<maze[2*cur.y-1][cur.x]<<endl;
                        if(cur.y != 0 && maze[2*cur.y-1][cur.x] == 0){
                            nx = cur.x + dx[i];
                            ny = cur.y + dy[i];
                        }
                        break;
                    default:
                        break;
                }

                //cout << nx << "," << ny << endl;
                //cout << distance[ny][nx] << "," <<distance[cur.y][cur.x] + 1 << endl;

                if(nx+ny != -2){
                    if(distance[ny][nx] != -1){
                        if(distance[ny][nx] > distance[cur.y][cur.x] + 1){
                            distance[ny][nx] = distance[cur.y][cur.x] + 1;
                            que.push({nx,ny});
                        }
                    }else{
                        distance[ny][nx] = distance[cur.y][cur.x] + 1;
                        que.push({nx,ny});
                    }
                    nx = -1;
                    ny = -1;
                }

            }

            //cout << "-------------" << endl;

        }

/*
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cout << distance[i][j] << ",";
            }
            cout << endl;
        }
*/
        if(distance[H-1][W-1] == -1){
            cout << 0 << endl;
        }else{
            cout << distance[H-1][W-1]+1 << endl;
        }

    }


 }