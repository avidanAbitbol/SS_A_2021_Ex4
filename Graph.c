#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Graph.h"


typedef struct GRAPH_NODE_ *pnode;

typedef struct edge_ {
    int weight;
    pnode target;
    struct edge_ *next;
}
edge, *pedge;


typedef struct node_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
}
node, *pnode;

pnode create_Node(int ID, pnode Next){
    pnode newNode = (pnode)malloc(sizeof(node));
    newNode->node_num = ID;
    newNode->next = Next;
    newNode->edges = NULL;
    return newNode;
}

pedge create_Edge(pnode target, int w){
    pedge newEdge = (pedge)malloc(sizeof(edge));
    newEdge->target = target;
    newEdge->next = NULL;
    newEdge->weight = weight;
    return newEdge;
}

void build_graph_cmd(numOfNodes) {
    for (int i = 0; i < numOfNodes; i++) {
        scanf("%c", &a);
        if (a == 'n') {
            insert_node_cmd(head);
        }
    }
}

int nodeExist(pnode *head, int ID){
    pnode current = *head;
    while(current!=null) {
        if (current->node_num == ID) {
            return 1;
        }
        current = current->next;
    }
    return 0;
    }
}
void insert_node_cmd(pnode *head){
    int newNode = -1;
    pnode addedNode;
    scanf("%d",&newNode);
    if(nodeExist(head, newNode)==0){
      addedNode = create_Node(newNode, *head)
  }
    else {
        pnode current = *head;
        while (current != NULL) {
            if (current->node_num == newNode) {
                break;
            }
            current = current->next;
        }
        pedge edges = current->edges;
        while (edges != NULL) {
            pedge tmp = edges->next;
            edges = tmp;
            free(tmp)
        }
        current->edges = NULL;
        addedNode = current;
    }

    pedge *insertEdge = &(addedNode->edges);
    int target = -1;
    while (scanf("%d",&target)!=0)
    {
        if(target==-1){
            return;
        }
        pnode tarNode = NULL;
        if(nodeExist(head,target)==0){
            create_Node(target,head);
        }
        pnode current = *head;
        while(current!=NULL){
            if(current->node_num==target){
                break;
            }
            current=current->next;
        }
        tarNode = current;

        int weight = -1;
        scanf("%d",&weight);
        *insertEdge = create_Edge(tarNode,weight)
  }
}


void delete_node_cmd(pnode *head){
    int del = -1;
    scanf("%d",&del);
    pnode tmp = *head;

    while (tmp != NULL)
    {
        if(tmp->node_num == del)
        {
            tmp = tmp->next;
            if(tmp == NULL)
            {
                break;
            }
        }
        pedge to_free = NULL;
        pedge prev_edge = NULL;
        pedge Edges = tmp->edges;
        while (Edges != NULL)
        {
            if(Edges->endpoint->node_num == del)
            {
                if(prev_edge == NULL)
                {
                    to_free = Edges;
                    Edges = Edges->next;
                    free(to_free);
                    tmp->edges = Edges;
                }
                else
                {
                    to_free = Edges;
                    prev_edge->next = Edges->next;
                    Edges = Edges->next;
                    free(to_free);
                }
            }
            else
            {
                prev_edge = Edges;
                Edges = Edges->next;
            }
        }
        tmp = tmp->next;
    }
    pnode prev_node = *head;
    if(prev_node->node_num == delete) {
        pedge Edges = prev_node->edges;
        while (Edges != NULL){
            pedge tmp = Edges->next;
            Edges = tmp;
            free(tmp);
        }
        prev_node->edges=NULL;
        pnode to_free = prev_node;
        prev_node = prev_node->next;
        free(to_free);
        *head = prev_node;
    }
    else{
        while (prev_node->next != NULL && prev_node->next->node_num != delete){
            if(prev_node->next == NULL){
                return;
            }
            prev_node = prev_node->next;
        }
        pnode Node_to_free = prev_node->next;
        pedge Edge = Node_to_free->edges;
        while (Edge != NULL){
            pedge tmp = Edge->next;
            Edge = tmp;
            free(tmp);
        }
        Node_to_free->edges=NULL;
        prev_node->next = Node_to_free->next;
        free(Node_to_free);
    }
}
}
void printGraph_cmd(pnode head){
    pnode temp = head;
    while (temp != NULL)
    {
        printf("Node: %d {", tempNode->node_num);
        pedge NodeEdges = temp->edges;
        while (NodeEdges != NULL)
        {
            printf("dest: %d weight: %d ", NodeEdges->target->node_num, tempEdge->weight);
            NodeEdges = NodeEdges->next;
        }
        printf("}");
        temp = temp->next;
    }
}
void deleteGraph_cmd(pnode* head){{
        pnode tempNode = *head;
        while (tempNode != NULL)
        {
            pedge tempEdge = tempNode->edges;
            while (tempEdge != NULL)
            {
                pedge deleteEdge = tempEdge;
                tempEdge = tempEdge->next;
                free(deleteEdge);
            }
            node *deleteNode = tempNode;
            tempNode = tempNode->next;
            free(deleteNode);
        }
        free(tempNode);
    }


void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);








