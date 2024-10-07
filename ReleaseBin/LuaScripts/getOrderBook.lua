
--[[
]]--

function delay(seconds)
  local start_time = os.clock()
  while os.clock() < start_time + seconds do
      -- 等待
  end
end

q = "qt.gtimg.cn"
s = "80"
c = "/"

r = curlGet(q, s, c);
dbgPrint(r[1])
dbgPrint(r[2])
