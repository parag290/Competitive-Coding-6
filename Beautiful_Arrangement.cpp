/*
Leetcode : https://leetcode.com/problems/beautiful-arrangement/description/

Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
perm[i] is divisible by i.
i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.
Watch vide for more understanding : https://www.youtube.com/watch?v=c4jou17l2ys
*/


class Solution {
    int count{0};
public:
    int countArrangement(int n) {
        vector<int>numbers;
        for(int i = 1; i <=n ;i++){
            numbers.push_back(i);
        }
        vector<int>path;
        set<int>hSet;
        dfs(numbers, 1, path, hSet, n);
        return count;
    }

    void dfs(vector<int>numbers, int idx, vector<int>&path, set<int>&hSet, int n){
        if(idx == n+1){
            count++;
            return;
        }
        for(int i=0; i<n; i++){
            if(hSet.find(numbers[i]) == hSet.end()){
                if(numbers[i]%idx==0 || idx%numbers[i] == 0){
                    hSet.insert(numbers[i]);
                    path.push_back(numbers[i]);
                    dfs(numbers, idx+1, path, hSet, n);
                    hSet.erase(numbers[i]);
                    path.pop_back();
                }
            }
        }


    }

};