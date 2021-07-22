#include"SmartPtr.h"
SmartPtr::SmartPtr(TestClass *T)
{
	_wsk=T;
	T=nullptr;
}
SmartPtr::SmartPtr(SmartPtr && P)
{
	
	_wsk=std::__exchange(P._wsk,nullptr);
}
TestClass* SmartPtr::get()
{
	return _wsk;
}
TestClass *SmartPtr::operator->() const
{
	return _wsk;
}
TestClass &SmartPtr::operator*() const
{
	return *_wsk;
}
SmartPtr::operator bool() const
{
	if (_wsk)
		return 1;
	else
		return 0;
}
SmartPtr &SmartPtr::operator=(SmartPtr && P)
{
	delete _wsk;
	_wsk=std::__exchange(P._wsk,nullptr);
	return *this;
}
TestClass * SmartPtr::release()
{
	return std::__exchange(_wsk, nullptr);
}
SmartPtr::~SmartPtr()
{
	delete _wsk;
}