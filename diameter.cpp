pair<int, int> bfs(int root){
    vector<int> distt(n+1, 0);
    distt[root] = 1;
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int curr = q.front();
        for(auto it : g[curr]){
            if(distt[it] != 0){
                continue;
            }
            q.push(it);
            distt[it] = distt[curr] + 1;
        }
        q.pop();
    }
    int mx = INT_MIN, vertex = -1;
    for(int i=1 ; i<=n ; i++){
        if(mx < distt[i]){
            mx = distt[i];
            vertex = i;
        }
    }
    return make_pair(mx, vertex);
}
 
int diameter(int root){
    pair<int, int> p1 = bfs(root), p2;

    xx = p1.second; 


    p2 = bfs(p1.second);

    yy = p2.second;
    return p2.first;
}