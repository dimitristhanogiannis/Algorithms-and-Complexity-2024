#include <bits/stdc++.h>

using namespace std;

int N, M;

bool f(pair<int, int> i, pair<int, int> j){

    return i.first < j.first;
}

int max(int i, int j){

    if(i > j) return i;
    else return j;
}

bool greedy(vector<pair<int, int>> intervals, int d){

    int count = 0;
    int lastpos = -1e9;
    int pos;

    for(int i = 0; i < M; i++){
        pos = max(intervals[i].first, lastpos + d);
        while(pos <= intervals[i].second){
            count++;
            lastpos = pos;
            pos += d;
            
            if (count == N) return true;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<pair<int, int>> intervals(M);

    for(int i = 0; i < M; i++){
        cin >> intervals[i].first >> intervals[i].second; 
    }

    sort(intervals.begin(), intervals.end(), f);

    int low, high, mid, d;

    low = 1;

    high = 0;

    for(int i = 0; i < M; i++){
        high += intervals[i].second - intervals[i].first + 1;
    } 

    while(low <= high){
        mid = low + (high - low) / 2;
        if(greedy(intervals, mid)){
            d = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    cout << d << endl;

    return 0;    
}