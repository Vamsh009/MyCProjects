#include <stdlib.h>
#include <stdio.h>
#define max 5

typedef struct Job
{
  int jobId;
  char *documentName;
  int totalPages;
  struct Job *next;
} Job;

typedef struct PQueue
{
  int front;
  int rear;
  Job data[max];
} PQueue;

int intializeQueue(PQueue *pq)
{
  pq->front = -1;
  pq->rear = -1;
  return 1;
}
int isFull(PQueue *pq)
{
  return (pq->rear + 1) % max == pq->front;
}
int isEmpty(PQueue *pq)
{
  return pq->front == -1;
}

void enqueue(PQueue *pq, Job job)
{
  int docno = 1;
  if (isFull(pq))
  {
    printf("Print queue is full. Cannot add new job.\n");
    return;
  }
  if (isEmpty(pq))
  {
    pq->front = 0;
  }
  pq->rear = (pq->rear + 1) % max;
  pq->data[pq->rear] = job;
  printf("Enqueued Job ID: %d\n , Filename:%s %d, Pages:%d\n ", job.jobId, job.documentName, docno++, job.totalPages);
}

Job dequeue(PQueue *pq)
{
  Job job;
  if (isEmpty(pq))
  {
    printf("Print queue is empty. No job to dequeue.\n");
    job.jobId = -1;
    return job;
  }
  job = pq->data[pq->front];
  if (pq->front == pq->rear)
  {
    pq->front = -1;
    pq->rear = -1;
  }
  else
  {
    pq->front = (pq->front + 1) % max;
  }
  printf("Dequeued Job ID: %d\n", job.jobId);
  return job;
}

int main()
{
  PQueue pq;
  intializeQueue(&pq);
  int newjobId = 1;

  printf("Adding print jobs to the queue:\n");
  for (int i = 0; i < 5; i++)
  {
    Job job;
    job.jobId = newjobId++;
    job.documentName = "Document";
    job.totalPages = 10 + i;
    enqueue(&pq, job);
  }
  printf("\nProcessing 3 print jobs from the queue:\n");
  for (int i = 0; i < 3; i++)
  {
    dequeue(&pq);
  }
  printf("\nAdding 2 more print jobs to the queue:\n");
  for (int i = 0; i < 2; i++)
  {
    Job job;
    job.jobId = newjobId++;
    job.documentName = "Document";
    job.totalPages = 20 + i;
    enqueue(&pq, job);
  }
  printf("\nProcessing remaining print jobs from the queue:\n");
  while (!isEmpty(&pq))
  {
    dequeue(&pq);
  }
  return 0;
}
