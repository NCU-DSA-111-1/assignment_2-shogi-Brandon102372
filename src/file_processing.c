#include "../inc/file_processing.h"
void write_file(stack* st,const char *name){
	char file_name[30];
	int i;
	for(i=0;i<strlen(name);i++){
		file_name[i]=name[i];
	}
	file_name[strlen(name)]='\0';
	strcat(file_name,".bin");
	
	
	FILE *fptr;
	if ((fptr = fopen(file_name,"w")) == NULL){
		printf("Error! opening file\n");
   	}else{
   		printf("Saving file.......\r");	
		step data;
		stack *cur=st;
		while(cur!=NULL){
			fwrite(&(cur->value), sizeof(step), 1, fptr);
			cur=cur->next;
		}
		printf("Sucessfully save the file!\n");
	}
	fclose(fptr);
}

void read_file(stack** st,const char *name){
	FILE *fptr;
	char file_name[30];
	int i;
	for(i=0;i<strlen(name);i++){
		file_name[i]=name[i];
	}
	file_name[strlen(name)]='\0';
	strcat(file_name,".bin");
	
	if ((fptr = fopen(file_name,"r")) == NULL){
		printf("File not found !\n");
	}else{
		printf("Loading...\r");
		step read;
		stack *tmp=NULL;
		while(!feof(fptr)){
			fread(&read, sizeof(step), 1, fptr);
			push(st,read);
		}
		pop(st);
		printf("Sucessfully load the file!\n");
	}
	fclose(fptr);
}
