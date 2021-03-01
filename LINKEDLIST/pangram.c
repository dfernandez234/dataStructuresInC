#include <stdbool.h>
#include <stdio.h>

bool is_pangram(char *str_in) {
  int alphabet [26] = {0};
  int pos = -1;
  for(int i=0;str_in[i]!='\0';i++){
      if((str_in[i]>=65 && str_in[i]<=90)||(str_in[i]>=97 && str_in[i]<=122)){
        if (str_in[i]>=65 && str_in[i]<=90){
            pos = str_in[i]+32-97;
        }
        else{
            pos = str_in[i]-97;
        }
      }
      alphabet[pos] = 1;
  }
  for (int i = 0; i < 26; i++){
      if(alphabet[i] < 1){
          return false;
      }
  }
  return true;
}

int main(int argc, char const *argv[])
{
    printf("%d\n",is_pangram(" BCDEFGHIJKLMNOPQRSTUVWXYZ"));
    return 0;
}
