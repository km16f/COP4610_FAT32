#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

struct INSTRUCTION{
	char** tokens;
	int numTokens;
};

#include"info.c"
#include"ls.c"
#include"cd.c"
#include"size.c"
#include"creat.c"
#include"mkdir.c"
#include"open.c"
#include"close.c"
#include"read.c"
#include"write.c"
#include"rm.c"
#include"rmdir.c"


void userINPUT(struct INSTRUCTION* instr);

void Shell(const char* file_name){
	struct INSTRUCTION instruction;
	while(1==1){
		instruction.tokens = NULL;
		instruction.numTokens = 0;
		
		printf("%s> ", file_name);

		userINPUT(&instruction);
		
		if(strcmp(instruction.tokens[0], "exit")==0){
			printf("EXITING\n");
			break;
		}

		else if(strcmp(instruction.tokens[0], "info")==0){
			INFO();
			continue;
		}
		else if(strcmp(instruction.tokens[0], "ls")==0){
			LS(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "cd")==0){
			CD(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "size")==0){
			SIZE(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "creat")==0){
			CREAT(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "mkdir")==0){
			MKDIR(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "open")==0){
			OPEN(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "close")==0){
			CLOSE(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "read")==0){
			READ(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "write")==0){
			WRITE(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "rm")==0){
			RM(&instruction);
			continue;
		}
		else if(strcmp(instruction.tokens[0], "rmdir")==0){
			RMDIR(&instruction);
			continue;
		}
		else{
			printf("INSTRUCTION (%s) FAILED!\n", instruction.tokens[0]);
		}
		printf("end of loop\n");
	}
}

void userINPUT(struct INSTRUCTION* instr){
	instr->tokens = (char**)malloc(5);
	instr->tokens[0] = (char*)malloc(100);
	instr->tokens[1] = (char*)malloc(100);
	instr->tokens[2] = (char*)malloc(100);
	instr->tokens[3] = (char*)malloc(100);
	instr->tokens[4] = (char*)malloc(100);

	char * cmd = (char*)malloc(500);

	scanf("%[^\n]%*c", cmd);

	int i = 0;

	char * temp = strtok(cmd, " ");
	instr->tokens[i] = (char*)malloc(sizeof(temp));
	strcpy(instr->tokens[i], temp);
	instr->numTokens++;
	while(temp!=NULL){
		i=i+1;
		temp = strtok(NULL, " ");
		if(temp != NULL){
			instr->tokens[i] = (char*)malloc(sizeof(temp));
			strcpy(instr->tokens[i], temp);
			instr->numTokens++;
		}
	}

	//for testing purposes
	/*for(i=0; i<instr->numTokens; i++){
		printf("tokens: %s\n", instr->tokens[i]);
	}
	printf("numTokens: %d\n", instr->numTokens);*/

}