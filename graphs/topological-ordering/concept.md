Topological ordering using DFS:
Helps with iterative DP and all stuff 

Mostly valid for DAG

solved using DFS with order pushed at end of dfs function.

----


Topological ordering using BFS:
Kahn's algorithm

Just use BFS and maintain inodes and put stuff with inode == 0 in the queue and keep simulating removing the nodes by decreasing inodes from neighbours.
We can detect cycle too using it when we have the topo order length < the nodes length.

Lexicographically smallest/largest ordering: use pq ordering

