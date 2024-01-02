#ifndef RPN_CLASS_H
# define RPN_CLASS_H

# include <string>
# include <list>
# include <iostream>

class RPN {
public:
	RPN(void);
	RPN(const RPN &src);
	~RPN(void);
	RPN &operator =(const RPN &src);

	float result(const std::string expr);

	class BadExpressionException: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};

	class DivisionBy0: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};

	class RemainingTerms: public std::exception {
	public:
		virtual const char* what(void) const throw();
	};
};

#endif
