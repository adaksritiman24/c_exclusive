#include<stdio.h>
//A Queue data structure required for performing the bfs of the graph
struct Q{

	int front;
	int rear;
};

void enqueue(int data , int q[100] , struct Q *mask)
{
	if(mask->front == -1)/* the queue is empty*/
	{
		q[0] = data;
		mask->front = 0;
		mask->rear =0;
	}
	else{
		q[mask->rear + 1] = data;
		mask->rear++;
	}
}

int dequeue(int q[100] , struct Q *mask)
{
	if(mask->front==-1)
		return 9999;
	else{
		int data = q[mask->front];
		for(int i=0;i<mask->rear;i++)
		{
			q[i] = q[i+1];
		}
		mask->rear = mask->rear-1;
		if(mask->rear==-1)
			mask->front = -1;
		return data;
	}		
}
//Algorithm to find the max network flow in the graph
int fordfulkerson(int adj[100][100], int source, int sink, int n)
{	
	//parent array contains the parent node of the current visited node.
	//initial max flow = 0
	int visited[sink+1], parent[sink+1], flow = 0,p;
	int temp[sink + 1][sink + 1];
	int i,j;
	//Creating the temporary array for storing the adjacency matrix.
	for(i=0;i<sink+1;i++)
	{
		for(j=0;j<sink+1;j++)
			temp[i][j] =adj[i][j];
	}
	/*		
	for(i=0;i<sink+1;i++)
	{
		for(j=0;j<sink+1;j++)
			printf("%d ",temp[i][j]);
		printf("\n");
	}
	*/
	for(i=0;i<=sink;i++)
	{
		visited[i]= 0;
		parent[i] = 0;
	}
	// mask contains the front, rear values of the queue-->(q).	
	struct Q mask;
	mask.front = -1;
	mask.rear = -1;
	int q[100], current=0;
	while(1)
	{
		visited[source] = 1;
		parent[source] = -1;
		enqueue(source, q, &mask);
		current = dequeue(q, &mask);
		while(1)
		{
			
			for(i=0;i<=sink;i++)
			{
				if(visited[i]==0 && temp[current][i]==1)
				{
					enqueue(i, q, &mask);
					visited[i]=1;
					parent[i] = current;
				}
					
			}
			current = dequeue(q, &mask);
			if(current==9999 || current== sink)
				break;	
			
		}
		// If a possible path has been found between source and the sink, then the residual graph is created with backward moving edges , and flow is incremented, which at the end of the algorithm will sum up to max flow. 
		if(current==sink)
		{
			p = parent[current];
			temp[p][current]=0;
			temp[current][p] = 1;
		
			while(p>=0){
				temp[parent[p]][p]=0;
				temp[p][parent[p]]=1;
				p = parent[p];
			}
			flow++;
			for(i=0;i<=sink;i++)
			{
				visited[i]= 0;
				parent[i] = 0;
			}		
				
		}
		//If no further path from source to sink exist, we break out from the loop.
		if(current==9999)
			break;		
	}	
	printf("Max Network Flow = %d\n", flow);
	//If the max flow is equal to the number of women/men in the party then arrangemen of dance is possible, else not possible
	if(flow==n)
		printf("It is possible to arrange a dance where every woman dances with a man, she dosen't know.\n");
	else
		printf("It is not possible to arrange a dance where every woman dances with a man, she dosen't know. \n");	
}


int main()
{
	int n, k;
	int i, j;
	printf("Enter the number of men and wemen in the ivy party(n): ");
	scanf("%d",&n);
	printf("Enter the number of men each woman knows/the number of women each man knows(k): ");
	scanf("%d", &k);
	int w[n][k];
	for(i=0;i<n;i++)
	{	
		printf("Enter the %d men which woman %d knows (man should be between 1 to %d):", k,i+1,n);
		for(j=0;j<k;j++)
		{
			scanf("%d", &w[i][j]);
		}
			
	}
	//Creating The adjacency matrix of a bipartite graph out of the given information.
	//int the adjacency matrix, women nodes=> 1 to n , men nodes=> n+1 to 2*n
	int adj[100][100];
	for(i=0;i<=2*n + 1;i++)
	{
		for(j=0;j<=2*n + 1;j++)
			adj[i][j] =0;
	}
	// Connecting source to all the wemen in the graph. source=>0
	
	for(i=1;i<=n;i++)
		adj[0][i] = 1;
	//Connecting all men to the sink in the graph.	sink =>2n + 1
	
	for(i=n+1; i<= 2*n; i++)
		adj[i][2*n + 1] = 1;	
		
	int source = 0, sink = 2*n + 1;	
	for(i=1;i<=n;i++)
	{
		//Initially let all wemen knows all men, so in the graph all wemen are connected to all men.
		for(j=n+1;j<=2*n;j++)
			adj[i][j] = 1;
	}		
		//If woman knows men, adjacency will be set to '0' , as we want to connect only those wemen to men who dont know one another.
	for(i=1;i<=n;i++)
	{	
		for(j=0;j<k;j++)
			adj[i][n +w[i-1][j]]= 0;	
	}
	/*
	for(i=0;i<=2*n + 1;i++)
	{
		for(j=0;j<=2*n + 1;j++)
			printf("%d ", adj[i][j]);
		printf("\n");	
	}
	*/
	fordfulkerson(adj, source, sink, n);	
	
	return 0;

}
