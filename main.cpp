#include <iostream>
#include <string>
#include <vector>
#include "queue.h"


int main(int argc, char** argv)
{
	Queue myqueue;
	myqueue.enqueue(20);
	myqueue.insert(3);
	myqueue.enqueue(15);
	myqueue.enqueue(82);

	//std::cout << "isServiceStationOpen: " <<myqueue.isServiceStationOpen();

	while (myqueue.getLength() > 0)
	{
		if (myqueue.isServiceStationOpen() == 1)
		{
			myqueue.serviceStation(myqueue.dequeue());
		}
			

	}
	
	std::cout << "Completed Jobs Size: " << myqueue.completedJobs.size() << std::endl;
	return 0;
}