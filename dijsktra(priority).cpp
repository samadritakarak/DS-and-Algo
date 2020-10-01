void dijsktra(vector<pair<int,int>>graph[],int v,int e){
    
   
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(v,INT_MAX);
    
    //push vertex 0
    
    pq.push(make_pair(0,0));
    dist[0]=0;
  
    
    while(!pq.empty()){
        
        int u=pq.top().second;
        pq.pop();
        
        for(auto it=graph[u].begin();it!=graph[u].end();it++){
            
            int v =(*it).first;
            
            if(dist[v]>dist[u]+(*it).second){
                dist[v]=dist[u]+(*it).second;
                pq.push(make_pair(dist[v],v));
            }
        }
        
       
    }
     for(int i=0;i<v;i++){
            cout<<i<<" "<<dist[i]<<"\n";
        }
    
    
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    
  vector<pair<int,int>>graph[V];
  for(int i=0;i<E;i++){
      int a,b,c;
      cin>>a>>b>>c;
      graph[a].push_back({b,c});
      graph[b].push_back({a,c});
  } 
  // for(int i=0;i<E;i++){
  // sort(graph[i].begin(),graph[i].end());
  // }
  dijsktra(graph,V,E);

  

  return 0;
}