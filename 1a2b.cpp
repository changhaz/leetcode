#include <iostream>
#include <pthread.h>

using namespace std;

int count = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_var = PTHREAD_COND_INITIALIZER;

void* threadfunc1(void* v);
void* threadfunc2(void* v);

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	
	int result1 = pthread_create(&thread1,NULL,threadfunc1,NULL);
	int result2 = pthread_create(&thread2,NULL,threadfunc2,NULL);
	
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}

// 123
void* threadfunc1(void* v)
{
	while (true) {
		pthread_mutex_lock(&mutex1);
		//cout<<"thread1 get lock"<<endl;

		if (count%2 == 1) {
			pthread_cond_wait(&condition_var,&mutex1);
		}

		cout<<" "<<count/2+1;
		count++;
		
		if (count>=5) {
			pthread_mutex_unlock(&mutex1);
			return NULL;
		}

		pthread_mutex_unlock(&mutex1);
	}
}

// abc
void* threadfunc2(void* v)
{
	while (true) {
		pthread_mutex_lock(&mutex1);
		//cout<<"thread2 get lock"<<endl;

		if (count%2 == 1) {
			cout<<" "<<char(count/2+'A');
			count++;
			pthread_cond_signal(&condition_var);
		}
		
		if (count>=6) {
			pthread_mutex_unlock(&mutex1);
			return NULL;
		}

		pthread_mutex_unlock(&mutex1);
	}
}
