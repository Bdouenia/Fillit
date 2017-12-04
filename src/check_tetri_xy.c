void     movetmpx(*tmp)
{
    int i;
    while(i < 4)
    {
        (*tmp)->x[i] -= 1;
        i++;
    }
    return (0);
}

void     check_tetri_xy(t_tetri *tetri)
{
    int     i;
    int     j;
    int     a;
    t_tetri *tmp;

    *tmp = (*tetri)->next;
    i = 0;
    j = 0;
    a = 0;
    while(i < 4)
    {
        while(j < 4)
        {
          if((*tetri)->x[i] = (*tmp)->x[j] && (*tetri)->y[j] = (*tmp)->y[j])
                {
                  movetmpx(*tmp);
                  return(check_tetri_yx(*tetri))
                }
            j++;
        }
        i++;
        j = 0;
    }
}

void     check_tetri_yx(t_tetri *tetri)
{
    int     i;
    int     j;
    int     a;
    t_tetri *tmp;

    *tmp = (*tetri)->next;
    i = 0;
    j = 0;
    a = 0;
    while(i < 4)
    {
        while(j < 4)
        {
          if((*tetri)->x[i] = (*tmp)->x[j] && (*tetri)->y[j] = (*tmp)->y[j])
                {
                  movetmpy(*tmp);
                  return(check_tetri_xy(*tetri))
                }
            j++;
        }
        i++;
        j = 0;
    }
}

void     movetmpy(*tmp)
{
    int i;
    while(i < 4)
    {
        (*tmp)->y[i] -= 1;
        i++;
    }
    return (0);
}