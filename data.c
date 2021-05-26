#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "data.h"

void cinput(char *command, char *variable1, char *variable2)
{

		printf("The command is %s\n", command);
		printf("Variable 1 is %s\n", variable1);
		printf("Variable 2 is %s\n", variable2);
	
}

void input(char *command, char *variable1, char *variable2)
{

	do
	{
		printf("$");
		scanf("%s", command);
			if (strcmp (command ,"bye") != 0)
				{
					if (strcmp (command ,"pwd") == 0)
					{
							pwd();
					}

					else if (strcmp (command ,"mkdir") == 0)
					{
							scanf("%s", variable1);
							mkdir(variable1,0);
					}
					else if (strcmp (command, "cd") == 0)
					{
							scanf("%s", variable1);
							cd(variable1);
					}
					else if (strcmp (command, "ls") == 0)
					{
							ls();
					}

					else if (strcmp (command, "addf") == 0)
					{
							scanf("%s",variable1);
							mkdir(variable1, 1);
					}

					else if (strcmp (command, "mv") == 0)
					{
							scanf("%s",variable1);
							scanf("%s",variable2);
							mv(variable1,variable2);
					}

					else if (strcmp (command, "rm") == 0)
					{
							scanf("%s", variable1);
							rm(variable1);
					}
					else 
					{
						printf("Command not recognized\n Please try again\n");
					}
					
				}
		
	}while (strcmp (command ,"bye") != 0);
	//name of terminating string

	printf("You have now exited the program\n");
}

void startup()
{
	root = (struct node*) malloc(sizeof(struct node));
	position = root;

	printf("System ready\n");

	strcpy(root->fname,"root");
	root->content=0;
	root->child=NULL;
	root->sibling=NULL;
	root->back=NULL;	
	root->parent=NULL;

	printf("%s has been created\n", root->fname);

}

void pwd()
{
	int i=0;
	int j;
	node* traverse=position;
	char *array[HARDDRIVE];

	printf("ben/root/");
	
	while (strcmp (traverse->fname , root->fname) != 0)
		{
			array[i]=traverse->fname;
			traverse=traverse->parent;
			i++;
		}
	
		i--;
		
	for(j=i; i>=0; i--)
		{
		
			printf("%s/", array[i]);
		}
		
		printf("\n");	
}


void mkdir (char *name, int type)
{

node *traverse=position;
int end = 0;


	if(traverse->child==NULL)
	{
		node *newnode;
		newnode = (struct node*)malloc (sizeof(struct node));
		traverse->child=newnode;
		printf("Created\n");

		strcpy(newnode->fname,name);
		newnode->content=type;
		newnode->child=NULL;
		newnode->back=NULL;
		newnode->sibling=NULL;
		newnode->parent=position;
		//printf("New node parent %s\n", newnode->parent->fname);
		//printf("Position is %s\n", position->fname);
		return;
	}

	else
	{	traverse=traverse->child;
		while(end!=1)
		{
			if ( (strcmp (name , traverse->fname) == 0) && traverse->content==type)
			{
				printf("Already exist\n");
				return;

			}

			if(traverse->sibling!=NULL)
			{
				traverse=traverse->sibling;
			}
			else 
			end=1;
		}

		//fprintf(stderr, "Fail 1\n");
		node *newnode;
		newnode = (struct node*)malloc (sizeof(struct node));

		traverse->sibling=newnode;

		printf("Created\n");

		//fprintf(stderr, "Fail 2\n");
			
		strcpy(newnode->fname,name);
		newnode->content=type;
		newnode->child=NULL;
		newnode->back=traverse;
		newnode->sibling=NULL;
		newnode->parent=position;
		//printf("New node parent %s\n", newnode->parent->fname);
		//printf("Position is %s\n", position->fname);

	}
}




void cd (char *directory)
{
	node *traverse = position->child;

	if (strcmp (directory , "..") == 0)
	{
		if(position==root)
		{
			printf("At root directory\n");
			return;
		}
		
		position=position->parent;
		return;
	}
	
	else
	{
		
		while (traverse!=NULL)
		{
			if (strcmp (traverse->fname, directory) == 0)
			{
				//printf("Current directory %s\n", position->fname);
				if(traverse->content==T_FILE)
				{
					printf("Directory doesnt exist\n");
					return;
				}
				
				position=traverse;
				return;
			}

			traverse=traverse->sibling;
		}

		printf("Directory doesnt exist\n");
	}
}



void ls()
{
	node *traverse = position->child;

	//printf("name is %s\n", traverse->fname);

	printf("NAME\t\tTYPE\n");
	while(traverse!=NULL)
	{
		if(traverse->fname!=NULL)
			{
				printf("%s\t\t%s\n", traverse->fname, (traverse->content==0) ? "Directory" : "File");
			}
			traverse=traverse->sibling;
	
	}
	
}

void mv(char *name, char *rename)
{
	node *traverse;
	traverse=position->child;

	while(traverse!=NULL)
	{
		if (strcmp (traverse->fname, name) == 0)
		{
			strcpy(traverse->fname,rename);
			printf("Name changed to %s\n", traverse->fname);
			return;
		}

		traverse=traverse->sibling;

	}

	printf("File or directory doesnt exist\n");


}

void rm(char *name)
{

	node *traverse, *temp, *temp2;
	traverse=position->child;
	

	while(traverse!=NULL)
	{
		if (strcmp (traverse->fname, name) == 0)
		{
				if(traverse->content==T_FILE && traverse->content==T_FILE)
				{
					if (traverse->back!=NULL)
					{
						temp=traverse->sibling;
						if(traverse->sibling!=NULL)
						{
							temp2=traverse->sibling->back;
						}

						traverse->back->sibling=temp;
						temp2=traverse->back;
						free(traverse);
						return;

					}
					else
						{
							temp=traverse->parent->child;
							temp=traverse->sibling;
							free(traverse);
							return;
						}
				}
				
				
				printf("%s is a directory\n", traverse->fname);
				return;
		}

		traverse=traverse->sibling;

	}

	printf("File or directory doesnt exist\n");


}

