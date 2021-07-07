template<typename Monoid>
struct DisjointSetUnion {
	struct rnk {
		Monoid val = 1;
		Monoid get() const {
			return val;
		}
		void add(const rnk &r) {
			val += r.val;
		}
	};
	vector<Monoid> p;
	vector<rnk> r;
	Monoid comp = 0, edge = 0;
	DisjointSetUnion() {}
	bool empty() const {
		return p.empty();
	}
	DisjointSetUnion(Monoid n) {
		p = vector<Monoid>(n);
		r = vector<rnk>(n);
		iota( p.begin(), p.end() , (Monoid)0 ) ;
		comp = n;
	}
	Monoid getp(Monoid v) { // returns head element in a set
		return v == p[v] ? v : p[v] = getp(p[v]);
	}
	bool check(Monoid a, Monoid b) { // a and b are in one component
		return getp(a) == getp(b);
	}
	bool unite(Monoid a, Monoid b) { // a and b are in diff components
		a = getp(a);
		b = getp(b);
		if (a == b) return false;
		++edge;
		--comp;
		if (r[a].get() > r[b].get()) swap(a, b);
		p[a] = b;
		r[b].add(r[a]);
		return true;
	}
};
