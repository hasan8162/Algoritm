visited = [0] * 1000

def dfs(node, adj_lst):   #depth first search function
    if visited[node] == 0:
        visited[node] = 1   #to keep track with visited node
        print(node, end=' ')  #printing the dfs path
        for i in adj_lst[node]:
            if visited[i] == 0:
                dfs(i, adj_lst)


node, ed = input().split()  #input number of nodes and edges
node = int(node)
ed = int(ed)

adj_lst = [[]]

for i in range(node):
    adj_lst.append([])    #adjacency list to represent the graph.

for i in range(ed):
    x, y = input().split()   #input connected nodes
    x = int(x)
    y = int(y)
    adj_lst[x].append(y)
    adj_lst[y].append(x)

dfs(1, adj_lst)
