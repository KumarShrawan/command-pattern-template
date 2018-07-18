#include <queue>
#include <pthread.h>
namespace SvcIpc{


class ICommand{
public:
	virtual ~ICommand(){}
	virtual void execute() = 0;

};

class CCommandQueue
{
public:
	explicit CCommandQueue();
	~CCommandQueue();
	ICommand* get();
	void post(ICommand* event);
	void postFront(ICommand* event);
private:
	bool enableDebounce;
	pthread_mutex_t commandQueueLock;
	pthread_cond_t condvar;
	std::deque<ICommand*> commandQueue;
};

}