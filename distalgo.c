Let's go through the **Distance Vector Routing Algorithm** and the provided code step by step, just like an algorithm.

---

## **Distance Vector Routing Algorithm Overview**

**Distance Vector Routing (DVR)** is a dynamic routing algorithm used in computer networks. It is based on the Bellman-Ford algorithm and is primarily used in small to medium-sized networks.

### **Key Concepts**
1. **Routers**: Each router maintains a routing table containing:
    - The shortest known distance to each destination.
    - The next hop (neighbor) to forward packets to reach the destination.
  
2. **Cost Matrix**: 
    - Represents the direct link costs between routers.
    - If no direct link exists, it is represented by **INFINITY (9999)**.
  
3. **Updating Routing Tables**:
    - Each router periodically shares its routing table with its neighbors.
    - Routes are updated based on the least-cost path using the formula:
      \[
      D(i, j) = \min \left( D(i, j), D(i, k) + D(k, j) \right)
      \]
      Where:
      - \( D(i, j) \) = Distance from router \( i \) to router \( j \)
      - \( D(i, k) + D(k, j) \) = Distance via an intermediate router \( k \)
  
4. **Convergence**: 
    - Routers keep exchanging information until no further updates occur, meaning all routers have the shortest path information.

---

## **Algorithm Breakdown (Step-by-Step)**

### **Step 1: Include Libraries and Define Constants**
```c
#include <stdio.h>
#define INFINITY 9999
#define MAX 10
```
- **stdio.h** is used for input-output functions.
- `INFINITY` is set to **9999** to represent the absence of a direct link.
- `MAX` is set to **10**, indicating a maximum of 10 routers.

---

### **Step 2: Declare Variables**
```c
int cost[MAX][MAX], dist[MAX][MAX], next_hop[MAX][MAX];
int nodes;
```
- `cost[][]`: Stores the cost of direct links between routers.
- `dist[][]`: Maintains the shortest distance from each router to every other router.
- `next_hop[][]`: Tracks the next router to forward packets along the shortest path.
- `nodes`: Number of routers in the network.

---

---

## **Step 3: Initialization**

```c
void initialize() {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            dist[i][j] = cost[i][j];
            next_hop[i][j] = j;
        }
    }
}
```
**Explanation**:  
- This function initializes the routing tables.
- `dist[i][j] = cost[i][j]` sets the initial distance to the known cost from the input.
- `next_hop[i][j] = j` assumes that the next hop for all destinations is initially the destination itself (direct connection).
- This is a necessary step before running the algorithm.

---

---

## **Step 4: Update Routing Tables Using Distance Vector Algorithm**

```c
void updateRoutes() {
    int updated;
    do {
        updated = 0;
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                for (int k = 0; k < nodes; k++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        next_hop[i][j] = next_hop[i][k];
                        updated = 1;
                    }
                }
            }
        }
    } while (updated);
}
```

**Explanation**:  
- This function runs the **Distance Vector Algorithm** using three nested loops:
  - **Outer Loop (i)** → Represents the source router.
  - **Middle Loop (j)** → Represents the destination router.
  - **Inner Loop (k)** → Represents the intermediate router (neighbor).
- The algorithm checks if the path through router `k` is shorter than the current path.  
  - **If yes**:  
    - Update the shortest path using `dist[i][j] = dist[i][k] + dist[k][j]`.
    - Update the `next_hop[i][j]` to the next hop towards `k`.
    - Set `updated = 1` to indicate a change in the routing table.
- This process repeats until no further updates occur, ensuring all shortest paths are calculated.

---

---

## **Step 5: Display the Routing Tables**

```c
void display() {
    for (int i = 0; i < nodes; i++) {
        printf("\nRouter %d's Routing Table:\n", i + 1);
        printf("Destination\tCost\tNext Hop\n");
        for (int j = 0; j < nodes; j++) {
            printf("%d\t\t%d\t%d\n", j + 1, dist[i][j], next_hop[i][j] + 1);
        }
    }
}
```
**Explanation**:  
- This function prints the final routing table for each router.
- For every router `i`:
  - **Destination**: The router `j`.
  - **Cost**: The shortest distance from router `i` to router `j`.
  - **Next Hop**: The first router along the shortest path to the destination.
- Note: `next_hop[i][j] + 1` is used because routers are displayed starting from **1** instead of **0**.

---

---

## **Step 6: Main Function**

```c
int main() {
    printf("Enter the number of routers: ");
    scanf("%d", &nodes);
```
- **User Input**: Number of routers in the network.

---

```c
printf("Enter the cost matrix (enter 9999 for no direct link):\n");
for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
        scanf("%d", &cost[i][j]);
        if (i == j) {
            cost[i][j] = 0;
        }
    }
}
```
- **Cost Matrix Input**:  
  - The user enters the cost of each link between routers.
  - **9999** represents no direct link.
  - The diagonal elements `cost[i][i]` are set to **0** because the distance from a router to itself is always **0**.

---

```c
initialize();
updateRoutes();
display();
return 0;
```
- **Function Calls**:
  - `initialize()` sets up initial distances and next hops.
  - `updateRoutes()` calculates the shortest paths using Distance Vector Routing.
  - `display()` prints the final routing tables for each router.
- The program exits successfully using `return 0`.

---

## **Summary of the Algorithm**
1. **Input the number of routers and the cost matrix.**
2. **Initialize** the routing tables using the cost matrix.
3. **Run Distance Vector Algorithm** to update the shortest paths using the Bellman-Ford principle.
4. **Display** the final routing tables for all routers.
5. **End the simulation.**

---

If you'd like further examples or test cases to visualize how the algorithm works, let me know!
