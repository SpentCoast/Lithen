project "Lithen"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "Off"

	files { "Source/**.h", "Source/**.cpp" }

	includedirs
	{
		"Source",
		"Vendor/GLFW/include",
		"Vendor/Glad/include",
		"Vendor/GLM",
		"Vendor/imgui",
		"Vendor/stb"
	}

	links
	{
		"GLFW",
		"Glad",
		"GLM",
		"ImGui",
		"opengl32.lib"
	}

	targetdir ("%{wks.location}/Binaries/" .. OutputDir .. "/%{prj.name}")
	objdir ("%{wks.location}/Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

	filter "system:windows"
		systemversion "latest"
		defines
		{
			"LN_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE"
		}

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
		defines { "LN_DIST" }
		runtime "Release"
		optimize "On"
		symbols "Off"
