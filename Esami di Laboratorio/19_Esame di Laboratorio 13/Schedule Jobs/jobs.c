#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int profit; //profitto
    int duration;   //tempo necessario per portarlo a termine 
    int deadline;   //tempo massimo entro cui completarlo 
}job;

int Compare(const void* aa, const void* bb) {
    job* job1 = (job*)aa;
    job* job2 = (job*)bb;
    int app1 = job1->profit / job1->duration;
    int app2 = job2->profit/job2->duration;
    if (app1 > app2) {
        return -1;
    }
    if (app2 > app1) {
        return 1;
    }
    if (job1->duration < job2->duration) {
        return -1;
    }
    if (job2->duration < job1->duration) {
        return 1;
    }
    return 0;
}

void PrintJob(const job* jobs, job* ordinato, size_t j_size) {
    size_t pos;
    for (size_t i = 0; i < j_size; ++i) {
        if (ordinato->deadline == jobs[i].deadline && ordinato->duration == jobs[i].duration &&
            ordinato->profit == jobs[i].profit) {
            pos = i;
        }
    }
    printf("%zi ", pos);
}

int ScheduleJobs(const job* jobs, size_t j_size) {
    if (jobs == NULL || j_size == 0) {
        return 0;
    }
    job* ordinato = malloc(j_size * sizeof(job));
    memcpy(ordinato, jobs, j_size * sizeof(job));
    qsort(ordinato, j_size, sizeof(job), Compare);
    int t = 0;
    int profitto_tot = 0;
    for (size_t i = 0; i < j_size; ++i) {
        if (t + ordinato[i].duration <= ordinato[i].deadline) {
            t += ordinato[i].duration;
            profitto_tot += ordinato[i].profit;
            PrintJob(jobs, ordinato + i, j_size);
        }
    }
    return profitto_tot;
}