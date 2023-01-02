//Link : https://leetcode.com/problems/bulls-and-cows/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        // int vis[n] = {0};
        vector<int> vis(n, 0);
        int no_of_bulls=0;
        int no_of_cows=0;
        map<char, int> mp;
        char ele;

        for(int i=0; i<n; i++){
            if(secret[i] == guess[i]){
                no_of_bulls++;
                ele = guess[i];
                int a = ele-'0';
                // cout<<a<<endl;
                vis[i] = 1;
            }
            else{
                ele = secret[i];
                mp[ele]++;
            }
        }
        char x;
        int a;
        for(int i=0; i<n; i++){
            x = guess[i];
            a = x-'0';
            if(mp.find(x)!=mp.end() && mp[x] >0 && !vis[i]){
                no_of_cows++;
                mp[x]--;
            }
        }

        // cout<<no_of_bulls<<" "<<no_of_cows<<endl;
        string bulls = to_string(no_of_bulls);
        string cows = to_string(no_of_cows);

        string ans = bulls+"A"+cows+"B";
        return ans;
    }
};