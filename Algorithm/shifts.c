#include "shifts.h"

void parseShiftFile(char *filename, struct Shift *shifts){
    FILE *fp = fopen(filename, "r");
    char line[1024];
    int i = 0;
    while (fgets(line, 1024, fp)){
	    
	    strtok(line, "\n");
	    printf("%s\n", line);
	    char *day = strtok(line, " ");
	    double start = atof(strtok(NULL, " "));
	    double end = atof(strtok(NULL, " "));
	    int num = atoi(strtok(NULL, " "));
	    
	    //struct Shift **constraints = calloc(num-1, sizeof(struct Shift *));
	    
	    for(int j = 0; j < num; j++){
		    shifts[i].id = i+1;
		    shifts[i].day = calloc(strlen(day) + 1, sizeof(char));
		    strcpy(shifts[i].day, day);
		    shifts[i].start = start;
		    shifts[i].end = end;
		    shifts[i].n_constraints = num;
		    shifts[i].constraints = calloc(num, sizeof(struct Shift *));
#ifdef DEBUG
		    printf("id: %d\n", shifts[i].id);
		    printf("day: %s\n", shifts[i].day);
		    printf("start: %f\n", shifts[i].start);
		    printf("end: %f\n\n", shifts[i].end);
#endif
		    i++;
	    }
	    
	    for (int j = i - num; j < i; j++) {
		    for (int k = 0; k < num-1; k++) {
			    if(k + i - num == j) j++;
                shifts[j].constraints[k] = &shifts[j];
		    }
	    }
	    
	    // People can't work twice in the same day -> add here !!
    }
    i++;
    shifts[i].day = '\0';
    
#ifdef DEBUG 
    printf("------------------------\n\n");
    traverseShifts(shifts);
#endif
    
    return;
}

void traverseShifts(struct Shift *shifts){
	int i = 0;
	while(shifts[i].day[0] != '\0'){
		printf("%d\n", i);
		printf("id: %d\n", shifts[i].id);
		printf("day: %s\n", shifts[i].day);
		printf("start: %f\n", shifts[i].start);
		printf("end: %f\n\n", shifts[i].end);
		i++;
	}
	return;
}
