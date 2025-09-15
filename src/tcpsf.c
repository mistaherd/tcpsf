#include <stdint.h> // gives the int8 type
#include <stdio.h> // give print out
#include <string.h>// gives strcmp
#include <regex.h>
enum Command {Unknown,Help,Filepath,Broadcast,Ip_address};
int8_t is_file(char* fname){
   FILE *file;
   if((file=fopen(fname,"r"))){
      fclose(file);
      return 0;
   }
   return 1;
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
   if (regmatch(arg,"/^((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/gm")==0) return Ip_address;
   
   return Unknown;
}
void gethelp(int8_t arguement){
   if (arguement ==Help){
      printf("\r\ntcpsf (tcp send file ) will send a file across a network mainly the one i made myself the following are the commands : \r\n -h \t provides help on each command \r\n <filepath>\t If you pass in a filepath this will be the file sent to server/client \r\n -b \t if you have passed in a file as an aruguement this will  share the file in the local tcp network \r\n <ip adress> \t  another option from when you pass  the file path  is entering  in its  ip address ");
   
   }
   else if(arguement==Filepath){
      printf("\r\n at the moment  this command only supports csv,txt,png,jpeg and pdf files your option are :\r\n -b \t which broadcast the file to all devices in your tcp sever\r\n <ip address>\t will send that file to the ip address");
   }
   else{
      printf("option not avilabe");
   }
}
int8_t main(int8_t argc,char * argv[]){
   if (argc<2){
      printf("\n \033[31mError \33[0m: Usage %s <command>\n",argv[0]);
      return 1;
   }
   switch (get_command(argv[1])){
      case Help:
         gethelp(Help);
         break;
      case Filepath:
         switch (get_command(argv[2])){
            case Help:
               gethelp(Filepath);
               break;
            case Broadcast:
               printf("\r\nsending file to all devices in network");
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
         printf("\n\33[31mInvalid arguement\33[0m try %s -h to see commands",argv[0]);
         break;
      }
   // remember argc 
   return 0;
}f (argc<2){
      printf("\n \033[31mError \33[0m: Usage %s <command>\n",argv[0]);
      return 1;
   }
   switch (get_command(argv[1])){
      case Help:
         printf("\r\ntcpsf (tcp send file ) will send a file across a network mainly the one i made myself the following are the commands : \r\n -h \t provides help on each command \r\n <filepath>\t If you pass in a filepath this will be the file sent to server/client \r\n -b \t if you have passed in a file as an aruguement this will  share the file in the local tcp network \r\n <ip adress> \t  another option from when you pass  the file path  is entering  in its  ip address ");
         break;
      case Filepath:
         switch (get_command(argv[2])){
            case Help:
               printf("\r\n at the moment  this command only supports csv,txt,png,jpeg and pdf files your option are :\r\n -b \t which broadcast the file to all devices in your tcp sever\r\n <ip address>\t will send that file to the ip address");
               break;
            case Broadcast:
               printf("\r\nsending file to all devices in network");
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
         printf("\n\33[31mInvalid arguement\33[0m try %s -h to see commands",argv[0]);
         break;
      }
   // remember argc 
   return 0;
}
