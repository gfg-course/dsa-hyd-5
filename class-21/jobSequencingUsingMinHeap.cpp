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

bool deadlinesComp(Job* &a, Job* &b) {
    if (a->deadline == b->deadline) {
        return a->profit > b->profit;
    }
    return a->deadline < b->deadline;
}

// TC: O(n*log(n))
// AS: O(n)
vector<int> getMaxProfit(vector<Job*> jobs) {

    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), deadlinesComp);

    priority_queue<int, vector<int>, greater<int>> profits; // min-heap of profits.
    int maxProfit = 0, jobsDone = 0;

    for (int i = 0; i < n; i++) {
        if (jobs[i]->deadline > jobsDone) {
            jobsDone++;
            maxProfit += jobs[i]->profit;
            profits.push(jobs[i]->profit);
        } else {
            if (jobs[i]->profit > profits.top()) {
                maxProfit += jobs[i]->profit - profits.top();
                profits.pop();
                profits.push(jobs[i]->profit);
            }
        }
    }
    

    return {maxProfit, jobsDone};
}

int main() {

    vector<int> res1 = getMaxProfit({new Job(1, 4, 20), new Job(2, 1, 10), new Job(3, 1, 40), new Job(4, 1, 30)});
    vector<int> res2 = getMaxProfit({new Job(1, 2, 100), new Job(2, 1, 19), new Job(3, 2, 27), new Job(4, 1, 25), new Job(5, 1, 15)});

    cout << res1[0] << " " << res1[1] << endl;
    cout << res2[0] << " " << res2[1] << endl;
}
