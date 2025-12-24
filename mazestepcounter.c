#include <stdio.h>

int main()
{

  int maze[5][5] = {
      {1, 0, 1, 1, 1},
      {1, 1, 1, 0, 1},
      {1, 0, 0, 0, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 0, 1, 1}};

  int visited[5][5] = {0};

  int queue_row[100];
  int queue_col[100];
  int queue_steps[100];

  int front = 0;
  int rear = 0;

  int startRow = 0, startCol = 0;
  int endRow = 4, endCol = 4;

  queue_row[rear] = startRow;
  queue_col[rear] = startCol;
  queue_steps[rear] = 0;
  rear++;

  visited[startRow][startCol] = 1;

  printf("Starting search...\n");

  while (front < rear)
  {

    int r = queue_row[front];
    int c = queue_col[front];
    int s = queue_steps[front];
    front++;

    if (r == endRow && c == endCol)
    {
      printf("Path Found! Total steps: %d\n", s);
      return 0;
    }

    if (r + 1 < 5)
    {
      if (maze[r + 1][c] == 1 && visited[r + 1][c] == 0)
      {
        visited[r + 1][c] = 1;
        queue_row[rear] = r + 1;
        queue_col[rear] = c;
        queue_steps[rear] = s + 1;
        rear++;
      }
    }

    if (r - 1 >= 0)
    {
      if (maze[r - 1][c] == 1 && visited[r - 1][c] == 0)
      {
        visited[r - 1][c] = 1;
        queue_row[rear] = r - 1;
        queue_col[rear] = c;
        queue_steps[rear] = s + 1;
        rear++;
      }
    }

    if (c + 1 < 5)
    {
      if (maze[r][c + 1] == 1 && visited[r][c + 1] == 0)
      {
        visited[r][c + 1] = 1;
        queue_row[rear] = r;
        queue_col[rear] = c + 1;
        queue_steps[rear] = s + 1;
        rear++;
      }
    }

    if (c - 1 >= 0)
    {
      if (maze[r][c - 1] == 1 && visited[r][c - 1] == 0)
      {
        visited[r][c - 1] = 1;
        queue_row[rear] = r;
        queue_col[rear] = c - 1;
        queue_steps[rear] = s + 1;
        rear++;
      }
    }
  }

  printf("No path found.\n");
  return 0;
}