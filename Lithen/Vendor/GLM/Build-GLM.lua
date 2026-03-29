project "GLM"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	targetdir ("%{wks.location}/Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

	files { "glm/**.hpp", "glm/**.cpp" }

	filter "system:windows"
		systemversion "latest"
