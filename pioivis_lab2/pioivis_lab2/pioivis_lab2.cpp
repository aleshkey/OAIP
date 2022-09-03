#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Graph {
private:
	int n; int m; int k;
	vector<int> array_of_ancestors;
	class Compartment {
	public:
		int valueX, valueY, valueZ;
	};
	struct Neighbors {
		Compartment up;
		Compartment down;
		Compartment left;
		Compartment right;
		Compartment front;
		Compartment back;
	};
	Neighbors neighbors;
	Compartment pointstart;
	Compartment pointend;
	Compartment pointnow;
public:

	void GetGraphValue(int x, int y, int z) {
		this->n = x;
		this->m = y;
		this->k = z;
	}

	void GetCompartmentValue(int x1, int y1, int z1, int x2, int y2, int z2) {
		pointstart.valueX = x1;
		pointstart.valueY = y1;
		pointstart.valueZ = z1;
		pointend.valueX = x2;
		pointend.valueY = y2;
		pointend.valueZ = z2;
	}

	int distance(Compartment point1, Compartment point2) {
		return(abs(point1.valueX - point2.valueX) + abs(point1.valueY - point2.valueY) + abs(point1.valueZ - point2.valueZ));
	}

	bool in_one_row(Compartment point1, Compartment point2) {
		if (point1.valueX == point2.valueX && point1.valueY == point2.valueY) return true;
		if (point1.valueZ == point2.valueZ && point1.valueY == point2.valueY) return true;
		if (point1.valueX == point2.valueX && point1.valueZ == point2.valueZ) return true;
		return false;
	}

	int mindistancenum(vector<int> distances) {
		int num_min = 0;
		for (int i = 0; i < distances.size(); i++) {
			if (distances[num_min] > distances[i]) {
				num_min = i;
			}
		}
		return num_min;
	}

	void NeighborsGetValue(){
		if (pointnow.valueX == 1) {
			neighbors.left.valueX = NULL;
			neighbors.left.valueY = NULL;
			neighbors.left.valueZ = NULL;
			neighbors.up.valueX = pointnow.valueX;
			neighbors.up.valueZ = pointnow.valueZ + 1;
			neighbors.up.valueY = pointnow.valueY;
			neighbors.down.valueX = pointnow.valueX;
			neighbors.down.valueZ = pointnow.valueZ - 1;
			neighbors.down.valueY = pointnow.valueY;
			neighbors.right.valueX = pointnow.valueX+1;
			neighbors.right.valueZ = pointnow.valueZ;
			neighbors.right.valueY = pointnow.valueY;
			neighbors.front.valueX = pointnow.valueX;
			neighbors.front.valueZ = pointnow.valueZ;
			neighbors.front.valueY = pointnow.valueY-1;
			neighbors.back.valueX = pointnow.valueX;
			neighbors.back.valueZ = pointnow.valueZ;
			neighbors.back.valueY = pointnow.valueY+1;
		}
	}
	
	void dfs() {
		while (pointnow.valueX!=pointend.valueX && pointnow.valueY != pointend.valueY&&pointnow.valueZ != pointend.valueZ)
		Compartment pointto;
		vector<int> distances;

		pointnow = pointto;
		dfs;
	}
};
int main()
{

	return 0;
}
