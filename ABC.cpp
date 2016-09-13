#include<iostream>
#include<pthread.h>
using namespace std;

int order = 0;
pthread_mutex_t m;

void* fun(void *arg){
	bool flag  = false;
	while (true) {
		pthread_mutex_lock(&m);
		if (order % 3 == (int)arg) {
			cout << char('A' + (int)arg);
			order ++ ;
			flag = order >= 3 * 9 + (int)arg;
		}
		pthread_mutex_unlock(&m);
		if (flag) break;
	}
	return 0;
}

int main(){
	pthread_t threadID[5];
	
	//init mutex
	pthread_mutex_init(&m,NULL);

	for(int i=0;i<3;i++){
		int ret = pthread_create(&threadID[i],NULL,fun,(void*)i);
		if(ret != 0){
			cout<<"create thread error :"<<ret<<endl;
		}
	}

	for(int i=0;i<3;i++) pthread_join(threadID[i],NULL);

	//destroy numtex
	pthread_mutex_destroy(&m);
	pthread_exit(0);
	return 0;
}
