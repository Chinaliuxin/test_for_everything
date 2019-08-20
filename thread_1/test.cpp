#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <vector>
#include <queue>
using namespace std;

pthread_mutex_t lock;

pthread_cond_t condA;
pthread_cond_t condB;
pthread_cond_t condC;
int i = 1;

void* funA(void* args)
{
	while (1)
	{

		pthread_mutex_lock(&lock);
		while (i != 1)
		{

			pthread_cond_wait(&condA, &lock);//wait是做完事情之前等待，是用来等待某一条件

		}

		i = 2;
		printf("funA...A\n");
		pthread_cond_signal(&condB);//通知下一个线程 
		pthread_mutex_unlock(&lock);

	}
	return NULL;
}

void* funB(void* args)
{
	while (1)
	{

		pthread_mutex_lock(&lock);

		while (i != 2)
		{


			pthread_cond_wait(&condB, &lock);
			sleep(1);

		}
		i = 3;
		printf("funB...B\n");
		pthread_cond_signal(&condC);

		pthread_mutex_unlock(&lock);

	}
	return NULL;
}

void* funC(void* args)
{
	while (1)
	{
		pthread_mutex_lock(&lock);
		while (i != 3)
		{

			pthread_cond_wait(&condC, &lock);
			//sleep(1);

		}
		i = 1;
		printf("funC...C\n");
		pthread_cond_signal(&condA);

		pthread_mutex_unlock(&lock);

	}
	return NULL;
}



int main(int argc, const char* argv[])
{

	pthread_t thd1;
	pthread_t thd2;
	pthread_t thd3;

	pthread_mutex_init(&lock, NULL);



	pthread_cond_init(&condA, NULL);
	pthread_cond_init(&condB, NULL);
	pthread_cond_init(&condC, NULL);

	pthread_create(&thd1, NULL, funA, NULL);
	//sleep(1);
	pthread_create(&thd2, NULL, funB, NULL);

	pthread_create(&thd3, NULL, funC, NULL);


	pthread_join(thd1, NULL);

	pthread_join(thd2, NULL);

	pthread_join(thd3, NULL);

	pthread_mutex_destroy(&lock);


	pthread_cond_destroy(&condA);
	pthread_cond_destroy(&condB);
	pthread_cond_destroy(&condC);

	return 0;