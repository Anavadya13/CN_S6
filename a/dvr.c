Distance Vector Routing (DVR) is a dynamic routing algorithm used in computer networks. It is based on the Bellman-Ford algorithm and is primarily used in small to medium-sized networks.

Key Concepts
Routers: Each router maintains a routing table containing:
The shortest known distance to each destination.
The next hop (neighbor) to forward packets to reach the destination.
Cost Matrix:
Represents the direct link costs between routers.
If no direct link exists, it is represented by INFINITY (9999).
Updating Routing Tables:
Each router periodically shares its routing table with its neighbors.
Routes are updated based on the least-cost path using the formula:

D(i,j)=min(D(i,j),D(i,k)+D(k,j))
Where:D(i,j) = Distance from router i to router 𝑗
D(i,k)+D(k,j) = Distance via an intermediate router 𝑘
Convergence:
Routers keep exchanging information until no further updates occur, meaning all routers have the shortest path information.
  Step 1: Include Libraries and Define Constants
stdio.h is used for input-output functions.
INFINITY is set to 9999 to represent the absence of a direct link.
MAX is set to 10, indicating a maximum of 10 routers.
  Step 2: Declare Variables
cost[][]: Stores the cost of direct links between routers.
dist[][]: Maintains the shortest distance from each router to every other router.
next_hop[][]: Tracks the next router to forward packets along the shortest path.
nodes: Number of routers in the network.
  Step 3: Initialization
This function initializes the routing tables.
dist[i][j] = cost[i][j] sets the initial distance to the known cost from the input.
next_hop[i][j] = j assumes that the next hop for all destinations is initially the destination itself (direct connection).
This is a necessary step before running the algorithm.
  Step 4: Update Routing Tables Using Distance Vector Algorithm
This function runs the Distance Vector Algorithm using three nested loops:
Outer Loop (i) → Represents the source router.
Middle Loop (j) → Represents the destination router.
Inner Loop (k) → Represents the intermediate router (neighbor).
The algorithm checks if the path through router k is shorter than the current path.
If yes:
Update the shortest path using dist[i][j] = dist[i][k] + dist[k][j].
Update the next_hop[i][j] to the next hop towards k.
Set updated = 1 to indicate a change in the routing table.
This process repeats until no further updates occur, ensuring all shortest paths are calculated.
  Step 5: Display the Routing Tables
This function prints the final routing table for each router.
For every router i:
Destination: The router j.
Cost: The shortest distance from router i to router j.
Next Hop: The first router along the shortest path to the destination.
Note: next_hop[i][j] + 1 is used because routers are displayed starting from 1 instead of 0.
  Step 6: Main Function
User Input: Number of routers in the network.
The user enters the cost of each link between routers.
9999 represents no direct link.
The diagonal elements cost[i][i] are set to 0 because the distance from a router to itself is always 0.
  Function Calls:
initialize() sets up initial distances and next hops.
updateRoutes() calculates the shortest paths using Distance Vector Routing.
display() prints the final routing tables for each router.
  Step 7:The program exits successfully using return 0.
....................................
  ALGORITHM:
 1. Start by defining the structure for the routing table, which includes arrays for cost 
and next hop information for each router.
 2. Initialize variables: costmat to hold the cost matrix, routers to store the number of 
routers, i, j, k as loop counters, and count to keep track of iterations.
 3. Read the number of routers from the user.
 4. Read the cost matrix from the user, populating the costmat array and initializing the 
routing table arrays.
 5. Perform the distance vector algorithm until no more changes occur:
 6. Set otherShorterPathExists flag to 0.
 a) Iterate over each router (outer loop).
 b) Iterate over each destination router (middle loop).
 c) Iterate over each intermediate router (inner loop).
 d) If a shorter path exists from i to j through k, update the routing table:
 • routingTable[i].cost[j] is updated to the sum of costs from i to k and from k to j.
 • routingTable[i].from[j] is updated to k.
 • Set otherShorterPathExists flag to 1 to indicate a change in the routing table.
 • Repeat the above loops until no more changes occur (otherShorterPathExists is 0).
 7. Print the routing table for each router:
 a) Iterate over each router.
 b) Print the router's number.
 c) Iterate over each destination router.
 d) Print the destination router's number, the next hop (routingTable[i].from[j] + 1), 
and the cost (routingTable[i].cost[j]).
 8. End the program
