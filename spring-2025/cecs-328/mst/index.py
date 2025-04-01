from pathlib import Path
from ast import literal_eval


class UnionFind:
    def __init__(self, n):
        # Initialize the parent and rank arrays
        self.parent = list(range(n))  # Each node is its own parent initially
        self.rank = [0] * n  # Rank is used to keep the tree flat

    def find(self, node):
        # Path compression heuristic
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union(self, u, v):
        # Find roots of the sets to which elements u and v belong
        root_u = self.find(u)
        root_v = self.find(v)

        if root_u == root_v:
            return

        # Union by rank to keep the tree flat
        if self.rank[root_u] > self.rank[root_v]:
            self.parent[root_v] = root_u
        elif self.rank[root_u] < self.rank[root_v]:
            self.parent[root_u] = root_v
        else:
            self.parent[root_v] = root_u
            self.rank[root_u] += 1


def kruskal(n, edges):
    # Step 1: Sort edges based on weight
    edges.sort(key=lambda x: x[2])

    # Step 2: Initialize Union-Find data structure
    uf = UnionFind(n)
    mst = []  # Store the edges of the MST
    mst_cost = 0  # Total cost of MST

    for u, v, weight in edges:
        # Step 3: Check if adding this edge creates a cycle
        if uf.find(u) != uf.find(v):
            uf.union(u, v)  # Combine sets
            mst.append((u, v, weight))  # Include this edge in MST
            mst_cost += weight  # Add the edge weight to total cost

    return mst, mst_cost


def find_number_of_vertices(edges: list[list[int]]):
    largest_n = 0

    for u, v, _ in edges:
        largest_n = max(u, largest_n)
        largest_n = max(v, largest_n)

    return largest_n


def main():
    folder = Path('tests')

    for obj in sorted(folder.iterdir()):
        if not obj.is_file():
            continue

        if obj.name == '10.txt':
            continue

        with obj.open('r') as file:
            content = file.read()
            content = content.replace('{', '[').replace('}', ']')
            edges = literal_eval(content)

            n = find_number_of_vertices(edges)
            print(n)

            _, cost = kruskal(edges)

            print(f"Weight: {cost}")


main()
