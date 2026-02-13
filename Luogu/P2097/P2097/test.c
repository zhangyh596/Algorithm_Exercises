#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>


struct Node
{
	int x;
	struct Node* next;
};

struct Node* head[100005];

void add(int u, int v)
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));
	p->x = v;
	p->next = head[u];
	head[u] = p;
}

int n, m;
int vis[100005];

void dfs(int u)
{
	vis[u] = 1;
	struct Node* p = head[u];
	while (p != NULL)
	{
		int v = p->x;
		if (vis[v] == 0)
		{
			dfs(v);
		}
		p = p->next;
	}
}

int main()
{
	int ans = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int p, q;
		scanf("%d %d", &p, &q);
		add(p, q);
		add(q, p);
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			ans++;
			dfs(i);
		}
	}
	printf("%d", ans);
	return 0;
}