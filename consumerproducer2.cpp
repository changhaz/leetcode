#include <pthread.h>
#include <iostream>
#include <queue>

using namespace std;

struct coke
{
	queue<int> q;
	pthread_mutex_t lk;
	pthread_cond_t consumerwait;
	pthread_cond_t producerwait;
	
/*
	coke() {
		lk = PTHREAD_MUTEX_INITIALIZER;
		consumerwait = PTHREAD_COND_INITIALIZER;
		producerwait = PTHREAD_COND_INITIALIZER;
	}
*/
};

coke c;
const int queuesize = 10;

void* producer(void*);
void* consumer(void*);

int main()
{
	pthread_mutex_init(&(c.lk), NULL);
	pthread_cond_init(&(c.consumerwait), NULL);
	pthread_cond_init(&(c.producerwait), NULL);
	pthread_t threadproducer, threadconsumer;
	int return1 = pthread_create(&threadproducer, NULL, producer, NULL);
	int return2 = pthread_create(&threadconsumer, NULL, consumer, NULL);

	pthread_join(threadproducer, NULL);
	pthread_join(threadconsumer, NULL);
	
	return 0;
}

void* producer(void* v)
{
	for (int i=0;i<50;i++) {
		pthread_mutex_lock(&(c.lk));
		if (c.q.size() >= queuesize) {
			pthread_cond_wait(&(c.producerwait),&(c.lk));
		}
		cout<<"produce "<<i+1<<endl;
		c.q.push(i+1);
		pthread_cond_signal(&(c.consumerwait));
		pthread_mutex_unlock(&(c.lk));
	}
}

void* consumer(void* v)
{
	for (int i=0;i<50;i++) {
		pthread_mutex_lock(&(c.lk));
		if (c.q.size() == 0) {
			pthread_cond_wait(&(c.consumerwait),&(c.lk));
		}
		cout<<"consume "<<c.q.front()<<endl;
		c.q.pop();
		pthread_cond_signal(&(c.producerwait));
		pthread_mutex_unlock(&(c.lk));
	}
}
