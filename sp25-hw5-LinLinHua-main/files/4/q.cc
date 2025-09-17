#include "q.h"

#include <climits>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Implement each function of `q.h` here.
#include <queue>
// Constructor:
// Graph::Graph(std::map<int, std::set<std::pair<int, int>>> &weight_map)
//     : weight_map_(weight_map) {}

// Returns a map of a node to a s etof its predecessors.
std::map<int, std::set<int>> Graph::GetPredecessors() {
    std::map<int, std::set<int>> predecessor;

    // First initialize every node with an empty set
    for (const auto& entry : weight_map_) {
        int u = entry.first;
        predecessor[u];  // ensures u is in the map even if no one points to it
        for (const auto& vw : entry.second) {
            int v = vw.first;
            predecessor[v].insert(u);  // u → v means u is a predecessor of v
        }
    }

    return predecessor;
}


// Returns a set of all (u,v) edges in a graph.
  std::set<std::pair<int, int>> Graph::GetEdges(){
    std::set<std::pair<int,int>> edges;

    for(const auto& entry:weight_map_){
        int u=entry.first; // the parent node
        for(const auto& vw:entry.second){
            int v=vw.first; //connected node
            edges.insert({u,v});
        }
    }

    return edges;
  }

int Graph::GetWeight(int i, int j){
    //find node i

    auto it = weight_map_.find(i); // it is a pointer

    if (it ==weight_map_.end()){ // no i find
    return INT_MAX;
    }

    for (const auto& pair: it->second){
        if (pair.first == j){
            return pair.second; //return the weight
        }

    }
    return INT_MAX; //if no find j, retrun INT_MAX

}


int Graph::GetMinWeight(){
    int min_weight = INT_MAX;

    for (const auto& entry : weight_map_){
        for (const auto& vw : entry.second){
            int weight= vw.second;
            if (weight < min_weight){
                min_weight=weight;
            }
        }
    }

    return min_weight;
}

std::vector<long> Graph::Dijkstra(int source){
    // find the biggest number of node, to construct the storage heap
    int max_node = 0;
    for (const auto& entry : weight_map_){
        max_node = std::max(max_node, entry.first);
        for (const auto& vw:entry.second){
            max_node = std::max(max_node, vw.first);
        }
    }

    //construct the min heap
    int n = max_node +1; //number start from 0 so the length+1 std::vector<long> dist(n, INT_MAX); // FIXED
    std::vector<long> dist(n, INT_MAX); // create a vecotr list n, set LONG_MAX first
    dist[source] = 0;//except the myself (source-source=0)
    std::priority_queue<std::pair<long, int>,  // each data is <dist,node>
                        std::vector<std::pair<long,int>>, // store as vector
                        std::greater<>> //use min_heap (sorting rule=greater)
                        min_heap; // called it min_heap
    min_heap.push({0,source}); //push the source/start first

    while (!min_heap.empty()){
        auto [curr_dist, u] = min_heap.top();
        min_heap.pop();

        if (curr_dist > dist[u]) continue;//the min_heap's current distant is not shortest
        //update it
        for (const auto& vw : weight_map_[u]){ //check the min_heap's top vector's node, u
            int v = vw.first;
            int w =vw.second;
            if (dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                min_heap.push({dist[v],v});
            }
        }
    }
    return dist;


}


std::vector<long> Graph::BellmanFord(int source) {
    int max_node = 0;
    for (const auto& [u, neighbors] : weight_map_) {
        max_node = std::max(max_node, u);
        for (const auto& [v, w] : neighbors) {
            max_node = std::max(max_node, v);
        }
    }
    int n = max_node + 1;
    std::vector<long> d(n, INT_MAX);
    d[source] = 0;

    // Convert to edge list and relax
    for (int i = 0; i < n - 1; ++i) {
        for (const auto& [u, neighbors] : weight_map_) {
            for (const auto& [v, w] : neighbors) {
                if (d[u] != INT_MAX && d[u] + w < d[v]) {
                    d[v] = d[u] + w;
                }
            }
        }
    }

    // Optional negative cycle check
    for (const auto& [u, neighbors] : weight_map_) {
        for (const auto& [v, w] : neighbors) {
            if (d[u] != INT_MAX && d[u] + w < d[v]) {
                // Negative cycle detected — cry into your compiler
            }
        }
    }

    return d;
}



