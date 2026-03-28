#include<bits/stdc++.h>
using namespace std;

/*
if a < b:
    return something (true)
otherwise
    return something_else (false)
*/
bool timelineComp(pair<int, char> &a, pair<int, char> &b) {

    if (a.first == b.first) {
        // if (a.second == 'a') {
        //     return true;
        // } else {
        //     return false;
        // }
        return a.second == 'a';
    }

    // if (a.first < b.first) {
    //     return true;
    // } else {
    //     return false;
    // }
    return a.first < b.first;
}

// TC: O(n*log(n))
// AS: O(n)
int getMinPlatforms(vector<int> arr, vector<int> dep) {

    int n = arr.size();
    vector<pair<int, char>> timeline;
    for (int i = 0; i < n; i++) {
        timeline.push_back({arr[i], 'a'});
        timeline.push_back({dep[i], 'd'});
    }

    sort(timeline.begin(), timeline.end(), timelineComp);

    int currentCount = 0, maxCount = 0;
    for (int i = 0; i < timeline.size(); i++) {
        if (timeline[i].second == 'a') {
            currentCount++;
        } else {
            currentCount--;
        }

        maxCount = max(maxCount, currentCount);
    }

    return maxCount;
}

int main() {

    cout << getMinPlatforms({900, 940, 950, 1100, 1500, 1800}, {910, 1200, 1120, 1130, 1900, 2000}) << endl;;
    cout << getMinPlatforms({1000, 1200}, {1200, 1500}) << endl;;
}
