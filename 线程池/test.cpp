#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <queue>

#define THREADCOUNT 4

typedef void(*Handler_t)(int);
class ThreadTask
{
public:
	ThreadTask()
	{
		Data_ = -1;
		Handler_ = NULL;
	}

	ThreadTask(int Data, Handler_t Handler)
	{
		Data_ = Data;
		Handler_ = Handler;
	}

	void Run()
	{
		Handler_(Data_);
	}
private:
	int Data_;
	Handler_t Handler_;
};

class ThreadPool
{
public:
	ThreadPool()
	{
		ThreadCapacity_ = THREADCOUNT;
		//�Ƚϼ�ª��һ���������ȽϺõ������ǣ������̵߳�ʱ��ʱ�����ͳ�ƣ�Ȼ���ڸ�ֵ
		ThreadCurNum_ = THREADCOUNT;

		pthread_mutex_init(&Mutex_, NULL);
		pthread_cond_init(&Cond_, NULL);
		IsQuit_ = false;

		//�����߳�
		bool IsCreate = ThreadCreate();
		if (!IsCreate)
		{
			printf("ThreadPool Create thread failed\n");
			//exit(1);
		}
	}

	~ThreadPool()
	{
		pthread_mutex_destroy(&Mutex_);
		pthread_cond_destroy(&Cond_);
	}

	//������
	bool Push(ThreadTask* Tt)
	{
		pthread_mutex_lock(&Mutex_);
		//����������̳߳ص��е��߳̽����˳�����Ͳ�Ҫ�ٽ���push�����ˣ����������ͷţ����̳߳ص��е��߳��˳�
		if (IsQuit_)
		{
			pthread_mutex_unlock(&Mutex_);
			return false;
		}
		Que_.push(Tt);
		pthread_mutex_unlock(&Mutex_);

		//�������ݵ�ʱ����Ҫ֪ͨ�̳߳ص��е��߳�
		pthread_cond_signal(&Cond_);

		return true;
	}
	//ȡ����
	bool Pop(ThreadTask** Tt)
	{
		*Tt = Que_.front();
		Que_.pop();
		return true;
	}

	bool PoolClear()
	{
		pthread_mutex_lock(&Mutex_);
		IsQuit_ = true;
		pthread_mutex_unlock(&Mutex_);
		//���̳߳ص��еĶ���û�����ݵ�ʱ���̶߳���������pthread_cond_wait���У��ȴ�������
		//while(ThreadCurNum_ > 0)
		if (ThreadCurNum_ > 0)
		{
			pthread_cond_broadcast(&Cond_);
		}
		return true;
	}
private:
	//�̵߳���ں���
	//static ��Ҫthisָ��
	static void* ThreadStart(void* arg)
	{
		ThreadPool* tp = (ThreadPool*)arg;
		while (1)
		{
			//����A
			pthread_mutex_lock(&tp->Mutex_);
			//1 if(IsQuit_) �϶����е�
		   // if(tp->IsQuit_)
		   // {
		   //     tp->ThreadQuit();
		   // }
			while (tp->Que_.empty())
			{
				//2 if(IsQuit_)
				if (tp->IsQuit_)
				{
					//�������while(tp->Que_empty())��������жϺ����Ƿ��˳������п������̳߳ض���û�����ݵĵ�ʱ��һֱ������pthread_cond_wait����߼����У���ʱ������Ҳ��ͨ��whileѭ���ж�֮����ִ��pthread_cond_wait
					tp->ThreadQuit();
				}
				//����B
				//��һ�֣�����PCB�ȴ����е���
				//�ڶ��֣��Ѿ������ѹ�һ�Σ�����û����������Դ�����ڵȴ�����Դ��
				//        ��������Ϳ��Թ�������A�����
				pthread_cond_wait(&tp->Cond_, &tp->Mutex_);
			}
			//����C
			ThreadTask* tt;
			tp->Pop(&tt);
			pthread_mutex_unlock(&tp->Mutex_);
			//�����Ѿ��õ������ˣ����Կ��԰����ͷŵ���
			tt->Run();
			delete tt;
		}
		return NULL;
	}

	void ThreadQuit()
	{
		//�ٽ�
		ThreadCurNum_--;
		pthread_mutex_unlock(&Mutex_);
		pthread_exit(NULL);
	}
private:
	bool ThreadCreate()
	{
		int ret = -1;
		pthread_t tid;
		for (int i = 0; i < THREADCOUNT; i++)
		{
			ret = pthread_create(&tid, NULL, ThreadStart, (void*)this);
			printf("[%d]\n", i);
			if (ret != 0)
			{
				printf("create thread failed\n");
				return false;
			}
		}
		return true;
	}
private:
	//�̳߳ص��� ��ʼ����ʱ���̵߳�����
	size_t ThreadCapacity_;
	//��ǰ�̳߳��ж��ٸ�����
	size_t ThreadCurNum_;
	//�̰߳�ȫ�Ķ���
	std::queue<ThreadTask*> Que_;
	//����
	pthread_mutex_t Mutex_;
	//ͬ������
	pthread_cond_t Cond_;

	//�߳��˳��ı�־
	bool IsQuit_;
};

void Printf(int Data)
{
	printf("i am Handler func, i print [%d]\n", Data);
}

int main()
{
	ThreadPool* tp = new ThreadPool();
	for (int i = 0; i < 10; i++)
	{
		ThreadTask* tt = new ThreadTask(i, Printf);
		tp->Push(tt);
	}

	sleep(6);
	tp->PoolClear();
	delete tp;
	return 0;
}
