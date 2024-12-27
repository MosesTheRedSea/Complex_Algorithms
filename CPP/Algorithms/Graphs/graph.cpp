#include <iostream>
#include <string>
#include <cmath>
#include <typeinfo>
#include <array>
#include <time.h>
#include <time.h>
#include <time.h>

// Built Data Structures
#include <bits/stdc++.h>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <unordered_set>
#include <set> 
using namespace std;

/*			  											 														 
	█▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
	█░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
	█──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀											 
*/

/*

	Depth First Search

	Deep into a node before we ask any children

	We might run really far away

	Breadth First Search
	
*/

class Edge;
	  
class Node {
public:
    int value;
    bool visited; // Boolean which checks if the node was visited
    std::vector<std::shared_ptr<Edge>> edges;
    Node(int val) : value(val), visited(false) {}
};

class Edge {
public:
    int value;
    std::shared_ptr<Node> node_from;
    std::shared_ptr<Node> node_to;
    Edge(int val, std::shared_ptr<Node> from, std::shared_ptr<Node> to) 
        : value(val), node_from(from), node_to(to) {}
};

class Graph {
public:
    std::vector<std::shared_ptr<Node>> nodes;
    std::vector<std::shared_ptr<Edge>> edges;
    std::unordered_map<int, std::string> node_names;

    std::shared_ptr<Node> insertNode(int val) {
        auto new_Node = std::make_shared<Node>(val);
        nodes.push_back(new_Node);
        return new_Node;
    }

    void insertEdge(int new_Edge_Val, int node_From_Val, int node_To_Val) {
        std::unordered_map<int, std::shared_ptr<Node>> node_map;
        node_map[node_From_Val] = nullptr;
        node_map[node_To_Val] = nullptr;
        for (const auto& node : nodes) {
            if (node_map.find(node->value) != node_map.end()) {
                node_map[node->value] = node;
                if (node_map[node_From_Val] && node_map[node_To_Val]) {
                    break;
                }
            }
        }

        for (auto& pair : node_map) {
            if (!pair.second) {
                pair.second = insertNode(pair.first);
            }
        }

        auto node_from = node_map[node_From_Val];
        auto node_to = node_map[node_To_Val];
        auto new_edge = std::make_shared<Edge>(new_Edge_Val, node_from, node_to);
        
        node_from->edges.push_back(new_edge);
        node_to->edges.push_back(new_edge);
        edges.push_back(new_edge);
    }

    std::vector<std::tuple<int, int, int>> getEdgeList() {
        std::vector<std::tuple<int, int, int>> edge_list;
        for (const auto& edge : edges) {
            edge_list.emplace_back(edge->value, edge->node_from->value, edge->node_to->value);
        }
        return edge_list;
    }

    std::vector<std::tuple<int, std::string, std::string>> getEdgeListNames() {
        std::vector<std::tuple<int, std::string, std::string>> edge_list;
        for (const auto& edge : edges) {
            edge_list.emplace_back(edge->value, node_names[edge->node_from->value], node_names[edge->node_to->value]);
        }
        return edge_list;
    }

    std::vector<std::vector<std::pair<int, int>>> getAdjacencyList() {
        int max_index = findMaxIndex();
        std::vector<std::vector<std::pair<int, int>>> adjacency_list(max_index);

        for (const auto& edge : edges) {
            adjacency_list[edge->node_from->value].emplace_back(edge->node_to->value, edge->value);
        }

        for (auto& list : adjacency_list) {
            if (list.empty()) {
                list = std::vector<std::pair<int, int>>();
            }
        }

        return adjacency_list;
    }

    std::vector<std::vector<std::pair<std::string, int>>> getAdjacencyListNames() {
        auto adjacency_list = getAdjacencyList();
        std::vector<std::vector<std::pair<std::string, int>>> adjacency_list_names;

        for (const auto& list : adjacency_list) {
            std::vector<std::pair<std::string, int>> name_list;
            for (const auto& pair : list) {
                name_list.emplace_back(node_names[pair.first], pair.second);
            }
            adjacency_list_names.push_back(name_list);
        }

        return adjacency_list_names;
    }

    std::vector<std::vector<int>> getAdjacencyMatrix() {
        int max_index = findMaxIndex();
        std::vector<std::vector<int>> adjacency_matrix(max_index, std::vector<int>(max_index, 0));

        for (const auto& edge : edges) {
            adjacency_matrix[edge->node_from->value][edge->node_to->value] = edge->value;
        }

        return adjacency_matrix;
    }

    int findMaxIndex() {
        if (!node_names.empty()) {
            return node_names.size();
        }

        int max_index = -1;
        for (const auto& node : nodes) {
            if (node->value > max_index) {
                max_index = node->value;
            }
        }
        return max_index;
    }

    std::shared_ptr<Node> findNode(int node_number) {
        for (const auto& node : nodes) {
            if (node->value == node_number) {
                return node;
            }
        }
        return nullptr;
    }

    void clearVisited() {
        for (const auto& node : nodes) { // Sets the Boolean of Visited in all the nodes to False
            node->visited = false;
        }
    }

    // Recursive DFS Helper
    std::vector<int> dfsHelper(std::shared_ptr<Node> start_node) {
        std::vector<int> ret_list;
        ret_list.push_back(start_node->value);
        start_node->visited = true;

        for (const auto& edge : start_node->edges) {
            if (!edge->node_to->visited) {
                auto result = dfsHelper(edge->node_to);
                ret_list.insert(ret_list.end(), result.begin(), result.end());
            }
        }
        return ret_list;
    }

    std::vector<int> dfs(int start_node_num) {
        clearVisited();
        auto start_node = findNode(start_node_num);
        return dfsHelper(start_node);
    }

    std::vector<std::string> dfsNames(int start_node_num) {
        auto result = dfs(start_node_num);
        std::vector<std::string> names;
        for (const auto& num : result) {
            names.push_back(node_names[num]);
        }
        return names;
    }

    std::vector<int> bfs(int start_node_num) {
        std::vector<int> ret_list;
        std::queue<std::shared_ptr<Node>> queue;
        auto start_node = findNode(start_node_num);
        clearVisited();
        start_node->visited = true;
        queue.push(start_node);
        while (!queue.empty()) {
            auto node = queue.front();
            queue.pop();
            ret_list.push_back(node->value);

            for (const auto& edge : node->edges) {
                if (!edge->node_to->visited) {
                    edge->node_to->visited = true;
                    queue.push(edge->node_to);
                }
            }
        }
        return ret_list;
    }

    std::vector<int> bfs(int start_node_num) {
    	std::vector<int> ret_list;
    	std::queue<std::shared_ptr<Node>> queue;
    	auto start_node = findNode(start_node_num);
    	clearVisited();
    }

    std::vector<std::string> bfsNames(int start_node_num) {
        auto result = bfs(start_node_num);
        std::vector<std::string> names;
        for (const auto& num : result) {
            names.push_back(node_names[num]);
        }
        return names;
    }
};