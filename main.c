int main()
{
    char buf[4096];
    char *p;
    char *params;
    int32_t ret;
    int32_t found;

    setup();

    while (1)
    {
        printf(PROMPT);

        memset(buf, '\0', sizeof(buf));

        ret = read(0, buf, sizeof(buf) - 1);
        if (ret <= 1)
            continue;

        buf[ret - 1] = '\0';

        p = strchr(buf, ' ');
        if (p != NULL)
        {
            *p++ = '\0';

            while (*p == ' ')
                p++;
                
            params = p;
        }
        else
        {
            params = NULL;
        }

        found = 0;
        for (int32_t i = 0; i < ARRAY_SIZE(CMDS); i++)
        {
            if (strcmp(buf, CMDS[i].s) == 0)
            {
                found = 1;
                CMDS[i].func(params);
                break;
            }
        }

        if (!found)
            printf("%s: command not found\n", buf);
    }

    return 0;
}
