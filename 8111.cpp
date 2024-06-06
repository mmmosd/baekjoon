#include <iostream>
#include <stdio.h>
#include <queue>
#include <string>
using namespace std;

int t;

string find(int n) {
    string result = "";

    int visited[] = {0,};
    queue<string> q;

    q.push("1");

    while (!q.empty()) {
        string now = q.front();
        q.pop();

        for (int i = 0; i < 2; i++) {
            string diff = i==0?now.append("0"):now.append("1");

            if (diff.length() > 100) continue;
            if (visited[] == true) continue;
            visited[i] = true;

            q.push(diff);
        }
    }
    
}

int main() {
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        cout >> find(n);
    }
}