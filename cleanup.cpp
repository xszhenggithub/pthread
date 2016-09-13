#include<iostream>
#include<pthread.h>
using namespace std;

void output(void *arg){
	cout<<(int)arg<<endl;
}

void* fun(void *arg){
	cout<<"thread "<<(int)arg<<" start"<<endl;
	pthread_cleanup_push(output,(void*)1);
	pthread_cleanup_push(output,(void*)2);
	return 0;
	//pthread_exit(arg);
	pthread_cleanup_pop(0);
	pthread_cleanup_pop(0);
	return arg;
}

int main(){
	void *pret;
	pthread_t threadID[5];
	int ret = pthread_create(&threadID[0],NULL,fun,(void*)1);
	if(ret != 0){
			cout<<"create thread error :"<<ret<<endl;
	}
	pthread_exit(0);
	return 0;
}
