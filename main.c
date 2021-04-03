#include <stdio.h>
#include <string.h>

#define BUFFER_LENGTH 64

int match(char *s0, char *s1);
int cmp(char a, char b);
int tlcase(char c);

int main(int argc, char *argv[])
{
	FILE *fp;
	char buffer[BUFFER_LENGTH];

	if(argc != 3 || ((fp = fopen(argv[1], "r")) == NULL))
	{
		puts("Usage: ./hangman \"wordlist file\" \"word\"");
		return 1;
	}

	if(match("B__m", argv[2]))
	{
		puts("Baum");
	}

	while(fgets(buffer, BUFFER_LENGTH, fp) != NULL)
	{
		strtok(buffer, "\n");
		if(match(argv[2], buffer))
		{
			puts(buffer);
		}
	}

	fclose(fp);
	return 0;
}

int match(char *s0, char *s1)
{
	while(*s0 && *s1 && cmp(*s0, *s1))
	{
		++s0, ++s1;
	}

	return !(*s0 || *s1);
}

int cmp(char a, char b)
{
	return ((a == '_') || (tlcase(a) == tlcase(b)));
}

int tlcase(char c)
{
	return (c >= 65 && c <= 90) ? c + 32 : c;
}
