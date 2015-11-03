struct node {
	node *l, *r;
	int val, s, m, e, lazyadd;
	node(int _s, int _e): s(_s), e(_e), m((_s+_e)/2), val(0), lazyadd(0), l(NULL), r(NULL) {
		if (s != e) l = new node(s, m), r = new node(m+1, e);
	}
	int value() { //returns the value of the current node after lazy propagating
		if (s == e) return val + lazyadd;
		val += lazyadd;
		l->lazyadd += lazyadd, r->lazyadd += lazyadd;
		lazyadd = 0;
		return val;
	}
	void add(int x, int y, int v) {
		if (s == x && e == y) lazyadd += v;
		else {
			if (x > m) r->add(x, y, v);
			else if (y <= m) l->add(x, y, v);
			else l->add(x, m, v), r->add(m+1, y, v);
			val = min(l->value(), r->value()); //Change here to max
		}
	}
	int query(int x, int y) {
		value();
		if (s == x && e == y) return value();
		if (x > m) return r->query(x, y);
		if (y <= m) return l->query(x, y);
		return min(l->query(x, m),r->query(m+1, y)); //Change here to max
	}
};

/*Inclusive*/
node root(0, N-1);
/* Initialize it to an array value */
for (int i = 0; i < N; ++i) add(i, i, a[i]); //Add is inclusive and is O(log N)
query(5, 1000); //Query is O(log N) and inclusive
