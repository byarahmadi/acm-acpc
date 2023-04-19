# acm-icpc
This is the a not complite solution for ACM-ICPC Program 2017 (Program A)
This program solves a problem related to intersecting lines and polygons. It uses a simple greedy approach and has a time complexity of O(n^2), which is a bit weired since it doesn't consider when a line intersects with another line.

# Compiling the Program
To compile the program, you can use any available C++ compiler. There are no fancy new C++ features used in the code. For example, you can use g++ or MSVC.

# Algorithm Overview
The algorithm considers all the vertices and compares the distance to other vertices when they are not connected (From point to point). For the test cases provided in the paper, this approach works well.

# Time Complexity
The time complexity of the program is O(n^2), as I did not consider when a line between to vertices are interseted or it is outside the polygon.




