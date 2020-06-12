workspace "Oak"
    architecture "x86_64"
    startproject "Sandbox"
    configurations { 
        "Debug",
        "Release",
        "Dist"
    }
    flags {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Oak/vendor/GLFW/include"

-- include GLFW premake file
include "Oak/vendor/GLFW"

project "Oak"
    location "Oak"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    pchheader "oakpch.h"
    pchsource "Oak/src/oakpch.cpp"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"
        defines {
            "OAK_PLATFORM_WINDOWS",
            "OAK_BUILD_DLL"
        }
        
    postbuildcommands {
        ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
    }

    filter "configurations:Debug"
        defines "OAK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OAK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "OAK_DIST"
        optimize "On"
        

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "On"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "Oak/vendor/spdlog/include",
        "Oak/src"
    }

    links {
        "Oak"
    }

    filter "system:windows"
        systemversion "latest"
        defines {
            "OAK_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "OAK_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "OAK_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "OAK_DIST"
        optimize "On"