
--[[
]]--

function delay(seconds)
  local start_time = os.clock()
  while os.clock() < start_time + seconds do
      -- 等待
  end
end

function loadPics()
    loadBmp(".\\Pics\\buy1.bmp|.\\Pics\\buy2.bmp|.\\Pics\\stockID.bmp|.\\Pics\\trade1.bmp|.\\Pics\\trade2.bmp|.\\Pics\\lock1.bmp|.\\Pics\\lock2.bmp|.\\Pics\\lockBuyOne.bmp|.\\Pics\\lockSellOne.bmp|.\\Pics\\price.bmp")
    inputInit("");
end


function dd()
  local flag = true;
  while flag do
    local r = findDAPicA(0, 0, 0, 1920, 1024, "trade1", 32);
    if r[1] >= 0 then
      moveTo(r[1], r[2])
      lOnClick()
    end

    --check
    local q = findDAPicA(0, 0, 0, 1920, 1024, "buy1", 32);
    local c = findDAPicA(0, 0, 0, 1920, 1024, "buy2", 32);
    if q[1] >= 0 or c[1] >= 0 then
        flag = false
    end

  end
end

function ee ()
  local flag = true;
  while flag do
    local q = findDAPicA(0, 0, 0, 1920, 1024, "buy1", 32);
    local c = findDAPicA(0, 0, 0, 1920, 1024, "buy2", 32);
    if q[1] >= 0 then
      moveTo(q[1] , q[2])
      lOnClick()
    end
    if c[1] >= 0 then
      moveTo(c[1] , c[2])
      lOnClick()
    end

    --check
    local z = findDAPicA(0, 0, 0, 1920, 1024, "stockID", 32);
    if z[1] >= 0 then
        flag = false
    end
  end
end

function ff ()
  local flag = true;
  while flag do
    local v = findDAPicA(0, 0, 0, 1920, 1024, "stockID", 32);

    if v[1] >= 0 then
      moveTo(v[1] + 130 , v[2])
      lOnClick()
      lOnClick()
      sendString(para["StockIDStringVal"] )
    end
    --check
    flag = false;
  end
end

function gg()
  local flag = true;
  while flag do
    local v = findDAPicA(0, 0, 0, 1920, 1024, "lock1", 32);
    local g = findDAPicA(0, 0, 0, 1920, 1024, "lock2", 32);
    if v[1] >= 0 then
      moveTo(v[1] + 2, v[2] + 2)
      lOnClick()
    end
    if g[1] >= 0 then
      moveTo(g[1] + 2, g[2] + 2)
      lOnClick()
    end
    delay(1)
 
    local z = findDAPicA(0, 0, 0, 1920, 1024, "lockBuyOne", 32);
    if z[1] >= 0 then
      moveTo(z[1] + 2, z[2] + 2)
      lOnClick()
    end
    --check
    local k = findDAPicA(0, 0, 0, 1920, 1024, "lock1", 32);
    if k[1] >= 0 then
      flag = false
    end

  end
end


function hh()
  local flag = true
     delay(1)
    local v = findDAPicA(0, 0, 0, 1920, 1024, "price", 32);
    if v[1] >= 0 then
      moveTo(v[1] + 110, v[2] + 15)
      lOnClick()
      lOnClick()
      delay(0.3)
      keyDown(17)
      delay(0.1)
      keyPress(67)
      delay(0.1)
      keyUp(17)
    end
    local q = getClipboardText()
    dbgPrint(q)

end





loadPics();


--dd();
--ee();
--ff();
--gg();
--hh();
freeBmp()

sendStringToClipboard("ASDFG")

q = getClipboardTexti()

dbgPrint(q)