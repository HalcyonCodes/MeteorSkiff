
#pragma once
#include <string>

#pragma once
#include <string>
class String
{
public:
	// ����ӿ�
	static std::string Utf8ToAnsi(const std::string& str);
	static std::string AnsiToUtf8(const std::string& str);

private:
	// �ڲ�����
	static std::string UnicodeToUtf8(const std::wstring& wstr);
	static std::wstring Utf8ToUnicode(const std::string& str);
	static std::string UnicodeToAnsi(const std::wstring& wstr);
	static std::wstring AnsiToUnicode(const std::string& str);

	// disabled functions
	String() = delete;
	~String() = delete;
	String(const String& rhs) = delete;
	String& operator=(const String& rhs) = delete;
};
