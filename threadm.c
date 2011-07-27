/*thread_example.c */
#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#define MAX 10
pthread_t thread[2];//保存线程标号信息的类型
pthread_mutex_t mut;//互斥变量
int number=0, i;

void *thread1()
{
        printf ("thread1 : I'm thread 1\n");
        for (i = 0; i < MAX; i++)
        {                
printf("thread1 : number = %d\n",number);
                pthread_mutex_lock(&mut); //互斥，上锁
                number++;
                pthread_mutex_unlock(&mut);//解锁，通过锁传递消息
                sleep(2);
        }        
printf("thread1 :主函数在等待吗？\n");
pthread_exit(NULL);
}

void *thread2()
{        
printf("thread2 : I'm thread 2\n");
        for (i = 0; i < MAX; i++)
        {                
printf("thread2 : number = %d\n",number);                
pthread_mutex_lock(&mut);
number++;
pthread_mutex_unlock(&mut);
sleep(3);
        }        
printf("thread2 :主函数在等待吗？\n");        
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
}

int main()/*一个进程会启动默认线程，其线程函数为main，用于管理其他线程，在默认线程基础上创建thread1,thread2,程序由三个线程组成。*/
{        
/*用默认属性初始化互斥锁*/
        pthread_mutex_init(&mut,NULL);
        printf("主函数，正在创建线程\n");
        thread_create();
        printf("主函数，正在等待线程完成任务\n");
        thread_wait();
        return 0;
}

