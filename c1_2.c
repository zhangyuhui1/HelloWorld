#include<stdio.h>
#include<string.h>

char puzzle[4][4] = {		//puzzle set
	{'t','h','i','s'},
	{'w','a','t','s'},
	{'o','a','h','g'},
	{'f','g','g','t'}
};

char *dictionary[4] = {"this","two","fat","that"}; //dictionary

int WordExist(int x,int y,int dir,int len,char *word);

int main()
{
	int x,y,len;
	int dir;
	char word[5];
	/*
	 * x is abscissa, y is ordinate.
	 * 'dir' is dirction,there are eight dirction.
	 * 'len' is the length of the string.
	*/	
	for(x = 1; x <= 4; x++){
		for(y = 1; y <= 4; y++){
			for(dir = 1; dir <= 8; dir++){
				for(len = 2; len <= 4; len++){
					if(WordExist(x,y,dir,len,word)==1){
						printf("%s\n",word);
					}
				}
			}
		}
	}
}					



int WordExist(int x,int y,int dir,int len,char *word){
	char temp[4];
	int i;
	for(i = 0; i <= len-1; i++){
		if(x <= 4 && x >= 1 && y <= 4 && y >= 1){
			temp[i] = puzzle[x-1][y-1];
			temp[i+1] = '\0';
			switch(dir){
				case 1:		//form left to right
					x++; 
					break;
				case 2:		//form top left to bottom right
					x++; 
					y++;
					break;
				case 3:		//form top to bottom
					y++;
					break;
				case 4:		//form top right to bottom left
					x--;
					y++;
					break;
				case 5:		//form right to left
					x--;	
					break;
				case 6:		//form bottom right to top left
					x--;
					y--;
					break;
				case 7:		//form bottom to top
					y--;
					break;
				case 8:		//form bottom left to top right
					x++;
					y--;
					break;
				default:
					printf("dirction error\n");
					return 0;
			}
		}
	}
	for(i = 0; i <= 3; i++){
		if(strcmp(temp,dictionary[i])==0){
			strcpy(word,dictionary[i]);
			return 1;
		}
	}
	return 0;
}
