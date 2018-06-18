#include <stdio.h>
#include <stdlib.h>

struct point {
    int value;
    int index;
};


int main() {
    FILE *input, *output;
    long long int n;

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fscanf(input, "%lld", &n);
    int a[n];
    struct point deque[n];

    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &a[i]);
    }

    int lIndex, rIndex, dequeEnd, dequeStart;
    lIndex = rIndex = dequeEnd = dequeStart = deque[0].index = 0;
    deque[0].value = a[0];

    int shiftsCount;
    fscanf(input, "%d\n", &shiftsCount);

    char shifts[shiftsCount];
    for (int i = 0; i < shiftsCount; i++){
        fscanf(input, "%c", &shifts[i]);
    }

    for (int i = 0; i < shiftsCount; i++){
        if (shifts[i] == 'R') {
            rIndex++;
            dequeEnd++;
            deque[dequeEnd].index = rIndex;
            deque[dequeEnd].value = a[rIndex];
            while ((a[rIndex] >= deque[dequeEnd - 1].value) && (dequeEnd != dequeStart)){
                dequeEnd--;
                deque[dequeEnd].value = a[rIndex];
                deque[dequeEnd].index = rIndex;
            }
            fprintf(output, "%d ", deque[dequeStart].value);
        } else{
            lIndex++;
            if (lIndex <= deque[dequeStart].index){
                fprintf(output, "%d ", deque[dequeStart].value);
            } else{
                dequeStart++;
                fprintf(output, "%d ", deque[dequeStart].value);
            }
        }
    }
    fclose(input);
    fclose(output);

}