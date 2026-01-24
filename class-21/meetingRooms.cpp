#include<bits/stdc++.h>
using namespace std;

// return true -> order of (a, b) will be retained. That is, a will come before b.
// return false -> order of (a, b) will be reversed. That is, b will come before a.
bool cmp(pair<int, char> &a, pair<int, char> &b) {
    if (a.first == b.first) {
        // if (a.second == 'e') {
        //     return true;
        // }
        // return false;
        return a.second == 'e';
    }

    // if (a.first < b.first) {
    //     return true;
    // }
    // return false;
    return a.first < b.first;
}

// TC: O(n * log(n))
// AS: O(n)
int getMinRooms(vector<vector<int>> meetings) {
    int n = meetings.size();

    vector<pair<int, char>> timeline;
    for (int i = 0; i < n; i++) {
        timeline.push_back({meetings[i][0], 's'});
        timeline.push_back({meetings[i][1], 'e'});
    }

    // sort(timeline.begin(), timeline.end(), cmp);
    sort(timeline.begin(), timeline.end());

    int currentMeetings = 0, maxMeetings = 0;
    for (int i = 0; i < timeline.size(); i++) {
        if (timeline[i].second == 's') {
            currentMeetings++;
        } else {
            currentMeetings--;
        }

        maxMeetings = max(maxMeetings, currentMeetings);
    }

    return maxMeetings;
}

int main() {

    cout << getMinRooms({{1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13}}) << endl;
}
