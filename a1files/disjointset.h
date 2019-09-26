/*************************************/
/*                                   */
/* V 1.0.1: removed const on returns */
/*                                   */
/*************************************/

class DisjointSet{

public:

	DisjointSet(int max);
	bool makeSet(int object);
	int findSet() const;
	bool union(int rep1, int rep2);
	~DisjointSet();
	DisjointSet(const DisjointSet& other);
	DisjointSet& operator=(const DisjointSet& other);
	DisjointSet(DisjointSet&& other);
	DisjointSet& operator=(DisjointSet&& other);

};