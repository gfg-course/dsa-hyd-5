#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, vector<vector<int>> &maze) {

    return
        i >= 0 && i < maze.size() &&
        j >= 0 && j < maze[i].size() &&
        maze[i][j] == 1;
}

int dx[4] =   {+1, +0, +0, -1};
int dy[4] =   {+0, -1, +1, +0};
char dir[4] = {'D', 'L', 'R', 'U'};
void ratInAMazeUtil(int i, int j, vector<vector<int>> &maze, string &curr, vector<string> &result) {
    
    if (i == maze.size() - 1 && j == maze[i].size() - 1) {
        result.push_back(curr);
        return;
    }

    maze[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (isValid(new_i, new_j, maze)) {
            curr.push_back(dir[k]);
            ratInAMazeUtil(new_i, new_j, maze, curr, result);
            curr.pop_back();
        }
    }

    // // Down
    // if (isValid(i + 1, j, maze)) {
    //     curr.push_back('D');
    //     ratInAMazeUtil(i + 1, j, maze, curr, result);
    //     curr.pop_back();
    // }

    // // Left
    // if (isValid(i, j - 1, maze)) {
    //     curr.push_back('L');
    //     ratInAMazeUtil(i, j - 1, maze, curr, result);
    //     curr.pop_back();
    // }

    // // Right
    // if (isValid(i, j + 1, maze)) {
    //     curr.push_back('R');
    //     ratInAMazeUtil(i, j + 1, maze, curr, result);
    //     curr.pop_back();
    // }

    // // Up
    // if (isValid(i - 1, j, maze)) {
    //     curr.push_back('U');
    //     ratInAMazeUtil(i - 1, j, maze, curr, result);
    //     curr.pop_back();
    // }

    maze[i][j] = 1;
}

// H = O(n^2)
// TC: O(4 ^ (n^2))
// AS: O(n^2)
vector<string> ratInAMaze(vector<vector<int>> maze) {

    if (maze[0][0] == 0) {
        return {};
    }

    string curr = "";
    vector<string> result;

    ratInAMazeUtil(0, 0, maze, curr, result);
    return result;
}

int main() {

    vector<string> res = ratInAMaze({{1, 0, 0, 0},
                                     {1, 1, 0, 1},
                                     {1, 1, 0, 0},
                                     {0, 1, 1, 1}});
    
    for (string i : res) {
        cout << i << " ";
    }

    cout << endl;

    vector<string> res2 = ratInAMaze({{1, 1, 1},
                                    {1, 0, 1},
                                    {0, 0, 1}});

    for (string i : res2) {
        cout << i << " ";
    }
}
