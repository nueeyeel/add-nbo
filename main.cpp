#include <stdint.h>
#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>

uint32_t readint(char* filename){
    FILE * file = fopen(filename, "rb");
    uint32_t f;
    size_t readlen = fread(&f, 1, sizeof(uint32_t), file);
    if(readlen !=sizeof(uint32_t)){
        fprintf(stderr, "fread return %lu\n", readlen);
        exit(-1);
    }
    f = ntohl(f);
    fclose(file);
    return f;

}

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("systax : add-nbo <file1> <file2> \n");
        printf("sample : add-nbo a.bin b.bin\n");
        return -1;
    }

    uint32_t f1, f2;
    f1 = readint(argv[1]);
    f2 = readint(argv[2]);

    uint32_t result = f1+f2;
    printf("%d(0x%x)+%d(0x%x)= %d(0x%x)\n", f1, f1,f2,f2,result,result);
}
