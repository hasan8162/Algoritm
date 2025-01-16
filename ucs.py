import heapq

def uniform_cost_search(graph, start, goal):
    # Priority queue to store (cost, node) tuples
    queue = []
    heapq.heappush(queue, (0, start))  # Start with the start node and cost 0
    
    # Dictionary to store the cost to reach each node
    costs = {start: 0}
    
    # Dictionary to store the parent of each node for path reconstruction
    parents = {start: None}
    
    while queue:
        # Pop the node with the lowest cost
        current_cost, current_node = heapq.heappop(queue)
        
        # If we reach the goal, reconstruct the path and return
        if current_node == goal:
            path = []
            while current_node is not None:
                path.append(current_node)
                current_node = parents[current_node]
            path.reverse()
            return path, current_cost  # Return the path and the total cost
        
        # Explore neighbors
        for neighbor, (cost_to_neighbor) in graph[current_node].items():
            new_cost = current_cost + cost_to_neighbor
            
            # If this new path to the neighbor is cheaper, update cost and add to queue
            if neighbor not in costs or new_cost < costs[neighbor]:
                costs[neighbor] = new_cost
                parents[neighbor] = current_node
                heapq.heappush(queue, (new_cost, neighbor))
    
    # If no path is found, return None
    return None, float('inf')

# Example graph (adjacency list) with costs (node -> {neighbor: cost})
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

# Test UCS from node 'A' to node 'D'
path, cost = uniform_cost_search(graph, 'A', 'D')
print("Path:", path)
print("Cost:", cost)
