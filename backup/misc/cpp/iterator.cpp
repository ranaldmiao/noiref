for (vector<pair<int, int> >::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
    //Ensures the first number of the pair is always <= than the second
    if (it->first > it->second) {
        int t = it->first;
        it->first = it->second;
        it->second = t;
    }
}