#include "utils.hpp"
#include <queue>

typedef bool(*Handler) (int sock);
//http����Ĵ��������
//����һ����Ա����socket
//����һ����������
class HttpTask
{
private:
	int _cli_sock;
	Handler TaskHandler;

public:
	HttpTask()
		: _cli_sock(-1)
	{}

	HttpTask(int sock, Handler handler)
		: _cli_sock(sock)
		, TaskHandler(handler)
	{}

	//��������Ҳ���Ƕ��������������г�ʼ��
	void SetHttpTask(int sock, Handler handler)
	{
		_cli_sock = sock;
		TaskHandler = handler;
	}

	//ִ����������
	void Run()
	{
		TaskHandler(_cli_sock);
	}

};

//�̳߳���
//����ָ���������߳�
//����һ���̰߳�ȫ���������
//�ṩ�������Ӻͳ��ӣ��̳߳ص�����/��ʼ���ӿ�
class ThreadPool
{
private:
	//��ǰ�̳߳��е�����߳���
	int _max_thr;
	//��ǰ�̳߳��е��߳���
	int _cur_thr;
	bool _is_stop;
	std::queue<HttpTask> _task_queue;
	pthread_mutex_t _mutex;
	pthread_cond_t _cond;

private:
	void QueueLock()
	{
		pthread_mutex_lock(&_mutex);
	}

	void QueueUnLock()
	{
		pthread_mutex_unlock(&_mutex);
	}

	bool IsStop()
	{
		return _is_stop;
	}

	void ThreadExit()
	{
		_cur_thr--;
		pthread_exit(NULL);
	}

	void ThreadWait()
	{
		if (IsStop())
		{
			//���̳߳����٣�������ȴ���������ֱ���˳�
			QueueUnLock();
			ThreadExit();
		}
		pthread_cond_wait(&_cond, &_mutex);
	}

	void ThreadWakeUpOne()
	{
		pthread_cond_signal(&_cond);
	}

	void ThreadWakeUpAll()
	{
		pthread_cond_broadcast(&_cond);
	}

	bool QueueIsEmpty()
	{
		return _task_queue.empty();
	}

private:
	//����̻߳�ȡ���񣬴�������
	//static��Ϊ���������ֻ����һ��������������������thisָ��
	static void* thr_start(void* arg)
	{
		while (1)
		{
			ThreadPool *tp = (ThreadPool*)arg;
			tp->QueueLock();
			while (tp->QueueIsEmpty())
			{
				tp->ThreadWait();
			}

			HttpTask ht;
			tp->PopTask(ht);
			tp->QueueUnLock();
			ht.Run();
		}
		return NULL;
	}

public:
	ThreadPool(int max)
		: _max_thr(max)
		, _cur_thr(0)
		, _is_stop(false)
	{
	}

	~ThreadPool()
	{
		pthread_mutex_destroy(&_mutex);
		pthread_cond_destroy(&_cond);
	}

	//����̴߳�����������/����������ʼ��
	bool ThreadPoolInit()
	{
		pthread_t tid;
		for (int i = 0; i < _max_thr; i++)
		{
			int ret = pthread_create(&tid, NULL, thr_start, this);
			if (ret != 0)
			{
				LOG("thread create error\n");
				return false;
			}
			pthread_detach(tid);
			_cur_thr++;
		}
		pthread_mutex_init(&_mutex, NULL);
		pthread_cond_init(&_cond, NULL);

		return true;
	}

	//�̰߳�ȫ���������
	bool PushTask(HttpTask& tt)
	{
		QueueLock();
		_task_queue.push(tt);
		ThreadWakeUpOne();
		QueueUnLock();
		return true;
	}

	//�̰߳�ȫ���������
	bool PopTask(HttpTask& tt)
	{
		//��Ϊ����ĳ��������߳̽ӿ��е��ã�����
		//�߳̽ӿ����ٳ���֮ǰ�ͻ���м�������ˣ����ﲻ��Ҫ���мӽ���
		tt = _task_queue.front();
		_task_queue.pop();

		return true;
	}

	//�����̳߳�
	bool ThreadPoolStop()
	{
		if (!IsStop())
		{
			_is_stop = true;
		}

		while (_cur_thr > 0)
		{
			ThreadWakeUpAll();
		}

		return true;
	}

};

