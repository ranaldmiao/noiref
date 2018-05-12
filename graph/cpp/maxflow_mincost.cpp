typedef long long ll;
struct Edge {
    int to;
    ll cap, flow, cost;
    Edge(int tar, ll _cost, ll capacity): to(tar), cost(_cost), cap(capacity), flow(0) {}
    ll amt() { return cap-flow; }
};

struct MinCost {
    int N;
    vector<Edge> E;
    vector<vector<int> > G;
    vector<int> phi;
    
    MinCost(int _N): N(_N), G(_N) {}
    
    void AddEdge(int a, int b, ll cost, ll cap) { 
        if (a == b) return;
        G[a].push_back(E.size());
        E.push_back({b, cost, cap});
        G[b].push_back(E.size());
        E.push_back({a, -cost, 0});
    }
    
    pair<ll, ll> SPFA(int S, int T) {           //flow, unit cost
        vector<ll> dist(N, -1);
        vector<int> pre(N, -1);
        vector<bool> inq(N);
        queue<int> q;
        
        dist[S] = 0;
        inq[S] = 1;
        q.push(S);
        
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            inq[x] = 0;
            for (auto it:G[x]) {
                if (E[it].amt() <= 0) continue;
                int y = E[it].to;
                ll c = dist[x] + E[it].cost;
                if (c < dist[y] || dist[y] == -1) {
                    dist[y] = c;
                    pre[y] = it;
                    if (!inq[y]) q.push(y);
                    inq[y] = 1;
                }
            }
        }
        if (dist[T] == -1) return make_pair(0, 0);
        ll flow = LLONG_MAX;
        int it = pre[T];
        ll cost = 0;
        while(it != -1) {
            flow = min(flow, E[it].amt());
            cost += E[it].cost;
            it = pre[E[it^1].to];
        }
        it = pre[T];
        while (it != -1) {
            E[it].flow += flow;
            E[it^1].flow -= flow;
            it = pre[E[it^1].to];
        }
        return make_pair(flow, cost);
    }
    pair<ll, ll> MinCost_SPFA(int S, int T, ll F=LLONG_MAX) {       //max_flow, min_total_cost
        ll sum_flow = 0;
        for (auto it:G[S]) sum_flow += E[it].cap;
        F = min(sum_flow, F);
        ll min_cost = 0, cur_flow = 0;
        pair<ll, ll> ret;
        while (ret = SPFA(S, T), ret.first > 0 && cur_flow < F) {
            ll flow = min(F-cur_flow, ret.first);
            cur_flow += flow;
            min_cost += flow * ret.second;
        }
        return make_pair(cur_flow, min_cost);
    }
    
    pair<ll, ll> DijkstraPot(int S, int T) {                        //flow, unit cost
        vector<ll> dist(N, -1);
        vector<int> pre(N, -1);
        priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
        dist[S] = 0;
        pq.emplace(0, S);
        
        while(!pq.empty()) {
            int x = pq.top().second;
            ll d = pq.top().first;
            pq.pop();
            if (dist[x] != d) continue;
            for (auto it:G[x]) {
                if (E[it].amt() <= 0) continue;
                int nx = E[it].to;
                ll nd = d + E[it].cost + phi[x] - phi[nx];
                if (dist[nx] == -1 || dist[nx] > nd) {
                    dist[nx] = nd;
                    pre[nx] = it;
                    pq.emplace(dist[nx], nx);
                }
            }
        }
        if (dist[T] == -1) return make_pair(0, 0);
        for (int i = 0; i < N; ++i) {
            if (dist[i] != -1) phi[i] += dist[i];
        }
        
        ll flow = LLONG_MAX;
        int it = pre[T];
        ll cost = 0;
        while(it != -1) {
            flow = min(flow, E[it].amt());
            cost += E[it].cost;
            it = pre[E[it^1].to];
        }
        it = pre[T];
        while (it != -1) {
            E[it].flow += flow;
            E[it^1].flow -= flow;
            it = pre[E[it^1].to];
        }
        
        return make_pair(flow, cost);
    }
    pair<ll, ll> MinCost_Dijkstra(int S, int T, ll F=LLONG_MAX) {       //max_flow, min_total_cost
        ll sum_flow = 0;
        for (auto it:G[S]) sum_flow += E[it].cap;
        F = min(sum_flow, F);
        phi.resize(N, 0);
        ll min_cost = 0, cur_flow = 0;
        pair<ll, ll> ret;
        while (ret = DijkstraPot(S, T), ret.first > 0 && cur_flow < F) {
            ll flow = min(F-cur_flow, ret.first);
            cur_flow += flow;
            min_cost += flow * ret.second;
        }
        phi.clear();
        return make_pair(cur_flow, min_cost);
    }
};