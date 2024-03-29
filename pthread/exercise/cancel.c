#include <stdio.h>
#include <string.h>
#include <pthread.h>

pthread_t threads[5];
int done[5];

void *thread_main(void *);

int main(void)
{
	int i;
	int rc;
	int status;
	int tid;	

	printf("pid=%d\n", getpid());

	for (i = 0; i < 5; i++)
	{	
		done[i] = 0;
		tid = pthread_create(&threads[i], NULL, &thread_main, (void *)i);
		if(tid<0)
		{
			perror("thread create error: ");
			exit(0);
		}
		printf("thread is created i: %d, thraed[i]:%d\n", i, threads[i]);
		
		usleep(100);
	}

	
	for (i = 4; i >= 0; i--)
	{
		usleep(100);
		rc = pthread_cancel(threads[i]); // 강제종료
		if (rc == 0)
		{
			// 자동종료
			rc = pthread_join(threads[i], (void **)&status);
			if (rc == 0)
			{
				printf("Completed join with thread %d status= %d\n",i, status);
			}
			else
			{
				printf("ERROR; return code from pthread_join() is %d, thread %d\n", rc, i);
         			return -1;
			}
		}
	}

	return 0;
}

void *thread_main(void *arg)
{
	int i;
	double result=0.0;

	printf("therad: %d, %d\n", (int)arg, getpid());

	while (!done[(int)arg])
	{
	  for (i=0; i < 1000000; i++)
  	  {
  		result = result + (double)random();
	  }
  	  printf("thread: %d, result = %e\n", (int)arg, result);
	}

	pthread_exit((void *) 0);
}
