#pragma once
#include<iostream>
class Codec
{
public:
	Codec();
	virtual std::string encodeMsg();
	virtual void* decodeMsg();
	//虚析构函数
	virtual ~Codec();
};

