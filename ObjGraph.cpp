#include <iostream>
#include <set>

using namespace std;

template <class T>
class Graph {
private:
	static const int MAXI = 10;
	bool adjM[MAXI][MAXI];
	T labels[MAXI];
	int manyV;
	
public:
	Graph();
	~Graph();
	
	void addVertex(const T& value) {
		assert(size() < MAXI);
		int newV = manyV;
		manyV++;
		for(int i=0; i< manyV; i++) {
			adjM[i][newV] = false;
			adjM[newV][i] = false;
		}
		labels[newV] = value;
	}
	
	void addEdge(int source, int target){
		assert(source < size() && target < size());
		adjM[source][target] = true;
	}
	
	void removeEdge(int source, int target) {
		assert(source < size() && target < size());
		adjM[source][target] = false;
	}
	
	T& operator [] (int vertex) {
		assert(vertex < size());
		return labels[vertex];
	}
	
	T operator [] (int vertex) const {
		assert(vertex < size());
		return labels[vertex];
	}
	
	int size() const;
	bool isEdge(int source, int target) const {
		assert(source < size() && target < size());
		return adjM[source][target];
	}
	
	set<int> get_neighbours(int vertex) const {
		assert(vertex < size());
		set<int> neighbours;
		
		for(int i=0; i<size(); i++)
			if(adjM[vertex][i])
				neighbours.insert(vertex);
		
		return neighbours;
	}
	
};

int main(int argc, const char *argv[]) {
	cout<<"Ghost"<<endl;
}
