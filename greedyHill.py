def greedy_hill_climbing(start, goal, neighbors, heuristic):
    """
    Greedy Hill Climbing Algorithm
    :param start: The start state.
    :param goal: The goal state (not necessarily used in greedy search, but useful for comparison).
    :param neighbors: A function that returns the neighboring nodes for a given node.
    :param heuristic: A function that returns the heuristic value for a given node.
    :return: The path found to the goal or a message indicating failure.
    """
    current = start
    path = [current]
    
    while current != goal:
        # Get neighbors of the current state
        neighbor_nodes = neighbors(current)
        
        # Find the neighbor with the best heuristic value (greedy choice)
        next_node = None
        best_heuristic = float('inf')  # Start with an infinite heuristic value
        
        for neighbor in neighbor_nodes:
            h = heuristic(neighbor)
            if h < best_heuristic:  # We want to minimize the heuristic value
                next_node = neighbor
                best_heuristic = h
        
        if next_node is None:  # If no improvement is possible, stop
            print("Stuck in a local optimum!")
            return None
        
        # Move to the best neighbor
        current = next_node
        path.append(current)
    
    return path


# Example Problem:
# States are represented by numbers, and we are trying to reach the goal state 1.

# The heuristic function estimates the "distance" to the goal (lower is better).
def heuristic(state):
    return abs(state - 1)

# Neighbor function returns possible neighboring states
def neighbors(state):
    if state == 5:
        return [4, 6]
    elif state == 4:
        return [3, 5]
    elif state == 3:
        return [2, 4]
    elif state == 2:
        return [1, 3]
    else:
        return [state]  # End state (1) has no neighbors

# Start the Greedy Hill Climbing search from state 5
start_state = 5
goal_state = 1
path = greedy_hill_climbing(start_state, goal_state, neighbors, heuristic)

if path:
    print("Path found:", path)
else:
    print("No path found.")
