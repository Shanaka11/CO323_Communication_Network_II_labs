/* Sample UDP server */
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char**argv){

	int sockfd,n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t len;
	char mesg[1000];
	char* banner = "Hello UDP client! This is UDP server";
	// the count variable for the loop
	int i;
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(32000);
	
	bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
	len = sizeof(cliaddr);
	// wait for the packet with no of sentences
	
	//use
	n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
	//mesg will have the number
	//now get the int value of it somehow ;)
	//number is that value

	
	//send the acknowledgement
	char* ack = "ack"; 
	//use
	sendto(sockfd,ack,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
	
	//only added while loop(inside is not changed)
	for( i = 0 ; i < number ; i++){
	
		n=recvfrom(sockfd,mesg,1000,0,(struct sockaddr*)&cliaddr,&len);
	//to echo the message changed banner from below to mesg
		toupper(mesg);
		sendto(sockfd,mesg,n,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
	
		mesg[n] = 0;
		printf("Received: %s\n",mesg);
		
	}
	return 0;
}
