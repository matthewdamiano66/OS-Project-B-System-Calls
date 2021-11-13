void handleInterrupt21(int ax, int bx, int cx, int dx);
void printString(char* s);
void printChar(char c);
void readString(char*);
void readSector(char*,int);
void makeInterrupt21();
int main(){
	char line [100 ];
	makeInterrupt21();
	interrupt(0x21,0,"Enter a line: ",0,0);
//	printString("Enter a line:");
	readString(line);
	printString(line);
	while(1);

}
void printChar(char c){
	interrupt(0x10,0x0e*0x100+c,0,0,0);
}

void printString(char* s)
{
	int i=0;
	while(s[i]!='\0')
		printChar(s[i++]);
}



	void readString(char* line)
	{
	int i=0;
	while(1){
	line[i] = interrupt(0x16,0,0,0,0);
	printChar(line[i]);
	if(line[i] == '\r')
		{
	line[i+1]='\n';
		printChar('\n');
		line[i+2]='\0';
		return;	
		}
	i++;
	}


}
void handleInterrupt21(int ax,int bx,int cx,int dx){
	if (ax ==0)
		printString(bx);

}
