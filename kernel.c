void handleInterrupt21(int*);
void printString(char* s);
void printChar(char c);
void readString(char*);
void readSector(char*,int);
void makeInterrupt();
int main(){
//	char* chars;
//	char line[80];
//	char buffer[512];
	makeInterrupt21();
	interrupt(0x21,0,"Enter a line: ",0,0);
//	interrupt(0x21,1,line,0,0);
//	interrupt(0x21,2,buffer,30,0);
//	interrupt(0x21,0,buffer,0,0);
	while(1);	


}
void printChar(char c){


	interrupt(0x10,0x0e*0x100+c,0,0,0);
	
}

void printString(char* s)
{
	int i=0;
	while(s[i]!='\0')
		printChar(c(i++));
}
	void readString(char* line)
	{
	int i=0;
	while(1){
	line[i] = interrupt(0x16,0,0,0,0);
	printChar(line[i]);
	if(line[1] == '\r')
		{
	line[i+1]='n';
		}
	}
}
