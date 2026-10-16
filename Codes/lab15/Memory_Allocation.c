#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
size_t size = 4*1024*1024*1024ULL;
int* buffer = (int*)malloc(size);

if (buffer == NULL) {
fprintf(stderr, "Memory allocation Failed\n");
return 1; }
//Access  Memory
size_t elements = size / sizeof(int);
for (size_t i=0; i< elements; ++i) {
buffer[i] = i;
}

printf("Memory allocated. Check with 'ps -aux' or 'top'. \n");
sleep(30);

free(buffer);
return 0; }
