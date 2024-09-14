#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

extern int ScheduleJobs(const job* jobs, size_t j_size);

int main(void) {
    job v1[] = { { 80, 2, 4 }, { 100, 5, 6 }, { 30, 1, 3 } };
    job v2[] = { { 50, 2, 4 }, { 100, 4, 7 }, { 30, 1, 3 } };
    size_t v1_size = sizeof(v1) / sizeof(job);
    size_t v2_size = sizeof(v2) / sizeof(job);

    int profitto;
    profitto = ScheduleJobs(v1, v1_size);
    printf("\n");
    profitto = ScheduleJobs(v2, v2_size);
	return 0;
}