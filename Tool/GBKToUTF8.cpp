
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS


#include "GBKToUTF8.h"
#include <string>
#include <windows.h>

#include "String.h"
#include <codecvt>
#include <iostream>


std::string String::Utf8ToAnsi(const std::string& str)
{
	return UnicodeToAnsi(Utf8ToUnicode(str));
}

std::string String::AnsiToUtf8(const std::string& str)
{
	return UnicodeToUtf8(AnsiToUnicode(str));
}

std::string String::UnicodeToUtf8(const std::wstring& wstr)
{
	std::string out;
	try {
		std::wstring_convert<std::codecvt_utf8<wchar_t>> wcv;
		out = wcv.to_bytes(wstr);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return out;
}

std::wstring String::Utf8ToUnicode(const std::string& str)
{
	std::wstring ret;
	try
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> wcv;
		ret = wcv.from_bytes(str);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

std::string String::UnicodeToAnsi(const std::wstring& wstr)
{
	std::string ret;
	std::mbstate_t state{};
	const wchar_t* src = wstr.data();
	size_t len = std::wcsrtombs(nullptr, &src, 0, &state);

	if (len != static_cast<size_t>(-1))
	{
		std::unique_ptr<char[]> buff(new char[len + 1]);
		len = std::wcsrtombs(buff.get(), &src, len, &state);
		if (len != static_cast<size_t>(-1))
		{
			ret.assign(buff.get(), len);
		}
	}
	return ret;
}

std::wstring String::AnsiToUnicode(const std::string& str)
{
	std::wstring ret;
	std::mbstate_t state{};
	const char* src = str.data();
	size_t len = std::mbsrtowcs(nullptr, &src, 0, &state);
	if (len != static_cast<size_t>(-1))
	{
		std::unique_ptr<wchar_t[]> buff(new wchar_t[len + 1]);
		len = std::mbsrtowcs(buff.get(), &src, len, &state);
		if (len != static_cast<size_t>(-1))
		{
			ret.assign(buff.get(), len);
		}
	}
	return ret;
}

