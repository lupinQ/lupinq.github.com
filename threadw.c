#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <semaphore.h>
#include <unistd.h>
#include <signal.h>

pthread_t thread[3];//保存线程标号信息的类型
pthread_mutex_t mut;//互斥变量
int number=0, i;
char buf[1024]={0},str[7]={0};
sem_t sem;

void *thread1()
{
        printf ("thread1 : I'm thread 1\n");
	while(1)
        {       		
		pthread_mutex_lock(&mut); //互斥，上锁
		if(number<10){                
		number++;
	//	sem_wait(&sem);
		}		
		else 	
		break;    
		pthread_mutex_unlock(&mut);   
	//printf("thread1 : %d.dat\n",number);
	sem_wait(&sem); 	
	sprintf(str,"%d.dat",number);
        FILE *fp=fopen(str,"r");
	fgets(buf,1024,fp);
	printf("thread1 : %d.dat\n%s\n",number,buf);
//	fprintf(stdout,"thread1 : %d.dat\n",number);
//	fwrite(stdout,30,2,fp);
	
	if(!fp)	
	fclose(fp);
        sem_post(&sem);     
        }
pthread_mutex_unlock(&mut);//解锁，通过锁传递消息  	        
printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);
}

void *thread2()
{        
printf ("thread2 : I'm thread 2\n");
	while(1)
        {       
		pthread_mutex_lock(&mut); //互斥，上锁
                if(number<10){ 
	//	sem_wait(&sem);               
		number++;
		}		
		else 
		break;
                pthread_mutex_unlock(&mut);//解锁，通过锁传递消息         
//	printf("thread2 : %d.dat\n",number);
	sem_wait(&sem); 	
	sprintf(str,"%d.dat",number);
        FILE *fp=fopen(str,"r");
	fgets(buf,1024,fp);
//	printf("%s\n",buf);
	printf("thread2 : %d.dat\n%s\n",number,buf);
	//fprintf(stdout,"thread2 : %d.dat\n",number);
	//fwrite(stdout,,2,fp);	
	
	if(!fp)	
	fclose(fp);
	sem_post(&sem);
        }   
pthread_mutex_unlock(&mut);//解锁，通过锁传递消息  	     
printf("thread2 :主函数在等待吗？\n");        
pthread_exit(NULL);
}

void *thread3()
{        
printf ("thread3 : I'm thread 3\n");
	while(1)
        {       
				
		pthread_mutex_lock(&mut); //互斥，上锁
                if(number<10){                
		number++;
	//	sem_wait(&sem);	
		}		
		else 	
		break;    
                pthread_mutex_unlock(&mut);//解锁，通过锁传递消息         
//	printf("thread3 : %d.dat\n",number);
	sem_wait(&sem); 	
	sprintf(str,"%d.dat",number);
        FILE *fp=fopen(str,"r");
	fgets(buf,1024,fp);
//	printf("%s\n",buf);
	printf("thread3 : %d.dat\n%s\n",number,buf);
//	fprintf(stdout,"thread3 : %d.dat\n",number);
//	fwrite(stdout,30,2,fp);	
	
	if(!fp)	
	fclose(fp);
	sem_post(&sem);
        }        
pthread_mutex_unlock(&mut);//解锁，通过锁传递消息  
printf("thread3 :主函数在等待吗？\n");        
pthread_exit(NULL);
}

void thread_create(void)
{
        int temp;
        memset(&thread, 0, sizeof(thread));
          //comment1        /*创建线程*/
        if((temp = pthread_create(&thread[0], NULL, thread1, NULL)) != 0)  //创建线程，启动thread1函数   
  //comment2
                printf("线程1创建失败!\n");
        else
                printf("线程1被创建\n");
        if((temp = pthread_create(&thread[1], NULL, thread2, NULL)) != 0)  //comment3
                printf("线程2创建失败");
        else
                printf("线程2被创建\n");
	if((temp = pthread_create(&thread[2], NULL, thread3, NULL)) != 0)  //创建  
  //comment3
                printf("线程3创建失败!\n");
        else
                printf("线程3被创建\n");
}

void thread_wait(void)
{
        /*等待线程结束*/
        if(thread[0] !=0)
 {
                   //comment4
                pthread_join(thread[0],NULL);
                printf("线程1已经结束\n");
        }        
if(thread[1] !=0)
 {                //comment5
                pthread_join(thread[1],NULL);
                printf("线程2已经结束\n");
        }
if(thread[2] !=0)
 {                //comment5
                pthread_join(thread[2],NULL);
                printf("线程3已经结束\n");
        }
}

int main()/*一个进程会启动默认线程，其线程函数为main，用于管理其他线程，在默认线程基础上创建thread1,thread2,程序由三个线程组成。*/
{        
/*用默认属性初始化互斥锁*/
        pthread_mutex_init(&mut,NULL);
	sem_init(&sem,0,2);
	FILE *fp1=("registor");        
	printf("主函数，正在创建线程\n");
        thread_create();
        printf("主函数，正在等待线程完成任务\n");
        thread_wait();
        return 0;
}
