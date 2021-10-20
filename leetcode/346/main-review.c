typedef struct {
    int sum;
    int size;
    int *q;
    int ptr;
    int n;
} MovingAverage;


MovingAverage* movingAverageCreate(int size) {
    MovingAverage *m = (MovingAverage*)malloc(sizeof(MovingAverage));
    m->sum = 0;
    m->size = size;
    m->q = (int*) calloc(size, sizeof(int));
    m->ptr = 0;
    m->n = 0;
    return m;
}

double movingAverageNext(MovingAverage* obj, int val) {
    obj->sum -= obj->q[obj->ptr];
    obj->sum += val;
    obj->q[obj->ptr++] = val;
    obj->ptr = obj->ptr % obj->size;
    if(obj->n < obj->size)
        obj->n++;
    return (double) obj->sum / obj->n;
}

void movingAverageFree(MovingAverage* obj) {
    free(obj->q);
}

/**
 * Your MovingAverage struct will be instantiated and called as such:
 * MovingAverage* obj = movingAverageCreate(size);
 * double param_1 = movingAverageNext(obj, val);
 
 * movingAverageFree(obj);
*/
