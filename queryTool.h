/**
*   @brief class that maintains values of timestamp, IP address, CPU_ID and CPU_USAGE
*/

#ifndef FILECONTENT_H
#define FILECONTENT_H

class fileContent
{
	public:
		std::string timestamp;
		std::string ip_address;
		std::string cpu_id;
		std::string cpu_usage;

/**
*  @brief Parameterized constructor to initialize values.
*
*  @param timestamp, ip,cpu_id and cpu_usage all are string   	
*/
		fileContent(std::string timestamp,std::string ip_address,std::string cpu_id,std::string cpu_usage){
			this->timestamp = timestamp;
			this->ip_address = ip_address;
			this->cpu_id = cpu_id;
			this->cpu_usage = cpu_usage;
		}


};

#endif
