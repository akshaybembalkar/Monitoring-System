/**
 *	@file   .cpp
 *	@Author Akshay S. Bembalkar
 *	@Date   07/09/2016
 *	@brief  A simulator to generate the logs for one day
 *	        
 *	       
 */

#include <iostream>
#include <fstream> /* Input/output stream class for files*/
#include <string.h>
#include <ctime>
#include <time.h>  /* time types */
#include <stdlib.h>
#include <string>

std::string getIP(int count);

int main(int argc,char** argv)
{
	char* path = argv[1]; ///< A directory path for files

	int cpu_usage;
	int day = 1440;
	std::string ip_address;

	std::time_t timeStamp = std::time(NULL);
	struct tm *tm = localtime(&timeStamp);
	char date[30];
	strftime(date, sizeof(date), "%Y-%m-%d", tm);
	std::cout<<date<<std::endl;
	strcat(path,"/");
	strcat(path,date);

	std::ofstream file(path);

	std::string data("timestamp\tIP\t\tcpu_id\tusage\n");
	file << data;
	srand (time(NULL));

	while(day > 0){
		int server_count = 1000;
		int ip_count = 1;
		timeStamp += 60;

		while(server_count>0){

		   cpu_usage = rand() % 100;
		   ip_address = getIP(ip_count);

		   file<<timeStamp<<"\t"<<ip_address<<"\t"<<0<<"\t"<<cpu_usage<<"\n";
		   cpu_usage = rand() % 100;
		   file<<timeStamp<<"\t"<<ip_address<<"\t"<<1<<"\t"<<cpu_usage<<"\n";

		   ip_count += 1;
		   server_count --;
		}
		day --;
	}
	return 0;
}

/**
*   Function getIP returns the IP address for log depending upon the 
*    count of the current logs in file. It also decides IP range.
*
*    @log_count is a count of a currently generating log.
*    @return ip address to assign for the current log.
*/

std::string getIP(int log_count)
{
	std::string ip_address;

	if(log_count > 762){
		ip_address = "192.168.4.";
		ip_address.append(std::to_string(log_count-762));
	}	
	else if(log_count > 508){
		ip_address = "192.168.3.";
		ip_address.append(std::to_string(log_count-508));
	}
	else if(log_count > 254){
		ip_address = "192.168.2.";
		ip_address.append(std::to_string(log_count-254));
	}
	else{
		ip_address = "192.168.1.";
		ip_address.append(std::to_string(log_count));
	}


	return ip_address;
}



