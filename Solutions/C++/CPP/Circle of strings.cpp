// problem:---Given an array of lowercase strings A[] of size N, determine if the strings can be chained together to form a circle. A string X can be chained together 
// with another string Y if the last character of X is same as first character of Y. If every string of the array can be chained, it will form a circle.

// For example, for the array arr[] = {"for", "geek", "rig", "kaf"} the answer will be Yes as the given strings can be chained as "for", "rig", "geek" and "kaf"


// solution:-

class Solution
{
    public:
   int isCircle(int N, vector<string> A)
    {
        vector<pair<int, int>> vec (26, {0, 0});
        vector<int> adj[26];
        stack<int> st;
        vector<bool> visited(26, false);
        for(auto &e : A){
            vec[e.front() - 'a'].first++;
            vec[e.back() - 'a'].second++;
            adj[e.front() - 'a'].push_back(e.back() - 'a');
            visited[e.front() - 'a'] = true;
            visited[e.back() - 'a'] = true;
        }
        st.push(A[0][0] - 'a');
        for(auto &e : vec){
            if(e.first != e.second){
                return 0;
            }
        }
        while(st.empty() == false){
            int curr = st.top();
            st.pop();
            visited[curr] = false;
            for(auto &e : adj[curr]){
                if(visited[e] == true)
                st.push(e);
            }
        }
        for(int i = 0; i < 26; i++){
            if(visited[i]){
                return 0;
            }
        }
        return 1;
    }
};
