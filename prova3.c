int scan1(char **t, char c)
{
    int a;
    int b;
    int e;

    a = 0;
    b = 0;
    e = 0;
    while (t[a])
    {
        b = 0;
        while (t[a][b])
        {
            if (t[a][b] == c)
                e++;
            b++;
        }
        a++;
    }
    //ft_printf("numero di c %d\n", e);
    return (e);
}