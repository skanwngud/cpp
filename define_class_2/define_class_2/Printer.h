#ifndef __PRINTER_H__
#define __PRINTER_H__

class Printer
{
private:
	char string[100];
public:
	void SetString(const char * setString);
	void ShowString();
};

#endif