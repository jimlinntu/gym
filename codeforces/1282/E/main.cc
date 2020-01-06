#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <vector>
#define MAXN 100001
#define INITSIZE 8
#define MIN(x,y) ((x)<(y)? (x):(y))
using namespace std;

int n, t; // the number of nodes and the number of testcases

int a, b, c;

struct Node;
struct Triangle;
struct Pair;

int intlog2(int n){
    int power = 0;
    while((n >>=1)) power++;
    return power;
}

struct Pair{
    int left, right;
    Pair(int l, int r){
        left = l, right = r;
    }
    // https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key
    // (a, b) == (b, a)
    bool operator ==(const Pair &other) const{
        // swap-invariant equal
        return (left == other.left and right == other.right) or (left == other.right and right == other.left); 
    }
};

namespace std{
    template <>
    class hash<Pair>{
        public:
            hash<int> hasher;
            size_t operator()(const Pair &pair) const{
                return this->hasher(pair.left) ^ this->hasher(pair.right);
            }
    };
}

// (a,b) -> 0(no connecting edge) or 1(non merge cut) or 2(merge cut)
unordered_map<Pair, int> edge2count;

struct Node{
    // x[node index] = (has edge, is merge cut)
    int index;
    vector<int> indices;


    void init(int idx){
        index = idx;
        indices.clear();
    }

    bool link(int node_idx){
        // this (a -> b) link already exist
        Pair edge = Pair(index, node_idx);
        if(edge2count[edge] != 0){
            edge2count[edge] += 1; // second visit: mark it as a merge cut
            return true; // exist
        }else{
            edge2count[edge] = 1;
            indices.push_back(node_idx); // record its neighbors
            return false; // not exist
        }
    }
    
    static bool link_two(Node *left, int left_idx, Node *right, int right_idx){
        bool ret = left->link(right_idx);
        right->link(left_idx);
        return ret;
    }
};


// vertices from 0 to n-1
Node vertices[MAXN];
bool visit[MAXN];

// Map an edge (a, b) to an index of a triangle
unordered_map<Pair, int> edge2triangleIdx;

struct Triangle{
    int index; // the original index
    int num_cut;
    void init(int i, int a, int b, int c, Triangle triangles[], vector<int> *neighbors_of_triangles){
        index = i;
        num_cut = 0;
        // ( a <-> b )
        bool ret = Node::link_two(&vertices[a], a, &vertices[b], b);
        // if this link already exists
        if(ret){
            // this (a, b) pair belongs to this triangle
            int existing_triangle_index = edge2triangleIdx[Pair(a, b)];
            triangles[existing_triangle_index].num_cut += 1; // other
            triangles[index].num_cut += 1; // itself

            // register this triangle's neighbor
            neighbors_of_triangles[index].push_back(existing_triangle_index);
            neighbors_of_triangles[existing_triangle_index].push_back(index);
        }else{
            // register this edge
            edge2triangleIdx[Pair(a, b)] = index;
        }

        // ( b <-> c )
        ret = Node::link_two(&vertices[b], b, &vertices[c], c);
        if(ret){
            int existing_triangle_index = edge2triangleIdx[Pair(b, c)];
            triangles[existing_triangle_index].num_cut += 1; // other
            triangles[index].num_cut += 1; // itself

            // register this triangle's neighbor
            neighbors_of_triangles[index].push_back(existing_triangle_index);
            neighbors_of_triangles[existing_triangle_index].push_back(index);
        }else{
            edge2triangleIdx[Pair(b, c)] = index;
        }
        
        // ( c <-> a )
        ret = Node::link_two(&vertices[c], c, &vertices[a], a);
        if(ret){
            int existing_triangle_index = edge2triangleIdx[Pair(c, a)];
            triangles[existing_triangle_index].num_cut += 1; // other
            triangles[index].num_cut += 1; // itself

            // register this triangle's neighbor
            neighbors_of_triangles[index].push_back(existing_triangle_index);
            neighbors_of_triangles[existing_triangle_index].push_back(index);
        }else{
            edge2triangleIdx[Pair(c, a)] = index;
        }
    }
    bool operator < (const Triangle& t) const{
        return num_cut < t.num_cut;
    }

    static void heapify_indices(int indices[], Triangle triangles[], int root_idx, int triangleIdx2heapIdx[]){
        // heapify the indices based on the num_cut of triangles
        // min heap (<)
        int left = 2 * root_idx + 1, right = left + 1;
        if(left < n) Triangle::heapify_indices(indices, triangles, left, triangleIdx2heapIdx);
        if(right < n) Triangle::heapify_indices(indices, triangles, right, triangleIdx2heapIdx);

        int min_index = root_idx;
        if(left < n && triangles[indices[left]].num_cut < triangles[indices[root_idx]].num_cut) min_index = left;
        if(right < n && triangles[indices[right]].num_cut < triangles[indices[root_idx]].num_cut && 
                triangles[indices[right]].num_cut < triangles[indices[left]].num_cut)
            min_index = right;
        
        // swap
        if(min_index != root_idx){
            // make sure triangleIdx2heapIdx[idx] can retrieve the current position of idx in heapified indices
            swap(triangleIdx2heapIdx[indices[root_idx]], triangleIdx2heapIdx[indices[min_index]]);
            // swap two triangles' indices
            swap(indices[root_idx], indices[min_index]);
            // swap this value until no children is strictly smaller than this parent
            Triangle::siftdown(indices, triangles, min_index, triangleIdx2heapIdx);
        }
    }

