typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vpi::iterator vpit;

for (vpit it = adjList[x].begin(); it != adjList[x].end(); ++it) {
    //Ensures the first number of the pair is always <= than the second
    if (it->first > it->second) {
        int t = it->first;
        it->first = it->second;
        it->second = t;
    }
}