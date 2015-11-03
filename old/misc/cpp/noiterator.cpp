for (int i = 0; i < adjList[x].size(); ++i) {
    //Ensures the first number of the pair is always <= than the second
    if (adjList[x][i].first > adjList[x][i].second) {
        int t = adjList[x][i].first;
        adjList[x][i].first = adjList[x][i].second;
        adjList[x][i].second = t;
    }
}