#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};

struct node* createNode(int v) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));

    graph->visited = (int*)malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    int v;
    for (v = 0; v < graph->numVertices; v++) {
        struct node* temp = graph->adjLists[v];
        printf("\n Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

bool hasPathDFS(struct Graph* graph, int src, int dest) {
    if (src == dest) {
        return true;
    }

    graph->visited[src] = 1;

    struct node* adjList = graph->adjLists[src];

    while (adjList != NULL) {
        int neighbor = adjList->vertex;

        if (graph->visited[neighbor] == 0) {
            if (hasPathDFS(graph, neighbor, dest)) {
                return true;
            }
        }

        adjList = adjList->next;
    }

    return false;
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of Vertices \n");
    scanf("%d", &numVertices);
    printf("Enter the number of Edges you want to insert \n");
    scanf("%d", &numEdges);
    struct Graph* graph = createGraph(numVertices);

    for (int i = 0;i < numEdges;i++) {
        int src, des;
        scanf("%d %d", &src, &des);
        addEdge(graph, src, des);
    }
    /*addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);*/

    printGraph(graph);

    int source_node, destination_node;
    printf("\nEnter source node: ");
    scanf("%d", &source_node);
    printf("Enter destination node: ");
    scanf("%d", &destination_node);

    if (hasPathDFS(graph, source_node, destination_node)) {
        printf("\nThere is a path from %d to %d", source_node, destination_node);
    }
    else {
        printf("\nThere is no path from %d to %d", source_node, destination_node);
    }

    return 0;
}