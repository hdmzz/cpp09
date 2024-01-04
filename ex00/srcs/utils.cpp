#include <string>
#include <cstring>
#include <sstream>
#include <iostream>

bool checkDateFormat(std::string str)
{
	// Check field length
	std::string test_length = str;
	char *ptr;
	ptr = strtok((char *)test_length.c_str(), "-");//split the date at the "-" character
	int ctr = 0;
	while (ptr != NULL) {
        //check the first field of ptr that must be the year
		if (ctr == 0 && strlen(ptr) != 4)
			return false;
		else if (ctr > 0 && strlen(ptr) != 2)//then check the other fields to see if their len is equal to 2 for the month and the day
			return false;
		ptr = strtok(NULL, "-");//get to the next token of the string after the next "-" character
		ctr++;
	}
	if (ctr != 3)
		return false;

	// Check format
	struct tm result;
    //strptime parse the string representing the date into a tm according to the format
	if(strptime(str.c_str(), "%Y-%m-%d", &result) == NULL)
		return false;

	return true;
}

bool checkValue(std::string str)
{
	std::stringstream s(str);//create a stringstream so we can manipulate the string to extract entry values
	float f;//will stock the value

    //put the string into the float with the >> operator if not possible then if the stream is NOT at the end of the string 
	if (!(s >> f) || !s.eof())
		return false;
    //if f is a negative value then the value is wrong
	if (f < 0)
		return false;
	return true;
}

float strToFloat(std::string str)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof())
		return -1;

	return f;
}
