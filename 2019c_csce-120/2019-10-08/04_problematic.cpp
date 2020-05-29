char * problematic();

int main()
{
    char *str = problematic();
    /* tries to do something interesting with str */
    return 0;
}

char * problematic()
{
    char localStr[] = "Hello!";
    return localStr;
}