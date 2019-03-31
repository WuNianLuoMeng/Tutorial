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
 * ����Χ�ĸ�����ƫ��
 */
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

/**
 * ��¼����ĵ�ͼ
 */
char     map[MAXSIZE][MAXSIZE];

/**
 * ��ǰλ���Ƿ��Ѿ������ʹ�
 */
bool    vis[MAXSIZE][MAXSIZE];
/**
 * ����Ĵ�С
 */
int     n, m;

/**
 *Ŀ��·��
 */
string  target;

/**
 *�������(xpos, ypos)�Ƿ�Խ��
 */
bool check(int xpos, int ypos)
{
    return xpos >= 0 && xpos < n && ypos >= 0 && ypos < m;
}

/**
 *�����ǰ����״̬
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
 * �����������
 */
bool dfs(int x, int y, string &path)
{
    #ifdef DEBUG
    print(path );
    #endif // DEBUG

    /**
     * �Ѿ�������Ŀ��·��
     */
    if(path == target) {
        return true;
    }

    /**
     * ���ĸ���������
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
