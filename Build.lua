workspace "Lithen"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }
	startproject "App"

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

include "LithenExternal.lua"
include "App/Build-App.lua"