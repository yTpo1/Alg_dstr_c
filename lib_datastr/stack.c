int buffer[100];
int index_buff = 0;

void push(int n){
    if(index_buff < 100)
        buffer[index_buff++] = n;
}

int pop(){
    if(index_buff>0)
        return buffer[index_buff--];
    return 0;
}
