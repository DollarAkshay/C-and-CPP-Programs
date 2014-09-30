
//https://www.hackerrank.com/contests/evernote-coding-challenge/challenges/evernote-search

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

struct TimeStamp {
	int DD, MM, YYYY;
	int hh, mm, ss;
	struct tm time;
};

struct Note{
	char guid[50];
	TimeStamp created;
	char tag[1000][100];
	int no;
	char content[1000000];
	bool valid;
};

Note book[1000];
Note *searchRes[1000][1000];
int res[1000];
int pages = 0, row = 0;


void addToRes(Note *n){
	if (row == 0){
		searchRes[row][res[row]++] = n;
		return;
	}

	for (int i = 0; i < res[row - 1]; i++){
		if (0 == strcmp(searchRes[row - 1][i]->guid, n->guid)){
			searchRes[row][res[row]++] = n;
			return;
		}
	}

}

void displayNote(Note n){

	printf("\nID :%s \n", n.guid);
	printf("%04d-%02d-%02d %02d:%02d:%02d \n",
		n.created.YYYY, n.created.MM, n.created.DD, n.created.hh, n.created.mm, n.created.ss);
	printf("\nTags : |");
	for (int i = 0; i < n.no; i++){
		printf(" %s |", n.tag[i]);
	}
	printf("\n\nNote :\n%s\n", n.content);

}

int updateNote(){

	Note *n = NULL;
	char line[10000], guid[40], end;
	int i, j;


	//Reading <note> tag
	scanf("%[^\n]%c", line, &end);


	// ~~ guid ~~
	scanf("%[^\n]%c", line, &end);
	j = (int)(strchr(line, '>') - line + 1);
	for (i = j; line[i] != '<'; i++)
		guid[i - j] = line[i];
	guid[i - j] = '\0';

	// Searching for the note with the given guid
	for (i = 0; i < pages; i++){
		if (book[i].valid && !strcmp(book[i].guid, guid)){
			n = (struct Note*) &book[i];
			break;
		}
	}
	if (n == NULL){
		gets(line);
		while (strcmp(line, "</note>"))
			gets(line);
		return 0;
	}



	// ~~ Date ~~
	scanf("%[^\n]%c", line, &end);
	j = (int)(strchr(line, '>') - line + 1);
	n->created.YYYY = (line[j] - '0') * 1000 + (line[j + 1] - '0') * 100 + (line[j + 2] - '0') * 10 + (line[j + 3] - '0');
	n->created.MM = (line[j + 5] - '0') * 10 + (line[j + 6] - '0');
	n->created.DD = (line[j + 8] - '0') * 10 + (line[j + 9] - '0');
	n->created.hh = (line[j + 11] - '0') * 10 + (line[j + 12] - '0');
	n->created.mm = (line[j + 14] - '0') * 10 + (line[j + 15] - '0');
	n->created.ss = (line[j + 17] - '0') * 10 + (line[j + 18] - '0');
	n->created.time.tm_sec = n->created.ss;
	n->created.time.tm_min = n->created.mm;
	n->created.time.tm_hour = n->created.hh;
	n->created.time.tm_mday = n->created.DD;
	n->created.time.tm_mon = n->created.MM - 1;
	n->created.time.tm_year = n->created.YYYY - 1900;


	// ~~ Tags ~~
	scanf("%[^\n]%c", line, &end);
	n->no = 0;
	while (strlen(line) != 11){
		j = (int)(strchr(line, '>') - line + 1);
		for (i = j; line[i] != '<'; i++)
			n->tag[n->no][i - j] = line[i];
		n->tag[n->no][i - j] = '\0';
		n->no++;
		scanf("%[^\n]%c", line, &end);
	}


	// ~~ Content ~~
	int xx = scanf("%[^\n]%c", line, &end);
	strcpy(n->content, "");
	while (strcmp(line, "  </content>")){
		if (strlen(line)>4)
			strcat(n->content, line + 4);
		strcat(n->content, "\n");
		xx = scanf("%[^\n]%c", line, &end);
		if (xx == 0){
			strcpy(line, "");
			scanf("%c", &end);
		}
	}


	// Converting Content to lower case
	i = 0;
	while (n->content[i] != '\0') {
		n->content[i] = tolower(n->content[i]);
		i++;
	}

	//Reading <note> tag
	scanf("%[^\n]%c", line, &end);

	n->valid = true;
	return 1;

}

