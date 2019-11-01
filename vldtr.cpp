#include "vldtr.h"
#include <cctype>
#include <iostream>

inline bool vldtr::verify(char *input)
{
	short symbbol = 0, alpha = 0, digit = 0, whitespace = 1;
	short password_length = strlen(input);
	if (password_length < 8 || password_length > 20)
	{
		return false;
	}
	else
	{
	int counter = 0;
		while(counter < password_length)
		{
			if(isspace(input[counter]))
			{
				whitespace = 0;
				return false;
			}
			if( ispunct(input[counter]) )
			{
				symbbol = 1;
				counter++;
				continue;
			}
    		if( isdigit(input[counter]) )
			{
    			digit = 1;
				counter++;
				continue;
			}
			if (isalpha(input[counter]))
			{
				alpha = 1;
				counter++;
				continue;
			}
        counter++;
		}

	if ((symbbol == 0) || (digit == 0) || (alpha == 0))
	{
		return false;
	}
	else { return true; }
	}
}

inline vldtr::vldtr(char *input)
{
	if (verify(input))
	{
		short strlength = strlen(input), x = 0;
		while (x <strlength)
		{
			password[x] = input[x];
			x++;
		}
	}
}

inline void vldtr::display()
{
	short length = strlen(password), x = 0;
	while (x < length)
	{
		std::cout << password[x];
		x++;
	}
	if (length == 0)
	{
		std::cout << "Invalid password was Entered.";
	}
}
