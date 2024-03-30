#include <bits/stdc++.h>

using namespace std;

class compare {
    public:
        bool operator()(pair<int, int> below, pair<int, int> above){
            if(below.first > above.first){
                return true;
            }
            return false;
        }
};

int main(){
    int T, exit;
    cin >> T;
    for(int a = 1; a <= T; a++){
        exit = 0;
        int N, Q, C;
        cin >> N >> Q >> C;
        int sequence[N + 1];
        for(int b = 1; b <= N; b++){
            cin >> sequence[b];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for(int b = 1; b <= Q; b++){
            pair<int, int> temp;
            cin >> temp.first >> temp.second;
            pq.push(temp);
        }
        int input[Q + 1][2];
        for(int b = 1; b <= Q; b++){
            input[b][0] = (pq.top()).first;
            input[b][1] = (pq.top()).second;
            pq.pop();
        }
        vector<int> mobile;
        mobile.push_back(0);
        for(int b = 1; b <= N; b++){
            if(sequence[b] == 0){
                sequence[b] = 1;
                mobile.push_back(b);
            }
        }
        mobile.push_back(N + 1);
        int pointer[N + 2];
        for(int b = 0; b < mobile.size() - 1; b++){
            for(int c = mobile[b] + 1; c <= mobile[b + 1]; c++){
                pointer[c] = mobile[b];
            }
        }
        int lastindex = 1;
        for(int b = 2; b <= Q; b++){
            if(input[b][0] < input[lastindex][1]){
                if(input[b][1] != input[lastindex][1]){
                    cout << -1 << "\n";
                    exit = 1;
                    break;
                }
                input[b][1] = 0;
            }
            else{
                lastindex = b;
            }
        }
        if(exit == 1){
            continue;
        }
        int max = sequence[1];
        for(int b = 2; b <= input[1][0]; b++){
            if(sequence[b] > max){
                max = sequence[b];
            }
        }
        lastindex = 0;
        for(int b = 1; b <= Q; b++){
            if(input[b][1] == 0){
                continue;
            }
            for(int c = input[b][0] + 1; c < input[b][1]; c++){
                if(sequence[c] > max){
                    if((lastindex != 0 && pointer[input[b][0] + 1] < input[lastindex][1]) || (lastindex == 0 && pointer[input[b][0] + 1] == 0)){
                        cout << -1 << "\n";
                        exit = 1;
                        break;
                    }
                    sequence[pointer[input[b][0] + 1]] = sequence[c];
                    max = sequence[c];
                }
            }
            if(exit == 1){
                break;
            }
            if(sequence[input[b][1]] <= max){
                if(pointer[input[b][1] + 1] != input[b][1]){
                    cout << -1 << "\n";
                    exit = 1;
                    break;
                }
                else{
                    sequence[input[b][1]] = max + 1;
                    max++;
                }
            }
            else{
                max = sequence[input[b][1]];
            }
            lastindex = b;
        }
        if(exit == 1){
            continue;
        }
        for(int a = 1; a <= N; a++){
            if(sequence[a] > C){
                cout << -1 << "\n";
                exit = 1;
                break;
            }
        }
        if(exit == 1){
            continue;
        }
        for(int a = 1; a <= N; a++){
            cout << sequence[a];
            if(a != N){
                cout << " ";
            }
        }
        cout << "\n";
    }
}