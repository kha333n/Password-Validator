#include "vldtr.h"
#include <cctype>
#include <iostream>

inline bool vldtr::verify(char *input)
{
	short symbol = 0, alpha = 0, digit = 0;
	short password_length = (short) strlen(input);
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
				return false;
			}
			if( ispunct(input[counter]) )
			{
				symbol = 1;
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

	if ((symbol == 0) || (digit == 0) || (alpha == 0))
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
		short strlength = (short) strlen(input), x = 0;
		while (x <strlength)
		{
			password[x] = input[x];
			x++;
		}
	}
}

inline void vldtr::display()
{
	short length = (short) strlen(password), x = 0;
	while (x < length)
	{
		std::cout << password[x];
		x++;
	}
	if (length == 0)
	{
		std::cout << "Invalid password was Entered." << std::endl << std::endl;
	}
	 else
    {
        std::cout << "Password is valid." << std::endl << std::endl;
    }
}
