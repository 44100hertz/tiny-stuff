local counter = function (a)
   a = a or 0
   return function ()
      a = a+1
      return a-1
   end
end

local count = counter(0)

print(count())
print(count())
