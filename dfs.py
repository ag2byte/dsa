from collections import defaultdict

G = defaultdict(list)
n = 5  # we have 5 nodes
visited = [False]*5

dfsar = []


def addEdge(u, v):  # add edge from u to v
    G[u].append(v)


def dfs(at):
    if visited[at]:
        return

    visited[at] = True
    dfsar.append(at)
    neighbours = G[at]

    for next in neighbours:
        dfs(next)
