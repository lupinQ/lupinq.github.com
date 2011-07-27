#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>
#if 0 
        #define MAXSTACK 100
        int stack[MAXSTACK][2];
        int size=0;
        //sem_t sem;
	unsigned count=0;
	pthread_mutex_t count_lock;
        pthread_cond_t count_nonzero;
        
        void ReadData1(void){
        FILE *fp=fopen("1.dat","r");
        while(!feof(fp)){
//	sem_wait(&sem-2);        
	fscanf(fp,"%d %d",&stack[size][0],&stack[size][1]);
     // sem_post(&sem);
	
        ++size;
        }
        fclose(fp);
        }
        
        void ReadData2(void){
        FILE *fp=fopen("2.dat","r");
        while(!feof(fp)){
//	sem_wait(&sem+2);           

	pthread_mutex_lock (&count_lock);
        while(count==2) 
        pthread_cond_wait( &count_nonzero, &count_lock);
        fscanf(fp,"%d %d",&stack[size][0],&stack[size][1]);
	count = count+1;
        pthread_mutex_unlock (&count_lock);

	
        sem_post(&sem);
        ++size;
        }
        fclose(fp);
        }
        
        void HandleData1(void){
        while(1){
	pthread_mutex_lock(&count_lock);
        if(count==2)
        pthread_cond_signal(&count_nonzero);
        count=count+1;
        pthread_mutex_unlock(&count_lock);
        printf("Plus:%d+%d=%d\n",stack[size][0],stack[size][1],
        stack[size][0]+stack[size][1]);
        --size;
        }
        }
      

        int main(void){
        pthread_t t1,t2,t3;
        sem_init(&sem,0,0);
        pthread_create(&t1,NULL,(void *)HandleData1,NULL);
        pthread_create(&t2,NULL,(void *)ReadData1,NULL);
        pthread_create(&t3,NULL,(void *)ReadData2,NULL);
        
        pthread_join(t1,NULL);//只等t1会浪费空间
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
        }

#else 
#define MAXSTACK 100
        int stack[MAXSTACK][2];
        int size=0;
        sem_t sem;
	sem_t sem1;
        
        void ReadData1(void){
        FILE *fp=fopen("1.dat","r");        
	while(!feof(fp)){
	sem1 = sem1;        
	sem_wait(&sem1);
	fscanf(fp,"%d %d",&stack[size][0],&stack[size][1]);
        sem_post(&sem);
        ++size;
        }
        fclose(fp);
        }
        
        void ReadData2(void){
        FILE *fp=fopen("2.dat","r");
        while(!feof(fp)){
        fscanf(fp,"%d %d",&stack[size][0],&stack[size][1]);
        sem_post(&sem);
        ++size;
        }
        fclose(fp);
        }
        
        void HandleData1(void){
        while(1){
        sem_wait(&sem);
        printf("Plus:%d+%d=%d\n",stack[size-1][0],stack[size-1][1],
        stack[size][0]+stack[size][1]);
        --size;
        }
        }
      
        int main(void){
        pthread_t t1,t2,t3,t4;
        sem_init(&sem,0,0);
        pthread_create(&t1,NULL,(void *)HandleData1,NULL);
        pthread_create(&t2,NULL,(void *)ReadData1,NULL);
        pthread_create(&t3,NULL,(void *)ReadData2,NULL);
        
        pthread_join(t1,NULL);//只等t1会浪费空间
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
        }


#endif
