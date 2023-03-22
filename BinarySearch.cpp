#include<bits/stdc++.h>
using namespace std;
int Count1(int arr[],int m){
    int low = 0;
    int high = m-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]== m){
            ans = mid;
            high = mid - 1;
            continue;
        }
        if(m>arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int Count2(int arr[],int m){
    int low = 0;
    int high = m-1;
    int ans = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]== m){
            ans = mid;
            low  = mid + 1;
            continue;
        }
         if(m>arr[mid]){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    int m;
    cin>>m;
    int arr[m];
    for(int i =0; i<m; i++){
        cin>>arr[i];
    }
    cout<<Count2(arr,m)-Count1(arr,m)+1<<endl;
}

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
class Solution {
    void markParents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_track,TreeNode*target){
        queue<TreeNode*>queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode*curr = queue.front();
            queue.pop();
            if(curr->left){
                parent_track[curr->left] = curr;
                queue.push(curr->left);
            }
            if(curr->right){
                parent_track[curr->right] = curr;
                queue.push(curr->right);
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         unordered_map<TreeNode*, TreeNode*> parent_track; 
        markParents(root, parent_track, target); 
        
        unordered_map<TreeNode*, bool> visited; 
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!queue.empty()) { 
            int size = queue.size();
            if(curr_level++ == k) break;
            for(int i=0; i<size; i++) {
                TreeNode* current = queue.front(); queue.pop();
                if(current->left && !visited[current->left]) {
                    queue.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    queue.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    queue.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> result;
        while(!queue.empty()) {
            TreeNode* current = queue.front(); queue.pop();
            result.push_back(current->val);
        }
        return result;
    }
};*/
