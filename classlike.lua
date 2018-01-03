local Class = function (tab)
  return setmetatable(
    tab, {__call = function (t)
            return setmetatable(t or {}, tab)
  end})
end

local Pizza = Class{
  pepperoni = true,
}

local ass = Pizza()
print(ass.pepperoni)
