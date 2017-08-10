local char = {
   ["<"] = "h=(h+1)%256",
   [">"] = "h=(h-1)%256",
   ["+"] = "t[h]=((t[h] or 0)+1)%256",
   ["-"] = "t[h]=((t[h] or 0)-1)%256",
   ["."] = "io.write(string.char(t[h]))",
   [","] = "t[h]=io.read()[1]",
   ["["] = "while t[h]>0 do",
   ["]"] = "end",
}
io.write([[
local t = {}
local h = 0
]])
for c in io.input(arg[1]):read("a"):gmatch(".") do
   if char[c] then io.write(char[c]) end
end
io.write(table.concat(strs, " "));
print()
