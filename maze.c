#include <stdio.h>

int main()
{

  char maze[7][13] = {
      "|S . . . . .|",
      "|. .XXX. . .|",
      "|. . . . .X.|",
      "|. XX .X. . |",
      "|. X. . .X. |",
      "|. XXXX. . .|",
      "|. . . . . E|"};

  int q_row[100];
  int q_col[100];
  int head = 0;
  int tail = 0;

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

      if (next_r >= 0 && next_r < 7 && next_c >= 0 && next_c < 13)
      {

        if (maze[next_r][next_c] == ' ' || maze[next_r][next_c] == 'E')
        {

          q_row[tail] = next_r;
          q_col[tail] = next_c;
          tail++;

          if (maze[next_r][next_c] != 'E')
          {
            maze[next_r][next_c] = '.';
          }
        }
      }
    }
  }

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