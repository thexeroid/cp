Graph overview:

1. Reachability(x, y): can you reach from node x to node y?
=> Algorithms used: BFS: DFS

2. DFS (Multiple variants)

3. BFS 
    (Shortest part variants)
    3.1: Single sure shortest part problem 
    3.2: Multi source shortest part problem
    both above (
        BFS => unweighted graph,
        0-1 BFS => 0-1 weighted edges
        dynamic positive weight or no-negative cycles => dijkstra
        if negative cycles => bellman-ford
    )

    3.3: All pair shortest part problem
    shortest part between any two pairs
    (
        Floyd Warshal algorithm
    )
    

---
Glossary:
1. SSSP = Single source shortest path: 
From a single source find the shortest path to every other node.

2. MSSP = Multi source shortest path:
From every source find the closest path to every other node.

3. APSP = All pairs shortest path:
From all pairs you find the shortest path.

4. Spanning Tree = A tree that spans all the nodes 

5. MST = Minimum Spanning Tree

6. UF = Union Find

7. Trees 
    7.1: BFS/DFS
    7.2: Diameter
    7.3: Center/Centroid
    7.4: Subtree

8. Topological ordering

9. Articulation Point & Bridges

10. Eulerian Tour / Hamiltonian Tour

11. SCC

12. Max Flow / Min Cost Max Flow

13. DS on Trees, Block cut tree
    13.1: Euler tour on tree 

Algorithms:
(Single source shortest path, multi source shortest path)
1. BFS => unweighted graphs
2. 0-1 BFS => graphs with 0-1 edges
3. Dijkstra => positive weight and no negative cycles
4. Bellman Ford => contains negative cycles
5. Floyd Warshal => 
6. Krushall's Algo => calculating MST
7. BFS/DFS, Diameter, Center/Centroid => Tree
8. Kahn's algorithm => Lexicographically smallest topological 
9. Fleury, Heirholzer => Eulerian Tour
10. Tarjan's => SCC

