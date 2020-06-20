int Solution::solve(string start, string end, vector<string> &dict){
    
    unordered_map<string, bool>vis;
    // unordered_map<string, string>mp;
    
    for(int i = 0; i < (int)dict.size(); i++){
        vis[dict[i]] = false;
        // mp[dict[i]] = dict[i];
    }
    
    queue<string>q;
    q.push(start);
    vis[start] = true;
    
    unordered_map<string, int>dist;
    
    while(!q.empty()){
        
        string node = q.front();
        q.pop();
        for(int i = 0; i < node.size(); i++){
            string temp = node;
            for(int ch = 'a'; ch <= 'z'; ch++){  
                temp[i] = ch;
                if(vis.find(temp) != vis.end() && !vis[temp]){
                    q.push(temp);
                    vis[temp] = true;
                    dist[temp] = dist[node]+1;
                    /*if(temp == end){
                        return dist[temp]+1;
                    }*/
                }
            }
        }
    }
    return dist[end]+1;
}

/*
I think it should be O( N + N * ( W * 26 ) * ( W * log(N) ) ). Since every string can be put in or be removed from the queue only once therefore
 the O(N) factor and for each node (string) at worst all changes in positions would result in a valid word present in the dictionary i.e a node
  would be at worst connected to W * 26 other nodes where W is the length of the word. Now when putting any such node in a queue we need to check
   if it is present in a dictionary or not and that would take W*log(N) time assuming an ordered_map (the W since it is a string). Such comparisons
    would happen for all N nodes(strings), making it O( N * (W * 26) * (W * log(N)) ).

Also we can derive this using the complexity of BFS which is O(V+E) and here a node (string of length W) can be connected to atmost W * 26 other
 nodes and therefore for N number of nodes it would be N * W * 26 and a factor of W * log(N) for checking as here we need to use maps with keys
  as strings. Making it the same as before.So I think this is correct.
*/