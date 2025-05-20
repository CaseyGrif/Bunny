workspace "Bunny"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- ===================
-- Bunny Shared Library
-- ===================
project "Bunny"
	location "Bunny"
	kind "SharedLib"
	language "C++"

	targetdir ("build/" .. outputDir .. "/%{prj.name}")
	objdir ("build-intermediates/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"lib/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "on"
		systemversion "10.0"

		defines
		{
			"B_PLATFORM_WINDOWS",
			"B_BUILD_DLL"
		}

		buildoptions
		{
			"/utf-8"
		}

		postbuildcommands
		{
			"{COPYFILE} %{cfg.buildtarget.relpath} ../build/" .. outputDir .. "/Sandbox"
		}

	filter "configurations:Debug"
		defines "B_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "B_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "B_DIST"
		optimize "on"

-- ==============
-- Sandbox Console App
-- ==============
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("build/" .. outputDir .. "/%{prj.name}")
	objdir ("build-intermediates/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"lib/spdlog/include",
		"Bunny/src"
	}

	links
	{
		"Bunny"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "on"
		systemversion "10.0"

		defines
		{
			"B_PLATFORM_WINDOWS"
		}

				buildoptions
		{
			"/utf-8"
		}



	filter "configurations:Debug"
		defines "B_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "B_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "B_DIST"
		optimize "on"
