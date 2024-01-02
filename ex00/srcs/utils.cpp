#include <string>
#include <cstring>
#include <sstream>

bool checkDateFormat(std::string str)
{
	// Check field length
	std::string test_length = str;
	char *ptr;
	ptr = strtok((char *)test_length.c_str(), "-");

	int ctr = 0;
	while (ptr != NULL)
	{
		if (ctr == 0 && strlen(ptr) != 4)
			return false;
		else if (ctr > 0 && strlen(ptr) != 2)
			return false;

		ptr = strtok(NULL, "-");
		ctr++;
	}
	if (ctr != 3)
		return false;

	// Check format
	struct tm result;
	if(strptime(str.c_str(), "%Y-%m-%d", &result) == NULL)
		return false;

	return true;
}

bool checkValue(std::string str)
{
	std::stringstream s(str);
	float f;

	if (!(s >> f) || !s.eof())
		return false;

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
