void memcpy(char *a, char *b, int nbytes){
	int i=0;
	while(i<nbytes){
		*(a+i)=*(b+i);
		i++;
	}
}
