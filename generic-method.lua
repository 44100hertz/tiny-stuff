local hello = {
   print = function (self, value)
      for i=1,self.times do
         print(value)
      end
   end
}

function hello.new(times)
   return setmetatable({times = times or 1}, {__index = hello})
end

h = hello.new(2)
h:print"cool"
h:print(11)
