project "App"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	files { "Source/**.h", "Source/**.cpp", "Shaders/**.glsl" }

	includedirs
	{
		"Source",
		"%{wks.location}/Lithen/Source",
		"%{wks.location}/Lithen/Vendor/GLFW/include",
		"%{wks.location}/Lithen/Vendor/Glad/include",
		"%{wks.location}/Lithen/Vendor/GLM",
		"%{wks.location}/Lithen/Vendor/imgui",
	}

	links
	{
		"Lithen"
	}

	targetdir ("%{wks.location}/Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

	filter "system:windows"
		systemversion "latest"
		defines { "LN_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines { "LN_DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "LN_RELEASE" }
		runtime "Release"
		optimize "On"
		symbols "On"

	filter "configurations:Dist"
		kind "WindowedApp"
		defines { "LN_DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"
