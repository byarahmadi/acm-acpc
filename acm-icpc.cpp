#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
#include <algorithm>

/* Each point is an coordinate with (x,y) */
using Point = std::pair<int,int>;


struct Vertex {
	Point point1;
	Point point2;
};

/* A function to check if two edges are connected */
bool isConnectedEdge(const std::vector<Vertex> & vertices, int i, int j) {
	if (vertices[i].point2 == vertices[j].point1) 
	  return true;
	return false; 
}

/* A function to calculate the distance between two points */
double getDistance(const Point & point1, const Point & point2) {
	int x1 = point1.first;
	int x2 = point2.first;
	int y1 = point1.second;
	int y2 = point2.second;
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    std::string input;
    int n;
    
    /* Getting the number of vertices qnd input validation */
    std::getline(std::cin, input);
    std::stringstream stream(input);
    if (!(stream >> n)) {
        std::cout << "Invalid input." << std::endl;
        return 1;
    }
    
    /* edge cases of the input */
    if (n < 3 || n > 200) {
    	std::cout << "Invalid input." << std::endl;
        return 1;
	}
    
    /* adding each point to the vector of points and input validation */
    std::vector<Point> points;
    for (int i = 0; i < n; ++i) {
    	 std::string input;
    	 int x,y;
    	 std::getline(std::cin, input);
    	 std::stringstream stream(input);
         if (!(stream >> x >> y)) {
            std::cout << "Invalid input" << std::endl;
            return 1;
         }
         points.emplace_back(x, y);
	}
	
    /* creating the verices vector */
    std::vector<Vertex> vertices;    
	for (int i = 0; i < points.size() - 1; ++i) {
		 Vertex V;
		 V.point1 = points[i];
		 V.point2 = points[i + 1];
		 vertices.push_back(V);
	}
	/* This part is for the last vertex in poly */	
	Vertex V;
	V.point1 = vertices[vertices.size() - 1].point2;
	V.point2 = vertices[0].point1;
    vertices.push_back(V);
	
	/* Itrerating over each vertex and compare the distance with the other vertex from points */
	double max_distance = 0;
	for (int i = 0; i < vertices.size(); ++i) {
		for (int j = i + 1; j < vertices.size(); ++j) {
			if (!isConnectedEdge(vertices, i, j)) {
				double d1 = getDistance(vertices[i].point1, vertices[j].point1);
			    double d2 = getDistance(vertices[i].point1, vertices[j].point2);
			    double d3 = getDistance(vertices[i].point2, vertices[j].point1);
			    double d4 = getDistance(vertices[i].point2, vertices[j].point2);
			    max_distance = std::max({max_distance, d1, d2 , d3 , d4});
			}
		}
	}
	std::cout<<std::endl<< max_distance<<std::endl;
    return 0;
}

