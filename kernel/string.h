int strlen(char str[]){			//"hello\0"=5
	int i=0;
	while(str[i]!=0){
		i++;
	}
	return i;
}
void strcpy(char a[], char b[]){		//copy b to a
	int i=0;
	while(b[i]!=0){
		a[i]=b[i];
		i++;
	}
	a[i]=0;
}
void strrev(char str[]){			//hello\0 = olleh\0
	int len=strlen(str), i=0, a=strlen(str)-1;
	char temp[len];
	strcpy(temp, str);
	while(i<len){
		temp[i]=str[a];
		a--;
		i++;
	}
	strcpy(str, temp);
}