Note createNote(){

	Note n;
	char line[10000], end;
	int i, j;


	//Reading <note> tag
	scanf("%[^\n]%c", line, &end);


	// ~~ guid ~~
	scanf("%[^\n]%c", line, &end);
	j = (int)(strchr(line, '>') - line + 1);
	for (i = j; line[i] != '<'; i++)
		n.guid[i - j] = line[i];
	n.guid[i - j] = '\0';


	// ~~ Date ~~
	scanf("%[^\n]%c", line, &end);
	j = (int)(strchr(line, '>') - line + 1);
	n.created.YYYY = (line[j] - '0') * 1000 + (line[j + 1] - '0') * 100 + (line[j + 2] - '0') * 10 + (line[j + 3] - '0');
	n.created.MM = (line[j + 5] - '0') * 10 + (line[j + 6] - '0');
	n.created.DD = (line[j + 8] - '0') * 10 + (line[j + 9] - '0');
	n.created.hh = (line[j + 11] - '0') * 10 + (line[j + 12] - '0');
	n.created.mm = (line[j + 14] - '0') * 10 + (line[j + 15] - '0');
	n.created.ss = (line[j + 17] - '0') * 10 + (line[j + 18] - '0');
	n.created.time.tm_sec = n.created.ss;
	n.created.time.tm_min = n.created.mm;
	n.created.time.tm_hour = n.created.hh;
	n.created.time.tm_mday = n.created.DD;
	n.created.time.tm_mon = n.created.MM - 1;
	n.created.time.tm_year = n.created.YYYY - 1900;

	// ~~ Tags ~~
	scanf("%[^\n]%c", line, &end);
	n.no = 0;
	while (strlen(line) != 11){
		j = (int)(strchr(line, '>') - line + 1);
		for (i = j; line[i] != '<'; i++)
			n.tag[n.no][i - j] = line[i];
		n.tag[n.no][i - j] = '\0';
		n.no++;
		scanf("%[^\n]%c", line, &end);
	}


	// ~~ Content ~~
	int xx = scanf("%[^\n]%c", line, &end);
	strcpy(n.content, "");
	while (strcmp(line, "  </content>")){
		if (strlen(line)>4)
			strcat(n.content, line + 4);
		strcat(n.content, "\n");
		xx = scanf("%[^\n]%c", line, &end);
		if (xx == 0){
			strcpy(line, "");
			scanf("%c", &end);
		}
	}

	// Converting Content to lower case
	i = 0;
	while (n.content[i] != '\0') {
		n.content[i] = tolower(n.content[i]);
		i++;
	}


	//Reading <note> tag
	scanf("%[^\n]%c", line, &end);

	n.valid = true;
	return n;
}

void deleteNote(){

	char line[10000], end;
	int i, j;

	//Reading guid 
	scanf("%[^\n]%c", line, &end);
	for (i = 0; i < pages; i++){
		if (!strcmp(book[i].guid, line)){
			book[i].valid = false;
			break;
		}
	}

}

