local lg = love.graphics

local function run_game(bluefn)
	function love.draw()
		lg.clear(255, 0, bluefn(), 255)
	end
end

run_game(function () return love.timer.getTime()*10 % 255 end)

