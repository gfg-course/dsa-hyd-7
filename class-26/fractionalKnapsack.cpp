#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(n))
// AS: O(n)
double getMaxValue(vector<int> values, vector<int> wts, int W) {

    int n = values.size();

    vector<pair<double, int>> valByWtToWt(n);
    for (int i = 0; i < n; i++) {
        valByWtToWt[i] = {(double)values[i] / wts[i], wts[i]};
    }

    // Sort in reverse order of values[i]/wts[i].
    sort(valByWtToWt.begin(), valByWtToWt.end(), greater<pair<double, int>>());

    double result = 0;
    for (int i = 0; i < n; i++) {
        double valByWt = valByWtToWt[i].first;
        int wt = valByWtToWt[i].second;

        if (wt <= W) {
            result += wt * valByWt;
            W -= wt;
        } else {
            result += W * valByWt;
            W = 0;
            break;
        }
    }

    return result;
}

int main() {

    cout << getMaxValue({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << getMaxValue({60, 100, 120}, {9, 19, 29}, 50) << endl;
}
