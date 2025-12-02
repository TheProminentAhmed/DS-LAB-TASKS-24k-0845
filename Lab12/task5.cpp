#include <iostream>
using namespace std;

const int V = 5;

int adjList[V+1][V];
int adjCount[V+1];
int adjMat[V+1][V+1];
bool visited[V+1];

void addEdge(int u, int v) {
    adjList[u][adjCount[u]++] = v;
    adjList[v][adjCount[v]++] = u;
    adjMat[u][v] = adjMat[v][u] = 1;
}

void resetVisited() {
    for (int i = 1; i <= V; i++) visited[i] = false;
}

void BFS(int start) {
    int q[100], front = 0, rear = 0;
    q[rear++] = start;
    visited[start] = true;

    cout << "BFS: ";

    while (front < rear) {
        int u = q[front++];
        cout << u << " ";

        for (int i = 0; i < adjCount[u]; i++) {
            int v = adjList[u][i];
            if (!visited[v]) {
                visited[v] = true;
                q[rear++] = v;
            }
        }
    }
    cout << endl;
}

void DFSutil(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adjCount[u]; i++) {
        int v = adjList[u][i];
        if (!visited[v]) DFSutil(v);
    }
}

void DFS(int start) {
    cout << "DFS: ";
    DFSutil(start);
    cout << endl;
}

int main() {
    for (int i = 1; i <= V; i++)
        for (int j = 1; j <= V; j++)
            adjMat[i][j] = 0;

    addEdge(1, 4);
    addEdge(2, 4);
    addEdge(4, 5);
    addEdge(2, 5);
    addEdge(3, 5);

    cout << "Adjacency List:\n";
    for (int i = 1; i <= V; i++) {
        cout << i << ": ";
        for (int j = 0; j < adjCount[i]; j++)
            cout << adjList[i][j] << " ";
        cout << endl;
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++)
            cout << adjMat[i][j] << " ";
        cout << endl;
    }

    resetVisited();
    BFS(1);

    resetVisited();
    DFS(1);
}
