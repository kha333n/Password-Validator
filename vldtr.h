#pragma once
class vldtr
{
	char password[20]{};
	inline bool verify(char *);
public:
	inline vldtr(char *);
	inline void display();
};

