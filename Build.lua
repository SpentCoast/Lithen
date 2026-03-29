workspace "Lithen"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "App"

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "App/Build-App.lua"

group "Dependencies"
	include "Lithen/Vendor/GLFW/Build-GLFW.lua"
	include "Lithen/Vendor/Glad/Build-Glad.lua"
	include "Lithen/Vendor/GLM/Build-GLM.lua"
	include "Lithen/Vendor/imgui/Build-ImGui.lua"
group ""

group "Core"
	include "Lithen/Build-Lithen.lua"
group ""