
dbgPrint("����");

loadBmp(".\\Pics\\dot.bmp|.\\Pics\\buy1.bmp|.\\Pics\\12.bmp");

--r = findDAPicA(0, 0, 0, 1920, 1024, "buy1", 52);
--dbgPrint("===x:", r[1]);
--dbgPrint("===y:", r[2]);
--r = findDAPicA(0, 0, 0, 1920, 1024, "22", 52);
--dbgPrint("===x:", r[1]);
--dbgPrint("===y:", r[2]);

--

loadBmpList(".\\Pics\\12.bmp|.\\Pics\\22.bmp|.\\Pics\\32.bmp|.\\Pics\\42.bmp|.\\Pics\\52.bmp|.\\Pics\\62.bmp|.\\Pics\\72.bmp|.\\Pics\\82.bmp|.\\Pics\\92.bmp");


r = findDAPicA(0, 0, 0, 1920, 1024, "buy1", 72);
dbgPrint("gggggggg");
dbgPrint( r[1]);
startX = r[1] + 5;
dbgPrint("YYYYYY");
startY = r[2] - 2;
dbgPrint(startY);

currentX = 0;

price = '';

flag = true;

tflag = 0;

while flag do
    
    --local r = findDAPicA(0, startX, startX + 4, startY, startY + 16, "dot", 13)
    --dbgPrint(r[1])
    --if r[1] >= 0 then
      --  price = price .. "."
     --   startX = startX + 4
     --   tflag = tflag + 1
     --   dbgPrint("dqdq")
   -- else
        dbgPrint("qxqstartX")
        dbgPrint(startX)
        dbgPrint("qxqstartX2")
        dbgPrint(startX + 10)
        local q = findLNPicA(0, startX, startX + 9, startY, startY + 18, 42)
        --local q = findDAPicA(0, startX, startX + 10, startY, startY + 16, "12", 72)
        
        dbgPrint(startY)
        dbgPrint(startY + 16)
        
        dbgPrint("KDKDKD")
        local math = q[3]
        dbgPrint(math)
        
        price = price .. tostring(math)
        startX = startX + 9
        if tflag ~= 0 then
            tflag = tflag + 1
        end
    --end
    
    if tflag == 3 then
        flag = false
        dbgPrint("rklldlldslds")
    end
end


dbgPrint("===$$$:", price);