
int count;

typedef struct node
{
	int id;
	int income;
}node;

node ret[11];

void init()
{
	count = 0;
}

void addUser(int uID, int height)
{
	if (uID >= 10 && height < ret[9].income)
	{
		return;
	}
	int temp;
	for (temp = count-1; temp >= 0; temp--)
		if (ret[temp].income >= height)
			break;
	for (int i = count; i > temp; i--)
		ret[i + 1] = ret[i];
	ret[temp + 1].id = uID;
	ret[temp + 1].income = height;

	if (count != 10)
		count++;
}

int getTop10(int result[10])
{
	for (int i = 0; i < count; i++)
		result[i] = ret[i].id;

	return count;
}