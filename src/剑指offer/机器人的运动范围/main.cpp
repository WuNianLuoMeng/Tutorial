#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::pair;
using std::queue;

#define MAXSIZE 100

const int   dx[] = {1, 0, -1, 0};
const int   dy[] = {0, 1, 0, -1};

bool        vis[MAXSIZE][MAXSIZE];

int bitSum(int num)
{
    int sum = 0;
    while(num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void slove(int n, int m, int k)
{
    queue<pair<int, int> > Q;
    Q.push(std::make_pair(0, 0));
    memset(vis, 0, sizeof(vis));
    vis[0][0] = true;
    int cnt = 1;
    while(!Q.empty()) {

        pair<int, int> now = Q.front();
        Q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = now.first + dx[i];
            int ny = now.second + dy[i];

            if(!(nx >= 0 && nx < n && ny >= 0 && ny < m))
                continue;

            if(vis[nx][ny] == true)
                continue;

            if(bitSum(nx) + bitSum(ny) > k)
                continue;

            Q.push(std::make_pair(nx, ny));
            vis[nx][ny] = true;
            cnt++;
        }
    }

    cout << cnt << endl;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    slove(n, m, k);
    return 0;
}
