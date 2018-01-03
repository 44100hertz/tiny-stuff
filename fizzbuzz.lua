--for i=1,100 do loadstring(("if %d%%15==0~'fizzbuzz' else if %d%%5==0~'buzz' else if %d%%3==0~'fizz' else if true ~'%d'"):format(i,i,i,i):gsub("~", " then print"))() end

i=0
print(loadstring(('if i%%15==0~"fizzbuzz" else if i%%5==0~"buzz" else if i%%3==0~"fizz" else if true~(i) end'):format(i,i,i,i):gsub("~", " then print")))
