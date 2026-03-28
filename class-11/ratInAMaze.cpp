#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i, int j, vector<vector<int>> &arr) {
    return
        i >= 0 && i < arr.size() &&
        j >= 0 && j < arr[i].size() &&
        arr[i][j] == 1;
}

int dx[4] = {+1, +0, +0, -1};
int dy[4] = {+0, -1, +1, +0};
char dir[4] = {'D', 'L', 'R', 'U'};

void getAllPathsUtil(int i, int j, vector<vector<int>> &arr, string &curr, vector<string> &res) {
    if (i == arr.size() - 1 && j == arr[i].size() - 1) {
        res.push_back(curr);
        return;
    }

    arr[i][j] = 0;

    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        char ch = dir[k];

        if (isSafe(new_i, new_j, arr)) {
            curr.push_back(ch);
            getAllPathsUtil(new_i, new_j, arr, curr, res);
            curr.pop_back();
        }
    }

    // // Down - (i + 1, j)
    // if (isSafe(i + 1, j, arr)) {
    //     curr.push_back('D');
    //     getAllPathsUtil(i + 1, j, arr, curr, res);
    //     curr.pop_back();
    // }

    // // Left - (i, j - 1)
    // if (isSafe(i, j - 1, arr)) {
    //     curr.push_back('L');
    //     getAllPathsUtil(i, j - 1, arr, curr, res);
    //     curr.pop_back();
    // }

    // // Right - (i, j + 1)
    // if (isSafe(i, j + 1, arr)) {
    //     curr.push_back('R');
    //     getAllPathsUtil(i, j + 1, arr, curr, res);
    //     curr.pop_back();
    // }

    // // Up - (i - 1, j)
    // if (isSafe(i - 1, j, arr)) {
    //     curr.push_back('U');
    //     getAllPathsUtil(i - 1, j, arr, curr, res);
    //     curr.pop_back();
    // }

    arr[i][j] = 1;
}

// TC: TODO
// AS: TODO
vector<string> getAllPaths(vector<vector<int>> arr) {
    string curr = "";
    vector<string> res;

    if (arr[0][0] == 0) {
        return res;
    }

    getAllPathsUtil(0, 0, arr, curr, res);
    return res;
}

int main() {

    vector<string> res = getAllPaths({
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    });

    for (auto i : res){
        cout << i << " ";
    }

    cout << endl;

    vector<string> res2 = getAllPaths({
        {1, 0, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {0, 1, 1, 1}
    });

    for (auto i : res2){
        cout << i << " ";
    }
}
