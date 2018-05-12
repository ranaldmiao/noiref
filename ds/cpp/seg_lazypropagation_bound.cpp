struct node {
    int s, e, mx;
    node *l, *r;
    node (int _s=0, int _e=N-1): s(_s), e(_e), mx(0) {
        if (s != e) {
            int m = (s+e)>>1;
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }
    void update(int x, int y, int v) {
        if (s == x && e == y) {
            mx = max(v, mx);
            return;
        }
        int m = (s+e)>>1;
        if (x <= m) l->update(x, min(m, y), v);
        if (y > m) r->update(max(x, m+1), y, v);
    }
    int query(int x) {
        if (s == e) return mx;
        int m = (s+e)>>1;
        if (x <= m) return max(mx, l->query(x));
        else return max(mx, r->query(x));
    }
};

/*Inclusive*/
node root(0, N-1);
root->update(0, 5, 3);		//set [0, 5] to minimum 3
root->update(3, 7, 2);		//set [3, 7] to minimum 2
root->query(5);				//return 3
root->query(6);				//return 2