/* Sample TCP client */
#include<stdio.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/socket.h>

int main(int argc, char**argv){
	int sockfd,n;

	struct sockaddr_in servaddr;
	char request[] = "TCPClient.c";
	char buffer[1000];
	
	if (argc != 2){
		printf("usage: ./%s <IP address>\n",argv[0]);
		return -1;
	}
	
/* socket to connect */
	sockfd=socket(AF_INET,SOCK_STREAM,0);
/* IP address information of the server to connect to */

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr=inet_addr(argv[1]);
	servaddr.sin_port=htons(32001);
	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	
	sendto(sockfd,request,strlen(request),0, (struct sockaddr *)&servaddr,sizeof(servaddr));

	n=recvfrom(sockfd,buffer,10000,0,NULL,NULL);

	buffer[n]=0;printf("Received:%s\n",buffer);
	
	FILE *pFile;
	


	while(1){
		
		
		n=recvfrom(sockfd,buffer,10000,0,NULL,NULL);
		buffer[n]=0;
		//printf("%s",buffer);
		pFile=fopen("myfile2.txt", "a");
		if(pFile==NULL) {
    		perror("Error opening file.");
		}else {
    		//while(fgets(buffer, sizeof(buffer), pFile)) {
        	fprintf(pFile, "%s", buffer);
    	}

		fclose(pFile);
	
	}
	
	return 0;
}
