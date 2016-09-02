/**
*	@file   .cpp
*	@Author Akshay S. Bembalkar
*	@Date   07/10/2016
*	@brief  A command line tool which takes a directory of data files as a 
*	        parameter and lets you query CPU usage for a specific CPU in a 
*	        given time period.
*/
#include <readline/readline.h> /* Get a line from a user with editing */
#include <readline/history.h>
#include <stdlib.h>
#include <iostream>
#include <dirent.h>   /*Format of directory entries */
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>    /* Manipulate date and time information.*/
#include "queryTool.h"


std::vector<std::string> openDirectory(std::string);

/**
*  Vector files to store all the files in directory
*  Vector cardCatalog to store file contents.
*/
std::vector<std::string> files;
std::vector<fileContent*> cardCatalog;

int main(int argc, char ** argv)
{

	files = openDirectory(argv[1]);

	std::vector<std::string>::iterator it;
	for(it = files.begin();it!=files.end();++it)
	{
		std::string path = argv[1];
		
		path.append("/");
		path.append(*it);
		std::string line;
		std::ifstream myfile(path);
		int temp= 0;
		if (myfile.is_open())
		{
			while ( getline (myfile,line) )
			{
				std::stringstream ss(line);
				std::string s1,s2,s3,s4;
				getline(ss,s1,'\t');
				getline(ss,s2,'\t');
				getline(ss,s3,'\t');
				getline(ss,s4);
				///Allocate block of memory for each object in a vector
				fileContent *obj = new fileContent(s1,s2,s3,s4);
				cardCatalog.push_back(obj);
			}
			myfile.close();
		}

		else{
			std::cout << "Unable to open file"; 
			exit(0);
		}
		

	}


	while(1)
	{
		char * line = readline("> ");
		if(!line){
			free(line);
			break;
		}

		std::string read = line; ///< String variable to store user input

		if(read.find("QUERY") != std::string::npos){

			std::string ip_address,cpu_id,startDate,startTime,endDate,endTime,s1; 
			std::stringstream ss(read);
			/** Separate each word at space from input Query and store it in strings.
			 */
			getline(ss,s1,' ');
			getline(ss,ip_address,' ');
			getline(ss,cpu_id,' ');
			getline(ss,startDate,' ');
			getline(ss,startTime,' ');
			getline(ss,endDate,' ');
			getline(ss,endTime);

			startDate.append(" "+startTime);
			endDate.append(" "+endTime);

			std::cout<<"CPU"<<cpu_id<<" usage on "<<ip_address<<":"<<std::endl;
			std::vector<fileContent*>::iterator it;

			for(it = cardCatalog.begin();it!=cardCatalog.end();++it){

			   if((*it)->ip_address == ip_address && (*it)->cpu_id == cpu_id){ //If IP address and CPU_ID matches

				std::time_t result = atoi((*it)->timestamp.c_str());
				struct tm *tm = localtime(&result);
				char date[40];
				strftime(date, sizeof(date), "%Y-%m-%d %H:%M", tm);
				std::stringstream timeStamp(date);

				std::string splitDate,splitTime;
				getline(timeStamp,splitDate,' ');
				getline(timeStamp,splitTime);

				if(date>=startDate && date < endDate){

					std::cout<<"("<<splitDate<<" "<<splitTime<<" "<<((*it)->cpu_usage)<<"%"<<")"<<",";
				}
			   }

			}
			std::cout<<std::endl;
		}
		if(read=="exit" || read=="EXIT"){
			free(line);
			break;
		}
		free(line);
	}

///Free the allocated memory blocks within a cardCatalog vector
	std::vector<fileContent*>::iterator it2;
	for(it2 = cardCatalog.begin();it2!=cardCatalog.end();++it2){
		delete *it2;
	}
	return 0;
}

/**
 *   Function openDirectory scans all the files from directory path
 *
 *    @param path is an initialized path to a directory.
 *    @return vector containing names of all the files in the directory.
 */

std::vector<std::string> openDirectory(std::string path) {

	DIR*    dir;  ///< dir represents a directory stream
	dirent* pdir;
	std::vector<std::string> files;

	dir = opendir(path.c_str());

	while (pdir = readdir(dir)) {
		files.push_back(pdir->d_name);
	}
	closedir(dir);	

	return files;
}







