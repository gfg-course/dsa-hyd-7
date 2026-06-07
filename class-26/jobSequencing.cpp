#include<bits/stdc++.h>
using namespace std;

class Job {
    public:
    int id;
    int deadline; 
    int profit;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool profitsComp(Job* &a, Job* &b) {
    if (a->profit == b->profit) {
        return a->deadline > b->deadline;
    }

    return a->profit > b->profit;
}

// TC: O(n*log(n) + n*min(n, maxDeadline))
// AS: O(maxDeadline)
pair<int, int> getMaxProfit(vector<Job*> jobs) {

    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), profitsComp);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i]->deadline);
    }

    vector<int> slots(maxDeadline, -1);

    int jobsDone = 0, profitGained = 0;
    for (int i = 0; i < n; i++) {
        int j = jobs[i]->deadline - 1;
        while (j >= 0) {
            if (slots[j] == -1) {
                jobsDone++;
                profitGained += jobs[i]->profit;
                slots[j] = jobs[i]->id;
                break;
            }
            j--;
        }
    }

    return {jobsDone, profitGained};
}

int main() {

    pair<int, int> result = getMaxProfit({
        new Job(1, 4, 20),
        new Job(2, 1, 10),
        new Job(3, 1, 40),
        new Job(4, 1, 30),
    });

    cout << result.first << " " << result.second << endl;

    pair<int, int> result2 = getMaxProfit({
        new Job(1, 2, 100),
        new Job(2, 1, 19),
        new Job(3, 2, 27),
        new Job(4, 1, 25),
        new Job(5, 1, 15),
    });

    cout << result2.first << " " << result2.second << endl;

    pair<int, int> result3 = getMaxProfit({
        new Job(1, 2, 100),
        new Job(2, 1, 19),
        new Job(3, 1, 27),
        new Job(4, 1, 25),
        new Job(5, 1, 15),
    });

    cout << result3.first << " " << result3.second << endl;
}
