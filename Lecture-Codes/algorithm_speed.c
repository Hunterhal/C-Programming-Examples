#include <stdio.h>
#include <time.h>

#define DELAY_TIME 10000000

int main()
{
    printf("Hello World\n");
    clock_t t0, t1;

    t0 = clock();
    for(int delay = 0; delay < DELAY_TIME; delay++);
    t1 = clock();

    double time_spent = (double) (t1 - t0)/CLOCKS_PER_SEC;
    printf("%f\n", time_spent);
    
    double time_stamps[2][10];

    for(int sample_count=1; sample_count < 11; sample_count++)
    {
        //O(n)
        t0 = clock();
        for(int i = 0; i < sample_count; i++)
            for(int j = 0; j < sample_count; j++)
                for(int delay = 0; delay < DELAY_TIME; delay++);
        t1 = clock();

        time_stamps[0][sample_count - 1] = (double) (t1 - t0)/CLOCKS_PER_SEC;

        //O(nlogn)
        t0 = clock();
        for(int i = 0; i < sample_count; i++)
            for(int j=1; j < sample_count; j = j*2)
                for(int delay = 0; delay < DELAY_TIME; delay++);
        t1 = clock();

        time_stamps[1][sample_count - 1] = (double) (t1 - t0)/CLOCKS_PER_SEC;

        printf("%d, %f, %f\n", sample_count, time_stamps[0][sample_count-1], time_stamps[1][sample_count-1]);
    }
    
    return 0;
}

