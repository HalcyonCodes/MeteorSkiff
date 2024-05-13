

loadBmp("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

--bmp002 loadBmpSub
loadBmpSub("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

--bmp003 loadBmpList
loadBmpList("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

--bmp004 freeBmp
--msgFreeBmp();

--bmp005 findPAPicA
--[[while(true)
do
    r = findPAPicA(0, 0, 0, 1920, 1024, "C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp", 52);
    dbgPrint("===x:", r[1]);
    dbgPrint("===y:", r[2]);
end]]--

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
    r = findLNPicA(0, 0, 0, 1920, 1024, "testFincPic1", 32);
    dbgPrint(r[1]);
    dbgPrint(r[2]);
    dbgPrint(r[3]);
end]]--

--BmpColor 011 findLNPicN
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


