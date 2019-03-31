#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istringstream;

#define MAXSIZE 100

/**
 * 向周围四个方向偏移
 */
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

/**
 * 记录输入的地图
 */
char     map[MAXSIZE][MAXSIZE];

/**
 * 当前位置是否已经被访问过
 */
bool    vis[MAXSIZE][MAXSIZE];
/**
 * 矩阵的大小
 */
int     n, m;

/**
 *目标路径
 */
string  target;

/**
 *检查坐标(xpos, ypos)是否越界
 */
bool check(int xpos, int ypos)
{
    return xpos >= 0 && xpos < n && ypos >= 0 && ypos < m;
}

/**
 *输出当前搜索状态
 */
void print(string &path)
{
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << vis[i][j] << ' ';
        }
        cout << endl;
    }
    cout << "Path:" << path << endl;
}

/**
 * 深度优先搜索
 */
bool dfs(int x, int y, string &path)
{
    #ifdef DEBUG
    print(path );
    #endif // DEBUG

    /**
     * 已经搜索到目标路径
     */
    if(path == target) {
        return true;
    }

    /**
     * 向四个方向搜索
     */
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(check(nx, ny) == false)
            continue;
        if(vis[nx][ny] == true)
            continue;

        vis[nx][ny] = true;
        string p = path + map[nx][ny];
        if(dfs(nx, ny, p) == true)
            return true;
        vis[nx][ny] = false;
    }

    return false;
}

void slove()
{
    string path = "";
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(dfs(i, j, path)) {
                std::cout << "I find it!" << std::endl;
                return;
            }
        }
    }

    std::cout << "I can't find it..." << std::endl;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> map[i];

    cin >> target;

    slove();
    return 0;
}
/*

3 4
abtg
cfcs
jdeh

bfce

*/