void searchQuerry(char q[], int type, int exact){

	Note *n = NULL;
	char *ptr = NULL;
	int i = 0, j;
	struct tm temp;
	time_t after;

	if (type == 2){
		temp.tm_year = (q[0] - '0') * 1000 + (q[1] - '0') * 100 + (q[2] - '0') * 10 + (q[3] - '0') - 1900;
		temp.tm_mon = (q[4] - '0') * 10 + (q[5] - '0') - 1;
		temp.tm_mday = (q[6] - '0') * 10 + (q[7] - '0');
		temp.tm_hour = 0;
		temp.tm_min = 0;
		temp.tm_sec = 0;
		after = mktime(&temp);
	}


	while (q[i]){
		q[i] = tolower(q[i]);
		i++;
	}
	// Searching for Querry in all the notes
	for (i = 0; i < pages; i++){
		if (book[i].valid){
			n = (struct Note*) &book[i];
			if (type == 0){
				ptr = strstr(n->content, q);
				if (ptr && exact == 0){
					addToRes(n);
				}
				else if (ptr && exact == 1){
					char a, b;
					while (ptr){
						a = tolower(*(ptr - 1));
						b = tolower(*(ptr + strlen(q)));
						if (a != 39 && (a<97 || a>122) && b != 39 && (b<97 || b>122)){
							addToRes(n);
							break;
						}
						ptr = strstr(ptr + strlen(q), q);
					}
				}
			}
			else if (type == 1){
				for (j = 0; j < n->no; j++){
					ptr = strstr(n->tag[j], q);
					if (ptr)
						break;
				}
				if (ptr && exact == 0){
					addToRes(n);
				}
				else if (exact == 1){
					char a, b;
					while (ptr){
						a = tolower(*(ptr - 1));
						b = tolower(*(ptr + strlen(q)));
						if (a != 39 && (a<97 || a>122) && b != 39 && (b<97 || b>122)){
							addToRes(n);
							break;
						}
						ptr = strstr(ptr, q);
					}
				}
			}
			else if (type == 2){
				double d = difftime(mktime(&n->created.time), after);
				if (d >= 0)
					addToRes(n);
			}
		}
	}
}

void searchBook(){

	char line[10000], querry[1000], end;
	int i = 0, j, type = 0, exact = 1; // 0 content 1 for tag 2 for date

	//Reading Search Querry line tag
	scanf("%[^\n]%c", line, &end);
	while (line[i] != '\0'){

		for (j = 0; line[i] != ' ' && line[i] != '\0'; i++, j++)
			querry[j] = line[i];
		querry[j] = '\0';
		if (line[i] == ' ')
			i++;
		if (strstr(querry, "tag:")){
			type = 1;
			strcpy(querry, querry + 4);
		}
		else if (strstr(querry, "created:")){
			type = 2;
			strcpy(querry, querry + 8);
		}
		int len = strlen(querry);
		if (querry[len - 1] == '*'){
			querry[len - 1] = '\0';
			exact = 0;
		}
		searchQuerry(querry, type, exact);
		row++;
	}


	// Printing Search Querry DateWise
	Note *n = NULL;
	for (j = 0; j < res[row - 1]; j++){
		time_t early = -1, cr;
		int pos;
		for (i = 0; i < res[row - 1]; i++){
			if (searchRes[row - 1][i] == NULL)
				continue;
			cr = mktime(&searchRes[row - 1][i]->created.time);
			if (early == -1){
				early = cr;
				n = searchRes[row - 1][i];
				pos = i;
			}
			if (cr < early){
				early = cr;
				n = searchRes[row - 1][i];
				pos = i;
			}
		}
		printf("%s", n->guid);
		searchRes[row - 1][pos] = NULL;
		if (j + 1 < res[row - 1])
			printf(",");
	}
	printf("\n");
	memset(res, 0, sizeof(res));
	row = 0;

}

int main() {

	int exit = 0;
	char command[10000];
	while (!exit){
		if (gets(command) == NULL){
			exit = 1;
			break;
		}
		if (!strcmp("CREATE", command)){
			book[pages++] = createNote();
		}
		else if (!strcmp("DELETE", command)){
			deleteNote();
		}
		else if (!strcmp("UPDATE", command)){
			int success = updateNote();
			if (!success)
				printf("Failed to Update Note\n");
		}
		else if (!strcmp("SEARCH", command)){
			searchBook();
		}
	}
	return 0;
}
