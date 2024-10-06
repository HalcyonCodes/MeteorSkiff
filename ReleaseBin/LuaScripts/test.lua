
--注意：所有中文字符必须在utf-8文件编辑后，
--在txt编辑器里另存为ansi编码，才能在内存里读取到中文字符

--dbgPrint("����");

--loadBmp("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

--bmp002 loadBmpSub
--loadBmpSub("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

--bmp003 loadBmpList
--loadBmpList("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

--bmp004 freeBmp
--freeBmp();

--bmp005 findPAPicA
--[[while(true)
--do
    r = findPAPicA(0, 0, 0, 1920, 1024, "C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp", 52);
    dbgPrint("===x:", r[1]);
    dbgPrint("===y:", r[2]);
--end]]--

--freeBmp();

--BmpColor 006 findDAPicA
--[[while(true)
do
    r = findDAPicA(0, 0, 0, 1920, 1024, "testFincPic1", 52);
    dbgPrint("===x:", r[1]);
    dbgPrint("===y:", r[2]);
end]]--

--BmpColor 007 findSAPicA
--[[while(true)
do
    r = findSAPicA(0, 0, 0, 1920, 1024, "testFincPic1", 52);
    dbgPrint("===x:", r[1]);
    dbgPrint("===y:", r[2]);
end]]--

--BmpColor 008 findPAPicN
--[[while (true)
do
    r = findPAPicN(0, 0, 0, 1920, 1024, "C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp", 32);
    dbgPrint(r[1][1]);
    dbgPrint(r[1][2]);
    dbgPrint("\n");
    dbgPrint(r[2][1]);
    dbgPrint(r[2][2]);
    dbgPrint("\n");
end]]--

--BmpColor 009 findDAPicN
--[[while (true)
do
    r = findDAPicN(0, 0, 0, 1024, 1920, "testFincPic1", 32);
    dbgPrint(r[1][1]);
    dbgPrint(r[1][2]);
    dbgPrint("\n");
    dbgPrint(r[2][1]);
    dbgPrint(r[2][2]);
    dbgPrint("\n");
end]]--

--BmpColor 010  findSAPicN
--[[while (true)
do
    r = findSAPicN(0, 0, 0, 1920, 1024, "testFincPic1", 32);
    dbgPrint(r[1][1]);
    dbgPrint(r[1][2]);
    dbgPrint("\n");
    dbgPrint(r[2][1]);
    dbgPrint(r[2][2]);
    dbgPrint("\n");
end]]--


--BmpColor 011 findLNPicA
--[[while (true)
do
    r = findLNPicA(0, 0, 0, 1920, 1024, 32);
    dbgPrint(r[1]);
    dbgPrint(r[2]);
    dbgPrint(r[3]);
end]]--

--BmpColor 012 findLNPicN
--[[while (true)
do
    r = findLNPicN(nullptr, 0, 0, 1024, 1920, 32);
    dbgPrint(r[1][1]);
    dbgPrint(r[1][2]);
    dbgPrint(r[1][3]);
    dbgPrint("===");
    dbgPrint(r[2][1]);
    dbgPrint(r[2][2]);
    dbgPrint(r[2][3]);
    dbgPrint("===");
    dbgPrint(r[3][1]);
    dbgPrint(r[3][2]);
    dbgPrint(r[3][3]);
    dbgPrint("===");
    dbgPrint(r[4][1]);
    dbgPrint(r[4][2]);
    dbgPrint(r[4][3]);
    dbgPrint("===");
end
--]]


----InputAction ??-----
--InputAction 001 inputInit
--inputInit("����ץץ��������2014.05.16868");

--InputAction 002 lClickDown
--lClickDown(0);

--InputAction 003 rClickDown
--rClickDown(0);

--InputAction 004 mClickDown
--mClickDown(0);

--InputAction 005 lClickUp
--lClickUp();

--InputAction 006 rClickUp
--rClickUp();

--InputAction 007 mClickUp
--mClickUp();

--InputAction 008 moveTo
--moveTo(0, 0);

--InputAction 009 moveToChange
--moveToChange(120, 130);

--InputAction 010 mOnClick
--mOnClick();

--InputAction 011 lOnClick
--lOnClick();

--InputAction 012 rOnClick
--rOnClick();

--InputAction 013 keyDown
--keyDown(65);

--InputAction 014 keyUp
--keyUp(65);

--InputAction 015 keyPress
--keyPress(65)

--InputAction 016 keyPress
--sendString("123456")

--InputAction 017 sendStringToClipboard
--sendStringToClipboard("ASDFG")

--InputAction 018 getClipboardText
--getClipboardText()

-----------Order  ----------
--order 008 httpPost
--r = 'localhost';
--t = '5036';
--q = '/api/v1/Account/PostTest';
--w = '';
--dbgPrint("����");
--httpPost(r, t, q, w)
--dbgPrint("66666666");
dbgPrint("����");

----system------

--getClipboardText()

