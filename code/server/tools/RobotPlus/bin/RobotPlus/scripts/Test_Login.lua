LoginUnit = {}

--RegMessage(106, "LoginUnit", "OnPlayerLogin")
RegMessage(108, "LoginUnit", "OnUserLogin")
RegMessage(109, "LoginUnit", "OnPlayerCount")

LoginUnit.Logic = function()
end

LoginUnit.Event = function()
end

LoginUnit.OnUserLogin = function(socket, uid, key, server, ip, port)
	ConnectGate(socket, uid, key, server, ip, port)
end

LoginUnit.OnPlayerCount = function(socket, count)
	if count <= 0 then
		CreatePlayer(socket, 1, "»úÆ÷ÈË"..socket, 1, 1, 1)
	end
end

LoginUnit.OnPlayerLogin = function(socket, pid)
	--UserLogout(socket)
end
