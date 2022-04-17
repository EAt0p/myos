int strlen(char str[]){
	int i=0;
	while(str[i]!=0){
		i++;
	}
	return i;
}
void strcpy(char a[], char b[]){
	int i=0;
	while(i<strlen(b)){
		a[i]=b[i];
		i++;
	}
}
void strrev(char str[]){
	int i=0, len=strlen(str), j=strlen(str)-1;
	char temp[len];
	strcpy(temp, str);
	while(i<len){
		str[i]=temp[j];
		i++;
		j--;
	}
}
