#include<iostream>
#include<pthread.h>
using namespace std;

void* fun(void *arg){
	cout<<pthread_self()<<endl;
	return 0;
}

int main(){
	pthread_t threadID[5];
	for(int i=0;i<5;i++){
		int ret = pthread_create(&threadID[i],NULL,fun,NULL);
		if(ret != 0){
			cout<<"create thread error :"<<ret<<endl;
		}
	}
	pthread_exit(0);
	return 0;
}
