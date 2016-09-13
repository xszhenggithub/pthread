#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void* fun(void *arg){
	cout<<pthread_self()<<endl;
	sleep(5);
	return arg;
}

int main(){
	void *pret;
	pthread_t threadID[5];
	for(int i=0;i<5;i++){
		int ret = pthread_create(&threadID[i],NULL,fun,(void*)i);
		if(ret != 0){
			cout<<"create thread error :"<<ret<<endl;
		}
		//pthread_cancel(threadID[i]);
		pthread_join(threadID[i],&pret);
		if(pret==PTHREAD_CANCELED) cout<<"thread "<<i<<" was canceled"<<endl;
		cout<<pret<<endl;
	}
	return 0;
}
