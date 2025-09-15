#include "proxy_parse.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>  
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<netdb.h>
#define MAX_CLIENTS 10

type def struct cache_element cache_element;
struct cache_element{
    char* data;
    int len;
    char* url;
    time_t lru_time_track;
    cache_element *next;
};
cache_element * find(char*url);
int add_cache_element(char*data,int size,char*url);
void remove_cache_element();


int port_number= 8080;
int proxy_socketId;
pthread_t tid[MAX_CLIENTS];
sem_t semaphore;
pthread_mutex_t lock;

cache_element *head;
int cache_size;


void *thread_fn(void* arg){

}






int main(int argc,char*argv[]){
    int client_socketId,client_len;
    struct sockaddr server_addr,client_addr;
    sem_init(&semaphore,0,MAX_CLIENTS);

    pthread_mutex_init(&lock,NULL);
    if(argv==2){
        port_number=atoi(argv[1]);
    }
    else {
        printf("TOO FEW ARGUMENTS\N");
        exit(1);
    }

    printf("Starting Proxy Server at port: %d\n",port_number);
    proxy_socketId=socket(AF_INET,SOCK_STREAM,0);
    if(proxy_socketId<0){   
        perror("Socket Creation Failed\n");
        exit(1);
    }
    int reuse=1;
    if(setsockopt(proxy_socketId,SOL_SOCKET,SO_REUSEADDR,(const char*)&reuse,sizeof(reuse))<0){
        perror("Set Socket Options Failed\n");
    }


    bzero((char*)&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(port_number);
    server_addr.sin_addr.s_addr=INADDR_ANY;

    if(bind(proxy_socketId,(struct sockaddr*)&server_addr,sizeof(server_addr))<0){
        perror("port not available\n");
        exit(1);
    }
    printf("Binding Successful on port :\n",port_number);
    int listen_status=listen(proxy_socketId,MAX_CLIENTS);

    if(listen_status<0){
        perror("Listening Failed\n");
        exit(1);
    }
    int i=0;
    int connected_socketId[MAX_CLIENTS];

    while(1){
        bzero((char*)&client_addr,sizeof(client_addr));
        client_len=sizeof(client_addr);

        client_socketId=accept(proxy_socketId,(struct sockaddr*)&client_addr,&client_len);

        if(client_socketId<0){
            perror("Accepting Failed\n");
            exit(1);
        }
        else{
            connected_socketId[i]=client_socketId;
        }
        struct sockaddr_in *client_pt = (struct sockaddr_in *)&client_addr;
        struct in_addr ip_Addr =client_pt->sin_addr;
        char str[INET_ADDRSTRLEN];
        inet_ntop(AF_INET,&ip_Addr,str,INET6_ADDRSTRLEN);
        printf("Client is connected with port number %d and ip address is  %s\n",ntohs(client_addr.sin_port),str);

        
        pthread_create(&tid[i],NULL,&thrad_fn,(void*)&connected_socketId[i]);
        i++;
    }
    close(proxy_socketId);
    return 0;
}
