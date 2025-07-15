#include<proxy_parse.h>
#include<stdio.h>
#include<string.h>
#include<time.h>

type def struct cache_element cache_element;
struct cache_element{
    char* data;
    int length
    char* url;
    time_t lru_time_track;
    cache_element *next;
};
cache_element * find(char*url);
int add_cache_element(char*data,int size,char*url);
void remove_cache_element();

int port= 8080;
int proxy_socket_id;