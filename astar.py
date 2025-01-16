import heapq

# A simple example of the A* algorithm

class Node:
    def __init__(self, name, parent=None, g=0, h=0):
        self.name = name  # Node name
        self.parent = parent  # Parent node
        self.g = g  # Cost to reach this node
        self.h = h  # Estimated cost to reach the goal
        self.f = g + h  # Total cost (f = g + h)

    def __lt__(self, other):
        return self.f < other.f  # To compare nodes based on their f value


def a_star(start, goal, graph, heuristic):
    open_list = []
    closed_list = set()

    # Initialize the start node
    start_node = Node(start, None, 0, heuristic[start])
    heapq.heappush(open_list, start_node)

    while open_list:
        # Get the node with the lowest f value
        current_node = heapq.heappop(open_list)
        if current_node.name == goal:
            path = []
            while current_node:
                path.append(current_node.name)
                current_node = current_node.parent
            return path[::-1]  # Return reversed path
        
        closed_list.add(current_node.name)

        for neighbor, cost in graph[current_node.name].items():
            if neighbor in closed_list:
                continue

            g = current_node.g + cost
            h = heuristic[neighbor]
            neighbor_node = Node(neighbor, current_node, g, h)

            if all(neighbor_node.f < open_node.f for open_node in open_list if open_node.name == neighbor):
                heapq.heappush(open_list, neighbor_node)

    return None  # If no path found


# Example graph (adjacency list with costs)
graph = {
    'A': {'B': 1, 'C': 4},
    'B': {'A': 1, 'C': 2, 'D': 5},
    'C': {'A': 4, 'B': 2, 'D': 1},
    'D': {'B': 5, 'C': 1}
}

# Heuristic values (estimated cost to goal)
heuristic = {
    'A': 7,
    'B': 6,
    'C': 2,
    'D': 0
}

# Find the shortest path from A to D
path = a_star('A', 'D', graph, heuristic)
print(f"Path found: {path}")
