#include <stdio.h>

#define MAXLINE 1000

/* Function declarations */
int getaline(char line[], int maxline);
void copy(char to[], char from[]);

/* Prints the longest line in STDIN. */
int main(void) {
	int len;
	int max = 0;
	char line[MAXLINE];
	char longest[MAXLINE];

	/* while (there's another line)
	 * 		if (it's longer than the maximum length seen)
	 * 			save its length
	 * 			save it
	 * print longest line
	 */
	while ((len = getaline(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0) {
		printf("%s", longest);
	}
	return 0;
}


/* Stores text up to \n in line and returns its length. */
int getaline(char line[], int lim) {
	int len;
	int c;

	/* while (
	 * 		we have not reached line limit and
	 * 		it is not End Of File and
	 * 		c is not the newline char)
	 * 			read c into line
	 * if (c is newline char)
	 * 		append to s
	 * append NULL char '\0' to line
	 */
	for (len = 0; len<lim-1 && (c = getchar())!=EOF && c!='\n'; ++len) line[len] = c;

	if (c == '\n') { /* this is necessary for when input file has blank lines */
		line[len] = c;
		++len;		/* so len is at least 1 */
	}
	line[len] = '\0';	/* terminate line */

	return len;
}

/* Copies contents of to into from. */
void copy(char to[], char from[])
{
	int i = 0;

	while ((to[i] = from[i]) != '\0') {
		++i;
	}
}
