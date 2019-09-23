class DisjointSet{

public:

	DisjointSet(int max);
	bool makeSet(int object);
	int findSet() const;
	bool union(int rep1, int rep2);
	~DisjointSet();
	DisjointSet(const DisjointSet& other);
	const DisjointSet& operator=(const DisjointSet& other);
	DisjointSet(DisjointSet&& other);
	const DisjointSet& operator=(DisjointSet&& other);

};