#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode target;
    struct edge_ *next;
}edge, *pedge;


typedef struct GRAPH_NODE_ {
    int size;
    int visit;
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
}node, *pnode;

node* create_Node(int ID);
edge* create_Edge(pnode target, int w);
void build_graph_cmd(pnode *head);
pnode nodeExist(pnode *head, int ID);
int minNode(pnode *head) ;
void insert_node_cmd(pnode *node);
void delete_node_cmd(pnode *head);
void size(pnode *head , int key , int size);
void printGraph_cmd(pnode head);
void deleteGraph_cmd(pnode* head);



#endif
