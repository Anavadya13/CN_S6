#include <stdio.h>

#define MAX 10
#define INF 9999

void dijkstra(int graph[MAX][MAX], int nodes, int start) {
    int cost[MAX][MAX], distance[MAX], visited[MAX], next_hop[MAX];
    int i, j, count, min_distance, next_node;

    // Create the cost matrix
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];
        }
    }

    // Initialize distances and next hops
    for (i = 0; i < nodes; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
        next_hop[i] = (distance[i] != INF && i != start) ? i : -1;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < nodes - 1) {
        min_distance = INF;
        next_node = -1;

        // Find the unvisited node with the smallest distance
        for (i = 0; i < nodes; i++) {
            if (!visited[i] && distance[i] < min_distance) {
                min_distance = distance[i];
                next_node = i;
            }
        }

        if (next_node == -1) break;

        visited[next_node] = 1;

        // Update distances
        for (i = 0; i < nodes; i++) {
            if (!visited[i] && cost[next_node][i] != INF) {
                int new_dist = distance[next_node] + cost[next_node][i];
                if (new_dist < distance[i]) {
                    distance[i] = new_dist;
                    next_hop[i] = next_hop[next_node];
                }
            }
        }
        count++;
    }

    // Print routing table
    printf("\nRouting Table for Router %d:\n", start + 1);
    printf("Destination\tCost\tNext Hop\n");

    for (i = 0; i < nodes; i++) {
        if (i == start) continue;

        printf("%d\t\t", i + 1);

        if (distance[i] == INF) {
            printf("INF\tNo route\n");
        } else {
            printf("%d\t%d\n", distance[i], next_hop[i] + 1);
        }
    }
}

int main() {
    int graph[MAX][MAX], nodes, i, j, start;

    printf("Enter the number of routers: ");
    scanf("%d", &nodes);

    printf("Enter the cost adjacency matrix (use 0 for no direct link):\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source router (1 to %d): ", nodes);
    scanf("%d", &start);

    if (start < 1 || start > nodes) {
        printf("Invalid router number.\n");
        return 1;
    }

    dijkstra(graph, nodes, start - 1);

    return 0;
}
