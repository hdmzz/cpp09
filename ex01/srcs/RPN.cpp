#include "../includes/RPN.hpp"

RPN::RPN(void) {
}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN(void) {

}

RPN &RPN::operator= (const RPN &src) {
	(void) src;
	return *this;
}

float RPN::result(const std::string expr)
{
	std::list<float> elems;

	bool is_space = false;
	// Iterate through the string
	for (std::string::const_iterator it = expr.begin(); it != expr.end(); it++)
	{
		// If it's not a space, and the previous char is also not a space
		if (*it != ' ' && !is_space && elems.size() != 0)
			throw RPN::BadExpressionException();
		is_space = (*it == ' ');

		if (is_space)
			continue;
		if (isdigit(*it))
			elems.push_back(*it - '0');//- 0 to convert char to int
		else
		{
			if (elems.size() < 2)
				throw RPN::BadExpressionException();

			float l1 = elems.back();//get the last element
			elems.pop_back();//get rid of it
			float l2 = elems.back();//the second element
			elems.pop_back();//get rid of it

			switch (*it)
			{
			case '+':
				elems.push_back(l2 + l1);
				break;
			case '-':
				elems.push_back(l2 - l1);
				break;
			case '/':
				if (l1 == 0)
					throw RPN::DivisionBy0();
				elems.push_back(l2 / l1);
				break;
			case '*':
				elems.push_back(l2 * l1);
				break;
			default:
				throw RPN::BadExpressionException();
				break;
			}
		}
	}

	if (elems.size() != 1)
		throw RPN::RemainingTerms();

	return elems.front();
}

const char*	RPN::BadExpressionException::what(void) const throw()
{
	return ("Error: malformed expression");
}

const char*	RPN::DivisionBy0::what(void) const throw()
{
	return ("Error: division by 0 is not allowed");
}

const char*	RPN::RemainingTerms::what(void) const throw()
{
	return ("Error: remainging terms");
}
