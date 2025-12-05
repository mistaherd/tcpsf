#include <stdint.h> // gives the int8 type
#include <stdio.h> // give print out
#include <string.h>// gives strcmp
#include <regex.h>
#define IP_REGEX "/^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/gm"
enum Command {Unknown,Help,Filepath,Broadcast,Ip_address,NOARG};

int8_t is_file(char* fname){
  FILE *file=fopen(fname,"r");
  if(file==NULL){
    perror("Error while opening file");
    return 1;
   }
  fclose(file);
  return 0;
}
int8_t regmatch(char* input,char *pattern){
   regex_t reegex;
   int value;
   value =regcomp(&reegex,pattern,0);
   // compare pattern
   value =regexec(&reegex,input,0,NULL,0);
   regfree(&reegex);
   return value;
}
int8_t get_command(char *arg){
   if (strcmp(arg,"-h")==0) return Help;
   if (is_file(arg)==0) return Filepath;
   if (strcmp(arg,"-b")==0)return Broadcast;
   if (regmatch(arg,IP_REGEX)==0) return Ip_address;
   
   return Unknown;
}
void gethelp(int8_t arguement){
  switch(arguement){
    case Help:
      printf("Usage ./tcpsf <file>  [options]\r\nOptions: \n\r-h \t provides help on each command \r\n<filepath>\t If you pass in a filepath this will be the file sent to server/client \r\n-b \t if you have passed in a file as an aruguement this will  share the file in the local tcp network \r\n<ip adress> \t  another option from when you pass  the file path  is entering  in its  ip address\n");
      break;
    case Filepath:
      printf("At the moment  this command only supports csv,txt,png,jpeg and pdf files your options are :\n\r-h \t provides help on each command \n\r-b \t which broadcast the file to all devices in your tcp sever\r\n<ip address>\t will send that file to the ip address\n");
      break;
    case NOARG:
      printf("Options: \n\r-h \t provides help on each command \r\n<filepath>\t If you pass in a filepath this will be the file sent to server/client \r\n-b \t if you have passed in a file as an aruguement this will  share the file in the local tcp network \r\n<ip adress> \t  another option from when you pass  the file path  is entering  in its  ip address\n");
      break;
    default:
      printf("option not avilabe");
      break;
  }
}
int8_t main(int8_t argc,char * argv[]){
   if (argc<2){
      printf("\r\033[31mError \33[0m: Usage %s <file> [options]\n",argv[0]);
      gethelp(NOARG);
      return 1;
   }
   switch (get_command(argv[1])){
      case Help:
         gethelp(Help);

         break;
      case Filepath:
        if (argc<3){
        printf("\r\033[31mError \33[0m: Missing option After file path.\n");
        printf("Usage: %s <file> [Broadcast |Ip_address | Help]\n",argv[0]);
        gethelp(Filepath);
        return 1;
      }
        switch (get_command(argv[2])){
          case Help:
            gethelp(Filepath);
            break;
          case Broadcast:
            printf("\r\nsending file to all devices in network\n\r");
            /// add broadcast logic here
            break;
          case Ip_address:
            printf("\r\n Sending file to %s ",argv[1]);
            /// add ip logic here
            break;
          default:
            printf("\n \33[31Invalid aruguement\33[0m");
            break;
         }
         break;
      default:
         printf("\n\33[31mInvalid arguement\33[0m try %s -h to see commands\n\r",argv[0]);
         break;
      }
   // remember argc 
   return 0;
}

