from collections import deque

# BFS using a queue

def bfs(graph, start):
    visited = set()  # To keep track of visited nodes
    queue = deque([start])  # Initialize the queue with the start node
    visited.add(start)

    while queue:
        node = queue.popleft()  # Dequeue the first node in the queue
        print(node, end=" ")  # Process the node (e.g., print it)

        # Enqueue all unvisited neighbors
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)

# Example graph (adjacency list)
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

# Start BFS from node 'A'
bfs(graph, 'A')