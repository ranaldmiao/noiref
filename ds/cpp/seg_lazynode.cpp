struct node {
	node *l, *r;
	int val, s, m, e, lazyadd;
	node(int _s, int _e): s(_s), e(_e), m((_s+_e)/2), val(0), lazyadd(0), l(NULL), r(NULL) {}
	int value() { //returns the value of the current node after lazy propagating
		if (s == e) return val + lazyadd;
		if (lazyadd == 0) return val;
		val += lazyadd;
		if (l == NULL) l = new node(s, m);
		if (r == NULL) r = new node(m+1, e);
		l->lazyadd += lazyadd, r->lazyadd += lazyadd;
		lazyadd = 0;
		return val;
	}
	void add(int x, int y, int v) {
		if (s == x && e == y) lazyadd += v;
		else {
			if (x > m) {
				if (r == NULL) r = new node(m+1, e);
				r->add(x, y, v);
			}
			else if (y <= m) {
				if (l == NULL) l = new node(s, m);
				l->add(x, y, v);
			}
			else {
				if (r == NULL) r = new node(m+1, e);
				if (l == NULL) l = new node(s, m);
				l->add(x, m, v), r->add(m+1, y, v);
			}
			if (l != NULL && r != NULL) val = min(l->value(), r->value()); //Change here for max
			else if (l == NULL) val = r->value();
			else if (r == NULL) val = l->value();
		}
	}
	int query(int x, int y) {
		value();
		if (s == x && e == y) return value();
		if (x > m) return (r==NULL)? 0:r->query(x, y);
		if (y <= m) return (l==NULL)? 0:l->query(x, y);
		if (l == NULL && r != NULL) return r->query(m+1, y);
		if (l != NULL && r == NULL) return l->query(x, m);
		if (l != NULL && r != NULL) return min(l->query(x, m),r->query(m+1, y)); //Change here for max
		return 0;
	}
};
/*inclusive and employs lazy node creation. supports negative 'ranges', defaults to 0. */
node root(-1000000000, 1000000000);
/*Change the 'default' to 1 -> Lazy propagated O(log R)*/
add(-1000000000, 1000000000, 1); 
add(0, 5, -2); //adds -2 to (0 to 5) inclusive
query(5, 8); //first must be lower than second,  returns minimum of (5 to 8) inclusive