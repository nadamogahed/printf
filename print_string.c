int print_string(char *string, int count)
{
    char *ptr;
    int j = 0, i;

    ptr = (char *) malloc((count + 1) * sizeof(char));
    if (ptr == NULL)
        return (0);

    for (j = 0; j < count; j++)
    {
        ptr[j] = string[j];
    }
    ptr[count] = '\0';
    i = write(STDOUT_FILENO, ptr, count);
    free(ptr);
    return (i);
}
