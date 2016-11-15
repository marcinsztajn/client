/************* UDP CLIENT CODE *******************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

char dod[]="dodawanie";
char mno[]="mnozenie";
char odej[]="odejmowanie";
char dzie[]="dzielenie";
double operacja;
int er;


int main( int argc, char* argv[]){
  int clientSocket, portNum;
  int nBytes;
  double buffer[1024];
  double wynik;

   //printf("You typed: %f",buffer[0]);
  struct sockaddr_in serverAddr;
  socklen_t addr_size;

  /*Create UDP socket*/
  clientSocket = socket(PF_INET, SOCK_DGRAM, 0);

  /*Configure settings in address struct*/
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(7891);
  serverAddr.sin_addr.s_addr = inet_addr("192.168.0.16");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);

  /*Initialize size variable to be used later on*/
  addr_size = sizeof serverAddr;

  if(strcmp(dod,argv[3])==0){
	operacja=1.0;
  }
  if(strcmp(odej,argv[3])==0){
	operacja=2.0;
  }
  if(strcmp(mno,argv[3])==0){
	operacja=3.0;
  }
  if(strcmp(dzie,argv[3])==0){
	operacja=4.0;
  }
printf("argv[3]:  %s\n",argv[3]);
printf("argv[1]:  %s\n",argv[1]);
//


  //while(1){

    //fgets(buffer,1024,stdin);

	//strncpy(buffer,atoi(argv[1]),sizeof(argv[1]));
	buffer[0]=atof(argv[1]);
	buffer[1]=atof(argv[2]);
	buffer[2]=operacja;

    //nBytes = sizeof(buffer)+1 ;

    /*Send message to server*/
    er = sendto(clientSocket,buffer,sizeof(buffer),0,(struct sockaddr *)&serverAddr,addr_size);
    printf("sendto return: %d\n",er);
    /*Receive message from server*/
    nBytes = recvfrom(clientSocket,&wynik,sizeof(wynik),0,NULL, NULL);

    ///*Send message to server*/
    //sendto(clientSocket,buffer,nBytes,0,(struct sockaddr *)&serverAddr,addr_size);



    printf("Wynik operacji arytmetycznej: %f \n",wynik);

    //printf("Wynik operacji arytmetycznej: %f \n",buffer);


  //}

  return 0;
}

