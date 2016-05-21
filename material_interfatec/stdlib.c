atof(const char *str)
//str to float
atoi(const char *str)
//str to int
atol(const char *str)
//str to long int
strtod(const char *str)
//str to double
malloc(size_t)
//aloc the size and return a pointer to it
free(pointer)
//free memory
calloc(size_t nitem,size_t size)
//aloc the size and return a pointer to it
bsearch(const void *key, const void *base, size, typesize, function)
//perform a binary search
qsort(const void *base, size, typesize, function)
//sort array
//para as duas
int compare(const void *A, const void *B){
    TYPE *a = (TYPE)A, *b = (TYPE)b;
    if(*a > *b){
        return 1;
    }else{
        if(*a == *b){
            return 0;
        }else{
            return -1;
        }
    }
}
fgets(char *array,int nmax, file *stdin)
    
