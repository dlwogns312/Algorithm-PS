#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct disjoint
{
	long long data;
	int rank;
	int num;
	int printed;
	struct disjoint* parent;
};

typedef struct edge
{
	int v1;
	int v2;
	int key;
};
edge* heap;
int heap_count = 0;

disjoint* Find(disjoint* set)
{
	if (set == set->parent)
		return set;
	return set->parent = Find(set->parent);
}
void Union(disjoint* parent1, disjoint* parent2,long long n)
{
	if (parent1->rank >= parent2->rank)
	{
		if (parent1->rank == parent2->rank)
			parent1->rank++;
		parent2->parent = parent1;
		parent1->num += parent2->num;
		parent1->data += parent2->data+n;
	}
	else
	{
		parent1->parent = parent2;
		parent2->num += parent1->num;
		parent2->data += parent1->data+n;
	}
}

void push()
{
	int child = heap_count;
	int parent = child / 2;
	while (child > 1 && heap[parent].key > heap[child].key)
	{
		int temp = heap[parent].v1;
		heap[parent].v1 = heap[child].v1;
		heap[child].v1 = temp;

		temp = heap[parent].v2;
		heap[parent].v2 = heap[child].v2;
		heap[child].v2 = temp;

		temp = heap[parent].key;
		heap[parent].key = heap[child].key;
		heap[child].key = temp;

		child = parent;
		parent = child / 2;
	}

	return;
}
void pop()
{
	int parent = 1;
	int child = heap_count;

	edge temp = heap[1];
	heap[1] = heap[child];
	heap[child] = temp;

	heap_count--;

	edge temp_parent = heap[1];
	parent = 1;
	child = parent * 2;
	
	while (child <= heap_count)
	{
		if (heap[child].key > heap[child + 1].key)
			child++;
		if (child > heap_count)
			child--;
		if (heap[child].key > temp_parent.key)
			break;

		else
		{
			heap[child / 2] = heap[child];
			child *= 2;
		}
	}

	heap[child / 2] = temp_parent;
}
int main()
{
	FILE* fp1 = fopen("commands.txt", "r");
	int n_v, n_e;
	int MAX_WEIGHT;
	disjoint** set;
	int* save;
	char com[100];
	if (!fp1)
	{
		printf("commands.txt open error!\n");
		return 0;
	}
	fscanf(fp1, "%s", com);

	FILE* fp = fopen(com, "r");
	if (!fp)
	{
		printf("%s open eror!\n", com);
		return 0;
	}
	fscanf(fp, "%d %d %d", &n_v, &n_e, &MAX_WEIGHT);

	set = (disjoint**)malloc(sizeof(disjoint*) * (n_v + 1));
	save = (int*)calloc(n_v+1,sizeof(int) );
	heap = (edge*)malloc(sizeof(edge) * (n_e+1));
	for (int i = 0; i <= n_v; i++)
	{
		disjoint* node=(disjoint*)malloc(sizeof(disjoint));
		node->parent = node;
		node->data = 0;
		node->num = 1;
		node->rank = 0;
		node->printed = 0;
		set[i] = node;
	}
	heap_count++;
	clock_t start = clock();
	while(heap_count<=n_e)
	{
		fscanf(fp, "%d %d %d", &heap[heap_count].v1, &heap[heap_count].v2, &heap[heap_count].key);
		push();
		heap_count++;
	}
	heap_count--;
	int i;
	int count = 0;
	for (i = 0; i < n_e; i++)
	{
		disjoint* parent1 = Find(set[heap[1].v1]);
		disjoint* parent2 = Find(set[heap[1].v2]);
		if (parent1 != parent2)
		{
			Union(parent1, parent2,(long long)heap[1].key);
			count++;
		}
		if (count == n_v - 1)
		{
			i++;
			break;
		}
		pop();
	}
	clock_t end = clock();

	int len = strlen(com);
	strcpy(com + len - 4, "_MST_result.txt");

	printf("소요시간 : %lf kscanned: %d\n", (double)(end - start)/CLOCKS_PER_SEC,i);

	FILE* fp2 = fopen(com, "w");
	if (count == n_v - 1)
	{
		disjoint* temp = Find(set[0]);
		fprintf(fp2, "%d\n", 1);
		fprintf(fp2, "%d %lld\n", temp->num, temp->data);
	}
	else
	{
		int forpr = 0;
		for (int j = 0; j < n_v; j++)
		{
			disjoint* temp = Find(set[j]);
			if (temp->printed == 0)
			{
				temp->printed = 1;
				save[j] = 1;
				forpr++;
			}
		}
		fprintf(fp2, "%d\n", forpr);

		for (int j = 0; j < n_v; j++)
		{
			if (!forpr)
				break;
			if (save[j])
			{
				disjoint* temp = Find(set[j]);
				fprintf(fp2, "%d %lld\n", temp->num, temp->data);
			}
		}
	}
	fclose(fp1);
	fclose(fp);
	fclose(fp2);

	free(heap);
	free(save);
	for (i = 0; i <= n_v; i++)
		free(set[i]);
	free(set);
}