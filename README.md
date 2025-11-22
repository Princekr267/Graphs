# Graph Algorithms in C++

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![DSA](https://img.shields.io/badge/Data_Structures-Graphs-orange?style=for-the-badge)
![Algorithms](https://img.shields.io/badge/Algorithms-Graph_Theory-green?style=for-the-badge)

A comprehensive collection of graph algorithms implemented in C++ for learning and interview preparation. From basics like BFS/DFS to advanced topics like MST and topological sorting.

## 📋 Quick Overview

This repository contains implementations of essential graph algorithms organized by category:

**Traversal** • **Shortest Paths** • **MST** • **Cycle Detection** • **Topological Sort** • **Advanced Problems**

## 🎯 What's Inside

### Core Algorithms

| Category | Algorithms | Files |
|----------|-----------|-------|
| **Traversal** | BFS, DFS (connected & disconnected) | `build.cpp` |
| **Shortest Path** | Dijkstra, Bellman-Ford | `dijkstraAlgo.cpp`, `bellmanFord.cpp` |
| **MST** | Prim's, Kruskal's | `primsAlgo.cpp`, `kruskalsAlgo.cpp` |
| **Cycle Detection** | Directed & Undirected | `cycle.cpp`, `directedGraph.cpp` |
| **Topological Sort** | DFS-based, Kahn's Algorithm | `topologicalSort.cpp`, `kahns_algo.cpp` |
| **Union-Find** | Path compression, Union by rank | `disjointSet.cpp` |

### LeetCode Problems Solved

- **Course Schedule** (LC 207) - Detect cycles for course prerequisites
- **Course Schedule II** (LC 210) - Find valid course ordering
- **Min Cost to Connect Points** (LC 1584) - MST application
- **Cheapest Flights Within K Stops** (LC 787) - Modified BFS
- **Flood Fill** (LC 733) - DFS on 2D grid
- **Graph Valid Tree** - Bipartite checking

## 🚀 Quick Start

### Compile and Run

```bash
# Compile any file
g++ -std=c++11 dijkstraAlgo.cpp -o dijkstra
./dijkstra

# Or use this one-liner
g++ -std=c++11 filename.cpp -o output && ./output
```

### Basic Usage

```cpp
// Create graph with 6 vertices
Graph graph(6);
graph.addEdge(0, 1);
graph.addEdge(1, 2);

// Run algorithms
graph.bfs();           // Breadth-first traversal
graph.dfs();           // Depth-first traversal
bool cycle = graph.isCycleDir();  // Check for cycles

// Shortest path from vertex 0
dijkstra(0, graph, V);

// Find minimum spanning tree
graph.primsAlgo(0);
```

## 📊 Time Complexities Reference

| Algorithm | Time | Space | Notes |
|-----------|------|-------|-------|
| BFS/DFS | O(V + E) | O(V) | V = vertices, E = edges |
| Dijkstra | O(E log V) | O(V) | Non-negative weights only |
| Bellman-Ford | O(V × E) | O(V) | Handles negative weights |
| Prim's MST | O(E log V) | O(V) | With priority queue |
| Kruskal's MST | O(E log E) | O(V) | Edge sorting + Union-Find |
| Topological Sort | O(V + E) | O(V) | DAG only |
| Union-Find | O(α(n)) | O(n) | α ≈ constant (inverse Ackermann) |

## 📁 File Guide

### Fundamentals
- **`build.cpp`** - Graph class with BFS, DFS, path finding (connected & disconnected graphs)
- **`directedGraph.cpp`** - Directed graphs with cycle detection, bipartite checking, all paths

### Shortest Paths
- **`dijkstraAlgo.cpp`** - Single-source shortest path (non-negative weights)
- **`bellmanFord.cpp`** - Shortest path with negative weight support

### Minimum Spanning Tree
- **`primsAlgo.cpp`** - Greedy MST using priority queue
- **`kruskalsAlgo.cpp`** - Edge-based MST with Union-Find

### Topological Ordering
- **`topologicalSort.cpp`** - DFS + stack approach for DAG ordering
- **`kahns_algo.cpp`** - BFS-based using indegree (detects cycles too)

### Cycle Detection
- **`cycle.cpp`** - Undirected graphs using parent tracking
- **`directedGraph.cpp`** - Directed graphs using recursion stack

### Advanced Topics
- **`disjointSet.cpp`** - Union-Find with path compression
- **`connectPoints.cpp`** - Min cost MST & cheapest flights problems
- **`courseSchedule.cpp`** - Course prerequisite validation (cycle detection)
- **`courseSched_2.cpp`** - Valid course ordering (topological sort)
- **`floodFill.cpp`** - DFS-based region filling algorithm

## 💡 Key Concepts Explained

### When to Use What?

**Need shortest path?**
- Unweighted graph → BFS
- Non-negative weights → Dijkstra
- Negative weights → Bellman-Ford

**Need minimum cost to connect all nodes?**
- Dense graph → Prim's Algorithm
- Sparse graph → Kruskal's Algorithm

**Need ordering with dependencies?**
- Use Topological Sort (must be DAG)
- DFS-based for simple cases
- Kahn's to detect cycles simultaneously

**Need to check graph properties?**
- Cycle → DFS with recursion stack (directed) or parent tracking (undirected)
- Bipartite → BFS/DFS with 2-coloring
- Connected components → DFS/BFS on all unvisited nodes

### Union-Find Optimizations

```cpp
// Path Compression - flattens tree
int find(int x) {
    if(par[x] == x) return x;
    return par[x] = find(par[x]);  // Compress path
}

// Union by Rank - attach smaller tree under larger
void unionByRank(int a, int b) {
    int parA = find(a), parB = find(b);
    if(rank[parA] == rank[parB]) {
        par[parB] = parA;
        rank[parA]++;
    } else if(rank[parA] > rank[parB]) {
        par[parB] = parA;
    } else {
        par[parA] = parB;
    }
}
```

## 🎓 Learning Path

1. **Start Here:** `build.cpp` - Basic BFS, DFS, graph representation
2. **Cycle Detection:** `cycle.cpp`, `directedGraph.cpp` - Understand recursion stack
3. **Shortest Paths:** `dijkstraAlgo.cpp` → `bellmanFord.cpp`
4. **MST:** `primsAlgo.cpp` → `kruskalsAlgo.cpp` (requires `disjointSet.cpp`)
5. **Topological Sort:** `topologicalSort.cpp` → `kahns_algo.cpp`
6. **Apply:** `courseSchedule.cpp`, `connectPoints.cpp`, `floodFill.cpp`

## 🔍 Common Patterns

- **Most graph problems:** Start with BFS/DFS
- **Shortest path needed:** Think Dijkstra or BFS (unweighted)
- **"All possible" or "count ways":** DFS with backtracking
- **DAG + ordering:** Topological Sort
- **Connecting nodes with min cost:** MST (Prim's/Kruskal's)
- **Dynamic sets that merge:** Union-Find

## 📚 Resources

- [Visualize Algorithms](https://visualgo.net/en/graphds) - See how algorithms work
- [LeetCode Graph Tag](https://leetcode.com/tag/graph/) - Practice problems
- [CP-Algorithms](https://cp-algorithms.com/graph/breadth-first-search.html) - Detailed explanations

## 🤝 Contributing

Found a bug or want to add an algorithm? Contributions welcome!

## ⭐ If This Helped You

Star this repo if it helped you learn graphs! 

---

**Built for DSA learners preparing for interviews and competitive programming**
