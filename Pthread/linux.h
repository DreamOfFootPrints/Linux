#include<iostream>
using namespace std;

/***************************************************************************************************************************/

int socket(int a, int b, int c)
{
	return 1;
}

void inet_aton(char* ptr, void* p)
{
	return;
}


int htons(int a)
{
	return a;
}

#define AF_INET 1
#define SOCK_STREAM  1
#define SOCK_DGRAM   1

struct A
{
	int s_addr;
};

struct sockaddr_in
{
	int sin_family;
	int sin_port;
	A sin_addr;
};

struct sockaddr
{

};

int bind(int a, const struct sockaddr* p, int b)
{
	return 1;
}

int listen(int a, int b)
{
	return a;
}

void bzero(void* p, int a)
{

}
int accept(int a, struct sockaddr* p, int len)
{
	return 1;
}

typedef int ssize_t;

int read(int fd, void* p, int len)
{
	return 1;
}

int write(int fd, void* p, int len)
{
	return 1;
}

void close(int a)
{

}

int connect(int a, void* p, int len)
{
	return 1;
}


int strncasecmp(void* p1, void* p2, int len)
{
	return 1;
}
/***************************************************************************************************************************/


/***************************************************************************************************************************/
//UDP

int recvfrom(int a, void* ptr, int b, int c, void* p, int* len)
{
	return 1;
}

int sendto(int a, void* ptr1, int b, int c, void* ptr2, int* len)
{
	return 1;
}






/***************************************************************************************************************************/

/***************************************************************************************************************************/
#define AF_LOCAL  1
#define SOCK_STREAM 0
int fork()
{
	return 1;
}

int socketpair(int a, int b, int c, int* fd)
{
	return 1;
}

void sleep(int a)
{

}

int dup(int a)
{
	return 1;
}

int dup2(int a,int b)
{
	return 1;
}
int open(void* pte, int a, int b)
{
	return 1;
}
#define O_RDWR 1
#define O_CREAT 1


/***************************************************************************************************************************/

/***************************************************************************************************************************/
//select
typedef int fd_set[100];

struct timeval
{
	long tv_sec;
	long tv_usec;
};

int select(int a, fd_set* r_set, fd_set* w_set, fd_set ex_set, struct timeval* timeout)
{
	return 1;
}

int FD_CLR(int fd, void* set)
{
	return 1;
}

int FD_ISSET(int fd, void* set)
{
	return 1;
}


void FD_SET(int fd, void* set)
{

}

void FD_ZERO(void* set)
{

}



/***************************************************************************************************************************/
//poll

struct pollfd
{
	int fd;
	short events;
	short revents;
};

#define POLLIN 1
#define POLLOUT 1

int poll(struct pollfd* fds, int nfds, int timeout)
{
	return 1;
}


/***************************************************************************************************************************/
//epoll

typedef union epoll_data
{
	void* ptr;
	int fd;
	int u32;
	long u64;
}epoll_data_t;

struct epoll_event
{
	int events;
	epoll_data_t data;
};


//动作，是注册，修改，还是删除
#define EPOLL_CTL_ADD 1
#define EPOLL_CTL_MOD 1
#define EPOLL_CTL_DEL 1

//注册的事件，对应的文件描述符可读、可写、发生错误
#define EPOLLIN 1
#define EPOLLOUT 1
#define EPOLLERR 1



int epoll_create(int size)
{
	return 1;
}

int epoll_ctl(int epfd, int op, int fd, struct epoll_event* event)
{
	return 1;
}

int epoll_wait(int epfd, struct epoll_event* events, int maxevents, int timeout)
{
	return 1;
}



/***************************************************************************************************************************/
//pthread

typedef int pthread_t;

int pthread_create(pthread_t* tid, const void* p, void*(fun)(void*), void* arg)
{
	return 1;
}


int pthread_self()
{
	
}

void _exit(int a)
{

}

int pthead_canel(pthread_t tid)
{
	return 1;
}

void pthread_exit(void* retval)
{

}

