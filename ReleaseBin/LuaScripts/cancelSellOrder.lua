function delay(seconds)
    local start_time = os.clock()
    while os.clock() < start_time + seconds do
        -- 等待
    end
end


--登录机器人服务器
q = "127.0.0.1"
s = "5036" --需要修改接口
c = "/api/v1/Account/Login"
z = "{\"userName\" : " .. "\"stringName\"" .. "," .. "\"password\": \"" .. "z12312" .. "\"}" --需要配置账号密码
--dbgPrint('sss')
r = curlPost(q, s, c ,z , "");
jwt = "";
for match in string.gmatch(r[2], '"Access_token":"(.-)"') do
 jwt = match;
end

--登录机股票服务器
q = "127.0.0.1"
s = "5016" --需要修改接口
c = "/api/v1/Account/Login"
z = "{\"userName\" : " .. "\"stringName\"" .. "," .. "\"password\": \"" .. "z12312" .. "\"}" --需要配置账号密码
--dbgPrint('sss')
r = curlPost(q, s, c ,z , "");
jwt2 = "";
for match in string.gmatch(r[2], '"Access_token":"(.-)"') do
 jwt2 = match;
end

function loadPics()
    local path = [[.\\Pics\\vCancelOrder1.bmp|.\\Pics\\vCancelOrder2.bmp|.\\Pics\\vCancelSell.bmp|.\\Pics\\vCancelQueDing.bmp|.\\Pics\\vCancelFlag.bmp]]
    loadBmp(path)
    inputInit("");
end



function dd()
  
    local flag = true;
    while flag do
      local r = findDAPicA(0, 0, 0, 1920, 1024, "vCancelOrder1", 32);
      local z = findDAPicA(0, 0, 0, 1920, 1024, "vCancelOrder2", 32);
      
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
      local r = findDAPicA(0, 0, 0, 1920, 1024, "vCancelFlag", 32);
      if r[1] >= 0 then
            flag = false
        end
        --dbgPrint("find")
      
  
    end
end

function ee()
    delay(0.5)
    local flag = true;
    local w = findDAPicA(0, 0, 0, 1920, 1024, "vCancelSell", 42);

    if w[1] >= 0 then
        dbgPrint("find")
        --取消订单
        while flag do
            moveTo(w[1] + 15, w[2] + 12)
            lOnClick()
            --delay(0.2)
            --lOnClick()
            --check
            local q = findDAPicA(0, 0, 0, 1920, 1024, "vCancelFlag", 12);
            if q[1] >= 0 then
                moveTo(q[1] + 15, q[2] + 12)
                lOnClick()
                --dbgPrint("find")
                flag = false
            end
            delay(0.2)
            q = findDAPicA(0, 0, 0, 1920, 1024, "vCancelQueDing", 12);
            if q[1] >= 0 then
                moveTo(q[1] + 15, q[2] + 12)
                lOnClick()
                --dbgPrint("find")
                flag = false
            end
            delay(0.2)
            q = findDAPicA(0, 0, 0, 1920, 1024, "vCancelQueDing", 12);
            if q[1] >= 0 then
                moveTo(q[1] + 15, q[2] + 12)
                lOnClick()
                --dbgPrint("find")
                flag = false
            end

        end 
       
    else
        stockID = "sh510050" --需要配置的地方

        --卖出成功
        --1.获取卖出价
        q = "127.0.0.1"
        s = "5016"                                           --需要修改接口
        c = "/api/v1/TradeData/GetLastFourTradeBuy?stockID=sh510050" --需要修改配置股票代码
        r = curlGet(q, s, c);
        --r = curlGet(q, s, c);
        --dbgPrint(r[2])
        index = 0
        price1 = 0
        price2 = 0
        price3 = 0
        price4 = 0
        for match in string.gmatch(r[2], '"Price":([^,]+)') do
            if index == 0 then
                price1 = tonumber(match)
                --dbgPrint(price1)
            elseif index == 1 then
                price2 = tonumber(match)
                --dbgPrint(price2)
            elseif index == 2 then
                price3 = tonumber(match)
                --dbgPrint(price3)
            elseif index == 3 then
                price4 = tonumber(match)
                --dbgPrint(price4)
            end
            index = index + 1;
        end
        --2.将stockHolding移除
        q = "127.0.0.1"
        s = "5016" --需要修改接口
        c = "/api/v1/Trade/DeleteBottomStockHolding";
    
        local StockID = stockID -- 假设这是你的资本ID
        local z = string.format([["%s"]], StockID)
        r = curlPost(q, s, c, z, jwt2);
        --dbgPrint("remove holding" .. r[1])

        --3.更新资金
        q = "127.0.0.1"
        s = "5016"                            --需要修改接口
        c = "/api/v1/Trade/GetCapital?id=1"   --需要修改资金账户id
        r = curlGet(q, s, c);
        --dbgPrint(r[2])
        for match in string.gmatch(r[2], '"balance":([^,}]*)') do
          balance = tonumber(match)
        end
        
    
        local qbalance = balance + price1 * 100
        --dbgPrint("kkkkkffffrtrrrr");
        q = "127.0.0.1"
        s = "5016"                        --需要修改接口
        c = "/api/v1/Trade/UpdateCapital" --需要修改资金账户id
        --local balance = totalFee               -- 假设balance是您想要包含的数值
    
        -- 构造JSON字符串
        local capitalID = "1" -- 资本ID
   
        local z = string.format([[{"capitalID": "%s", "balance": %f}]], capitalID, qbalance)

        r = curlPost(q, s, c, z, jwt2);
        --dbgPrint(r[1]);

    end
end


delay(30)
loadPics()
dd()
ee()