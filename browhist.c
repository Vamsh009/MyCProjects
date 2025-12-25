#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Browser
{
  char url[100];
  struct Browser *next;
};
typedef struct Browser br;
br *back = NULL;
br *forward = NULL;
char current[100] = "HomePage";

void push(br **top, char *url)
{
  br *newNode = (br *)malloc(sizeof(br));
  strcpy(newNode->url, url);
  newNode->next = *top;
  *top = newNode;
}

int pop(br **top, char *buff)
{
  if (*top == NULL)
  {
    printf("No pages in this history\n");
    return 0;
  }
  br *temp = *top;
  strcpy(buff, temp->url);
  *top = (*top)->next;
  free(temp);
  return 1;
}

void clear(br **top)
{
  br *temp;
  while (*top != NULL)
  {
    temp = *top;
    *top = (*top)->next;
    free(temp);
  }
}

void visited(char *newurl)
{
  push(&back, current);
  strcpy(current, newurl);
  clear(&forward);
  printf("Current page: %s\n", current);
}

void goback()
{
  char temp[100];
  if (pop(&back, temp))
  {
    push(&forward, current);
    strcpy(current, temp);
    printf("Current page: %s\n", current);
  }
  else
  {
    printf("No pages in back history\n");
  }
}

void goforward()
{
  char temp[100];
  if (pop(&forward, temp))
  {
    push(&back, current);
    strcpy(current, temp);
    printf("Current page: %s\n", current);
  }
  else
  {
    printf("No pages in forward history\n");
  }
}

void show()
{
  printf("\nHsitory State\n");
  printf("Current page: %s\n", current);
  if (back)
  {
    printf("Back History is :%s\n", back->url);
  }
  else
  {
    printf("Back History is empty\n");
  }
  if (forward)
  {
    printf("Forward History is :%s\n", forward->url);
  }
  else
  {
    printf("Forward History is empty\n");
  }
}

int main()
{
  int ch;
  char url[100];
  while (1)
  {
    show();
    printf("\n1. Visit new page\n2. Go Back\n3. Go Forward\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      printf("Enter URL to visit: ");
      scanf("%s", url);
      visited(url);
      break;
    case 2:
      goback();
      break;
    case 3:
      goforward();
      break;
    case 4:
      clear(&back);
      clear(&forward);
      exit(0);
    default:
      printf("Invalid choice! Please try again.\n");
    }
  }
  return 0;
}
