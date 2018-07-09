#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>
#include <queue>
#include <utility>
#define P pair<int,int>
#define x first
#define y second
using namespace std;

const int MAXN = 305;

int n,m,sx,sy,tx,ty;
char arr[MAXN][MAXN];
bool state[4][MAXN][MAXN];
bitset<4> chk[MAXN][MAXN];
void read_input(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%s", arr[i] + 1);
	}
}

void maze(int i, int j, int S, int M){
	int L, R;
	state[S][i][j] = true;
	if(M == 0){
		L = i-1, R = i+1;
		while(L >= 1 || R <= n){
			if(arr[L][j] == '.') state[S][L][j] = true;
			else L = 1;
			if(arr[R][j] == '.') state[S][R][j] = true;
			else R = n;
			L--, R++;
		}
	}else if(M == 1){
		int x1 = i+1, y1 = j-1, x2 = i-1, y2 = j+1;
		while((x1 <= n && y1 >= 1) || (x2 >= 1 && y2 <= m)){
			if(arr[x1][y1] == '.') state[S][x1][y1] = true;
			else{
				x1 = n;
				y1 = 1;
			}
			x1++, y1--;
			if(arr[x2][y2] == '.') state[S][x2][y2] = true;
			else{
				x2 = 1;
				y2 = m;
			}
			x2--, y2++;
		}
	}else if(M == 2){
		L = j-1, R = j+1;
		while(L >= 1 || R <= m){
			if(arr[i][L] == '.') state[S][i][L] = true;
			else L = 1;
			if(arr[i][R] == '.') state[S][i][R] = true;
			else R = m;
			L--,R++;
		}
	}else if(M == 3){
		int x1 = i+1, y1 = j+1, x2 = i-1, y2 = j-1;
		while((x1 <= n && y1 <= m) || (x2 >= 1 && y2 >= 1)){
			if(arr[x1][y1] == '.') state[S][x1][y1] = true;
			else{
				x1 = n;
				y1 = m;
			}
			x1++, y1++;
			if(arr[x2][y2] == '.') state[S][x2][y2] = true;
			else{
				x2 = 1;
				y2 = 1;
			}
			x2--, y2--;
		}
	}	
}

void build(){
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(arr[i][j] == '-'){
				maze(i, j, 0, 2);
				maze(i, j, 1, 3);
				maze(i, j, 2, 0);
				maze(i, j, 3, 1);
			}
			if(arr[i][j] == '|'){
				maze(i, j, 0, 0);
				maze(i, j, 1, 1);
				maze(i, j, 2, 2);
				maze(i, j, 3, 3);

			}
			if(arr[i][j] == '\\'){
				maze(i, j, 0, 3);
				maze(i, j, 1, 0);
				maze(i, j, 2, 1);
				maze(i, j, 3, 2);
			}
			if(arr[i][j] == '/'){
				maze(i, j, 0, 1);
				maze(i, j, 1, 2);
				maze(i, j, 2, 3);
				maze(i, j, 3, 0);
			}
			if(arr[i][j] == 'S'){
				sx = i, sy = j;
			}
			if(arr[i][j] == 'E'){
				tx = i, ty = j;
			}
		}
	}
}
typedef struct node{
	int x,y,l;	
}node;

int x_[] = {0,0,1,-1}, y_[] = {-1,1,0,0};

int solve(){
	queue<node> Q;
	Q.push({sx,sy,0});
	while(!Q.empty()){
		node now = Q.front();
		Q.pop();
		// printf("%d %d %d\n", now.x, now.y, now.l);
		if(now.x == tx && now.y == ty) return now.l;
		for(int i = 0;i<4;++i){
			int nx = now.x + x_[i];
			int ny = now.y + y_[i];
			int nl = now.l + 1;
			if(nx < 1 || nx > n || ny < 1 || ny > m || state[nl%4][nx][ny] || chk[nx][ny][nl%4] || arr[nx][ny] == '#') continue;
			chk[nx][ny][nl%4] = true;
			Q.push({nx, ny, nl});
		}
		//if(Q.size() > 100000) break;
	}
	return -1;
}

int main(){
	// printf("-1\n");
	// return 0;
	//freopen("r","r",stdin);
	read_input();
	build();
	printf("%d\n", solve());
	// for(int z = 0; z < 4; ++z){
	// 	for(int i = 1; i <= n; ++i){
	// 		for(int j = 1; j <= m; ++j){
	// 			printf("%d", state[z][i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("-----------\n");
	// }
}