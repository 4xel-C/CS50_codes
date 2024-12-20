// Average using an array, a constant and a helper function 
#includ <cs50.h>
#includ <stdio.h>

int main(void){
    // déclaration d'un aray et assignationd es différents scores.
    int scores[3];
    scores[0] = 73;
    scores[1] = 72;
    scores[2] = 33;

    // Code optimization: 

    const int N = 3; // les coonstantes se notes habituellement en lettre capitale.
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (score[0] + scores[1] + scores[2] / (float) N))

}



// ################################################## Optimised code: 

const int N = 3;

// protype

float average(int length, int array[]);

int main(void){
    // get scores 
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Scores: ");
    }

    // print average
    printf("Average: %f\n", average(N, scores))
}

// defining the function

float average(int length, int array[])
{
    // calculate average
    int sum = 0;
    for (int i, i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}