int pthread_cancel(pthread_t thread)
{
	return 1;
}

//分离线程

int pthread_detach(pthread_t tid)
{
	return 1;
}


int pthread_join(pthread_t thread, void** retval)
{
	return 1;
}

//线程的同步与互斥

typedef  int  pthread_mutex_t;

int pthread_mutex_destory(pthread_mutex_t* mutex)
{
	return 1;
}

int pthread_mutex_init(pthread_mutex_t* mutex, void* p)
{
	return 1;
}

#define PTHREAD_MUTEX_INITIALIZER 1

//加锁与解锁
int pthread_mutex_lock(pthread_mutex_t* mutex)
{
	return 1;
}

int pthread_mutex_trylock(pthread_mutex_t* mutex)
{
	return 1;
}

int pthread_mutex_unlock(pthread_mutex_t* mutex)
{
	return 1;
}



//条件变量

typedef int pthread_cond_t;
#define PTHREAD_COND_INITIALIZER 1

int pthread_cond_destory(pthread_cond_t* cond)
{
	return 1;
}

int pthread_cond_init(pthread_cond_t* cond, void* p)
{
	return 1;
}

int pthread_cond_broadcast(pthread_cond_t* cond)
{
	return 1;
}

int pthread_cond_signal(pthread_cond_t* cond)
{
	return 1;
}

int pthread_cond_wait(pthread_cond_t* cond, pthread_mutex_t* mutex)
{
	return 1;
}

int pthread_cond_timedwait(pthread_cond_t* cond, pthread_mutex_t mutex, const void* time)
{
	return 1;
}

//信号量
typedef int sem_t;

int sem_init(sem_t* sem, int pshared, unsigned int value)
{
	return 1;
}

int sem_wait(sem_t* sem)
{
	return 1;
}


int sem_trywait(sem_t* sem)
{
	return 1;
}

int sem_destory(sem_t* sem)
{
	return 1;
}

int sem_post(sem_t* sem)
{
	return 1;
}


//读写锁
typedef int pthread_rwlock_t;

int pthread_rwlock_wrlock(pthread_rwlock_t* rwlock)
{
	return 1;
}
int pthread_rwlock_rdlock(pthread_rwlock_t* rwlock)
{
	return 1;
}
int pthread_rwlock_trywrlock(pthread_rwlock_t* rwlock)
{
	return 1;
}
int pthread_rwlock_tryrdlock(pthread_rwlock_t* rwlock)
{
	return 1;
}

int pthread_rwlock_unlock(pthread_rwlock_t* rwlock)
{
	return 1;
}
int pthread_rwlock_init(pthread_rwlock_t* rwlock, const void* p)
{
	return 1;
}
int pthread_rwlock_destory(pthread_rwlock_t* rwlock)
{
	return 1;
}





/***************************************************************************************************************************/
//signal
typedef int pid_t;
int kill(pid_t pid, itn signo)
{
	return 1;
}

int raise(int sigo)
{
	return 1;
	
}

//void abort(void)
unsigned int alarm(unsigned int seconds)
{
	return 1;
}

//信号集处理函数
typedef int sigset_t;

int sigempty(sigset_t* set)
{
	return 1;
}

int sigefillset(sigset_t set)
{
	return 1;
}

int sigaddset(sigset_t* set,int signo)
{
	return 1;
}

int sigdelset(sigset_t* set, int signo)
{
	return 1;
}


int sigismember(const sigset_t* set, int signo)
{
	return 1;
}

int sigprocmask(int how, const sigset_t* set, sigset_t* oset)//后一个为输出型参数
{
	return 1;
}

int sigpending(sigset_t* set)//后一个为输出性参数
{
	return 1;
}

#define SIG_BLOCK 1
#define SIG_UNBLOCK 1
#define SIG_SETMASK 1


int getpid()
{
	return 1;
}

int getppid()
{
	return 1;
}


struct sigaction
{
	void(*sa_handler)(int);
	sigset_t sa_mask;
	int sa_flags;
	void(*sa_sigaction)(int, void*, void*);
};


