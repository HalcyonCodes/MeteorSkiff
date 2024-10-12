--模拟炒股购入脚本

function delay(seconds)
  local start_time = os.clock()
  while os.clock() < start_time + seconds do
      -- 等待
  end
end

function loadPics()
    local path = [[.\\Pics\\vBuy1.bmp|.\\Pics\\vBuy2.bmp|.\\Pics\\vStockID.bmp|.\\Pics\\vLast.bmp|.\\Pics\\vBuyPrice.bmp|.\\Pics\\vBuyCount.bmp|.\\Pics\\vBuyButton.bmp|.\\Pics\\vQueDing.bmp|.\\Pics\\vQueDing2.bmp]]
    loadBmp(path)
    inputInit("");
end


function dd()
  
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vBuy1", 32);
    local z = findDAPicA(0, 0, 0, 1920, 1024, "vBuy2", 32);
    
    if r[1] >= 0 then
     --dbgPrint(r[1]);
      moveTo(r[1] + 15, r[2] + 12)
      lOnClick()
    end
    if z[1] >= 0 then
      --dbgPrint(z[1]);
      moveTo(z[1] + 15, z[2] + 12)
      lOnClick()
    end

    --check
    local q = findDAPicA(0, 0, 0, 1920, 1024, "vStockID", 12);
    if  q[1] >= 0 then
        flag = false
        --dbgPrint("find")
    end

  end
end

function ee()
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vStockID", 12);
    if r[1] >= 0 then
      moveTo(r[1]+120, r[2] + 12)
      lOnClick()
      lOnClick()
    end
    local t = para["StockIDStringVal"] :sub(3)
    --dbgPrint(t)
    sendString(t)

    --check
    local c = findDAPicA(0, 0, 0, 1920, 1024, "vStockID", 32);
    if c[1] >= 0 then
        flag = false
    end

  end
end

function ff()
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vBuyPrice", 32);
    if r[1] >= 0 then
      moveTo(r[1] + 110, r[2] + 12)
      lOnClick()
      delay(0.2)
      lOnClick()
      keyPress(8);
      delay(0.6)
      local t = para["StockPriceDoubleVal"]
      --dbgPrint(t)
      sendString(t)


      --check
      local c = findDAPicA(0, 0, 0, 1920, 1024, "vStockID", 32);
      if c[1] >= 0 then
        flag = false
      end
    end
  end
end


function gg()
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vBuyCount", 32);
    if r[1] >= 0 then
      moveTo(r[1] + 110, r[2] + 12)
      lOnClick()
      delay(0.2)
      lOnClick()
      keyPress(8);
      delay(0.6)
      local t = para["StockCountIntVal"]
      --dbgPrint(t)
      sendString(t)


      --check
      local c = findDAPicA(0, 0, 0, 1920, 1024, "vStockID", 32);
      if c[1] >= 0 then
        flag = false
      end
    end
  end
end

function HH()
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vBuyButton", 32);
    if r[1] >= 0 then
      moveTo(r[1] + 12, r[2] + 12)
      lOnClick()
    end

      --check
      local c = findDAPicA(0, 0, 0, 1920, 1024, "vStockID", 32);
      if c[1] >= 0 then
        flag = false
      end
  end
end

function II()
  delay(0.5)
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vQueDing2", 32);
    if r[1] >= 0 then
      moveTo(r[1] + 22, r[2] + 22)
      lOnClick()
      delay(0.5)
    end
    --check
    local c = findDAPicA(0, 0, 0, 1920, 1024, "vQueDing", 32);
      if c[1] >= 0 then
        flag = false
      end
  end
end

function JJ()
  delay(0.5)
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vQueDing", 32);
    if r[1] >= 0 then
      moveTo(r[1] + 22, r[2] + 22)
      lOnClick()
      delay(0.5)
    end
    --check
    local c = findDAPicA(0, 0, 0, 1920, 1024, "vQueDing", 32);
      if c[1] < 0 then
        flag = false
      end
  end
end


dbgPrint("start");

loadPics();


dd();
ee();
ff();
gg();
HH();
II();
JJ();