#define MAX_NODE 10000

struct Node {
	int data;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(0);
	
}

void addNode2Head(int data)
{
	Node* temp = getNode(data);
	temp->next = head->next;
	head->next = temp;
}

void addNode2Tail(int data)
{
	Node* temp = getNode(data);

	Node* find;
	for (find = head; find->next != nullptr; find = find->next);
	find->next = temp;
}

void addNode2Num(int data, int num)
{
	int count = 1;
	Node* find;
	for (find = head; find->next != nullptr; find = find->next)
	{
		if (count == num)
			break;
		count++;
	}
	Node* temp = getNode(data);

	temp->next = find->next;
	find->next = temp;
}

void removeNode(int data)
{
	Node* find;
	for (find = head; find->next != nullptr; find = find->next)
	{
		if (find->next->data == data)
			break;
	}
	
	Node* temp = find->next;
	if (!temp)
		return;
	find->next = temp->next;
}

int getList(int output[MAX_NODE])
{
	int count=0;
	for (Node* find = head->next; find != nullptr; find = find->next)
	{
		output[count++] = find->data;
	}
	return count;
}