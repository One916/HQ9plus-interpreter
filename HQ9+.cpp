#include<stdio.h>
#include<string>
int main(int argc,char** argv){
	if(argc==1) printf("Usage: HQ9+ prog.hq9+");
	else{
	for(int i=1;i<argc;i++){
	if(freopen(argv[i],"r",stdin)==NULL){
	printf("Error: input file\"%s\" not exist",argv[i]);return 1;}
	printf("Now exec file \"%s\"...\n\n\n",argv[i]);
	std::string prog="";size_t l=0;int c=0;char a;
	while((a=(prog[l++]=getchar()))!=EOF){
	prog[l]='\0';
	if(a=='H') printf("Hello world!\n");
	else if(a=='Q') printf("%s\n",prog.c_str());
	else if(a=='9'){
		printf("99 bottles of beer on the wall,\n\
99 bottles of beer.\n\
Take one down, pass it around,\n");
		for(int i=98;i>1;i--){
			printf("%d bottles of beer on the wall,\n\n\
%d bottles of beer on the wall,\n\
%d bottles of beer.\n\
Take one down, pass it around,\n",i,i,i);
		}
		printf("1 bottle of beer on the wall,\n\n\
1 bottle of beer on the wall,\n\
1 bottle of beer.\n\
Take one down, pass it around,\n\
No bottles of beer on the wall.\n");
	}
	else if(a=='+') c++;
	else if(a==' '||a=='\t'||a=='\v'||a=='\b'||a=='\n') continue;
	else if(a=='/'){
		size_t st=l;
		a=(prog[l++]=getchar());prog[l]='\0';if(a==EOF) return 1;
		if(a=='*'){
			bool _b=1;
			do{
				a=(prog[l++]=getchar());prog[l]='\0';if(a==EOF){
					printf("Error:unterminated comment(char %Zu)\n",st);
					return 1;
				}
				if(a=='*'){
					a=(prog[l++]=getchar());prog[l]='\0';if(a==EOF){
						printf("Error:unterminated comment(char %Zu)\n",st);
						return 1;
					}
					if(a=='/') _b=0;
				}
			}while(_b);
		}
		else {
			printf("Error: unexpected expression token %c(char %Zu)\n",prog[l-2],l-2);
			printf("Error: unexpected expression token %c(char %Zu)\n",a,l-1);
		}
	}
	else printf("Error: unexpected expression token %c(char %Zu)\n",a,l-1);
}
}
}
return 0;
}
