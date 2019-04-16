#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct {
	char* todo;
} element;

typedef struct {
	int size;
	element* arr;
} tList;

//DECLARE FUNCTIONS
void get_todos(tList* list);
void listInit(tList* list);
void add_todo(tList* list, char* todo);
void delete_todo(tList* list, int option);
void print_todos(tList list);
void update_todos(tList list);

//FUNCTION IMPLEMENTATION
void listInit(tList* list){
list->size = 0;
list->arr = NULL;
}

void get_todos(tList* list){
FILE* fp;
char buff[500];

//Get todos
fp = fopen("todoList.txt", "r");
if(fp == NULL){
	fp = fopen("todoList.txt", "w");
} else {
	while(!feof(fp)){
		if(fgets(buff,500,fp) == NULL) break;
		add_todo(list, buff);
	}
fclose(fp);
}
}
void add_todo(tList* list, char* todo){
//Allocate memory
if(list->size == 0){
	list->size = 1;
	list->arr = (element*) malloc(sizeof(element));
} else {
	list->size = list->size + 1;
	list->arr = (element*) realloc(list->arr, list->size * sizeof(element));
}
list->arr[list->size - 1].todo = (char*) malloc((strlen(todo)+1)*sizeof(char));
//Add todo
strcpy(list->arr[list->size - 1].todo, todo);
}

void delete_todo(tList* list, int option){
int i;
bool found = false;

//Remove todo
for(i = 0; i < list->size; i++){
	if(found){
		strcpy(list->arr[i-1].todo,list->arr[i].todo);
	}else if(i == option - 1) {
		found = true;
	}
}
//Allocate memory
if(found){
	//Modify num of elements
	list->size = list->size - 1;
	//Check if it is the last element
	if(list->size == 0){
		list->arr = NULL;
	} else {
	//Modify the used memory
	list->arr = (element*) realloc(list->arr, list->size * sizeof(element));
	}
}else {
	printf("--> Sorry, There is no todo stored with this number. Please try again!\n\n");
}
} 

void print_todos(tList list){
//Print todos
for(int i = 0; i < list.size; i++){
	printf("\t%d. %s\n",i+1,list.arr[i].todo);
}
}

void update_todos(tList list){
FILE* fp;

//OPen file
fp = fopen("todoList.txt","w");

//CHeck if file is correctly created
if(fp == NULL){
	printf("Error opening file!\n");
	exit(1);
}
//Update todos on file.txt
for(int i = 0; i < list.size; i++){
	fprintf(fp,"%s",list.arr[i].todo);
}
//check if file is empty
fseek(fp, 0, SEEK_END);
unsigned int len = (unsigned int)ftell(fp);
if(len == 0){
	printf("\n\t---- No Todos at this moment ----\n");
}

//Close file
fclose(fp);
}

//MAIN FUNCTION
int main(int argc, char* argv[]) {
tList list;
char todo[500];
int choice;
int option;

//Initialize list
listInit(&list);
//Get todos
get_todos(&list);

while(choice != 3){
//Clear previous commands
system("clear");
 
//Print Title
printf("\n\t--------------");
printf("\t|  TODO APP  |");
printf("\t--------------\n\n");
switch(choice){
         case 1: //ADD
                 while(getchar() != '\n');
                 //Get Todo 
                 printf("\nEnter todo (500 char Max): ");
                 fgets(todo,500,stdin);
                 add_todo(&list,todo);   
                 break;
         case 2: //DELETE
		 printf("\n Enter the number of todo you want to delete:");
		 scanf("%d", &option);
                 delete_todo(&list,option);
		 break;
         case 3: //EXIT
                 break;
}
//Print & update
update_todos(list);
print_todos(list);
//Menu
printf("\nOPTIONS |  Add(1)  |  Delete(2)  |  Exit(3)  | \n");
printf("press number for desired option: "); 
//Get user input
scanf("%d", &choice);
}

return 0;
}
