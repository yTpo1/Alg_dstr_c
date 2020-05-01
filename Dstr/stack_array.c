static int buffer[100];
static int index_buff = 0;

//void sa_init(){}

// index:success, -1: failure
int sa_push(int n)
{
	if(index_buff < 100){
		buffer[index_buff] = n;
		return index_buff++;
	}
	return -1;
}

// v:success, 0: failure
int sa_pop()
{
	int v = 0;	
	if(index_buff > 0){
		v = buffer[--index_buff];
		return v;
	}
	return 0;
}