int sigaction(int signo, const struct sigaction* act, struct sigaction* oact)//后面一个为输出型参数
{
	return 1;
}

int pause(void)
{
	return 1;
}


#define SIGINT 1
#define STGQUIT 1
#define SIGTSTP 1
#define SIGALRM 14



/***************************************************************************************************************************/
//竞态条件和SIGCHLD信号
int sigsuspend(const sigset_t* sigmask)
{
	return 1;
}

#define SIGCHLD 1

/***************************************************************************************************************************/
//守护进程
pid_t setsid(void)
{
	return 1;
}

typedef int mode_t;

mode_t umask(mode_t cmask)
{
	return 1;
}

int chdir(const char* path)//更改工作目录
{
	return 1;
}

/***************************************************************************************************************************/

//进程间的通信
//管道
int pipe(int filedes[2])
{
	return 1;
}

int mkfifo(const char* path, mode_t mode)
{
	return 1;
}


#define O_RDWR 1
#define O_RDONLY 1
#define O_WRONLY 1

int open(const char* pathname, int flags)
{
	return 1;
}


#define S_IFIFO 1



/***************************************************************************************************************************/
//消息队列
typedef int key_t;
int msgget(key_t key, int msgflg)
{
	return 1;
}

#define IPC_CREAT 1
#define IPC_EXCL  1


#define _SIZE_  1024//这个是用户指定大小
struct msgstru//这个是作为一个缓存区
{
	long mtype;
	char mtext[_SIZE_];
};

ssize_t msgrcv(int msqid, void* msgp, size_t msgsz, long msgtyp, int msgflg)
{
	return 1;
}
ssize_t msgsnd(int msqid, const void* msgp, size_t msgz, int msgflag)
{
	return 1;
}

int msgctl(int msgqid, int cmd, struct msqid_ds* buf)
{
	return 1;
}
key_t ftok(const char* pathname, int proj_id)
{
	return 1;
}

#define IPC_STAT 1
#define IPC_SET 1
#define IPC_RMID  1

/***************************************************************************************************************************/
//信号量
int semget(key_t key, int nsems, int semfly)
{
	return 1;
}

struct sembuf
{
	short semnum;//信号量集中的信号量的编号
	short val;//val>0,代表V    val<0,代表P
	short flag;//默认为0
};

union semun
{
	int val;
	struct semid_ds* buf;
	unsigned short* array;
	void* _buf;
};

int semop(int semid, struct sembuf* sops, unsigned nspos)
{
	return 1;
}


int semctl(int semid, int semnum, int cmd)
{
	return 1;
}

int semctl(int semid, int semum, int cmd, void* buf)
{
	return 1;
}


#define SETVAL 1

/***************************************************************************************************************************/
//共享内存

int shmget(key_t key, int size, int shmflg)
{
	return 1;
}

void* shmat(int shmid, const void* shmaddr, int shmflg)
{
	return NULL;
}

int shmdt(const void* shmaddr)
{
	return 1;
}


int shmctl(int shmid, int cmd, struct shmid_ds* buf)
{
	return 1;
}

/***************************************************************************************************************************/
//进程控制

int getuid()
{
	return 1;
}

int getgid()
{
	return 1;
}

int geteuid()
{
	return 1;
}

int getegid()
{
	return 1;
}


int vfork()
{
	return 1;
}


pid_t wait(int * status)
{
	return 1;
}

pid_t waitpid(pid_t pid, int* status, int options)
{
	return 1;
}

#define WNOHANG 1

//进程的程序替换
int execl(const char* path, const char* arg,...)
{
	return 1;
}

int execlp(const char* file, const char* arg,...)
{
	return 1;
}

int execle(const char* path, const char* arg,.../*char* const envp[]*/)
{
	return 1;
}

int execv(const char* path, char* const argv[])
{
	return 1;
}


int execvp(const char* file, char* const argv[])
{
	return 1;
}

int execve(const char* path, char* const argv[], char* const envp[])
{
	return 1;
}

/***************************************************************************************************************************/
