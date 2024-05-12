//### Luu d? li?u Stack vào file:
	
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20

typedef struct node {
    long maso;
    char hoten[40];
    char diachi[100];
} node;

typedef struct stack {
    int top;
    node list[N];
} stack;

void khoitao(stack &s) {
    s.top=-1;
}

int empty(stack s) {
    return s.top==-1?1:0;
}

int full(stack s) {
    return s.top==N-1?1:0;
}

void push(stack &s, node x) {
    if(!full(s))
        s.list[++s.top]=x;
}

node pop(stack &s) {
    node x;
    if(!empty(s))
        x=s.list[s.top--];
    return x;
}

int main() {
    int n;
    stack s;
    node x;
    printf("\n nhap vao so phan tu:");
    scanf("%d",&n);
    khoitao(s);
    FILE *fptr;
    fptr = fopen("stack_data.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for(int i=0;i<n;i++) {
        printf("\n nhap ma so:");
        scanf("%d",&x.maso);
        printf("\n nhap ho ten:");
        fflush(stdin);
        gets(x.hoten);
        printf("\n nhap dia chi :");
        fflush(stdin);
        gets(x.diachi);
        push(s,x);
        fprintf(fptr, "%ld %s %s\n", x.maso, x.hoten, x.diachi);
    }
    fclose(fptr);

    fptr = fopen("stack_data.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while (!empty(s)) {
        x = pop(s);
        printf("\nMa so:%d Ho ten:%s Dia chi:%s", x.maso, x.hoten, x.diachi);
    }
    fclose(fptr);
    return 0;
}

/* Luu d? li?u Queue vào file:

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 20

typedef struct node {
    char hoten[40];
    int tuoi;
} node;

typedef struct queue {
    int front,rear;
    node list[N];
} queue;

void khoitao(queue &q) {
    q.front=q.rear=-1;
}

int empty(queue q) {
    if((q.front==-1)&&(q.rear==-1))
        return 1;
    else
        return 0;
}

int full(queue q) {
    if(q.front==0&&q.rear==N-1)
        return 1;
    if(q.front==q.rear+1)
        return 1;
    else
        return 0;
}

void enqueu(queue &q,node x) {
    if(!full(q)) {
        if(empty(q))
            q.front=q.rear=0;
        else if(q.rear==N-1)
            q.rear=0;
        else
            q.rear=q.rear+1;
        q.list[q.rear]=x;
    }
}

node dequeu(queue &q) {
    if(!empty(q)) {
        node t=q.list[q.front];
        if(q.front==q.rear)
            khoitao(q);
        else if(q.front==N-1)
            q.front=0;
        else
            q.front=q.front+1;
        return t;
    }
}

int main() {
    int n;
    node x;
    queue q;
    printf("nhap so phan tu:");
    scanf("%d",&n);
    khoitao(q);
    FILE *fptr;
    fptr = fopen("queue_data.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    for(int i=1;i<=n;i++) {
        printf("nhap ho ten:");
        fflush(stdin);
        gets(x.hoten);
        printf("nhap tuoi:");
        scanf("%d",&x.tuoi);
        enqueu(q,x);
        fprintf(fptr, "%s %d\n", x.hoten, x.tuoi);
    }
    fclose(fptr);

    fptr = fopen("queue_data.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    while(!empty(q)) {
        x=dequeu(q);
        printf("\n hoten:%s",x.hoten);
        printf("\n tuoi:%d",x.tuoi);
    }
    fclose(fptr);
    return 0;
}*/
