#include"TestClass.h"
TestClass::TestClass(const char *t)
{
	_text = new char [strlen(t)+1];
	strcpy(_text, t);
	cout<<"++ Tworze obiekt TestClass: "<<_text<<endl;
}
const char * TestClass::info() const
{
	return _text;
}
void TestClass::setName(const char * t)
{
	delete [] _text;
	_text = new char [strlen(t)+1];
	strcpy(_text, t);
}
TestClass::~TestClass()
{
	if (_text)
	{
		cout<<"-- Usuwam obiekt TestClass: "<<_text<<endl;
		delete [] _text;
		
	}
}