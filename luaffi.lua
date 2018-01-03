local lcpp = require"lcpp/lcpp"
local ffi = require"ffi"

local sdl2_lib = ffi.load"#include <SDL2/SDL.h>"
local sdl2 = setmetatable({}, {
    __index = function (_, fn) return sdl2_lib["SDL_" .. fn] end
})
sdl2.CreateWindow("wow mom")
