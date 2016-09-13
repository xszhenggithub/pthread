#include<iostream>
#include<pthread.h>
using namespace std;

#define TNUM 20

int sum=0;
pthread_barrier_t b;

void* fun(void *arg){
	cout<<(int)arg<<" read "<<sum<<endl;
	pthread_barrier_wait(&b);	
	return 0;
}

int main(){
	pthread_t threadID[TNUM];
	
	//init barrier 
	pthread_barrier_init(&b,NULL,TNUM+1);

	for(int i=0;i<TNUM;i++){
		int ret = pthread_create(&threadID[i],NULL,fun,(void*)i);
		if(ret != 0){
			cout<<"create thread error :"<<ret<<endl;
		}
	}

	pthread_barrier_wait(&b);

	//destroy barrier 
	pthread_barrier_destroy(&b);
	pthread_exit(0);
	return 0;
}
