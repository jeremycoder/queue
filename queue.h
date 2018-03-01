#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <string>

class Queue
{
	private:
		
		struct jobData											//A job data structure
		{
			std::string jobName;								//Holds a job's name
			int jobNumber;										//Each jobs has a number to help with count
			int jobSize;										//How long it takes to do a job
			int queueEntryTime;									//Recorded when a job enters the queue								
			int queueExitTime;									//Recorded when a job exists the queue
			int serviceEntryTime;								//Recorded when a job starts to get service
			int serviceExitTime;								//Recorded when a job is finished
			int getQueueTime()									//Calculates a job's queue time
			{
				return (queueExitTime - queueEntryTime);
			}
			int getServiceTime()								//Calculates a job's service time
			{
				return (serviceExitTime - serviceEntryTime);
			}
			struct jobData* next;								//Pointers used to point to the next job
		};

		jobData* front;											//Queue's front pointer
		jobData* back;											//Queue's back pointer
		jobData* temp;											//Queue's temporary pointer
		jobData tempHoldingJob;									//Job data structure used to temporarily hold jobs
		std::string name;										//Name of the queue
		int serviceRate;										/*The rate at which the queue processes a job per unit time. 
																 Default is 1. 1 job processed per unit time */
		
		int systemTime;											//The queue's time
		int length;												//The queue's length (number of jobs in the queue)
		int serviceStationOpen;									//Signals whether the service station is ready to process
		int jobCount;											//Counts the total number of jobs processed
		bool incrementTimeAfterJobCompletion;					/*Stores option to increment system time right after a job is finished
																 Default is false*/
		int beginningHour;										//Hour at which queue starts to operate, default is 0
		void serviceStation(jobData*);							//Service station processes jobs right after they have been dequeued
						
	public:
		Queue(); 												//Queue constructor with no parameters
		Queue(int);												//Queue constructor with parameter to set system time
		void enqueue(int); 										//Enqueues an integer (jobSize) into the queue
		void insert(int); 										//Just another name for the void enqueue(int) function
		jobData dequeue();										//Dequeues a job data structure
		jobData remove(); 										//Just another name for the jobData dequeue() function
		
		void setServiceRate(int);								//Allows you to set the rate at which jobs get processed per unit time
		void setSystemTime(int); 								//Allows you to set the system time
		void setName(std::string);								//Allows you to set the name of the queue
		void setIncrementTimeOption(bool);						//Holds option to increment time after a job is completed
		void setBeginningHour(int);								/*Sets the time at which the queue will be recorded to have begun operating.
																Works with void modifyTime() */
		
		int getServiceRate(); 									//Returns the rate at which jobs get processed per unit time		
		int getSystemTime();									//Returns the system time
		std::string getName();									//Returns the name of the queue
		bool getIncrementTimeOption();							//Returns the choice of incrementing system time after a job is completed
		int getBeginningHour();									/*Returns the time at which the queue will be recorded to have begun operating.
																Works with void modifyTime() */
		
		
		jobData getFront();										//Returns the job at the front of the queue
		jobData getBack();										//Returns the job at the back of the queue
		int getLength();										//Returns the number of the jobs in the queue
		int getTotalQueueTime();								//Returns the total queue time of all jobs processed
		int getTotalServiceTime();								//Returns the total service time of all jobs processed
				
		bool isEmpty(); 										//Returns true if queue is empty, otherwise returns false
		void printAllCompletedJobs();							//Prints all the completed jobs		
		void incrementSystemTime();								//Increments the system time by 1
		void workOnJob();										//Calls void serviceStation(jobData) to work on a job
		int isServiceStationOpen();								/*Returns whether service station can process jobs
																/1 means yes, 0 means no*/		
		
		std::vector<jobData>completedJobs;						//A vector to hold completed jobs
		void modifyTime(int);									//Displays time in hr:min format
};

#endif
