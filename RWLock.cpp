#include<iostream>
#include<pthread.h>
using namespace std;

#define TNUM 20

int sum=0;
pthread_rwlock_t lock;

void* fun(void *arg){
	//writer
	if(int(arg)%5==0){
		pthread_rwlock_wrlock(&lock);
		sum=(int)arg;
		cout<<(int)arg<<" write "<<sum<<endl;	
		pthread_rwlock_unlock(&lock);
	}else{
		pthread_rwlock_rdlock(&lock);
		cout<<(int)arg<<" read "<<sum<<endl;
		pthread_rwlock_unlock(&lock);
	}
	return 0;
}

int main(){
	pthread_t threadID[TNUM];
	
	//init reader-writer lock
	pthread_rwlock_init(&lock,NULL);

	for(int i=0;i<TNUM;i++){
		int ret = pthread_create(&threadID[i],NULL,fun,(void*)i);
		if(ret != 0){
			cout<<"create thread error :"<<ret<<endl;
		}
	}

	for(int i=0;i<5;i++) pthread_join(threadID[i],NULL);

	//destroy reader-writer lock
	pthread_rwlock_destroy(&lock);
	pthread_exit(0);
	return 0;
}
