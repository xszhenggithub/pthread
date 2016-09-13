#include<iostream>
#include<pthread.h>
using namespace std;

int sum=0;
pthread_mutex_t m;

void* fun(void *arg){
	pthread_mutex_lock(&m);
	cout<<pthread_self()<<' '<<(int)arg<<endl;
	sum+=(int)arg;
	pthread_mutex_unlock(&m);
	return 0;
}

int main(){
	pthread_t threadID[5];
	
	//init mutex
	pthread_mutex_init(&m,NULL);

	for(int i=0;i<5;i++){
		int ret = pthread_create(&threadID[i],NULL,fun,(void*)i);
		if(ret != 0){
			cout<<"create thread error :"<<ret<<endl;
		}
	}

	for(int i=0;i<5;i++) pthread_join(threadID[i],NULL);

	//destroy numtex
	pthread_mutex_destroy(&m);

	cout<<"the sum is :"<<sum<<endl;
	pthread_exit(0);
	return 0;
}
