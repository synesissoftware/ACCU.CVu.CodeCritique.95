
#include <stdio.h>

#define ARRAY_SZ(x) sizeof(x)/sizeof(x[0])

typedef struct _Score
{
	char *name;
	int score;
} Score;

void to_string(Score *scores, size_t n,
		  char *buffer, size_t len)
{
	for (size_t i = 0; i < n; i++)
	{
		size_t printed = snprintf(buffer, len,
			"%s:\t%u\n",
			scores[i].name, scores[i].score);
		buffer += printed;
		len -= printed;
	}
}

void process(char buffer[])
{
	Score sc[] = {
		{ "Roger", 10 },
		{ "Bill", 5 },
		{ "Wilbur", 12 },
	};
	to_string(sc, ARRAY_SZ(sc),
		buffer, ARRAY_SZ(buffer));
}

int main()
{
	char buffer[100];

	process(buffer);
	printf(buffer);
}
