workspace "Lithen"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Lithen/vendor/GLFW/include"
IncludeDir["Glad"] = "Lithen/vendor/Glad/include"
IncludeDir["ImGui"] = "Lithen/vendor/imgui"
IncludeDir["glm"] = "Lithen/vendor/glm"

include "Lithen/vendor/GLFW"
include "Lithen/vendor/Glad"
include "Lithen/vendor/imgui"

project "Lithen"
	location "Lithen"
	kind "SharedLib"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "lnpch.h"
	pchsource "Lithen/src/lnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LN_PLATFORM_WINDOWS",
			"LN_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox\"")
		}

	filter "configurations:Debug"
		defines "LN_DEBUG"
		runtime "Debug"
		buildoptions "/utf-8"
		symbols "On"

	filter "configurations:Release"
		defines "LN_RELEASE"
		runtime "Release"
		buildoptions "/utf-8"
		optimize "On"

	filter "configurations:Dist"
		defines "LN_DIST"
		buildoptions "/utf-8"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "Off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Lithen/vendor/spdlog/include",
		"Lithen/src",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Lithen"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"LN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "LN_DEBUG"
		runtime "Debug"
		buildoptions "/utf-8"
		symbols "On"

	filter "configurations:Release"
		defines "LN_RELEASE"
		runtime "Release"
		buildoptions "/utf-8"
		optimize "On"

	filter "configurations:Dist"
		defines "LN_DIST"
		buildoptions "/utf-8"
		optimize "On"
