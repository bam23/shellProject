#ifndef _data_H
#define _data_H

#define LENGTH 255
#define HARDDRIVE 300
#define T_DIRECTORY 0
#define T_FILE 1

typedef struct node {

char fname[LENGTH];
int content;

struct node* child;
struct node* sibling;
struct node* back;
struct node* parent;

}node;

//points to current directory working in
node* position;

//pointer to the root directory
node* root;

void cinput(char *, char *, char *);
void input(char *, char *, char *); //works
void mkdir (char *,int); //works
void startup();// works
void pwd();//works
void cd(char *);
void ls();
void mv(char *, char *);
void rm(char *);

#endif
