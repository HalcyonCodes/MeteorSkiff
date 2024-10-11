
--[[
]]--

function delay(seconds)
  local start_time = os.clock()
  while os.clock() < start_time + seconds do
      -- 等待
  end
end

stockId = para["StockIDStringVal"]

dbgPrint(stockId );

q = "qt.gtimg.cn"
s = "80"
--c = "/q=sz002602"
c = "/q=" .. stockId

r = curlGet(q, s, c);

--dbgPrint(r[2])
buyPrice = 0
buyCount = 0
sellPrice = 0
sellCount = 0

local index = 0
for param in string.gmatch(r[2], "[^~]+") do
  --dbgPrint(param)
  if index == 9 then --买1价
    buyPrice = param
    --dbgPrint(param)
  end
  if(index == 10) then --买1量
    buyCount= param
    --dbgPrint(param);
  end
  if index == 19 then --卖1价
    sellPrice = param
    --dbgPrint(param)
  end
  if(index == 20) then --卖1量
    sellCount = param
    --dbgPrint(param);
  end
  index = index + 1
end
--====登录=====
q = "127.0.0.1"
s = "5016"
c = "/api/v1/Account/Login"
z = "{\"userName\" : " .. "\"stringName\"" .. "," .. "\"password\": \"" .. "z12312" .. "\"}"
r = curlPost(q, s, c ,z , ""); --登录
jwt = "";
for match in string.gmatch(r[2], '"Access_token":"(.-)"') do
  jwt = match;
end
--dbgPrint("kk" .. r[1])
c = "/api/v1/TradeData/AddTradeBuyToStock"
--c = "/api/v1/Account/PostTest"
local buyPrice = buyPrice -- 
local buyCount = buyCount -- 
local stockId = stockId -- 

z = string.format('{"price" : "%s", "count" : "%s", "stockId" : "%s"}', buyPrice, buyCount, stockId)

--dbgPrint(z);
r = curlPost(q, s, c ,z , jwt);
--dbgPrint("zz")
dbgPrint(r[1])
