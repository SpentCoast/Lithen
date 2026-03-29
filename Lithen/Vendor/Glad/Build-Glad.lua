project "Glad"
	kind "StaticLib"
	language "C"
	staticruntime "Off"

	targetdir ("%{wks.location}/Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

	files { "include/**.h", "src/glad.c" }
	includedirs { "include" }

	filter "system:windows"
		systemversion "latest"