    static void siftdown(int indices[], Triangle triangles[], int root_idx, int triangleIdx2heapIdx[]){
        int left, right;
        int parent = root_idx;
        while(true){
            left = 2*parent+1, right = 2*parent+2;
            if(left < n && triangles[indices[left]].num_cut < triangles[indices[parent]].num_cut) root_idx = left;
            if(right < n && triangles[indices[right]].num_cut < triangles[indices[parent]].num_cut &&
                triangles[indices[right]].num_cut < triangles[indices[left]].num_cut) root_idx = right;

            if(parent != root_idx){
                // make sure triangleIdx2heapIdx[idx] can retrieve the current position of idx in heapified indices
                swap(triangleIdx2heapIdx[indices[parent]], triangleIdx2heapIdx[indices[root_idx]]);
                swap(indices[parent], indices[root_idx]);
                parent = root_idx;
            }else break;
        }
    }
    static void siftup(int indices[], Triangle triangles[], int root_idx, int triangleIdx2heapIdx[]){
        int parent = (root_idx - 1) / 2;
        if(parent < 0) return;
        if(triangles[indices[root_idx]].num_cut < triangles[indices[parent]].num_cut){
            // make sure triangleIdx2heapIdx[idx] can retrieve the current position of idx in heapified indices
            swap(triangleIdx2heapIdx[indices[root_idx]], triangleIdx2heapIdx[indices[parent]]);
            swap(indices[root_idx], indices[parent]);
            Triangle::siftup(indices, triangles, parent, triangleIdx2heapIdx);
        }
    }

    static int pop(int indices[], Triangle triangles[], vector<int> neighbors_of_triangles[], int triangleIdx2heapIdx[]){
        // throw the minimum num_cut to the end of this array
        int pop_idx = indices[0];

        if(n == 1) return pop_idx; // if there is only one remaining.

        swap(indices[0], indices[n-1]);
        n--; // decrease the size of this heap
        
        Triangle::siftdown(indices, triangles, 0, triangleIdx2heapIdx);
        
        // update this pop_idx's neighbor's num_cut
        for(int i = 0; i < (int)neighbors_of_triangles[pop_idx].size(); i++){
            int updated_idx = neighbors_of_triangles[pop_idx][i];
            triangles[updated_idx].num_cut--;
            // triangleIdx2heapIdx[updated_idx] == the current index of `updated_idx` in `indices` heap
            Triangle::siftup(indices, triangles, triangleIdx2heapIdx[updated_idx], triangleIdx2heapIdx);
        }
        return pop_idx;
    }
};

Triangle triangles[MAXN];
int indices[MAXN]; // used for argument sorting
vector<int> neighbors_of_triangles[MAXN]; // save the neighbors of each triangle
int triangleIdx2heapIdx[MAXN];

void dfs(int start_idx){
    // initialize visit flag
    fill(visit, visit+n, false);
    vector<int> permutation;
    
    visit[start_idx] = true;
    permutation.push_back(start_idx);

    // traverse
    Node *current_vertex = &vertices[start_idx];
    bool is_end;
    do{
        // list current_vertex's neighbors
        int length = current_vertex->indices.size();
        is_end = true;
        // loop over each neighbor
        for(int i = 0; i < length; i++){
            int index = current_vertex->indices[i];
            // if this edge is not mark as merge cut, we do not pass through this edge!!
            if(visit[index] == false and edge2count[Pair(current_vertex->index, index)] == 1){
                permutation.push_back(index);
                visit[index] = true;
                // move to the next vertex
                current_vertex = &vertices[index];

                is_end = false;
                break;
            }
        }
    }while(!is_end);

    int length = permutation.size();
    for(int i = 0; i < length; i++){
        if(i != 0){
            printf(" %d", permutation[i]+1);
        }else printf("%d", permutation[i]+1);
    }
    printf("\n");
}

void search(){
    // print permutation
    dfs(0);
    // print the order of slicing
    for(int i = 0; i < n-2; i++){
        if(i != 0) printf(" %d", triangles[i].index+1);
        else printf("%d", triangles[i].index+1);
    }
    printf("\n");
}

int main(){
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            indices[j] = j;
            vertices[j].init(j); // initialize each vertex
        }
        for(int j = 0; j < n-2; j++){
            scanf("%d %d %d", &a, &b, &c);
            triangles[j].init(j, a-1, b-1, c-1, triangles, neighbors_of_triangles);
        }
        // Search
        search();
        // clear memory
        edge2triangleIdx.clear();
    }
    return 0;
}
