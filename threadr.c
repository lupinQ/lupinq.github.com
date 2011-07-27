#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>

#define MAXSTACK 100
        int stack[MAXSTACK];
        int size=0,num=0;
  //      sem_t sem;
	char str[7]={0};
        
        void ReadData1(void){
        while(num<=10){
	sprintf(str,"%d.dat",num++);
        FILE *fp=fopen(str,"r");
        while(!feof(fp)){
        fscanf(fp,"%d %d",&stack[size],&stack[size+1]);
	printf("%d %d",stack[size],stack[size+1]);
      //  sem_post(&sem);
        size=size+2;
        }
        fclose(fp);
        }
	sleep(10);
	}
        
        void ReadData2(void){
        while(num<=10){
	sprintf(str,"%d.dat",num++);
        FILE *fp=fopen(str,"r");
        while(!feof(fp)){
        fscanf(fp,"%d %d",&stack[size],&stack[size+1]);
	printf("%d %d",stack[size],stack[size+1]);
      //  sem_post(&sem);
        size=size+2;
        }
        fclose(fp);
        }
	sleep(10);
	}

	void ReadData3(void){
	while(num<=10){
	sprintf(str,"%d.dat",num++);
        FILE *fp=fopen(str,"r");
        while(!feof(fp)){
        fscanf(fp,"%d %d",&stack[size],&stack[size+1]);
	printf("%d %d",stack[size],stack[size+1]);
      //  sem_post(&sem);
        size=size+2;
        }
        fclose(fp);
	sleep(10);
        }
	}

        int main(void){
        pthread_t t1,t2,t3;
     //   sem_init(&sem,0,0);
     //   pthread_create(&t1,NULL,(void *)HandleData1,NULL);
        pthread_create(&t1,NULL,(void *)ReadData1,NULL);
        pthread_create(&t2,NULL,(void *)ReadData2,NULL);
        pthread_create(&t3,NULL,(void *)ReadData3,NULL);
        
        pthread_join(t1,NULL);//只等t1会浪费空间
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);	
	return 0;
        }
