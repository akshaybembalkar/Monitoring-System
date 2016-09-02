

To generate the logs for one day :

	1. Compile the logGenerator.cpp using command: g++ -std=c++11 logGenerator.cpp -o logGenerator
           This will produce an output file logGenerator.
	2. Run the output file logGenerator from step 1 using command: ./logGenerator DIR_PATH
	  For example: ./logGenerator /home/akshay/Quantil_Test/DIR_PATH/
	  This will generate a log file with todays date say 2016-07-11 in DIR_PATH directory.

To run the interactive query tool:
	
	1. Compile the queryTool.cp using command: g++ -std=c++11 queryTool.cpp -lreadline -o queryTool
	   This will produce an output file queryTool.
	2. Run the output file queryTool from step 1 using command: ./queryTool DIR_PATH
	   For example: ./queryTool /home/akshay/Quantil_Test/DIR_PATH/
	   Here DIR_PATH is the same directory where we have generated our log file.

	3. After running the queryTool (Step 2), the tool may take several minutes to initialize.
	   Now our tool will be ready to get a line from a user. (This will be prompted as ">")
	4. To get a query result, User input must be of following format:

		QUERY IP_Address CPU_ID start_time end_time
		
		start_time and end_time should be specified in the format YYYY-MM-DD HH:MM where YYYY is 
		a four digit year, MM is a two digit month (i.e., 01 to 12), DD is the day of the month 
		(i.e., 01 to 31), HH is the hour of the day, and MM is the minute of an hour.
	5. To exit the tool, use the command: EXIT or exit
