#include <stdio.h>
#include <stdlib.h>

FILE *save_file = NULL;

char *extended_fgets(char *, int, FILE *);

int main()
{
	char name[80];
	char *save_file_name;

	int lookup(char const *const name);

	while((argc > 1) && (argv[1][0] == '-')){
		switch(argv[1][1]){
			case 'S':
				save_file_name = &argv[1][2];
				save_file = fopen(save_file_name, "w");
				if(save_file == NULL)
					fprintf(stderr,
							"Warning: Unable to open save file %s\n",
							save_file_name);
				break;
			default:
				fprintf(stderr, "Bad option: %s\n", argv[1]);
				exit(8);
		}
		--argc;
		++argv;
	}

	while(1){
		printf("Enter name: ");
		fgets(name, sizeof(name), stdin);

		if(strlen(name) <= 1)
			break;

		name[strlen(name)-1] = '\0';

		if(lookup(name))
			printf("%s is in the list\n", name);
		else
			printf("%s is not in the list\n", name);
	}
	return(0);
}

int lookup(char const *const name)
{
	static char *list[] = {
		"John", "Jim", "Jane", "Clyde", NULL
	};

	int index;

	for(index = 0; list[index] != NULL; ++index){
		if(strcmp(list[index], name) == 0)
			return(1);
	}
	return(0);
}
