#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barrier;

typedef struct semaphore{
    int count;
    pthread_mutex_t lock;
    pthread_cond_t con;
} semaphore_t;

semaphore_t
 sem1;
semaphore_t
 sem2;
semaphore_t
 sem3;
 
void Wait( semaphore_t
 *s ) {
    pthread_mutex_lock(&s->lock);
    s->count --;
    if ( s->count < 0)
        pthread_cond_wait(&s->con, &s->lock);
    pthread_mutex_unlock(&s->lock);
}

void Open(int num,semaphore_t
 *s)
{
    pthread_mutex_lock(&s->lock);
    s->count = num;
    pthread_mutex_unlock(&s->lock);
}

void increament ( semaphore_t
 *s) {
    pthread_mutex_lock(&s->lock);
    s->count ++;
    pthread_cond_signal(&s->con);
    pthread_mutex_unlock(&s->lock);
};

void decreament( semaphore_t
 *s ) {
    pthread_mutex_lock(&s->lock);
    pthread_mutex_unlock(&lock);
    s->count --;
    if ( s->count < 0)
        pthread_cond_wait(&s->con, &s->lock);
    pthread_mutex_unlock(&s->lock);
}


int A = 0;
int B = 0;
int counter = 0;

void *  TeamA()

{
    pthread_barrier_wait(&barrier);
    Wait(&sem3);

    //part 1 starts
    pthread_mutex_lock(&lock);
    printf("Thread ID: %ld, Team: A, I am looking for a car\n",pthread_self());
    A++;
    
    if (A >= 2 && B >= 2){
        
        increament(&sem1);
        increament(&sem2);
        increament(&sem2);
        pthread_mutex_unlock(&lock);
    }
    else if ( A >= 4  ){
        increament(&sem1);
        increament(&sem1);
        increament(&sem1);
        pthread_mutex_unlock(&lock);

    }
    else{
        decreament(&sem1);
    }
    //part 1 ends


    //part 2 starts    
    pthread_mutex_lock(&lock);
    counter++;

    printf("Thread ID: %ld, Team: A, I have found a spot in a car\n",pthread_self());
    
    if (counter == 4 ){
        printf("Thread ID: %ld, Team: A, I am captain and driving the car\n",pthread_self());
        counter = 0;
        
        if ( A >= 4 ){
            A = A - 4;
            increament(&sem3);
            increament(&sem3);
            increament(&sem3);
            increament(&sem3);
        }
        else if ( A >= 2 && B >= 2 ){
            A = A - 2;
            B = B - 2;
        }
        
    }
    pthread_mutex_unlock(&lock);

    //part 2 ends
    pthread_exit(NULL);
    return 0;
}
void * TeamB()
{
    pthread_barrier_wait(&barrier);
    Wait(&sem3);

    //part 1 starts
    pthread_mutex_lock(&lock);
    printf("Thread ID: %ld, Team: B, I am looking for a car\n",pthread_self());
    B++;
    if ( B >= 4 ){
        increament(&sem2);
        increament(&sem2);
        increament(&sem2);
        pthread_mutex_unlock(&lock);
    }
    else if ( A >= 2 && B >= 2){
        increament(&sem1);
        increament(&sem1);
        increament(&sem2);
        pthread_mutex_unlock(&lock);

    }
    else{
        decreament(&sem2);
    }
        //part 1 ends

    //part 2 starts
    pthread_mutex_lock(&lock);
    counter++;
    printf("Thread ID: %ld, Team: B, I have found a spot in a car\n",pthread_self());
    
    if ( counter == 4 ){
        printf("Thread ID: %ld, Team: B, I am captain and driving the car\n",pthread_self());
        counter = 0;
        if ( A >= 2 && B >= 2 ){
            A = A - 2;
            B = B - 2;
        }
        else if ( B >= 4 )
            B = B - 4;
        increament(&sem3);
        increament(&sem3);
        increament(&sem3);
        increament(&sem3);
        
    }
    pthread_mutex_unlock(&lock);

    //phase 2 ends
    pthread_exit(NULL);
    return 0;
}

int main( int argc, char* argv[] ){

    //Variable declaration
    int first = atoi(argv[1]);;
    int second = atoi(argv[2]);;
    int total=0;
    total = first+second;
    pthread_t threads[total];
    
    if(first % 2 == 0 && second % 2 == 0 && total % 4 == 0 ){

        //initializing semaphores
        Open(0, &sem1 );
        Open(0, &sem2 );
        Open(5, &sem3 );
        pthread_barrier_init(&barrier, NULL, total);

        //making threads
        int i;
        for(i=0; i < first; i++){
            pthread_create(&threads[i], NULL, TeamA, NULL);
        }

        int j;
        for(j=first; j < total; j++){
            pthread_create(&threads[i], NULL, TeamB, NULL);
        }

        //terminating all threads
        int k;
        for(j=0; k < total; k++){
            pthread_join(threads[i], NULL);
        }
    }    
    else{
        printf("The main terminates\n");
        return 0;
    }
    pthread_barrier_destroy(&barrier);
    printf("The main terminates\n");
    return 0;
}
