void toTXT(char *from, char *to)			
{
	int i = 0;
	while (from[i] != '\0')
	{
		to[i] = from[i];
		i++;
	}
	to[i++] = '.';
	to[i++] = 't';
	to[i++] = 'x';
	to[i++] = 't';
	to[i] = '\0';
}
