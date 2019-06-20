#include "mooz_server.h"
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>

std::vector<std::pair<int, int>> find_bridge(int n);

std::vector<int> EDGE[505];
std::vector<std::pair<int, int>> BRIDGE;

int ASK[505], VIS[505];

int QUERY_COUNT;

void DFS(int u) {
	VIS[u] = 1;
	for(auto v : EDGE[u]) {
		if(ASK[v] && !VIS[v]) {
			DFS(v);
		}
	}
}

int get_component(std::vector<int> vertices) {
	QUERY_COUNT++;
	int component = 0;
	for(auto u : vertices) {
		ASK[u] = 1;
		VIS[u] = 0;
	}
	for(auto u : vertices) {
		if(!VIS[u]) {
			DFS(u);
			component++;
		}
	}
	for(auto u : vertices) {
		ASK[u] = 0;
	}
	return component;
}

int main() {
	//input
	int N, M;

	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int u, v, is_bridge;
		scanf("%d%d%d", &u, &v, &is_bridge);
		if(u > v) std::swap(u, v);
		EDGE[u].push_back(v);
		EDGE[v].push_back(u);
		if(is_bridge) {
			BRIDGE.push_back({u, v});
		}
	}
	std::sort(BRIDGE.begin(),BRIDGE.end());

	//receive answer
	std::vector<std::pair<int, int>> ret = find_bridge(N);
	for(auto &t : ret) {
		if(t.first > t.second) {
			std::swap(t.first, t.second);
		}
	}
	std::sort(ret.begin(), ret.end());

	//compare answers
	int correct = 1;
	if(BRIDGE.size() != ret.size()) {
		correct = 0;
	}
	else {
		for(int i = 0; i < BRIDGE.size(); i++) {
			if(BRIDGE[i] != ret[i]) {
				correct = 0;
			}
		}
	}
	if(correct) printf("Correct!\nCounter = %d\n",QUERY_COUNT);
	else printf("Incorrect.\n");
	return 0;
}
