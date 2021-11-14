
void handleInterrupt21(int ax, int bx, int cx, int dx);
void printString(char* s);
void printChar(char c);
void readString(char*);
void readSector(char*,int);
void makeInterrupt21();
int main(){
	char buffer[512];
	char line [100];
	makeInterrupt21();
	interrupt(0x21,0,"Enter a line: ",0,0);
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
//	else if(ax==1)
//	readString(bx);
//	else if (ax==2)
//	readSector(bx,cx);
//	else
	//	printString("Unhandled interrupt 21");
}
void readSector(char* buffer, int sector){
interrupt (0x13,0,0,0,0);
	int sector[100];



}

//void makeInterrupt21(){

//}
