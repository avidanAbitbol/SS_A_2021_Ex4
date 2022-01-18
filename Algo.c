#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Algo.h"


int shortsPath_cmd(pnode head,int src,int dest ){
    pnode current = head;
	pnode current1 = head;
	while (current != NULL) {
		current->size = INT_MAX;
		current->visit = 0;
		current = current->next;
	}
	size(&head, src, 0);
	while (current1 != NULL) {
		int min_node = minNode(&head);
		if (nodeExist(&head, min_node)->edges != NULL) {
			pedge e = nodeExist(&head, min_node)->edges;
			if (e != NULL) {
				while (e != NULL) {
					int size_ = nodeExist(&head,e->target->node_num)->size;
					int edge_size = e->weight;
					int s_Edge = nodeExist(&head, min_node)->size + edge_size;
					if (s_Edge < size_) {
						size(&head, e->target->node_num, s_Edge);

					}
					e = e->next;
				}
			}
		}
		nodeExist(&head, min_node)->visit = 1;
		current1 = current1->next;
	}
	if (nodeExist(&head, dest)->size == INT_MAX)
		return -1;
    return nodeExist(&head, dest)->size;
}
int TSP_cmd(pnode head){
    int Tsp;
	int *len;
	scanf("%d", &Tsp);
	len = (int*)malloc(Tsp * sizeof(int));
	if (len == NULL) {
		return 0;
	}
	int i = 0;
	while (i< Tsp) {
		scanf("%d", &len[i]);
		i++;
	}
	int sum_tsp = 0;
	for (i = 0; i < Tsp - 1; i++) {
		sum_tsp += shortsPath_cmd(head, len[i], len[i + 1]);
	}
    free(len);
    return sum_tsp;

}
