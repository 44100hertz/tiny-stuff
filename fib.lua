local fib = function ()
    local a,b = 1,1
    while true do
	coroutine.yield(a)
	a,b = b, a+b
    end
end

local cofib = coroutine.create(fib)
for i = 1,10 do
    local num = ({coroutine.resume(cofib)})[2]
    print(num)
end
