#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Algo.h"

node* create_Node(int ID){
    node* newNode = (node *)malloc(sizeof(node));
    if(!newNode){
        exit(1);
    }
    else {
        newNode->node_num = ID;
        newNode->next = NULL;
        newNode->edges = NULL;
        return newNode;
    }
}

edge* create_Edge(pnode target, int w){
    pedge newEdge = (pedge)malloc(sizeof(edge));
    newEdge->target = target;
    newEdge->next = NULL;
    newEdge->weight = w;
    return newEdge;
}

void insert_node_cmd(pnode *head){
  int src, dest, size;
	char flag = 0;
	scanf("%d", &src);
	pnode N_Src = nodeExist(head, src);
	if (N_Src == NULL) {
		N_Src = (pnode)malloc(sizeof(node));
		if (N_Src == NULL) {
			return;
		}
		else {
			N_Src->node_num = src;
			N_Src->edges = NULL;
			N_Src->next = *head;
			*head = N_Src;
		}
	}
	else {
		pedge Edge = N_Src->edges;
		while (Edge != NULL) {
			pedge temp = Edge->next;
			free(Edge);
			Edge = temp;
		}
		N_Src->edges = NULL;

	}
	int exist =scanf("%d", &dest);
	if (dest >= 0) {
		while (exist!=0&&flag != 'n' && flag != EOF&&flag != 'B'){
		    pnode N_Dest = nodeExist(head, dest);
			if (N_Dest == NULL) {
				N_Dest = (pnode)malloc(sizeof(node));
				if (N_Dest == NULL) {
					return;
				}
				else {
					N_Dest->node_num = dest;
					N_Dest->edges = NULL;
					N_Dest->next = *head;
					*head = N_Dest;
				}
			}
			scanf("%d", &size);
			if (N_Src->edges == NULL) {
				N_Src->edges = (pedge)malloc(sizeof(edge));
				if (N_Src->edges == NULL) {
					return;
				}
				N_Src->edges->target = N_Dest;
				N_Src->edges->weight = size;
				N_Src->edges->next = NULL;
			}
			else {
				pedge e = N_Src->edges;
				N_Src->edges = N_Src->edges->next;
				N_Src->edges = (pedge)malloc(sizeof(edge));
				if (N_Src->edges == NULL) {
					return;
				}
				N_Src->edges->target = N_Dest;
				N_Src->edges->weight = size;
				N_Src->edges->next = e;

			}
			scanf("%c", &flag);
			scanf("%c", &flag);
			dest = (flag)-'0';
		}
    }
}



pnode nodeExist(pnode *head, int ID){
    pnode current = *head;
    while(current!=NULL) {
        if(current->node_num>=0){
            if (current->node_num == ID) {
                return current;
            }
            current = current->next;
        }

    }
    return NULL;
}
int minNode(pnode *head) {
    pnode current = *head;
    int min_value = INT_MAX;
    int num = 1;
    while (current != NULL) {
        if (current->size <= min_value&&current->visit == 0) {
            min_value = current->size;
            num = current->node_num;
        }
        current = current->next;
    }
    return num;
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
            if(Edges->target->node_num == del)
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
    if(prev_node->node_num == del) {
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
        while (prev_node->next != NULL && prev_node->next->node_num != del){
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
void size(pnode *head , int key , int size){
    pnode current = *head;
    while(current != NULL){
        if(current->node_num == key){
            current->size=size;
        }
        current=current->next;
    }
}
void printGraph_cmd(pnode head){
    pnode temp = head;
    while (temp != NULL)
    {
        printf("Node: %d {", temp->node_num);
        pedge NodeEdges = temp->edges;
        while (NodeEdges != NULL)
        {
            printf("dest: %d weight: %d ", NodeEdges->target->node_num, NodeEdges->weight);
            NodeEdges = NodeEdges->next;
        }
        printf("}");
        temp = temp->next;
    }
}
void deleteGraph_cmd(pnode* head){
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
void build_graph_cmd(pnode *head) {
	deleteGraph_cmd(head);
	int numOfNodes;
	scanf("%d", &numOfNodes);
    char a;
	scanf("%c", &a);
	scanf("%c", &a);
	for (int i = 0; i < numOfNodes; i++) {
		insert_node_cmd(head);
	}
}
