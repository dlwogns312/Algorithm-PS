#define MAX_NODE 10000

struct Node {
	int data;
	Node* prev;
	Node* next;
};

Node node[MAX_NODE];
int nodeCnt;
Node* head;

Node* getNode(int data) {
	node[nodeCnt].data = data;
	node[nodeCnt].prev = nullptr;
	node[nodeCnt].next = nullptr;
	return &node[nodeCnt++];
}

void init()
{
	nodeCnt = 0;
	head = getNode(-1);
}

void addNode2Head(int data)
{
	Node* temp = getNode(data);
	Node* con = head->next;
	if(con)
		con->prev = temp;
	temp->next = con;
	temp->prev = head;
	head->next = temp;
}

void addNode2Tail(int data)
{
	Node* temp = getNode(data);
	Node* find;
	for (find = head; find->next != nullptr; find = find->next);

	find->next = temp;
	temp->prev = find;
}

void addNode2Num(int data, int num)
{
	int count = 1;
	Node* temp = getNode(data);
	Node* find;
	for (find = head; find->next != nullptr; find = find->next)
	{
		if (count == num)
			break;
		count++;
	}

	if (!find->next)
	{
		find->next = temp;
		temp->prev = find;
	}
	else {
		Node* con = find->next;
		if(con)
			con->prev = temp;
		temp->next = con;
		temp->prev = find;
		find->next = temp;
	}

}

int findNode(int data)
{
	Node* find;
	int count = 1;
	for (find = head; find->next != nullptr; find = find->next)
	{
		if (find->next->data == data)
			break;
		count++;
	}

	return count;

}

void removeNode(int data)
{
	Node* find;
	for (find = head; find->next != nullptr; find = find->next)
		if (find->next->data == data)
			break;

	Node* temp = find->next;
	if (!temp)
		return;
	else
	{
		find->next = temp->next;
		if (temp->next)
			temp->next->prev = find;
	}
}

int getList(int output[MAX_NODE])
{
	int count = 0;
	for (Node* temp = head->next; temp != nullptr; temp = temp->next)
		output[count++] = temp->data;

	return count;
}

int getReversedList(int output[MAX_NODE])
{
	Node* temp;
	for (temp = head; temp->next != nullptr; temp = temp->next);

	int count = 0;

	for (Node* save = temp; save != head; save = save->prev)
		output[count++] = save->data;

	return count;
}