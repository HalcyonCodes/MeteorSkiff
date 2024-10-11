

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
      local t = para["StockIDStringVal"] :sub(3)
      dbgPrint(t)
      sendString(t)
    end
    --check
    flag = false;
  end
end





dbgPrint("start");

loadPics();


dd();
ee();
ff();

