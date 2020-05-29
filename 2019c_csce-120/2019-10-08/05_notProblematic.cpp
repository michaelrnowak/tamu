char * notProblematic();

int main()
{
    char *str = notProblematic();
    /* does something interesting with str */
    return 0;
}

char * notProblematic()
{
    char *localStr = new char[7] {'H', 'e', 'l', 'l', 'o', '!', '\0'};
    return localStr;
}