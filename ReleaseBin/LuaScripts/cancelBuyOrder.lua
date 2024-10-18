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
    local path = [[.\\Pics\\vCancelOrder1.bmp|.\\Pics\\vCancelOrder2.bmp|.\\Pics\\vCancelBuy.bmp|.\\Pics\\vCancelQueDing.bmp|.\\Pics\\vCancelFlag.bmp]]
    loadBmp(path)
    inputInit("");
    --dbgPrint("loadPics")
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
    local r = findDAPicA(0, 0, 0, 1920, 1024, "vCancelBuy", 32);
    if r[1] >= 0 then
        --dbgPrint(r[1]);
        while flag do
            moveTo(r[1] + 15, r[2] + 12)
            lOnClick()
            delay(0.2)
            lOnClick()
            --check
            local q = findDAPicA(0, 0, 0, 1920, 1024, "vCancelQueDing", 12);
            if q[1] >= 0 then
                moveTo(q[1] + 15, q[2] + 12)
                lOnClick()
                --dbgPrint("find")
                flag = false
            end
        end
    else
        --====1.获取股票价格
        q = "127.0.0.1"
        s = "5016"                                           --需要修改接口
        c = "/api/v1/TradeData/GetLastFourTradeBuy?stockID=sz002241" --需要修改配置股票代码
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
        --====2.向股票服务器发送购入数量记录请求=====
         q = "127.0.0.1" --需要修改
         s = "5016"      --需要修改                                  
        c = "/api/v1/Trade/AddStockHolding"
        local stockHoldingID = "3fa85f64-5717-4562-b3fc-2c963f66afa6"
        local stockID = "sz002241"
        local count = 100
        local buyPrice = price1  -- 假设这是你的股票购买价格
        local z = string.format([[
         {
             "stockHoldingID": "%s",
             "stockID": "%s",
             "count": %d,
             "buyPrice": %f
         }
         ]], stockHoldingID, stockID, count, buyPrice)

        --dbgPrint(z)
        r = curlPost(q, s, c, z, jwt2);
        dbgPrint(r[1])

        --====3.更新资金余额====
        --查看剩余金额
        q = "127.0.0.1"
        s = "5016"                          --需要修改接口
        c = "/api/v1/Trade/GetCapital?id=1" --需要修改资金账户id
        r = curlGet(q, s, c);
        --dbgPrint(r[2])
        for match in string.gmatch(r[2], '"balance":([^,}]*)') do
            balance = tonumber(match)
            --dbgPrint(balance)
        end
        balance = tonumber(balance);
        --计算资金消耗
        local pricePerShare = price1
        --dbgPrint("price4 " .. pricePerShare)
        local shares = 100 -- 1手（配置）

        -- 计算成交金额
        local totalAmount = pricePerShare * shares

        -- 定义佣金费率和最低佣金
        local commissionRate = 0.0003 -- 0.03%
        local minCommission = 5

        -- 计算佣金
        local commission = totalAmount * commissionRate
        if commission < minCommission then
            commission = minCommission
        end

        -- 定义过户费率和最低过户费
        local transferFeeRate = 0.0002 -- 0.02%
        local minTransferFee = 1

        -- 计算过户费
        local transferFee = totalAmount * transferFeeRate
        if transferFee < minTransferFee then
            transferFee = minTransferFee
        end

        -- 计算总手续费
        local totalFee = commission + transferFee

        --总费用
        totalFee = totalFee + totalAmount
        balance = balance - totalFee


        q = "127.0.0.1"
        s = "5016"                        --需要修改接口
        c = "/api/v1/Trade/UpdateCapital" --需要修改资金账户id
        --local balance = totalFee        --假设balance是您想要包含的数值

        -- 构造JSON字符串
        local capitalID = "1" -- 资本ID
        --local balance = balance

        local z = string.format([[{"capitalID": "%s", "balance": %f}]], capitalID, balance)

        r = curlPost(q, s, c, z, jwt2);

        dbgPrint(r[1])
    end
end



delay(30)
loadPics()
dd()
ee()