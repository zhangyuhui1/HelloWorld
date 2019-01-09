#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{	
	if(argc < 1)
		return -1;
	char *name = argv[0];
	char fullName[20];
	strcpy(fullName,name);
	strcpy(fullName+strlen(name),".c");


	FILE *fp = fopen(fullName,"r+");
	if(!fp)
		return -1;
	char context[4097];
	char context2[4097];
	context2[4096] = '\0';
	context[4096] = '\0';

	while(fread(context,sizeof(char),4096,fp) != 0){
	}
	fclose(fp);
	int i,j,index;

	char include[10];
	strcpy(include,"#include<");
	index = 0;
	int nameIndex = 0;

	char fileName[40];
	char *prefix = "/usr/include/";
	strcpy(fileName,prefix);
	int fileLen = strlen(fileName);
	
	for(i = 0; i < 4097; i++){
		if(context[i] == '/' && context[i+1] == '/'){
			for(j = i; context[j] != '\n'; j++);
			i = j;
			continue;
		}
		if(include[index] != '\0'){
			if(context[i] != include[index]){
				index = 0;
			}
			else{
				index++;
			}
		}
		if(include[index] == '\0'){
			int tmp = fileLen;
			if(context[i+1] == ' '){
				printf("&");

				index = 0;
				continue;
			}
			while(1){

				i++;
				if(context[i] == '>'){
					index = 0;
					break;
				}
				if((context[i] >= 'a' && context[i] <= 'z') 							|| context[i] =='.')
					fileName[tmp++] = context[i];
			}
			fileName[tmp] = '\0';
			fp = fopen(fileName,"r+");
			if(!fp)
				return -1;
			while(fread(context2,sizeof(char),4096,fp) !=0){
				printf("%s\n",context2);
				printf("\n");
				printf("read fileName:%s\n",fileName);
			}
			fclose(fp);
		}
	}
	return 0;
}	

