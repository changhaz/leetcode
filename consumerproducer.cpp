#include <pthread.h>
#include <iostream>
#include <queue>

using namespace std;

void* consumer(void*);
void* producer(void*);

const int maxsize = 5;
queue<int> coke;
pthread_mutex_t lk = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cv = PTHREAD_COND_INITIALIZER; 

int main()
{
	pthread_t threadconsumer, threadproducer;
	
	int result1 = pthread_create(&threadconsumer, NULL, consumer, NULL);
	int result2 = pthread_create(&threadproducer, NULL, producer, NULL);

	pthread_join(threadconsumer, NULL);
	pthread_join(threadproducer, NULL);

	return 0;
}

void* consumer (void* in)
{
	while (true) {
		pthread_mutex_lock(&lk);
		if (coke.size()==0) {
			pthread_cond_wait(&cv,&lk);
		}

		cout<<"Consume coke "<<coke.front()<<". Remain: "<<coke.size()-1<<endl;
		if (coke.front() == 20) {
			pthread_exit(NULL);
		}
		coke.pop();
		pthread_mutex_unlock(&lk);
	}

	return NULL;
}

void* producer(void* in)
{
	int cokenum = 1;
	while (true) {
		pthread_mutex_lock(&lk);
		if (coke.size() != maxsize) {
			cout<<"Produce coke "<<cokenum<<". Remain: "<<coke.size()+1<<endl;
			coke.push(cokenum);
			cokenum++;
			pthread_cond_signal(&cv);

			if (cokenum == 21) {
				pthread_mutex_unlock(&lk);
				pthread_exit(NULL);
			}
		}
		pthread_mutex_unlock(&lk);
	}
	return NULL;
}
