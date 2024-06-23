workspace "Aurora"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Aurora/vendor/GLFW/include"
IncludeDir["GLAD"] = "Aurora/vendor/GLAD/include"
IncludeDir["ImGui"] = "Aurora/vendor/imgui"

group "Dependencies"
    include "Aurora/vendor/GLFW"
    include "Aurora/vendor/GLAD"
    include "Aurora/vendor/imgui"

group ""

project "Aurora"
    location "Aurora"
    kind "SharedLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "aurorapch.h"
    pchsource "Aurora/src/aurorapch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.GLAD}",
        "%{IncludeDir.ImGui}"
    }

    links
    {
        "GLFW",
        "opengl32.lib",
        "dwmapi.lib",
        "GLAD",
        "ImGui"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
            "AURORA_PLATFORM_WINDOWS",
            "AURORA_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        runtime "Debug"
        defines "AURORA_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        defines "AURORA_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        defines "AURORA_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Aurora/vendor/spdlog/include",
        "Aurora/src/",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "Aurora"
    }

    filter "system:windows"
        cppdialect "C++20"
        systemversion "latest"

        defines
        {
            "AURORA_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        runtime "Debug"
        defines "AURORA_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        runtime "Release"
        defines "AURORA_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        runtime "Release"
        defines "AURORA_DIST"
        buildoptions "/MD"
        optimize "On"