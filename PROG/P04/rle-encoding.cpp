//str to RLE encoding


void int_to_str(int n, char str[], int& pos){
     char reversed[100];
     int d = 0;
     char chr;
     int pos_rev = 0;

     while (n>0){
         d = n %10;
         n /= 10;
         chr = d + 48;
         reversed[pos_rev++] = chr;
     }

     for (int x= pos_rev - 1; x >= 0; x--){
         str[pos++] = reversed[x];
     }
}


void rle_encode(const char str[], char rle[]){
    int index = 0;
    int counter = 1;
    char letter = str[index];
    int pos = 0;

    while (letter != '\0'){
        if (str[index+1]==letter) counter++;
        else{
            int_to_str(counter, rle, pos);
            rle[pos] = letter;
            counter = 1;
            letter = str[index + 1];
            pos ++;
        }
        index ++;
    }
    
    rle[pos] = '\0';
}
