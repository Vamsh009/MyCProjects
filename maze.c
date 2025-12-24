#include <stdio.h>

int main()
{
  // R=Rows (7), C=Cols (13)
  char maze[7][13] = {
      "|S| | | | | |",
      "| | |X|X|X| |",
      "| | | | |X| |",
      "| |X|X| |X| |",
      "| |X| | |X| |",
      "| |X|X|X|X| |",
      "| | | | | |E|"};

  // Queue setup
  int q_row[100];
  int q_col[100];
  int head = 0;
  int tail = 0;

  // FIND START (S)
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 13; j++)
    {
      if (maze[i][j] == 'S')
      {
        q_row[tail] = i;
        q_col[tail] = j;
        tail++;
      }
    }
  }

  // FLOOD FILL BFS
  int found = -1;
  int dr[] = {-1, 1, 0, 0};
  int dc[] = {0, 0, -1, 1};

  while (head < tail)
  {
    int r = q_row[head];
    int c = q_col[head];
    head++;

    if (maze[r][c] == 'E')
    {
      found = 1;
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      int next_r = r + dr[i];
      int next_c = c + dc[i];

      // Check bounds (0 to 6 for rows, 0 to 12 for cols)
      if (next_r >= 0 && next_r < 7 && next_c >= 0 && next_c < 13)
      {
        // Check if empty space or End
        if (maze[next_r][next_c] == ' ' || maze[next_r][next_c] == 'E')
        {

          q_row[tail] = next_r;
          q_col[tail] = next_c;
          tail++;

          // Mark as visited with '.' (unless it is E)
          if (maze[next_r][next_c] != 'E')
          {
            maze[next_r][next_c] = '.';
          }
        }
      }
    }
  }

  // PRINT RESULT (FIXED)
  if (found)
  {
    printf("Maze Solved!\n");
    for (int i = 0; i < 7; i++)
    {
      for (int j = 0; j < 13; j++)
      {
        printf("%c", maze[i][j]);
      }
      printf("\n");
    }
  }
  else
  {
    printf("Impossible to reach E!\n");
  }

  return 0;
}