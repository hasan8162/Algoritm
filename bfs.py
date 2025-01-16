import heapq #for priority queue

def best_first_search(adj_lst, heuristic, start, goal):
    priority_queue = [(heuristic[start], start, [start])]   # (heuristic value, node, path)
    visited = set()
    
    while priority_queue:
        h_value, node, path = heapq.heappop(priority_queue)  # node with the lowest heuristic value
        
        if node in visited:
            continue
        visited.add(node)
    
        if node == goal:
            return path  # Return the path to reach the goal
        
        for neighbor, _ in adj_lst.get(node, []): # Explore neighbors
            if neighbor not in visited:
                # Add neighbor to the priority queue with its heuristic value and updated path
                heapq.heappush(priority_queue, (heuristic[neighbor], neighbor, path + [neighbor]))
    
    return None

adj_lst = {
    'A': [('B', 2), ('C', 1)],
    'B': [('D', 3), ('E', 4)],
    'C': [('F', 5)],
    'D': [('G', 6)],
    'E': [('G', 2)],
    'F': [('G', 3)],
    'G': []
} #graph

heuristic = {
    'A': 7, 'B': 6, 'C': 3, 'D': 4, 'E': 2, 'F': 6, 'G': 0
} # Heuristic values for each node

path = best_first_search(adj_lst, heuristic, 'A', 'G')
print("Path:", path)
