/*
 * @author AdvancerMan
 *
 * I add comments to this code. However, the ownership of code is not mine!
 */
#include <bits/stdc++.h>

using namespace std;

// Because each face has maximum 2 adjacent faces, we only need to know the previous face we have traverse to avoid loop
void dfs_order(int u, int p, vector<vector<int>> const& g, vector<int> &order) {
    // p: previous face
    // iterate over this face's adjacency faces
    for (auto v : g[u]) {
        if (v != p) {
            dfs_order(v, u, g, order);
        }
    }

    // if we reach the "end", we can push back into order
    order.push_back(u);
}

void get_order(map<pair<int, int>, vector<int>> const& in, int n, vector<int> &order) {
    // g[i] = [0, 3, 5] (its adjaceny face indices)
    vector<vector<int>> g(n); // dual graph
    // loop over every edge(e == (pair, vector)) of this graph to build a dual graph
    // O(n) time
    for (auto e : in) {
        auto vs = e.second; // vs(vertices): face vertices

        // if this edge belong to two triangle, we should add an "edge" between these two faces (dual graph)
        if (vs.size() == 2) {
            // create a double link for vs[0] <-> vs[1]
            g[vs[0]].push_back(vs[1]);
            g[vs[1]].push_back(vs[0]);
        }
    }

    dfs_order(0, -1, g, order);
}

void dfs_polygon(int u, vector<vector<int>> const& g, vector<bool> &used, vector<int> &res) {
    if (used[u]) {
        return;
    }
    used[u] = true;
    res.push_back(u);
    for (auto e : g[u]) {
        dfs_polygon(e, g, used, res);
    }
}

void get_polygon(map<pair<int, int>, vector<int>> const& in, int n, vector<int> &polygon) {
    vector<vector<int>> g(n);
    // loop over each edge
    for (auto e : in) {
        // e.second is its belonging triangle index
        // Consider only non-merged edge as a valid edge
        if (e.second.size() == 1) {
            auto edge = e.first;
            // build a bidirection link
            g[edge.first].push_back(edge.second);
            g[edge.second].push_back(edge.first);
        }
    }

    vector<bool> used(n);
    // start from 0
    dfs_polygon(0, g, used, polygon);
}

void get_polygon(vector<vector<int>> const& in, int n, vector<int> const& order, vector<int> &polygon) {

    // a list of pair: listp[i] is the vertex i's adjacenct two vertices
    vector<pair<int, int>> listp(n, {-1, -1});

    // a triplet
    auto last = in[order.back()]; // the last one in `order` is actually the first triangle being inserted

    // a doubly link list
    // listp[i].first: previous one
    // listp[i].second: next one
    for (int i = 0; i < 3; i++) {
        listp[last[i]] = {last[(i + 1) % 3], last[(i + 2) % 3]};
    }

    // loop over the remaining n-3 triangles
    for (int i = (int) order.size() - 2; i >= 0; i--) {
        auto x = in[order[i]]; // a triplet, ex. (3, 5, 6)
        // x[j] is one of the vertice of triangle `order[i]`

        int j = 0;
        while (listp[x[j]] != pair<int, int>{-1, -1}) {
            j++;
        }

        // j is an index of vertex that has not been initialize (because it is (-1, -1))

        int x1 = x[j], x2 = x[(j + 1) % 3], x3 = x[(j + 2) % 3];
        // Note that x1 must be the one that have not exist
        if (listp[x2].second != x3) {
            // assert(listp[x2].first == x3)
            swap(x2, x3);
        }

        listp[x1] = {x2, x3};
        // if listp[x2].second == x3, we change it to x1
        // if listp[x2].second != x3, it implies that listp[x2].first == x3 and listp[x3].second == x2
        // (because we already sort in[i] ex. (3, 5, 6), 3->(5,6), 5->(6,3), 6->(5,6))
        // Therefore, we swap(x2, x3),
        // and then now we are sure our current listp[x3].first == x2 and listp[x2].second == x3
        listp[x2].second = x1;
        listp[x3].first = x1;
    }

    // put 0 as the first one
    polygon.push_back(0);

    int now = listp[0].second;
    while (now != 0) {
        polygon.push_back(now);
        now = listp[now].second;
    }
}

void out(vector<int> const& v) {
    for (auto e : v) {
        cout << e + 1 << ' ';
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;

    // save (n-2) triangles
    vector<vector<int>> in(n - 2, vector<int>(3));
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> in[i][j];
            in[i][j]--;
        }
        // make this triplet unique
        sort(in[i].begin(), in[i].end());
    }

    // edge -> [triangle 1, triangle 2]
    map<pair<int, int>, vector<int>> mp;
    for (int i = 0; i < n - 2; i++) {
        // triangle: a triplet
        auto tri = in[i];
        for (int j = 0; j < 2; j++) {
            for (int k = j + 1; k < 3; k++) {
                // consider every edge in this triangle
                mp[{tri[j], tri[k]}].push_back(i); // consider this edge belongs to triangle i
            }
        }
    }

    vector<int> order;
    get_order(mp, n, order);

    vector<int> polygon;
    get_polygon(in, n, order, polygon);
    // get_polygon(mp, n, polygon);  // another solution

    out(polygon);
    out(order);
}

int main() {
    int t;
    cin >> t;

    for (int t_num = 1; t_num <= t; t_num++) {
        solve();
    }

    return 0;
}
