workspace "Bunny"
	architecture "x64"

	configurations
	{
		"Debug"
		"Release"
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Bunny"
	location "Bunny"
	kind "SharedLib"
	language "C++"

	tragetDir ("build/"..outputDir.."/%{prj.name}")
	objDir ("build-intermediates/"..outputDir.."/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	include 
	{
		"%{prj.name}/lib/spdlog/include"
	}


							
	-- ####################### START HERE TOMORROOW ######################### --
	-- ####################### START HERE TOMORROOW ######################### --
	-- ####################### START HERE TOMORROOW ######################### --
	-- ####################### START HERE TOMORROOW ######################### --
	-- ####################### START HERE TOMORROOW ######################### --
	-- 17:47
	-- 17:47
	-- 17:47
	-- 17:47

	filter "system:windows"

B_PLATFORM_WINDOWS;B_BUILD_DLL