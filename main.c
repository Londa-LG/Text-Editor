#include <stdio.h> 

const int CHARCOUNT = 255;
const int LINECOUNT = 39;
//char text[LINECOUNT][CHARCOUNT];

int getBufferCount(const char file[]){
    int length = 0;
    FILE *pF = fopen(file,"r");
    char buffer[CHARCOUNT];

    if(pF == NULL){
        printf("No such file found");
    }else{

        while(fgets(buffer, CHARCOUNT, pF) != NULL){
            //printf("Line: %d\n", length);
            //printf("%s\n", buffer);
            length++;
        }
    }

    fclose(pF);

    return length;
}



int main(){

    int length = getBufferCount("./text.txt");

    // LoadFile
    int i = 0;
    char buffer[CHARCOUNT];
    char text[LINECOUNT][CHARCOUNT];
    FILE *pF = fopen("./text.txt","r");

    if(pF == NULL){
        printf("No such file found");
    }else{

        while(fgets(buffer, CHARCOUNT, pF) != NULL){
            for(int j=0;j<CHARCOUNT; j++){
               text[i][j] = buffer[j];
            }
            i++;
        }
    }

    fclose(pF);

    // Print text
    for(int cnt = 0; cnt<length; cnt++){
        for(int cnt1 = 0; cnt1<CHARCOUNT; cnt1++){
            printf("%c",text[cnt][cnt1]);
        }
        printf("\n");
    }

    return 0;
}

